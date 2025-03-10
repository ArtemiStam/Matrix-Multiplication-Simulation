#ifndef DATASET_H
#define DATASET_H

#define SPARSE_ROWS 4
#define SPARSE_COLS 4
#define METADATA_COLS 2
#define DENSE_ROWS 4
#define DENSE_COLS 4

int8_t sparse_matrix[4][4] = {
    {57, 0, 0, -49},
    {0, 7, 0, 74},
    {125, 0, 0, 37},
    {-68, 0, 0, 53}
};

int8_t metadata_matrix[4][2] = {
    {0, 3},
    {1, 3},
    {0, 3},
    {0, 3}
};

int8_t dense_matrix[4][4] = {
    {-64, -91, -54, 63},
    {-43, -19, -29, -69},
    {-66, -16, -70, 53},
    {67, 97, 119, -14}
};

#endif // DATASET_H
