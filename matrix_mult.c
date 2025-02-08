#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "dataset1.h"

#define MIN(X, Y) (((X) < (Y)) ? (X) : (Y))
#define OPCODE 11     //opcode: 0001011
#define LOAD_DENSE 1  //funct3: 001
#define LOAD_SPARSE 2 //funct3: 010
#define RESET_ACC 0   //funct3: 000
#define STORE_ACC 3   //funct3: 011
#define min(x, y) ((x) < (y) ? (x) : (y))

int64_t REG_FILE[32]; //Memory elements accessed from both the accelerator and the program
int8_t sparse[4][2], meta_data[4][2], dense[4][4];
int32_t ACC[4][4];
int8_t compressed_sparse_matrix[SPARSE_ROWS][SPARSE_COLS / 2];
int64_t rs1, rs2, rd;

/*rs1 contains the first two rows of the dense matrix,
  rs2 contains the second  two rows of the dense matrix*/
void load_dense_matrix(int8_t dense[4][4], int rs1, int rs2) {
    int64_t rs1_data, rs2_data;

    rs1_data = REG_FILE[rs1];
    rs2_data = REG_FILE[rs2];

    for (int i=3; i >= 0; i--) {
        for (int j=3; j >= 0; j--) {
            if (i <= 1)
            {
                dense[i][j] = rs1_data & 0xFF; 
                rs1_data = rs1_data>>8;
            }
            else {
                dense[i][j] = rs2_data & 0xFF;
                rs2_data = rs2_data>>8;
            }
        }
    }
}

/*rs1 contains the sparse matrix,
  rs2 contains the metadata of the sparse matrix*/
void load_sparse_matrix(int8_t sparse[4][2], int8_t metadata[4][2], int rs1, int rs2) {
    int64_t rs1_data, rs2_data;

    rs1_data = REG_FILE[rs1];
    rs2_data = REG_FILE[rs2];

    for (int i=3; i >= 0; i--) {
        for (int j=1; j >= 0; j--) {
            sparse[i][j] = rs1_data & 0xFF; 
            rs1_data = rs1_data>>8;
          
            metadata[i][j] = rs2_data & 0xFF;
            rs2_data = rs2_data>>8;
        }
    }
}

void accelerator_unit(int32_t instr) {
    int8_t opcode, rs1, rs2, rd, funct3, funct7, i;
    int64_t wr_back_data;
    
    opcode = instr & 127;           //mask is 127=2^7-1 because opcode is 7bits long
    rd = (instr >> 7) & 31;         //mask is 31=2^5-1 because rd is 5bits long
    funct3 = (instr >> 12) & 7;     //mask is 7=2^3-1 because funct3 is 3bits long
    rs1 = (instr >> 15) & 31;       //mask is 31=2^5-1 because rs1 is 5bits long
    rs2 = (instr >> 20) & 31;       //mask is 31=2^5-1 because rs2 is 5bits long
    funct7 = (instr >> 25) & 127;   //mask is 127=2^7-1 because funct7 is 7bits long


    //printf("HERE: opcode: %d funct3: %d rs1: %d rs2: %d\n", opcode, funct3, rs1, rs2);
    if (opcode == OPCODE) {
        switch (funct3) {
            case LOAD_DENSE:
                load_dense_matrix(dense, rs1, rs2); 
                /*for (int i = 0; i < 4; i++)
                {
                    for (int j = 0; j < 4; j++)
                    {
                        printf("%d ", dense[i][j]);
                    }
                    printf("\n");
                }*/
                break;

            case LOAD_SPARSE:
                load_sparse_matrix(sparse, meta_data, rs1, rs2);
                /*for (int i = 0; i < 4; i++)
                {
                    for (int j = 0; j < 2; j++)
                    {
                        printf("%d ", sparse[i][j]);
                    }
                    printf("\n");
                }*/

                /*for (int i = 0; i < 4; i++)
                {
                    for (int j = 0; j < 2; j++)
                    {
                        printf("%d ", meta_data[i][j]);
                    }
                    printf("\n");
                }*/

                for (int i = 0; i < 4; i++) {  // Rows in the current block
                    for (int j = 0; j < 4; j++) {  // Columns in the current block
                        for (int k = 0; k < 2; k++) {  // Overlapping blocks
                            ACC[i][j] += sparse[i][k] * dense[meta_data[i][k]][j];  // Dot product for the block
                        }
                    }
                }

                /*for (int i = 0; i < 4; i++)
                {
                    for (int j = 0; j < 4; j++)
                    {
                        printf("%d ", ACC[i][j]);
                    }
                    printf("\n");
                }*/
                break;

            case RESET_ACC:
                for (int i = 0; i < 4; i++) {
                    memset(ACC[i], 0, 4*sizeof(int32_t));
                }

                /*for (int i = 0; i < 4; i++)
                {
                    for (int j = 0; j < 4; j++)
                    {
                        printf("%d ", ACC[i][j]);
                    }
                    printf("\n");
                }*/
                break;

            case STORE_ACC:
                wr_back_data = 0;
                i = 0; //if funct7 = 0 or 2, the row of ACC is 0
                if ((funct7 >= 4) & (funct7 <= 6)) {
                    i = 1;
                } else if ((funct7 >= 8) & (funct7 <= 10)) {
                    i = 2;
                } else if ((funct7 >= 12) & (funct7 <= 14)) {
                    i = 3;
                }

                if (funct7 % 4 == 0) //data are located at cols 0,1 of row i in ACC
                {
                    wr_back_data = (wr_back_data + ACC[i][0]) << 32;
                    wr_back_data = wr_back_data + ACC[i][1];
                } else { //data are located at cols 2,3 of row i in ACC
                    wr_back_data = (wr_back_data + ACC[i][2]) << 32;
                    wr_back_data = wr_back_data + ACC[i][3];
                }
                REG_FILE[rd] = wr_back_data;
                break;
        }

    } else {
        //fprintf(stderr, "Unknown instruction exception\n");
        //exit(1);
    }
}

