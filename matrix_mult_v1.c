#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

#define MIN(X, Y) (((X) < (Y)) ? (X) : (Y))
#define OPCODE 11     //opcode: 0001011
#define LOAD_DENSE 1  //funct3: 001
#define LOAD_SPARSE 2 //funct3: 010
#define RESET_ACC 0   //funct3: 000
#define STORE_ACC 3   //funct3: 011

int64_t REG_FILE[32]; //Memory elements accessed from both the accelerator and the program


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
                dense[i][j] = rs1_data ^ 0b00000000; 
                rs1_data = rs1_data>>8;
            }
            else {
                dense[i][j] = rs2_data ^ 0b00000000;
                rs2_data = rs2_data>>8;
            }
        }
    }
}

//void reset_accumulator()

void accelerator_unit(int32_t instr) {
    static int8_t sparse[4][2], meta_data[4][2], dense[4][4];
    static int32_t ACC[4][4];
    static int8_t opcode, rs1, rs2, funct3;
    
    opcode = instr & 127;       //mask is 127=2^7-1 because opcode is 7bits long
    funct3 = (instr >> 12) & 7; //mask is 7=2^3-1 because funct3 is 3bits long
    rs1 = (instr >> 15) & 31;   //mask is 31=2^5-1 because rs1 is 5bits long
    rs2 = (instr >> 20) & 31;   //mask is 31=2^5-1 because rs2 is 5bits long

    printf("HERE: opcode: %d funct3: %d rs1: %d rs2: %d\n", opcode, funct3, rs1, rs2);
    if (opcode == OPCODE) {
        switch (funct3) {
            case LOAD_DENSE:
                load_dense_matrix(dense, rs1, rs2); 
                for (int i = 0; i < 4; i++)
                {
                    for (int j = 0; j < 4; j++)
                    {
                        printf("%d ", dense[i][j]);
                    }
                    printf("\n");
                }
                break;

            case LOAD_SPARSE:
                break;

            case RESET_ACC:
                for (int i = 0; i < 4; i++) {
                    memset(ACC[i], 0, 4*sizeof(int32_t));
                }

                for (int i = 0; i < 4; i++)
                {
                    for (int j = 0; j < 4; j++)
                    {
                        printf("%d ", ACC[i][j]);
                    }
                    printf("\n");
                }
                break;

            case STORE_ACC:
                break;
        }

    } else {
        fprintf(stderr, "Unknown instruction exception\n");
        exit(1);
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

int main(void) {
  /*  int64_t rs[32] = {0}; //initialize all regs in regfile with 0
    int8_t sparse_block[4][2], meta_data_block[4][2], dense_block[4][4];
    int32_t final[4][4];*/
    int8_t sparse[8][4]={{1,4,5,5},{4,8,5,6},{5,7,9,4},{4,6,9,3},{6,5,8,3},{6,5,8,3},{6,5,8,3},{6,5,8,3}};  //Pressumed matrix is pre-compressed
    int8_t dense[8][8]={{1,4,5,6,2,8,8,3},{7,9,6,8,5,8,7,8},{3,4,5,6,8,7,5,3},{1,4,5,6,2,8,8,3},{7,9,6,8,5,8,7,8},{3,4,5,6,8,7,5,3},{1,4,5,6,2,8,8,3},{7,9,6,8,5,8,7,8}};
    int8_t metadata[8][4] = {{0,2,1,2},{2,3,1,2},{0,3,2,3},{0,2,2,3},{1,3,0,2},{2,3,0,1},{1,2,1,2},{2,3,1,2}};
    int32_t final[8][8] = {{0},{0},{0},{0},{0},{0},{0},{0}};
    int sparse_columns;
    int B=4, M=8, K=4, N=8; //B is the block dimensions, M is the num of sparse matrix rows, K is the num of sparse columns(un-compressed) and dense columns, N is the num of dense columns.
    int rs1, rs2, block_num = 0;


    /*Call nullifying instr to initialize the accelerator accumulators*/
    accelerator_unit(0b0001011);

    // Perform blocked multiplication row by row for blocks in row-major order.
    for (int ii = 0; ii < M; ii += B) {            // Block rows of Y and X
        for (int jj = 0; jj < N; jj += B) {        // Block columns of Z and X
            /*Here the specific block we want to process is known. 
              1. Software has to place the dense block into 2 registers in the register file so that the accelerator can read it.
              2. Call the accelerator instr to load the dense block into the accelerator.
            */
            rs1 = 10;
            rs2 = 11;
            REG_FILE[rs1] = 0;
            REG_FILE[rs2] = 0;
            for (int row = ii; row < MIN(ii + B, M); row++) /*Concut all the elements of the block*/
            {
                for (int col = jj; col < MIN(jj + B, N); col++)
                {
                    if ((row-ii) < 2)
                    {
                        REG_FILE[rs1] = (REG_FILE[rs1] << 8) ^ dense[row][col];
                    } else {
                        REG_FILE[rs2] = (REG_FILE[rs2] << 8) ^ dense[row][col];
                    }
                    
                }
            }
            printf("reg_file[%d]:%lx reg_file[%d]:%lx\n",block_num++, rs1, REG_FILE[rs1], rs2, REG_FILE[rs2]);
            accelerator_unit(0b00000000101101010001000000001011); //funct7:0 rs2:11 rs1:10 funct3:1 rd:0 opcode:11

            for (int kk = 0; kk < K; kk += B/2) {    // Block columns of Y and rows of Z
                sparse_columns =  kk/2; //because matrix is sparse with 50% sparisty(2:1) so we use half the columns
                /*Here the sparse block is known.
                  1. The software has to extract the sparse block and its metadata to the register file.
                  2. Call accelerator instruction to load the sparse block and metadata into the accelerator.
                  3. Start matrix multiplication.
                */

                rs1 = 12;
                rs2 = 13;
                REG_FILE[rs1] = 0;
                REG_FILE[rs2] = 0;
                for (int sparse_row = ii; sparse_row < MIN(ii + B, M); sparse_row++) /*Concut all the elements of the block*/
                {
                    for (int sparse_col = kk; sparse_col < MIN(kk + B/2, K); sparse_col++)
                    {
                        REG_FILE[rs1] = (REG_FILE[rs1] << 8) ^ sparse[sparse_row][sparse_col];
                        REG_FILE[rs2] = (REG_FILE[rs2] << 8) ^ metadata[sparse_row][sparse_col];
                    }
                }
                printf("reg_file[%d]:%lx reg_file[%d]:%lx\n", rs1, REG_FILE[rs1], rs2, REG_FILE[rs2]);

                /* This code is implemented inside the accelerator instead of software
                for (int i = ii; i < MIN(ii + B, M); i++) {  // Rows in the current block
                    for (int j = jj; j < MIN(jj + B, N); j++) {  // Columns in the current block
                        double r = 0.0;
                        for (int k = kk; k < MIN(kk + B, K); k++) {  // Overlapping blocks
                            r += sparse[i][k] * dense[k][j];  // Dot product for the block
                        }
                        final[i][j] += r; // Accumulate the result
                        print_matrix(final,M, N);
                    }
                }*/
            }
            /*When the block of the dense matrix changes to a new block column-wise we need to save the accumulators since the final matrix block is finished and will not change,
              also nullify the accumulators inside the acclerator to 
              1. For every accumulator call instr that saves two accumulators(32b + 32b = 64b) column-wise to a register
              2. Call nullifying instr for accelerator accumulators
            */
        }
        /*When the block of the sparse matrix changes row-wise we also need to nullify the changes and save the previous accumulator values
            1. For every accumulator call instr that saves two accumulators(32b + 32b = 64b) column-wise to a register
            2. Call nullifying instr for accelerator accumulators
        */
    }
    
    return 0;
}