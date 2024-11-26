#include <stdio.h>
#include <stdint.h>

#define MIN(X, Y) (((X) < (Y)) ? (X) : (Y))

void print_matrix(int matrix[5][6], int rows, int cols) {
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

    int sparse[16][8]={{1,4,5},{4,8,5},{5,7,9},{4,6,9},{6,5,8}};  //Pressumed matrix is pre-compressed
    int dense[16][16]={{1,4,5,6,2,8},{7,9,6,8,5,8},{3,4,5,6,8,7}};
    int metadata[16][8] = {{}};
    long int final[16][16] = {{0},{0},{0},{0},{0}}, REG_FILE[32];
    int dense_colums;
    int B=4, M=16, K=16, N=16; //here K represents the number of columns sparse matrix would have if it wasn't pre-compressed
    
    /*Call nullifying instr to initialize the accelerator accumulators*/

    // Perform blocked multiplication row by row for blocks in row-major order.
    for (int ii = 0; ii < M; ii += B) {            // Block rows of Y and X
        for (int jj = 0; jj < N; jj += B) {        // Block columns of Z and X
            /*Here the specific block we want to process is known. 
              1. Software has to place the dense block into 2 registers in the register file so that the accelerator can read it.
              2. Call the accelerator instr to load the dense block into the accelerator.
            */

            for (int kk = 0; kk < K; kk += B) {    // Block columns of Y and rows of Z
                sparse_columns =  kk/2; //because matrix is sparse with 50% sparisty(2:1) so we use half the columns
                /*Here the sparse block is known.
                  1. The software has to extract the sparse block and its metadata to the register file.
                  2. Call accelerator instruction to load the sparse block and metadata into the accelerator.
                  3. Start matrix multiplication.
                */

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