void print_matrix(int **matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%6.2d ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void remove_zeros(int8_t sparse_matrix[SPARSE_ROWS][SPARSE_COLS]) {
    for (int i = 0; i < SPARSE_ROWS; i++) {
        int index = 0;
        for (int j = 0; j < SPARSE_COLS; j++) {
            if (sparse_matrix[i][j] != 0) {
                compressed_sparse_matrix[i][index++] = sparse_matrix[i][j];
            }
            if (index >= SPARSE_COLS / 2) {
                break; // Ensure we do not exceed the allocated space
            }
        }
    }

    for (int i = 0; i < SPARSE_ROWS; i++)
    {
        for (int j = 0; j < SPARSE_COLS/2; j++)
        {
            printf("%6.2d", compressed_sparse_matrix[i][j]);
        }
        printf("\n"); //the prints here prevent from cva6 simulation
    }
    printf("\n"); //the prints here prevent from cva6 simulation
}

void matrix_mult_emul(int B, int M, int K, int N, int8_t sparse[M][K/2], int8_t dense[K][N], int8_t metadata[M][K/2]) {
    int rs1, rs2, rd;
    int32_t final[8][8], instr; 
    int64_t row1, row2, row3, row4;

    accelerator_unit(0b0001011);

    // Perform blocked multiplication row by row for blocks in row-major order.
    for (int ii = 0; ii < M; ii += B) {            // Block rows of Y and X
        for (int jj = 0; jj < N; jj += B) {        // Block columns of Z and X
            for (int kk = 0; kk < K; kk += B) {    // Block columns of Y and rows of Z
                rs1 = 10;
                rs2 = 11;
                row1 = (dense[kk][jj] << 24) | (dense[kk][jj+1] << 16) | (dense[kk][jj+2] << 8) | dense[kk][jj+3];
                row2 = (dense[kk+1][jj] << 24) | (dense[kk+1][jj+1] << 16) | (dense[kk+1][jj+2] << 8) | dense[kk+1][jj+3];
                row3 = (dense[kk+2][jj] << 24) | (dense[kk+2][jj+1] << 16) | (dense[kk+2][jj+2] << 8) | dense[kk+2][jj+3];
                row4 = (dense[kk+3][jj] << 24) | (dense[kk+3][jj+1] << 16) | (dense[kk+3][jj+2] << 8) | dense[kk+3][jj+3];
                
                REG_FILE[rs1] = ((row1 << 32) ^ row2); //rows 1 and 2 of dense go on rs1
                REG_FILE[rs2] = ((row3 << 32) ^ row4); //rows 3 and 4 of dense go on rs2
                accelerator_unit(0b00000000101101010001000000001011); // funct7:0 rs2:11 rs1:10 funct3:1 rd:0 opcode:11

                rs1 = 12;
                rs2 = 13;
                row1 = (sparse[ii][kk/2] << 8)   | sparse[ii][kk/2+1];
                row2 = (sparse[ii+1][kk/2] << 8) | sparse[ii+1][kk/2+1];
                row3 = (sparse[ii+2][kk/2] << 8) | sparse[ii+2][kk/2+1];
                row4 = (sparse[ii+3][kk/2] << 8) | sparse[ii+3][kk/2+1];
                REG_FILE[rs1] = (((((row1 << 16) ^ row2) << 16) ^ row3) << 16) ^ row4; //the whole sparse matrix gets stored on rs1
                
                row1 = (metadata[ii][kk/2] << 8)   | metadata[ii][kk/2+1];
                row2 = (metadata[ii+1][kk/2] << 8) | metadata[ii+1][kk/2+1];
                row3 = (metadata[ii+2][kk/2] << 8) | metadata[ii+2][kk/2+1];
                row4 = (metadata[ii+3][kk/2] << 8) | metadata[ii+3][kk/2+1];
                REG_FILE[rs2] = (((((row1 << 16) ^ row2) << 16) ^ row3) << 16) ^ row4; //the whole metadata matrix gets stored on rs2
                accelerator_unit(0b00000000110101100010000000001011); // funct7:0 rs2:12 rs1:13 funct3:2 rd:0 opcode:11
            }
            
            rd = 14; 
            for (int i = ii; i < MIN(ii + B, M); i++)
            {
                for (int j = jj; j < MIN(jj + B, N); j+=2)
                {
                    instr = 0;
                    instr = (instr + (i-ii)*4+(j-jj)) << 13; //is funct7
                    instr = ((((instr + 3) << 5) + rd) << 7) + 11; 
                    accelerator_unit(instr);
                    final[i][j] = REG_FILE[rd] >> 32;
                    final[i][j+1] = REG_FILE[rd] & 4294967295;
                }
            }
            accelerator_unit(0b0001011); //reset accumulator for new block
        }
    }
    
    /*for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            printf("%6.2d ", final[i][j]); //the prints here prevent from cva6 simulation
        }
        printf("\n"); //the prints here prevent from cva6 simulation
    }
    printf("\n"); //the prints here prevent from cva6 simulation*/
}

void matrix_mult_emul_accelerated(int B, int M, int K, int N, int8_t sparse[M][K/2], int8_t dense[K][N], int8_t metadata[M][K/2]) {
    int rs1, rs2, rd;
    int32_t final[8][8] = {{0},{0},{0},{0},{0},{0},{0},{0}}; 
    int64_t row1, row2, row3, row4;

    asm(".word 0b00000000000000000000000000001011"); //initialize the accelerator accumulators to zero

    // Perform blocked multiplication row by row for blocks in row-major order.
    for (int ii = 0; ii < M; ii += B) {            // Block rows of Y and X
        for (int jj = 0; jj < N; jj += B) {        // Block columns of Z and X
            for (int kk = 0; kk < K; kk += B) {    // Block columns of Y and rows of Z
                rs1 = 10;
                rs2 = 11;
                row1 = (dense[kk][jj] << 24) | (dense[kk][jj+1] << 16) | (dense[kk][jj+2] << 8) | dense[kk][jj+3];
                row2 = (dense[kk+1][jj] << 24) | (dense[kk+1][jj+1] << 16) | (dense[kk+1][jj+2] << 8) | dense[kk+1][jj+3];
                row3 = (dense[kk+2][jj] << 24) | (dense[kk+2][jj+1] << 16) | (dense[kk+2][jj+2] << 8) | dense[kk+2][jj+3];
                row4 = (dense[kk+3][jj] << 24) | (dense[kk+3][jj+1] << 16) | (dense[kk+3][jj+2] << 8) | dense[kk+3][jj+3];
                
                REG_FILE[rs1] = ((row1 << 32) ^ row2); //rows 1 and 2 of dense go on rs1
                REG_FILE[rs2] = ((row3 << 32) ^ row4); //rows 3 and 4 of dense go on rs2
            
                asm volatile(".insn r 0b0001011, 0b001, 0, x0, %1, %0" :: "r" (REG_FILE[rs2]), "r" (REG_FILE[rs1]));

                rs1 = 12;
                rs2 = 13;
                row1 = (sparse[ii][kk/2] << 8)   | sparse[ii][kk/2+1];
                row2 = (sparse[ii+1][kk/2] << 8) | sparse[ii+1][kk/2+1];
                row3 = (sparse[ii+2][kk/2] << 8) | sparse[ii+2][kk/2+1];
                row4 = (sparse[ii+3][kk/2] << 8) | sparse[ii+3][kk/2+1];
                REG_FILE[rs1] = (((((row1 << 16) ^ row2) << 16) ^ row3) << 16) ^ row4; //the whole sparse matrix gets stored on rs1
                
                row1 = (metadata[ii][kk/2] << 8)   | metadata[ii][kk/2+1];
                row2 = (metadata[ii+1][kk/2] << 8) | metadata[ii+1][kk/2+1];
                row3 = (metadata[ii+2][kk/2] << 8) | metadata[ii+2][kk/2+1];
                row4 = (metadata[ii+3][kk/2] << 8) | metadata[ii+3][kk/2+1];
                REG_FILE[rs2] = (((((row1 << 16) ^ row2) << 16) ^ row3) << 16) ^ row4; //the whole metadata matrix gets stored on rs2
                asm volatile(".insn r 0b0001011, 0b010, 0b0000001, x0, %1, %0" :: "r" (REG_FILE[rs2]), "r" (REG_FILE[rs1]));
            }
            
            rd = 14; 
            //Get the first row of the accumulator and put it inside the first row of the corresponding final block
            asm volatile(".insn r 0b0001011, 0b011, 0b0000000, %0, x0, x0" : "=r" (REG_FILE[rd]) :);
            final[ii][jj] = REG_FILE[rd] >> 32;
            final[ii][jj+1] = REG_FILE[rd] & 4294967295;
            asm volatile(".insn r 0b0001011, 0b011, 0b0000010, %0, x0, x0" : "=r" (REG_FILE[rd]) :);
            final[ii][jj+2] = REG_FILE[rd] >> 32;
            final[ii][jj+3] = REG_FILE[rd] & 4294967295;

            //Get the second row of the accumulator and put it inside the second row of the corresponding final block
            asm volatile(".insn r 0b0001011, 0b011, 0b0000100, %0, x0, x0" : "=r" (REG_FILE[rd]) :);
            final[ii+1][jj] = REG_FILE[rd] >> 32;
            final[ii+1][jj+1] = REG_FILE[rd] & 4294967295;
            asm volatile(".insn r 0b0001011, 0b011, 0b0000110, %0, x0, x0" : "=r" (REG_FILE[rd]) :);
            final[ii+1][jj+2] = REG_FILE[rd] >> 32;
            final[ii+1][jj+3] = REG_FILE[rd] & 4294967295;

            //Get the third row of the accumulator and put it inside the third row of the corresponding final block
            asm volatile(".insn r 0b0001011, 0b011, 0b0001000, %0, x0, x0" : "=r" (REG_FILE[rd]) :);
            final[ii+2][jj] = REG_FILE[rd] >> 32;
            final[ii+2][jj+1] = REG_FILE[rd] & 4294967295;
            asm volatile(".insn r 0b0001011, 0b011, 0b0001010, %0, x0, x0" : "=r" (REG_FILE[rd]) :);
            final[ii+2][jj+2] = REG_FILE[rd] >> 32;
            final[ii+2][jj+3] = REG_FILE[rd] & 4294967295;

            //Get the fourth row of the accumulator and put it inside the fourth row of the corresponding final block
            asm volatile(".insn r 0b0001011, 0b011, 0b0001100, %0, x0, x0" : "=r" (REG_FILE[rd]) :);
            final[ii+3][jj] = REG_FILE[rd] >> 32;
            final[ii+3][jj+1] = REG_FILE[rd] & 4294967295;
            asm volatile(".insn r 0b0001011, 0b011, 0b0001110, %0, x0, x0" : "=r" (REG_FILE[rd]) :);
            final[ii+3][jj+2] = REG_FILE[rd] >> 32;
            final[ii+3][jj+3] = REG_FILE[rd] & 4294967295;
    
            asm(".word 0b00000000000000000000000000001011");
        }
    }

    /*for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            printf("%6.2d ", final[i][j]); //the prints here prevent from cva6 simulation
        }
        printf("\n"); //the prints here prevent from cva6 simulation
    }
    printf("\n"); //the prints here prevent from cva6 simulation*/
}

void matrix_mult(int B, int M, int K, int N, int8_t sparse[M][K], int8_t dense[K][N]) {
    int32_t final[SPARSE_ROWS][DENSE_COLS], result; 

    for (int a = 0; a < M; a++) {
        for (int b = 0; b < N; b++)
        {
            final[a][b] = 0;
        }
    }

    // Perform blocked multiplication row by row for blocks in row-major order.
    for (int ii = 0; ii < M; ii += B) {            // Block rows of Y and X
        for (int jj = 0; jj < N; jj += B) {        // Block columns of Z and X
            for (int kk = 0; kk < K; kk += B) {    // Block columns of Y and rows of Z
                for (int i = ii; i < min(ii + B, M); i++) {  // Rows in the current block
                    for (int j = jj; j < min(jj + B, N); j++) {  // Columns in the current block
                        result = 0;
                        for (int k = kk; k < min(kk + B, K); k++) {  // Overlapping blocks
                            result += (int32_t) sparse[i][k] * dense[k][j];  // Dot product for the block
                        }
                        final[i][j] += result;
                    }
                }
            }
        }
    }
    
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            printf("%6.2d ", final[i][j]); //the prints here prevent from cva6 simulation
        }
        printf("\n"); //the prints here prevent from cva6 simulation
    }
    printf("\n"); //the prints here prevent from cva6 simulation
}

