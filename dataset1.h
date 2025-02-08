#ifndef DATASET_H
#define DATASET_H

#define SPARSE_ROWS 4
#define SPARSE_COLS 4
#define METADATA_COLS 2
#define DENSE_ROWS 4
#define DENSE_COLS 4

int8_t sparse_matrix[4][4] = {
    {-7, 0, 0, 0},
    {-62, 111, 0, 0},
    {-86, -51, 0, 0},
    {0, -94, -125, 0}
};

int8_t metadata_matrix[4][2] = {
    {0, 1},
    {0, 1},
    {0, 1},
    {1, 2}
};

int8_t dense_matrix[4][4] = {
    {35, 94, 109, 25},
    {96, 83, 58, -100},
    {-14, 106, 79, -30},
    {34, -68, 79, -124}
};

#endif // DATASET_H
