#ifndef DATASET_H
#define DATASET_H

#define SPARSE_ROWS 4
#define SPARSE_COLS 8
#define METADATA_COLS 4
#define DENSE_ROWS 8
#define DENSE_COLS 4

int8_t sparse_matrix[4][8] = {
    {62, 47, 0, 0, 0, -74, -89, 0},
    {-18, 85, 0, 0, 57, 85, 0, 0},
    {37, 0, -32, 0, -57, 0, 0, 39},
    {0, 88, 126, 0, 81, -115, 0, 0}
};

int8_t metadata_matrix[4][4] = {
    {0, 1, 1, 2},
    {0, 1, 0, 1},
    {0, 2, 0, 3},
    {1, 2, 0, 1}
};

int8_t dense_matrix[8][4] = {
    {60, -84, -5, 96},
    {-99, 9, -48, 51},
    {-89, -56, 48, -29},
    {-99, -64, 37, -54},
    {123, -24, 28, 106},
    {-29, -64, 10, -107},
    {88, -34, 4, -17},
    {120, 21, 82, 33}
};

#endif // DATASET_H