void matrix_mult_accelerated(int B, int M, int K, int N, int8_t sparse[M][K/2], int8_t dense[K][N], int8_t metadata[M][K/2]) {
    int32_t final[8][8] = {{0},{0},{0},{0},{0},{0},{0},{0}}; 
    int64_t row1, row2, row3, row4;

    asm(".word 0b00000000000000000000000000001011"); //initialize the accelerator accumulators to zero

    // Perform blocked multiplication row by row for blocks in row-major order.
    for (int ii = 0; ii < M; ii += B) {            // Block rows of Y and X
        for (int jj = 0; jj < N; jj += B) {        // Block columns of Z and X
            for (int kk = 0; kk < K; kk += B) {    // Block columns of Y and rows of Z
                row1 = (dense[kk][jj] << 24) | (dense[kk][jj+1] << 16) | (dense[kk][jj+2] << 8) | dense[kk][jj+3];
                row2 = (dense[kk+1][jj] << 24) | (dense[kk+1][jj+1] << 16) | (dense[kk+1][jj+2] << 8) | dense[kk+1][jj+3];
                row3 = (dense[kk+2][jj] << 24) | (dense[kk+2][jj+1] << 16) | (dense[kk+2][jj+2] << 8) | dense[kk+2][jj+3];
                row4 = (dense[kk+3][jj] << 24) | (dense[kk+3][jj+1] << 16) | (dense[kk+3][jj+2] << 8) | dense[kk+3][jj+3];
                
                rs1 = ((row1 << 32) ^ row2); //rows 1 and 2 of dense go on rs1
                rs2 = ((row3 << 32) ^ row4); //rows 3 and 4 of dense go on rs2
                asm volatile(".insn r 0b0001011, 0b001, 0, x0, %1, %0" :: "r" (rs2), "r" (rs1));

                row1 = (sparse[ii][kk/2] << 8)   | sparse[ii][kk/2+1];
                row2 = (sparse[ii+1][kk/2] << 8) | sparse[ii+1][kk/2+1];
                row3 = (sparse[ii+2][kk/2] << 8) | sparse[ii+2][kk/2+1];
                row4 = (sparse[ii+3][kk/2] << 8) | sparse[ii+3][kk/2+1];
                rs1 = (((((row1 << 16) ^ row2) << 16) ^ row3) << 16) ^ row4; //the whole sparse matrix gets stored on rs1
                
                row1 = (metadata[ii][kk/2] << 8)   | metadata[ii][kk/2+1];
                row2 = (metadata[ii+1][kk/2] << 8) | metadata[ii+1][kk/2+1];
                row3 = (metadata[ii+2][kk/2] << 8) | metadata[ii+2][kk/2+1];
                row4 = (metadata[ii+3][kk/2] << 8) | metadata[ii+3][kk/2+1];
                rs2 = (((((row1 << 16) ^ row2) << 16) ^ row3) << 16) ^ row4; //the whole metadata matrix gets stored on rs2
                asm volatile(".insn r 0b0001011, 0b010, 0b0000001, x0, %1, %0" :: "r" (rs2), "r" (rs1));
            }
            
            //Get the first row of the accumulator and put it inside the first row of the corresponding final block
            asm volatile(".insn r 0b0001011, 0b011, 0b0000000, %0, x0, x0" : "=r" (rd) :);
            final[ii][jj] = rd >> 32;
            final[ii][jj+1] = rd & 4294967295;
            asm volatile(".insn r 0b0001011, 0b011, 0b0000010, %0, x0, x0" : "=r" (rd) :);
            final[ii][jj+2] = rd >> 32;
            final[ii][jj+3] = rd & 4294967295;

            //Get the second row of the accumulator and put it inside the second row of the corresponding final block
            asm volatile(".insn r 0b0001011, 0b011, 0b0000100, %0, x0, x0" : "=r" (rd) :);
            final[ii+1][jj] = rd >> 32;
            final[ii+1][jj+1] = rd & 4294967295;
            asm volatile(".insn r 0b0001011, 0b011, 0b0000110, %0, x0, x0" : "=r" (rd) :);
            final[ii+1][jj+2] = rd >> 32;
            final[ii+1][jj+3] = rd & 4294967295;

            //Get the third row of the accumulator and put it inside the third row of the corresponding final block
            asm volatile(".insn r 0b0001011, 0b011, 0b0001000, %0, x0, x0" : "=r" (rd) :);
            final[ii+2][jj] = rd >> 32;
            final[ii+2][jj+1] = rd & 4294967295;
            asm volatile(".insn r 0b0001011, 0b011, 0b0001010, %0, x0, x0" : "=r" (rd) :);
            final[ii+2][jj+2] = rd >> 32;
            final[ii+2][jj+3] = rd & 4294967295;

            //Get the fourth row of the accumulator and put it inside the fourth row of the corresponding final block
            asm volatile(".insn r 0b0001011, 0b011, 0b0001100, %0, x0, x0" : "=r" (rd) :);
            final[ii+3][jj] = rd >> 32;
            final[ii+3][jj+1] = rd & 4294967295;
            asm volatile(".insn r 0b0001011, 0b011, 0b0001110, %0, x0, x0" : "=r" (rd) :);
            final[ii+3][jj+2] = rd >> 32;
            final[ii+3][jj+3] = rd & 4294967295;
    
            asm(".word 0b00000000000000000000000000001011");
        }
    }

    /*for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            printf("%6.2d ", final[i][j]); //the prints here prevent from cva6 simulation
        }
        printf("\n"); //the prints here prevent from cva6 simulation
    }
    printf("\n"); //the prints here prevent from cva6 simulation*/
}

