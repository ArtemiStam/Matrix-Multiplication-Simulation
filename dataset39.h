#ifndef DATASET_H
#define DATASET_H

#define SPARSE_ROWS 8
#define SPARSE_COLS 64
#define METADATA_COLS 32
#define DENSE_ROWS 64
#define DENSE_COLS 8

int8_t sparse_matrix[8][64] = {
    {0, 2, 0, -11, -34, 0, 0, 22, 0, 0, 62, -3, 0, -125, 0, -113, 0, 14, 0, -110, 0, 117, 0, 3, -45, 0, 0, 0, -48, 0, -78, 0, 0, 113, 0, 46, 0, 122, -65, 0, -83, 0, 69, 0, -90, 0, 0, 56, 127, 0, 78, 0, -3, 0, 0, 86, 0, 0, 91, -19, 0, 0, 23, 127},
    {0, 0, 79, 12, 109, 0, 0, -84, -97, 0, 114, 0, -21, 7, 0, 0, 0, 103, -97, 0, 83, 89, 0, 0, 0, 0, -127, 58, 83, 41, 0, 0, 114, 0, 0, 67, -26, 0, 0, -35, 0, 0, 115, -119, 0, 78, 95, 0, -32, 0, 0, 19, -113, 0, 8, 0, -45, 0, -53, 0, 0, 69, 0, -40},
    {0, 87, -31, 0, 0, 0, -97, 87, 0, 58, 0, 60, -89, 0, 0, 107, 96, -15, 0, 0, -47, 0, 0, 43, -3, -54, 0, 0, 0, 39, 0, -55, -7, 0, -14, 0, -4, 0, -118, 0, 0, 0, 95, 66, 98, 0, -85, 0, -3, 0, 0, 98, -21, 0, 0, -114, 0, 0, -55, -54, 13, 0, 0, 33},
    {2, 42, 0, 0, 22, -113, 0, 0, -17, 0, 0, 32, 119, 0, 74, 0, 0, 113, -112, 0, -31, -8, 0, 0, 8, -89, 0, 0, 0, -55, 78, 0, 126, 0, 0, 70, -79, 0, 114, 0, -105, 0, 0, 72, 0, 0, -56, 66, 0, 0, -96, 101, 123, 0, 71, 0, -61, 68, 0, 0, 0, 38, 31, 0},
    {0, 0, 113, 71, 0, -65, -45, 0, 85, 0, 0, 98, 0, -46, 3, 0, -43, 0, 0, 101, 0, 78, 0, 73, 0, 82, 0, 91, -117, 0, 0, -32, 0, 0, 83, 20, -11, 0, -44, 0, 106, 0, 25, 0, 0, 0, -30, 122, 0, 98, 63, 0, 21, 0, 0, 88, 0, -20, 0, 90, 0, 78, 0, -8},
    {50, 0, 0, 118, 0, 0, -13, -2, 0, 0, 14, 61, 0, 63, 0, -78, 0, 76, 0, 89, 76, -41, 0, 0, 0, -8, 0, 70, 0, 27, -15, 0, 0, 5, 0, -114, 29, 74, 0, 0, 92, 0, 0, 112, 0, 0, -111, -38, 30, -125, 0, 0, -113, 0, 0, -64, 0, 43, 19, 0, 0, 19, 0, 34},
    {0, -33, 0, -118, 0, -5, -51, 0, 0, 16, 103, 0, 0, -60, 0, -10, 121, 0, 0, 46, 0, -10, 0, 117, 0, -14, 46, 0, 0, -29, -51, 0, 0, 37, 0, -87, 0, -119, -86, 0, 21, 12, 0, 0, 0, -98, 12, 0, 0, 14, 0, -118, -33, 0, 41, 0, -115, 0, 0, 28, 0, 53, 0, -20},
    {-75, -104, 0, 0, 85, 0, 0, 62, 0, 0, -70, 66, -2, 0, 0, -34, 92, -93, 0, 0, 0, 0, 12, 31, 0, -124, -105, 0, -59, 0, 0, 21, 108, -2, 0, 0, 0, -54, 0, -91, 0, 26, 97, 0, 0, 0, 114, 85, 0, 0, -82, -27, -2, 0, -14, 0, 0, 0, -118, -44, -82, 89, 0, 0}
};

int8_t metadata_matrix[8][32] = {
    {1, 3, 0, 3, 2, 3, 1, 3, 1, 3, 1, 3, 0, 2, 0, 2, 1, 3, 1, 2, 0, 2, 0, 3, 0, 2, 0, 3, 2, 3, 2, 3},
    {2, 3, 0, 3, 0, 2, 0, 1, 1, 2, 0, 1, 2, 3, 0, 1, 0, 3, 0, 3, 2, 3, 1, 2, 0, 3, 0, 2, 0, 2, 1, 3},
    {1, 2, 2, 3, 1, 3, 0, 3, 0, 1, 0, 3, 0, 1, 1, 3, 0, 2, 0, 2, 2, 3, 0, 2, 0, 3, 0, 3, 2, 3, 0, 3},
    {0, 1, 0, 1, 0, 3, 0, 2, 1, 2, 0, 1, 0, 1, 1, 2, 0, 3, 0, 2, 0, 3, 2, 3, 2, 3, 0, 2, 0, 1, 1, 2},
    {2, 3, 1, 2, 0, 3, 1, 2, 0, 3, 1, 3, 1, 3, 0, 3, 2, 3, 0, 2, 0, 2, 2, 3, 1, 2, 0, 3, 1, 3, 1, 3},
    {0, 3, 2, 3, 2, 3, 1, 3, 1, 3, 0, 1, 1, 3, 1, 2, 1, 3, 0, 1, 0, 3, 2, 3, 0, 1, 0, 3, 1, 2, 1, 3},
    {1, 3, 1, 2, 1, 2, 1, 3, 0, 3, 1, 3, 1, 2, 1, 2, 1, 3, 1, 2, 0, 1, 1, 2, 1, 3, 0, 2, 0, 3, 1, 3},
    {0, 1, 0, 3, 2, 3, 0, 3, 0, 1, 2, 3, 1, 2, 0, 3, 0, 1, 1, 3, 1, 2, 2, 3, 2, 3, 0, 2, 2, 3, 0, 1}
};

