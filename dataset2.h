#ifndef DATASET_H
#define DATASET_H

#define SPARSE_ROWS 8
#define SPARSE_COLS 4
#define METADATA_COLS 2
#define DENSE_ROWS 4
#define DENSE_COLS 4

int8_t sparse_matrix[8][4] = {
    {0, 93, 112, 0},
    {0, 16, -1, 0},
    {-67, 116, 0, 0},
    {0, 122, 0, -89},
    {-52, 0, 0, 71},
    {-23, 0, -65, 0},
    {40, 0, 0, -45},
    {41, 0, 0, 71}
};

int8_t metadata_matrix[8][2] = {
    {1, 2},
    {1, 2},
    {0, 1},
    {1, 3},
    {0, 3},
    {0, 2},
    {0, 3},
    {0, 3}
};

int8_t dense_matrix[4][4] = {
    {-43, 40, -85, 66},
    {88, -48, -64, -24},
    {-108, -125, 13, 4},
    {-114, -42, 44, -74}
};

#endif // DATASET_H
