#include <stdio.h>
#include <stdint.h>
#include <string.h>
//#include <stdlib.h>

#define MIN(X, Y) (((X) < (Y)) ? (X) : (Y))
#define OPCODE 11     //opcode: 0001011
#define LOAD_DENSE 1  //funct3: 001
#define LOAD_SPARSE 2 //funct3: 010
#define RESET_ACC 0   //funct3: 000
#define STORE_ACC 3   //funct3: 011

int64_t REG_FILE[32]; //Memory elements accessed from both the accelerator and the program
int8_t sparse[4][2], meta_data[4][2], dense[4][4];
int32_t ACC[4][4];

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
                i = 0; //means its is the first 2 indexes of ACC
                if ((funct7 >= 4) & (funct7 <= 6)) {
                    i = 1;
                } else if ((funct7 >= 8) & (funct7 <= 10)) {
                    i = 2;
                } else if ((funct7 >= 12) & (funct7 <= 14)) {
                    i = 3;
                }

                if (funct7 % 4 == 0)
                {
                    wr_back_data = (wr_back_data + ACC[i][0]) << 32;
                    wr_back_data = wr_back_data + ACC[i][1];
                } else {
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

int main(void) {
    int8_t sparse[8][4]={{1,4,5,5},{4,8,5,6},{5,7,9,4},{4,6,9,3},{6,5,8,3},{6,5,8,3},{6,5,8,3},{6,5,8,3}};  //Pressumed matrix is pre-compressed
    int8_t dense[8][8]={{1,4,5,6,2,8,8,3},{7,9,6,8,5,8,7,8},{3,4,5,6,8,7,5,3},{1,4,5,6,2,8,8,3},{7,9,6,8,5,8,7,8},{3,4,5,6,8,7,5,3},{1,4,5,6,2,8,8,3},{7,9,6,8,5,8,7,8}};
    int8_t metadata[8][4] = {{0,2,1,2},{2,3,1,2},{0,3,2,3},{0,2,2,3},{1,3,0,2},{2,3,0,1},{1,2,1,2},{2,3,1,2}};
    int32_t final[8][8] = {{0},{0},{0},{0},{0},{0},{0},{0}}, instr, final_test[8][8] = {{33,60,75,90,84,111,93,45},{41,92,115,138,100,175,157,69},{49,120,129,158,62,200,196,95},{52,103,113,138,59,170,155,81},{106,158,124,160,86,179,162,136},{88,128,118,148,122,167,141,106},{84,118,116,144,140,163,131,96},{50,88,110,132,128,162,134,66}};
    int B=4, M=8, K=8, N=8; //B is the block dimensions, M is the num of sparse matrix rows, K is the num of sparse columns(un-compressed) and dense columns, N is the num of dense columns.
    int rs1, rs2, rd;
    int64_t row1, row2, row3, row4;
    
    //Call nullifying instr to initialize the accelerator accumulators
    accelerator_unit(0b0001011);

    // Perform blocked multiplication row by row for blocks in row-major order.
    for (int ii = 0; ii < M; ii += B) {            // Block rows of Y and X
        for (int jj = 0; jj < N; jj += B) {        // Block columns of Z and X
            //Here the specific block we want to process is known. 
              //1. Software has to place the dense block into 2 registers in the register file so that the accelerator can read it.
              //2. Call the accelerator instr to load the dense block into the accelerator.

            for (int kk = 0; kk < K; kk += B) {    // Block columns of Y and rows of Z

                rs1 = 10;
                rs2 = 11;
                row1 = (dense[kk][jj] << 24) | (dense[kk][jj+1] << 16) | (dense[kk][jj+2] << 8) | dense[kk][jj+3];
                row2 = (dense[kk+1][jj] << 24) | (dense[kk+1][jj+1] << 16) | (dense[kk+1][jj+2] << 8) | dense[kk+1][jj+3];
                row3 = (dense[kk+2][jj] << 24) | (dense[kk+2][jj+1] << 16) | (dense[kk+2][jj+2] << 8) | dense[kk+2][jj+3];
                row4 = (dense[kk+3][jj] << 24) | (dense[kk+3][jj+1] << 16) | (dense[kk+3][jj+2] << 8) | dense[kk+3][jj+3];
                
                REG_FILE[rs1] = ((row1 << 32) ^ row2);
                REG_FILE[rs2] = ((row3 << 32) ^ row4);
                accelerator_unit(0b00000000101101010001000000001011); // funct7:0 rs2:11 rs1:10 funct3:1 rd:0 opcode:11

                rs1 = 12;
                rs2 = 13;
                row1 = (sparse[ii][kk/2] << 8)   | sparse[ii][kk/2+1];
                row2 = (sparse[ii+1][kk/2] << 8) | sparse[ii+1][kk/2+1];
                row3 = (sparse[ii+2][kk/2] << 8) | sparse[ii+2][kk/2+1];
                row4 = (sparse[ii+3][kk/2] << 8) | sparse[ii+3][kk/2+1];
                REG_FILE[rs1] = (((((row1 << 16) ^ row2) << 16) ^ row3) << 16) ^ row4;
                
                row1 = (metadata[ii][kk/2] << 8)   | metadata[ii][kk/2+1];
                row2 = (metadata[ii+1][kk/2] << 8) | metadata[ii+1][kk/2+1];
                row3 = (metadata[ii+2][kk/2] << 8) | metadata[ii+2][kk/2+1];
                row4 = (metadata[ii+3][kk/2] << 8) | metadata[ii+3][kk/2+1];
                REG_FILE[rs2] = (((((row1 << 16) ^ row2) << 16) ^ row3) << 16) ^ row4;
                accelerator_unit(0b00000000110101100010000000001011); // funct7:0 rs2:12 rs1:13 funct3:2 rd:0 opcode:11
                /*rs1 = 10;
                rs2 = 11;
                REG_FILE[rs1] = 0;
                REG_FILE[rs2] = 0;
                for (int row = kk; row < MIN(kk + B, K); row++) //Concut all the elements of the block
                {
                    for (int col = jj; col < MIN(jj + B, N); col++)
                    {
                        if ((row - kk) < 2)
                        {
                            REG_FILE[rs1] = (REG_FILE[rs1] << 8) ^ dense[row][col];
                        }
                        else
                        {
                            REG_FILE[rs2] = (REG_FILE[rs2] << 8) ^ dense[row][col];
                        }
                    }
                }
                //printf("reg_file[%d]:%lx reg_file[%d]:%lx\n", rs1, REG_FILE[rs1], rs2, REG_FILE[rs2]);
                accelerator_unit(0b00000000101101010001000000001011); // funct7:0 rs2:11 rs1:10 funct3:1 rd:0 opcode:11

                //because matrix is sparse with 50% sparisty(2:1) so we use half the columns
                //Here the sparse block is known.
                  //1. The software has to extract the sparse block and its metadata to the register file.
                  //2. Call accelerator instruction to load the sparse block and metadata into the accelerator.
                  //3. Start matrix multiplication.
                

                rs1 = 12;
                rs2 = 13;
                REG_FILE[rs1] = 0;
                REG_FILE[rs2] = 0;
                for (int sparse_row = ii; sparse_row < MIN(ii + B, M); sparse_row++) //Concut all the elements of the block
                {
                    for (int sparse_col = kk/2; sparse_col < MIN(kk/2 + B/2, K/2); sparse_col++)
                    {
                        REG_FILE[rs1] = (REG_FILE[rs1] << 8) ^ sparse[sparse_row][sparse_col];
                        REG_FILE[rs2] = (REG_FILE[rs2] << 8) ^ metadata[sparse_row][sparse_col];
                    }
                }
                //printf("reg_file[%d]:%lx reg_file[%d]:%lx\n", rs1, REG_FILE[rs1], rs2, REG_FILE[rs2]);
                accelerator_unit(0b00000000110101100010000000001011); // funct7:0 rs2:12 rs1:13 funct3:2 rd:0 opcode:11*/
            }
            //When the block of the dense matrix changes to a new block column-wise we need to save the accumulators since the final matrix block is finished and will not change,
              //also nullify the accumulators inside the acclerator to 
              //1. For every accumulator call instr that saves two accumulators(32b + 32b = 64b) column-wise to a register
              //2. Call nullifying instr for accelerator accumulators
            
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
    
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            //printf("%6.2d ", final[i][j]); //the prints here prevent from cva6 simulation
        }
        //printf("\n"); //the prints here prevent from cva6 simulation
    }
    //printf("\n"); //the prints here prevent from cva6 simulation
    
    return 0;
}