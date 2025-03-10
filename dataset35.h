#ifndef DATASET_H
#define DATASET_H

#define SPARSE_ROWS 8
#define SPARSE_COLS 4
#define METADATA_COLS 2
#define DENSE_ROWS 4
#define DENSE_COLS 8

int8_t sparse_matrix[8][4] = {
    {0, 0, -44, -68},
    {-45, 0, 107, 0},
    {0, 120, 0, 3},
    {-68, 0, 0, 100},
    {0, 0, 63, 28},
    {59, -45, 0, 0},
    {0, 0, -75, 95},
    {107, 25, 0, 0}
};

int8_t metadata_matrix[8][2] = {
    {2, 3},
    {0, 2},
    {1, 3},
    {0, 3},
    {2, 3},
    {0, 1},
    {2, 3},
    {0, 1}
};

int8_t dense_matrix[4][8] = {
    {-99, -73, -23, -34, -9, 24, -25, -29},
    {94, -27, -94, -65, 75, -104, -34, 117},
    {-2, 35, 114, 16, 125, 63, 97, 89},
    {92, 15, -95, -34, 88, 9, 56, -77}
};

#endif // DATASET_H
