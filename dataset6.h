#ifndef DATASET_H
#define DATASET_H

#define SPARSE_ROWS 4
#define SPARSE_COLS 4
#define METADATA_COLS 2
#define DENSE_ROWS 4
#define DENSE_COLS 16

int8_t sparse_matrix[4][4] = {
    {0, 0, 93, -61},
    {0, -74, -59, 0},
    {0, 0, 18, 121},
    {0, 0, 47, -73}
};

int8_t metadata_matrix[4][2] = {
    {2, 3},
    {1, 2},
    {2, 3},
    {2, 3}
};

int8_t dense_matrix[4][16] = {
    {-119, 93, -32, 11, 65, 74, 16, 79, -12, -70, 99, -54, 75, 114, -6, 58},
    {-43, 86, -126, 51, -9, 50, -39, -7, 101, 49, 32, 4, 60, -28, 96, -7},
    {-23, -88, -6, -97, 27, 101, -94, -70, -29, -5, -12, -31, -45, -75, 115, -125},
    {-104, 53, -36, 23, -3, 5, 0, 47, 22, -68, 47, 2, 116, -13, 4, 83}
};

#endif // DATASET_H
