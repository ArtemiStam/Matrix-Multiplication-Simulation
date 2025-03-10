#ifndef DATASET_H
#define DATASET_H

#define SPARSE_ROWS 4
#define SPARSE_COLS 4
#define METADATA_COLS 2
#define DENSE_ROWS 4
#define DENSE_COLS 8

int8_t sparse_matrix[4][4] = {
    {36, 0, 0, 58},
    {0, -13, -13, 0},
    {0, -35, 48, 0},
    {0, -117, -76, 0}
};

int8_t metadata_matrix[4][2] = {
    {0, 3},
    {1, 2},
    {1, 2},
    {1, 2}
};

int8_t dense_matrix[4][8] = {
    {15, -28, -24, -88, 4, -102, -39, -85},
    {-94, 40, -98, 40, 26, 73, 118, 54},
    {44, 47, 93, 89, -115, 13, 7, -118},
    {-5, 109, 116, 40, -96, -128, -10, 42}
};

#endif // DATASET_H
