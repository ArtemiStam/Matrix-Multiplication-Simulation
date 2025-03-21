#ifndef DATASET_H
#define DATASET_H

#define SPARSE_ROWS 4
#define SPARSE_COLS 16
#define METADATA_COLS 8
#define DENSE_ROWS 16
#define DENSE_COLS 4

int8_t sparse_matrix[4][16] = {
    {60, 0, 6, 0, 0, -4, 0, -63, 0, 0, 53, -5, 0, 0, 62, 46},
    {-22, 4, 0, 0, 48, 0, 0, 115, -18, 0, 0, 50, 0, 42, 69, 0},
    {95, 0, 19, 0, 0, 0, 46, 57, 0, 0, -78, 95, 0, -121, 95, 0},
    {-16, 0, -37, 0, -122, 0, -128, 0, 0, -93, 0, -48, -18, 0, 105, 0}
};

int8_t metadata_matrix[4][8] = {
    {0, 2, 1, 3, 2, 3, 2, 3},
    {0, 1, 0, 3, 0, 3, 1, 2},
    {0, 2, 2, 3, 2, 3, 1, 2},
    {0, 2, 0, 2, 1, 3, 0, 2}
};

int8_t dense_matrix[16][4] = {
    {-106, -61, 103, -58},
    {-19, 37, -102, -107},
    {104, 64, -114, -8},
    {-106, 113, 62, -82},
    {-114, 25, -21, 1},
    {124, 4, 70, -54},
    {-95, 89, -91, -11},
    {-47, -40, 22, 69},
    {-44, 101, 45, 56},
    {-124, 44, 113, -68},
    {97, 40, 57, 88},
    {63, -25, 98, 50},
    {-61, 125, 61, 104},
    {-32, -45, -14, -76},
    {31, 119, -4, 14},
    {39, -26, 101, -35}
};

#endif // DATASET_H
