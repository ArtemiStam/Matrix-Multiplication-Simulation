#ifndef DATASET_H
#define DATASET_H

#define SPARSE_ROWS 4
#define SPARSE_COLS 4
#define METADATA_COLS 2
#define DENSE_ROWS 4
#define DENSE_COLS 64

int8_t sparse_matrix[4][4] = {
    {-35, 0, -70, 0},
    {4, 0, 0, -36},
    {0, 53, 17, 0},
    {0, -100, 0, 28}
};

int8_t metadata_matrix[4][2] = {
    {0, 2},
    {0, 3},
    {1, 2},
    {1, 3}
};

int8_t dense_matrix[4][64] = {
    {-72, -80, -42, -36, -123, 78, 61, -21, 39, 75, 122, -54, 40, 32, 66, -14, -61, -45, -101, 126, -33, 22, 62, 93, 48, -2, 122, 66, -57, 20, -79, -76, 1, -36, -38, 89, 2, 109, -18, -21, 51, 29, -83, 88, -98, 114, 71, 26, 89, -71, 65, 110, 102, -13, -59, -38, -26, 38, -15, -1, 95, 20, 80, 58},
    {62, 88, 49, 32, -111, 117, -91, -87, 104, 40, -120, 13, -58, -13, 98, 45, -83, 44, 4, -95, 21, -112, -56, -32, -87, 60, -59, 72, -84, -47, 114, 99, -121, 100, 103, 107, 5, 103, -103, -16, 12, -98, -62, 10, 13, -124, 87, 53, 22, -120, 113, 58, -51, 77, -6, 78, -80, -46, 117, 26, 29, 67, 125, 64},
    {49, 99, -19, -102, -86, -99, 112, -66, 69, -38, -104, -100, 100, 40, 50, -26, -94, 29, -77, 9, 120, -20, -111, -32, 120, -56, 117, -103, -121, 22, 124, -112, -118, 41, -126, 14, 49, -23, -60, -29, -63, -85, 48, 22, 91, 109, -50, 60, 28, 20, 62, 66, 98, 123, 67, 123, -93, -66, -65, -30, -73, 104, -30, -76},
    {24, 43, 15, 112, 33, -111, 38, -57, 45, -80, -45, 1, -59, 66, -19, 87, 103, 5, 40, -49, 5, 58, -47, -42, -4, 79, -63, -97, -49, 54, -115, -13, 60, 22, 5, 61, 92, -7, -11, -89, 77, 79, -39, -10, 82, 39, 72, -48, -81, -19, -54, -117, 102, 77, -18, -122, 87, -108, -14, -78, 93, 58, -55, -68}
};

#endif // DATASET_H
