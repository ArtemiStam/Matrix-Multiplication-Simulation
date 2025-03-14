#ifndef DATASET_H
#define DATASET_H

#define SPARSE_ROWS 32
#define SPARSE_COLS 16
#define METADATA_COLS 8
#define DENSE_ROWS 16
#define DENSE_COLS 32

int8_t sparse_matrix[32][16] = {
    {32, 0, 0, -121, 24, 0, -51, 0, 0, 48, 0, -34, 92, 0, -34, 0},
    {0, 0, 85, 76, 46, 13, 0, 0, 101, 95, 0, 0, 0, 0, -76, 71},
    {-46, 0, 0, -19, 0, -89, 0, 111, 0, -89, -5, 0, 91, 0, 53, 0},
    {-122, 0, 122, 0, 121, 0, 94, 0, 0, 0, 8, 111, 83, 0, 83, 0},
    {-123, 0, -105, 0, 0, 0, 8, -121, -99, 86, 0, 0, 0, 6, 0, -67},
    {0, -29, -102, 0, 0, 51, 51, 0, -81, 108, 0, 0, -17, 0, 0, -70},
    {20, 0, -98, 0, -128, 0, 0, 23, -90, 31, 0, 0, -45, 0, 0, 4},
    {0, -7, 0, 65, 0, 0, 7, 9, 0, 0, 74, -27, 99, 0, 0, 56},
    {0, -46, 0, -25, 0, 15, 0, -28, 0, -74, 27, 0, 0, 0, -24, 30},
    {0, 104, 0, -17, -35, 0, 0, 46, -92, 120, 0, 0, -44, 0, -83, 0},
    {0, 82, 0, -26, -36, 0, 0, 41, 100, 0, 0, -25, 39, -57, 0, 0},
    {17, 0, 107, 0, 0, -109, -1, 0, 0, 97, 0, -91, -73, 0, 0, -19},
    {0, 22, 37, 0, 0, 3, 14, 0, 79, 105, 0, 0, 0, -94, 0, 28},
    {-98, 0, 56, 0, 59, 0, 85, 0, -82, 0, 21, 0, -59, 0, 58, 0},
    {0, 0, -90, -47, 50, 0, 114, 0, 0, -44, 0, 46, 0, -91, 121, 0},
    {0, 110, -59, 0, 0, 56, -15, 0, -46, 0, 0, 44, 11, -22, 0, 0},
    {119, 0, 24, 0, -64, 0, 31, 0, -127, 0, 0, 2, 0, -14, -71, 0},
    {-95, -80, 0, 0, 0, 0, 49, 25, 0, 51, -88, 0, 0, 0, -121, 31},
    {0, -8, 0, -64, 77, 23, 0, 0, 0, -2, 90, 0, 0, 0, -112, -63},
    {102, 0, -37, 0, -71, -85, 0, 0, 0, -98, 0, -77, 56, 0, 0, 34},
    {117, -102, 0, 0, 0, 20, -113, 0, 16, 0, 0, -42, 0, 0, 119, -79},
    {0, 0, -97, -77, 0, 0, 34, 22, 0, 0, 13, 96, -125, 0, 22, 0},
    {0, 53, 0, 21, 12, 0, 0, 86, -88, 0, 0, 62, -39, 0, 0, -6},
    {0, -72, 50, 0, 0, 51, -61, 0, 99, 0, 12, 0, 0, -20, -128, 0},
    {23, -56, 0, 0, 34, 61, 0, 0, 0, -74, -91, 0, -46, 0, 0, 73},
    {0, -52, 0, -55, 65, 0, 0, 102, -100, 0, 0, 109, 0, 0, -127, 102},
    {-48, 0, 0, 64, -10, 0, 0, 8, 0, 0, 55, 83, 0, -24, -69, 0},
    {0, -128, -67, 0, 0, 0, -103, -91, 34, 0, 0, -21, 0, 31, 0, -103},
    {0, 0, 15, -34, -114, 0, 29, 0, -87, 0, 0, -6, 0, 72, 0, -58},
    {70, 112, 0, 0, 113, 0, 0, -93, 0, -53, 0, -38, 0, -82, 0, 5},
    {-53, 6, 0, 0, 0, 0, -91, 19, -65, 0, 0, 38, 0, 66, 0, -31},
    {81, 0, 0, -100, 123, 0, 0, -80, 0, 0, -117, -14, 19, 0, 9, 0}
};