void example(int B, int M, int K, int N, int8_t sparse[M][K/2], int8_t dense[K][N], int8_t metadata[M][K/2]) {
    int32_t final[8][8] = {{0},{0},{0},{0},{0},{0},{0},{0}}; 
    int64_t row1, row2, row3, row4;

    asm(".word 0b00000000000000000000000000001011"); //initialize the accelerator accumulators to zero

    // Perform blocked multiplication row by row for blocks in row-major order.
    for (int ii = 0; ii < M; ii += B) {            // Block rows of Y and X
        for (int jj = 0; jj < N; jj += B) {        // Block columns of Z and X
            for (int kk = 0; kk < K; kk += B) {    // Block columns of Y and rows of Z
                /*row1 = (dense[kk][jj] << 24) | (dense[kk][jj+1] << 16) | (dense[kk][jj+2] << 8) | dense[kk][jj+3];
                row2 = (dense[kk+1][jj] << 24) | (dense[kk+1][jj+1] << 16) | (dense[kk+1][jj+2] << 8) | dense[kk+1][jj+3];
                row3 = (dense[kk+2][jj] << 24) | (dense[kk+2][jj+1] << 16) | (dense[kk+2][jj+2] << 8) | dense[kk+2][jj+3];
                row4 = (dense[kk+3][jj] << 24) | (dense[kk+3][jj+1] << 16) | (dense[kk+3][jj+2] << 8) | dense[kk+3][jj+3];*/
                row1 = *((int32_t *) (dense[kk] + jj));
                row2 = *((int32_t *) (dense[kk+1] + jj));
                row3 = *((int32_t *) (dense[kk+2] + jj));
                row4 = *((int32_t *) (dense[kk+3] + jj));
                
                rs1 = ((row2 << 32) | row1); //rows 1 and 2 of dense go on rs1
                rs2 = ((row4 << 32) | row3); //rows 3 and 4 of dense go on rs2
                asm volatile(".insn r 0b0001011, 0b001, 0, x0, %1, %0" :: "r" (rs2), "r" (rs1));

                /*row1 = (sparse[ii][kk/2] << 8)   | sparse[ii][kk/2+1];
                row2 = (sparse[ii+1][kk/2] << 8) | sparse[ii+1][kk/2+1];
                row3 = (sparse[ii+2][kk/2] << 8) | sparse[ii+2][kk/2+1];
                row4 = (sparse[ii+3][kk/2] << 8) | sparse[ii+3][kk/2+1];*/
                row1 = *((int16_t *) (sparse[ii] + kk/2));
                row2 = *((int16_t *) (sparse[ii+1] + kk/2));
                row3 = *((int16_t *) (sparse[ii+2] + kk/2));
                row4 = *((int16_t *) (sparse[ii+3] + kk/2));
                //rs1 = (((((row1 << 16) ^ row2) << 16) ^ row3) << 16) ^ row4; //the whole sparse matrix gets stored on rs1
                rs1 = (((((row4 << 16) | row3) << 16) | row2) << 16) | row1;
                
                /*row1 = (metadata[ii][kk/2] << 8)   | metadata[ii][kk/2+1];
                row2 = (metadata[ii+1][kk/2] << 8) | metadata[ii+1][kk/2+1];
                row3 = (metadata[ii+2][kk/2] << 8) | metadata[ii+2][kk/2+1];
                row4 = (metadata[ii+3][kk/2] << 8) | metadata[ii+3][kk/2+1];*/
                row1 = *((int16_t *) (metadata[ii] + kk/2));
                row2 = *((int16_t *) (metadata[ii+1] + kk/2));
                row3 = *((int16_t *) (metadata[ii+2] + kk/2));
                row4 = *((int16_t *) (metadata[ii+3] + kk/2));
                //rs2 = (((((row1 << 16) ^ row2) << 16) ^ row3) << 16) ^ row4; //the whole metadata matrix gets stored on rs2
                rs2 = (((((row4 << 16) | row3) << 16) | row2) << 16) | row1; 
                asm volatile(".insn r 0b0001011, 0b010, 0b0000001, x0, %1, %0" :: "r" (rs2), "r" (rs1));
            }
            
            //Get the first row of the accumulator and put it inside the first row of the corresponding final block
            /*asm volatile(".insn r 0b0001011, 0b011, 0b0000000, %0, x0, x0" : "=r" (rd) :);
            final[ii][jj] = rd >> 32;
            final[ii][jj+1] = rd & 4294967295;
            asm volatile(".insn r 0b0001011, 0b011, 0b0000010, %0, x0, x0" : "=r" (rd) :);
            final[ii][jj+2] = rd >> 32;
            final[ii][jj+3] = rd & 4294967295;

            //Get the second row of the accumulator and put it inside the second row of the corresponding final block
            asm volatile(".insn r 0b0001011, 0b011, 0b0000100, %0, x0, x0" : "=r" (rd) :);
            final[ii+1][jj] = rd >> 32;
            final[ii+1][jj+1] = rd & 4294967295;
            asm volatile(".insn r 0b0001011, 0b011, 0b0000110, %0, x0, x0" : "=r" (rd) :);
            final[ii+1][jj+2] = rd >> 32;
            final[ii+1][jj+3] = rd & 4294967295;

            //Get the third row of the accumulator and put it inside the third row of the corresponding final block
            asm volatile(".insn r 0b0001011, 0b011, 0b0001000, %0, x0, x0" : "=r" (rd) :);
            final[ii+2][jj] = rd >> 32;
            final[ii+2][jj+1] = rd & 4294967295;
            asm volatile(".insn r 0b0001011, 0b011, 0b0001010, %0, x0, x0" : "=r" (rd) :);
            final[ii+2][jj+2] = rd >> 32;
            final[ii+2][jj+3] = rd & 4294967295;

            //Get the fourth row of the accumulator and put it inside the fourth row of the corresponding final block
            asm volatile(".insn r 0b0001011, 0b011, 0b0001100, %0, x0, x0" : "=r" (rd) :);
            final[ii+3][jj] = rd >> 32;
            final[ii+3][jj+1] = rd & 4294967295;
            asm volatile(".insn r 0b0001011, 0b011, 0b0001110, %0, x0, x0" : "=r" (rd) :);
            final[ii+3][jj+2] = rd >> 32;
            final[ii+3][jj+3] = rd & 4294967295;*/
    
            asm(".word 0b00000000000000000000000000001011");
        }
    }
}