int8_t dense_matrix[64][8] = {
    {-50, 76, 52, 47, -50, -3, -125, 49},
    {-2, 46, 18, 34, -83, -67, -55, 93},
    {124, -60, 47, -49, -45, 54, 21, -45},
    {-99, 33, -32, -37, -88, 21, -20, -56},
    {-7, 109, -58, 74, 84, 63, 47, 126},
    {25, -117, 125, 36, 92, 15, 104, 40},
    {54, -9, 80, 52, -14, 60, -125, -68},
    {-110, -108, -76, 115, 0, 19, 98, 20},
    {-48, 86, 88, 94, 28, -8, -18, -81},
    {-106, 108, -62, 85, 19, -5, 122, 81},
    {-41, 5, 38, 62, -44, -64, -79, 111},
    {-20, 125, 119, 27, -103, -35, 39, 102},
    {-118, 106, -54, -21, 45, -15, 63, 115},
    {113, 1, -117, 48, -124, 82, 28, 8},
    {28, -113, 71, -116, 81, 65, 76, 23},
    {44, -53, 6, 36, -9, 72, -102, -51},
    {20, -81, -107, -128, 19, 30, -49, 85},
    {114, -59, 48, 7, -2, 91, 38, -128},
    {21, 117, -97, 80, 91, -82, 34, 118},
    {116, -94, 105, -28, -90, 83, 82, 20},
    {63, 68, -12, -117, 60, -114, -124, 26},
    {26, 78, -120, 31, -84, -4, -28, -112},
    {88, 110, 35, 105, 106, -122, 68, 39},
    {2, 59, -53, -69, 91, -47, 99, 6},
    {91, -49, 88, -77, 25, 116, -55, 80},
    {-81, 92, 0, 116, 62, -40, 94, 22},
    {-79, -33, -104, 83, 90, 57, 93, -13},
    {92, 124, -109, -110, -60, 13, -87, 45},
    {19, -80, -5, -42, -118, 41, -57, 113},
    {125, 22, -63, 72, 86, -51, 95, 63},
    {45, -37, -105, -114, 108, -98, 78, -92},
    {112, -91, -24, 35, -65, -128, -100, -79},
    {31, 0, -56, -60, -67, -97, -90, 37},
    {46, -57, 110, -26, 109, -115, 46, -7},
    {93, -40, -7, 8, 68, 88, -62, -8},
    {110, -75, -40, 103, -12, -86, -108, 50},
    {-113, 30, 15, 113, 124, -67, 91, -97},
    {1, 21, 6, 27, 20, 78, 56, 43},
    {-97, -5, 125, 83, 101, -43, -39, 57},
    {31, 4, -118, 2, -33, -31, -15, -5},
    {-3, -96, -123, -82, -114, 100, 120, 73},
    {-29, 124, 52, 12, 99, -86, 66, 7},
    {22, 64, -72, -118, -85, -104, -97, 14},
    {-42, 56, -100, -97, 123, -7, -52, 112},
    {78, -121, 67, 69, 10, 108, 75, -124},
    {-109, 59, -73, 57, 79, -10, -71, -52},
    {113, -118, 27, -120, -5, -47, 85, -58},
    {-77, 26, 117, 91, 101, 16, 75, -18},
    {-51, 37, 82, -96, 106, -106, 80, -12},
    {-27, -93, 71, -2, 81, 105, 114, -98},
    {-34, -61, 53, 70, 63, -80, 114, -114},
    {-5, -25, -120, 6, 43, -59, 14, -121},
    {38, 12, 17, -51, 52, 109, 85, 47},
    {-120, -101, -18, 65, 120, -93, 90, -113},
    {-94, -71, -30, -63, 106, -34, 1, -117},
    {-94, -38, -21, 80, 108, -100, -80, 17},
    {34, 80, -22, 77, 88, 119, -36, 126},
    {43, 63, 101, -5, -72, -123, 35, 0},
    {16, 56, 97, 96, 54, 80, -57, -100},
    {-124, 56, -61, -54, 54, -45, -102, -85},
    {-85, 62, -36, 125, -28, 120, -8, 118},
    {-49, 115, 72, -21, -29, -69, 62, 101},
    {47, 78, 98, -118, -56, -57, 124, 6},
    {38, 24, -35, 97, -35, -38, 24, 16}
};

#endif // DATASET_H