int8_t metadata_matrix[32][8] = {
    {0, 3, 0, 2, 1, 3, 0, 2},
    {2, 3, 0, 1, 0, 1, 2, 3},
    {0, 3, 1, 3, 1, 2, 0, 2},
    {0, 2, 0, 2, 2, 3, 0, 2},
    {0, 2, 2, 3, 0, 1, 1, 3},
    {1, 2, 1, 2, 0, 1, 0, 3},
    {0, 2, 0, 3, 0, 1, 0, 3},
    {1, 3, 2, 3, 2, 3, 0, 3},
    {1, 3, 1, 3, 1, 2, 2, 3},
    {1, 3, 0, 3, 0, 1, 0, 2},
    {1, 3, 0, 3, 0, 3, 0, 1},
    {0, 2, 1, 2, 1, 3, 0, 3},
    {1, 2, 1, 2, 0, 1, 1, 3},
    {0, 2, 0, 2, 0, 2, 0, 2},
    {2, 3, 0, 2, 1, 3, 1, 2},
    {1, 2, 1, 2, 0, 3, 0, 1},
    {0, 2, 0, 2, 0, 3, 1, 2},
    {0, 1, 2, 3, 1, 2, 2, 3},
    {1, 3, 0, 1, 1, 2, 2, 3},
    {0, 2, 0, 1, 1, 3, 0, 3},
    {0, 1, 1, 2, 0, 3, 2, 3},
    {2, 3, 2, 3, 2, 3, 0, 2},
    {1, 3, 0, 3, 0, 3, 0, 3},
    {1, 2, 1, 2, 0, 2, 1, 2},
    {0, 1, 0, 1, 1, 2, 0, 3},
    {1, 3, 0, 3, 0, 3, 2, 3},
    {0, 3, 0, 3, 2, 3, 1, 2},
    {1, 2, 2, 3, 0, 3, 1, 3},
    {2, 3, 0, 2, 0, 3, 1, 3},
    {0, 1, 0, 3, 1, 3, 1, 3},
    {0, 1, 2, 3, 0, 3, 1, 3},
    {0, 3, 0, 3, 2, 3, 0, 2}
};

int8_t dense_matrix[16][32] = {
    {8, 46, -22, -59, -58, 68, -6, -96, 60, 78, -13, -95, 38, 56, -75, 74, -106, 65, 89, -74, 64, -87, 109, 112, -45, 72, 17, 116, 117, -36, -61, -101},
    {65, 70, -106, 1, 22, -20, -44, -36, -111, 95, 56, -40, 37, 80, -99, -49, -22, -124, 41, 57, 89, -122, 101, 82, 97, 85, -111, -53, 81, 102, -93, -73},
    {44, -57, -38, 96, 14, -105, 68, -3, 42, -67, 78, -68, 111, 47, 44, -49, 106, 87, -77, 57, -119, 120, -95, 37, 124, 96, 58, 121, 86, 28, 79, 1},
    {38, -5, 52, -69, 17, 39, -102, -117, -6, -2, -54, -67, -23, -48, 52, 42, -121, 61, 95, -23, 55, -53, -17, 83, 34, 9, 92, -109, 126, -83, -95, 64},
    {-12, -59, -21, -7, 36, -53, 66, 94, 14, 108, 8, -64, 100, -34, -114, 29, 62, -6, -117, 21, -55, 82, -12, -112, -9, 100, -104, 124, 5, -8, -83, -121},
    {-20, -45, 125, -90, -65, 88, -82, 76, 102, -105, -100, 23, 5, 64, -34, 0, -72, 14, -65, -25, -24, -52, 1, -80, 73, 119, -89, -22, -85, 93, 23, -91},
    {92, 48, 52, -38, 52, -117, -73, 59, -14, -92, 55, 102, -29, -80, 53, -84, -43, 47, 101, 91, 101, -33, 46, -88, 105, -97, 74, 55, 59, 71, 114, -113},
    {-67, 117, 37, -26, -101, -7, -19, -21, 70, 7, 66, -102, -33, -25, -31, 86, -28, 117, 97, 109, 37, -5, 60, 83, -47, 22, -108, 46, 103, -44, 54, -55},
    {-19, 110, -75, -28, 105, 75, 4, -106, -84, 124, -58, -19, 98, -127, 34, -24, -8, -64, -64, -18, 98, -97, -19, -101, -15, -22, -21, 8, 18, 89, -29, 97},
    {115, 111, 26, 96, 105, 56, -103, -114, -102, -7, 48, -64, 54, 18, -106, -75, 12, 46, -113, 52, 5, -6, -44, -66, -84, 33, 68, -32, -18, 1, -80, 126},
    {-72, 37, -44, 118, 20, -18, 25, -83, -68, 85, 32, 50, -22, 54, 73, -15, -122, 121, 37, 119, -54, 95, 118, 35, -61, 21, 0, -122, -126, -40, 65, -22},
    {-92, 120, -43, 87, -126, -90, -24, -91, -64, 76, 123, 50, -71, -69, -23, 12, -33, -117, -74, 87, -83, -32, -41, -43, -30, -3, 120, 70, 62, 38, -57, 29},
    {-62, 29, -11, -44, -111, -96, -42, -107, 4, 96, -45, -91, -17, -27, 110, -79, 60, 16, 12, 31, 95, -115, -67, -112, -104, -12, 24, -46, 33, 91, -16, 34},
    {-31, 73, -117, -74, -52, 66, 52, -48, -17, 32, 34, 125, 122, 2, -89, -26, -32, 112, 19, 39, 74, 18, 123, 62, -119, -75, 9, 63, -116, -110, 123, 69},
    {114, 79, 35, -1, -75, -53, 114, 0, -72, 85, -117, -82, -9, 72, -84, -108, 19, 114, -93, -10, 23, 108, -119, 78, -8, 101, 122, -43, 19, 117, 93, 74},
    {-34, -33, -7, 68, -59, -33, 43, -115, -95, 4, 74, -71, -48, 106, -79, -36, -37, -34, 17, -40, -13, 71, -104, 110, 61, -33, 47, -116, 61, 20, -24, 66}
};

#endif // DATASET_H