int main(void) {
    int8_t sparse[8][4]={{1,4,5,5},{4,8,5,6},{5,7,9,4},{4,6,9,3},{6,5,8,3},{6,5,8,3},{6,5,8,3},{6,5,8,3}};  //Pressumed matrix is pre-compressed
    int8_t sparse_orig[8][8]={{1,0,4,0,0,5,5,0},{0,0,4,8,0,5,6,0},{5,0,0,7,0,0,9,4},{4,0,6,0,0,0,9,3},{0,6,0,5,8,0,3,0},{0,0,6,5,8,3,0,0},{0,6,5,0,0,8,3,0},{0,0,6,5,0,8,3,0}};  //Pressumed matrix is not pre-compressed
    int8_t dense[8][8]={{1,4,5,6,2,8,8,3},{7,9,6,8,5,8,7,8},{3,4,5,6,8,7,5,3},{1,4,5,6,2,8,8,3},{7,9,6,8,5,8,7,8},{3,4,5,6,8,7,5,3},{1,4,5,6,2,8,8,3},{7,9,6,8,5,8,7,8}};
    int8_t metadata[8][4] = {{0,2,1,2},{2,3,1,2},{0,3,2,3},{0,2,2,3},{1,3,0,2},{2,3,0,1},{1,2,1,2},{2,3,1,2}};
    //int32_t final[8][8] = {{0},{0},{0},{0},{0},{0},{0},{0}}, instr, final_test[8][8] = {{33,60,75,90,84,111,93,45},{41,92,115,138,100,175,157,69},{49,120,129,158,62,200,196,95},{52,103,113,138,59,170,155,81},{106,158,124,160,86,179,162,136},{88,128,118,148,122,167,141,106},{84,118,116,144,140,163,131,96},{50,88,110,132,128,162,134,66}};
    int B=4, M=8, K=8, N=8; //B is the block dimensions, M is the num of sparse matrix rows, K is the num of sparse columns(un-compressed) and dense columns, N is the num of dense columns.
    /*int32_t *instr;
    instr = (int32_t *) dense[0];
    printf("%x", *instr);*/


    //matrix_mult(B,SPARSE_ROWS,SPARSE_COLS,DENSE_COLS,sparse_matrix,dense_matrix);
    //remove_zeros(sparse_matrix);
    //matrix_mult_accelerated(B,M,K,N,sparse,dense,metadata);
    example(B,M,K,N,sparse,dense,metadata);
    //matrix_mult_accelerated(B,SPARSE_ROWS,SPARSE_COLS,DENSE_COLS,sparse_matrix,dense_matrix,metadata_matrix);

    return 0;
}