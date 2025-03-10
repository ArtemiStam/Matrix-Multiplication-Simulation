#ifndef DATASET_H
#define DATASET_H

#define SPARSE_ROWS 4
#define SPARSE_COLS 4
#define METADATA_COLS 2
#define DENSE_ROWS 4
#define DENSE_COLS 32

int8_t sparse_matrix[4][4] = {
    {-121, -32, 0, 0},
    {5, 0, 97, 0},
    {0, -37, -15, 0},
    {-66, 0, -77, 0}
};

int8_t metadata_matrix[4][2] = {
    {0, 1},
    {0, 2},
    {1, 2},
    {0, 2}
};

int8_t dense_matrix[4][32] = {
    {-48, -95, 24, 17, -101, -76, 59, 89, 25, -114, -2, -68, 41, -119, 52, 113, 95, -22, 112, 73, -111, 75, 31, 46, -77, -32, 105, 61, 69, 64, 25, 14},
    {-8, 46, -13, 80, 52, -33, 104, -81, 91, 89, 66, -109, -26, 66, 74, -6, -78, -92, 102, 114, 65, 126, 7, -84, -18, 58, 44, 92, 46, -41, -63, -59},
    {14, -115, -114, -11, 96, -124, 99, -43, 81, -117, -59, -5, 32, 87, 116, 30, 12, -20, 78, -97, 121, 33, 28, -113, 114, -34, -111, 117, -9, -11, -18, 10},
    {-20, 45, 75, -60, 65, 81, -80, 72, 102, -112, -107, -5, -92, 124, -30, -123, 9, 55, -5, 115, 57, -66, -4, 7, -24, 53, -49, 125, -105, -10, -59, -88}
};

#endif // DATASET_H
