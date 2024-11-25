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
    int8_t sparse[4][2], meta_data[4][2], dense[4][4];
    int32_t final[4][4];*/

    int sparse[5][3]={{1,4,5},{4,8,5},{5,7,9},{4,6,9},{6,5,8}}, 
    dense[3][6]={{1,4,5,6,2,8},{7,9,6,8,5,8},{3,4,5,6,8,7}} , final[5][6] = {{0},{0},{0},{0},{0}};
    int B=2, M=5, K=3, N=6; 
    

    // Perform blocked multiplication row by row for blocks in row-major order.
    for (int ii = 0; ii < M; ii += B) {            // Block rows of Y and X
        for (int jj = 0; jj < N; jj += B) {        // Block columns of Z and X
            for (int kk = 0; kk < K; kk += B) {    // Block columns of Y and rows of Z
                for (int i = ii; i < MIN(ii + B, M); i++) {  // Rows in the current block
                    for (int j = jj; j < MIN(jj + B, N); j++) {  // Columns in the current block
                        double r = 0.0;
                        for (int k = kk; k < MIN(kk + B, K); k++) {  // Overlapping blocks
                            r += sparse[i][k] * dense[k][j];  // Dot product for the block
                        }
                        final[i][j] += r; // Accumulate the result
                        print_matrix(final,M, N);
                    }
                }
            }
        }
    }
    
    
    return 0;
}