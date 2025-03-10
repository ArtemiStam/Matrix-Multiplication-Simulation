#ifndef DATASET_H
#define DATASET_H

#define SPARSE_ROWS 4
#define SPARSE_COLS 256
#define METADATA_COLS 128
#define DENSE_ROWS 256
#define DENSE_COLS 4

int8_t sparse_matrix[4][256] = {
    {0, -18, 0, -124, -16, 0, -39, 0, 0, 117, 82, 0, -117, 0, 0, -95, -99, 61, 0, 0, -100, 0, 0, 111, 13, -97, 0, 0, -115, 0, 0, 102, 8, 0, -124, 0, 47, 0, 0, 9, 0, 0, -28, -75, -86, 124, 0, 0, 39, -28, 0, 0, 0, -70, -56, 0, 0, 0, 18, -122, 0, 0, 10, -15, 0, -104, -37, 0, 9, 0, -120, 0, 0, 0, 122, -127, 0, 36, -123, 0, 0, 0, 70, 83, 0, -23, -22, 0, 1, 73, 0, 0, 115, -107, 0, 0, 56, 0, -59, 0, 0, 89, 17, 0, 0, -45, 0, -74, 113, 121, 0, 0, 0, -16, -24, 0, 0, 51, 0, 95, 0, 74, 0, -83, 27, 0, 0, 121, 0, 86, -34, 0, 0, 45, 0, -51, 0, 36, 0, 96, -82, 0, 0, -62, 0, 35, 0, 82, 54, -51, 0, 0, 0, 114, 8, 0, 0, 0, -85, 32, -66, 0, 3, 0, 60, 0, -126, 0, 35, 0, 0, 87, 0, 0, -115, -95, 0, 45, 0, 27, 0, -23, -56, 0, 0, 0, 48, 83, 0, 40, -99, 0, 19, 0, 66, 0, 97, -119, 0, 0, 7, 0, 0, -47, -33, 0, 0, 0, 105, -90, 0, 0, -120, -100, 0, 0, 98, 17, 0, 0, 6, 0, 83, 0, -24, 125, 0, 0, 0, -119, 77, 0, 0, 0, 118, -102, 0, 0, -101, -32, 0, 52, 80, 0, 111, -24, 0, 0, 0, 102, 28, 0, 17, 71, 0, 0},
    {27, 0, -88, 0, -50, 0, 0, -58, 0, -117, -11, 0, 0, -128, 0, 120, 0, 23, 70, 0, 28, 0, 0, -73, 25, -120, 0, 0, -76, -52, 0, 0, 103, 0, -66, 0, 0, 0, 125, -105, 0, -100, 0, -98, 0, 32, -110, 0, 74, -16, 0, 0, -117, -33, 0, 0, -81, 0, -42, 0, 0, 0, -7, 39, 64, 0, -109, 0, 31, 0, 0, -20, 0, -87, 0, -113, 94, 82, 0, 0, 0, 0, 77, -60, -70, 0, 0, 110, -65, 0, -31, 0, 0, -109, 14, 0, 0, 0, 21, -36, 31, 0, 14, 0, 0, 46, -51, 0, 117, 0, 0, -86, 0, -75, 66, 0, -65, 0, 0, 117, -119, 0, 0, -15, 89, 65, 0, 0, -33, 0, 0, 3, 8, -83, 0, 0, 0, 0, -125, 127, 37, 0, 44, 0, 77, 0, 0, 49, 0, 104, 0, -128, -118, -3, 0, 0, 0, 0, -110, 114, 0, 0, 52, 32, -31, 0, 0, 62, -46, 0, 0, -2, -48, 0, 0, 22, 0, 0, -93, 19, 43, 0, -11, 0, 60, -38, 0, 0, 0, 0, 34, 91, 0, 26, -124, 0, 0, -106, 0, 86, -120, 0, 0, 54, -55, -127, 0, 0, 90, 0, -84, 0, 0, 0, 110, -106, 0, 0, 25, 5, 0, -29, 0, 121, -71, 0, 24, 0, 0, 0, 117, -47, 79, -48, 0, 0, 0, -121, 0, 26, 0, -68, 0, 38, 0, 44, -40, 0, 0, 4, -116, 0, 0, 60, 0, -60},
    {0, -66, -53, 0, 103, 0, 67, 0, 0, 0, -116, -127, -97, -88, 0, 0, 61, 0, 0, -113, 0, 0, -101, 92, 0, 37, -45, 0, 87, 0, 78, 0, 23, 0, 39, 0, 0, 115, -51, 0, 0, 1, -74, 0, 2, 0, 0, 103, 117, 0, 0, 127, -59, 0, 0, 55, 102, 0, 0, -115, 0, 0, -1, 53, -107, 0, 35, 0, 0, -54, 0, -51, -15, 0, -34, 0, 126, -52, 0, 0, 0, 9, 0, 124, 38, 0, -35, 0, 0, 16, 0, -65, 0, 68, 0, 84, 0, -120, 0, 69, 0, 64, 0, -61, 0, 8, -80, 0, -9, 0, 37, 0, 47, 21, 0, 0, 112, 0, -11, 0, -45, 0, 0, 66, 36, 0, -62, 0, 0, 107, -120, 0, 0, -42, 0, -15, 0, 0, 127, 61, -42, 126, 0, 0, 91, 0, 54, 0, 122, 0, 0, -2, -44, 45, 0, 0, 65, 0, 0, -69, 0, 2, -128, 0, -85, 0, 0, -38, 0, -43, -13, 0, -2, 21, 0, 0, 0, -35, 0, 38, 0, -86, 0, 110, 80, 0, 80, 0, 0, 101, -81, 0, 17, 0, 0, -16, 0, 96, 0, -94, 0, 119, -17, 0, 75, 0, 83, 0, 0, 0, -94, -7, 0, 76, -126, 0, 0, -55, 80, 0, 123, 0, 98, 0, -23, -125, 0, 0, 0, -105, 0, -11, 0, -101, 36, 0, 72, 0, 0, -80, 64, -26, 0, 0, 0, 0, 93, 15, 0, 90, 0, 38, 0, -48, 0, 99},
    {10, -111, 0, 0, 117, 0, 117, 0, -94, 0, 0, 58, 0, 13, 0, 124, 66, 0, 7, 0, -115, 0, 47, 0, 79, 0, 0, 58, -124, 0, 0, 70, 66, -110, 0, 0, 115, 0, 116, 0, 0, 41, -118, 0, 65, 0, 124, 0, 0, 75, 0, -110, 0, -78, 0, 86, 104, 0, 99, 0, 123, 92, 0, 0, 0, -77, 0, -121, 0, 0, -12, -97, 0, 86, 0, -117, 0, 65, -5, 0, 0, 122, 0, -72, 0, 0, 88, -65, 0, 0, -38, 0, 0, -76, 80, 0, 0, 109, 122, 0, 0, 110, 104, 0, -61, 0, -103, 0, 0, -59, -104, 0, 0, 9, 0, -111, 0, -120, 0, -72, 80, 0, 0, 72, 0, 0, 4, -29, -49, 0, 0, 106, 0, 15, -48, 0, -57, -60, 0, 0, -109, -29, 0, 0, 117, -95, 0, 0, -84, 0, -79, 0, 0, 0, -55, 127, -11, 0, 0, 126, 36, 0, 0, 21, -58, 0, 0, 89, 0, 58, -13, 0, 0, 0, 96, 103, 0, -43, 67, 0, 0, 93, -6, 0, 64, -89, 0, 0, 64, -123, 0, 0, -73, 0, 0, 121, -50, 54, 0, 0, 0, 0, 103, -67, 37, 0, 0, -28, 0, 0, 32, -106, 0, 126, 0, 87, 0, 0, 110, -52, 0, -28, 36, 0, 0, 97, 0, -35, -61, 0, 88, 0, -101, 0, 0, -85, 13, -63, 0, 0, 24, 0, 0, -12, 12, 0, 0, -46, 19, -106, 0, 0, 0, -7, 39, 0}
};

int8_t metadata_matrix[4][128] = {
    {1, 3, 0, 2, 1, 2, 0, 3, 0, 1, 0, 3, 0, 1, 0, 3, 0, 2, 0, 3, 2, 3, 0, 1, 0, 1, 1, 2, 2, 3, 2, 3, 1, 2, 0, 2, 2, 3, 1, 2, 2, 3, 1, 2, 0, 1, 0, 1, 0, 2, 1, 2, 1, 3, 0, 1, 1, 2, 1, 3, 1, 3, 0, 3, 1, 2, 1, 3, 1, 3, 0, 3, 1, 3, 0, 1, 1, 2, 2, 3, 0, 2, 0, 2, 0, 3, 2, 3, 1, 3, 1, 2, 2, 3, 1, 2, 0, 2, 0, 1, 0, 3, 0, 3, 0, 1, 0, 1, 0, 1, 0, 2, 0, 1, 1, 2, 2, 3, 2, 3, 1, 2, 0, 1, 1, 2, 0, 1},
    {0, 2, 0, 3, 1, 2, 1, 3, 1, 2, 0, 3, 0, 1, 0, 1, 0, 2, 2, 3, 1, 3, 1, 2, 0, 1, 0, 1, 0, 2, 2, 3, 0, 2, 0, 3, 1, 3, 0, 1, 2, 3, 0, 3, 0, 2, 1, 2, 2, 3, 0, 2, 1, 2, 0, 3, 1, 2, 0, 3, 0, 3, 0, 1, 0, 3, 0, 1, 2, 3, 0, 2, 0, 3, 1, 3, 0, 1, 2, 3, 2, 3, 0, 3, 0, 3, 0, 3, 2, 3, 0, 2, 0, 1, 2, 3, 1, 2, 1, 3, 0, 3, 0, 1, 0, 2, 2, 3, 2, 3, 1, 3, 0, 2, 2, 3, 0, 1, 1, 3, 1, 3, 1, 2, 1, 2, 1, 3},
    {1, 2, 0, 2, 2, 3, 0, 1, 0, 3, 2, 3, 1, 2, 0, 2, 0, 2, 1, 2, 1, 2, 0, 3, 0, 3, 0, 3, 0, 3, 2, 3, 0, 2, 1, 3, 0, 2, 0, 1, 1, 3, 0, 2, 1, 3, 1, 3, 1, 3, 1, 3, 1, 2, 0, 2, 0, 1, 0, 2, 0, 3, 0, 2, 1, 2, 1, 3, 2, 3, 0, 1, 0, 2, 0, 3, 0, 1, 0, 3, 1, 2, 0, 3, 1, 2, 0, 1, 1, 3, 1, 3, 0, 2, 1, 2, 0, 3, 1, 3, 1, 2, 0, 2, 2, 3, 1, 2, 1, 2, 0, 2, 0, 1, 1, 3, 1, 2, 0, 3, 0, 1, 2, 3, 1, 3, 1, 3},
    {0, 1, 0, 2, 0, 3, 1, 3, 0, 2, 0, 2, 0, 3, 0, 3, 0, 1, 0, 2, 1, 2, 0, 2, 1, 3, 1, 3, 0, 2, 0, 1, 1, 3, 2, 3, 1, 3, 1, 2, 1, 3, 2, 3, 1, 2, 1, 2, 1, 2, 1, 2, 0, 2, 1, 2, 1, 3, 1, 3, 0, 3, 2, 3, 0, 3, 1, 2, 0, 1, 0, 1, 0, 1, 0, 2, 2, 3, 0, 3, 0, 3, 0, 3, 1, 2, 2, 3, 1, 2, 1, 2, 0, 1, 0, 1, 0, 3, 0, 1, 2, 3, 0, 3, 2, 3, 1, 3, 2, 3, 1, 2, 1, 3, 0, 2, 0, 3, 0, 1, 0, 3, 0, 3, 0, 1, 1, 2}
};

int8_t dense_matrix[256][4] = {
    {-122, -74, -124, 35},
    {24, 113, 74, -125},
    {101, 55, -93, -28},
    {-39, 88, 63, 116},
    {-106, 41, -61, 15},
    {115, -109, 89, 30},
    {97, -113, -91, -6},
    {-43, 122, 118, -54},
    {86, 117, -25, 69},
    {-96, 112, 6, 112},
    {-67, -70, 39, -91},
    {-16, 18, 126, -37},
    {-47, -73, -97, -94},
    {-39, 112, -65, 113},
    {105, 103, 83, 87},
    {-80, 13, 60, 42},
    {-124, 80, -110, 38},
    {89, 56, 68, -96},
    {0, -57, -2, -80},
    {-77, 11, -1, -62},
    {-16, -100, -21, -21},
    {29, 59, 39, -75},
    {121, -123, 6, -95},
    {-119, -127, -90, 115},
    {-107, 4, 54, -102},
    {-73, -76, -64, 116},
    {108, 73, -123, -79},
    {-36, -102, -6, -121},
    {-70, 71, 26, 47},
    {-61, 89, 72, 53},
    {105, -124, -94, -11},
    {-105, 75, 14, -107},
    {-8, -112, -126, -117},
    {62, 109, 19, -59},
    {-94, 53, -106, 64},
    {88, -97, 110, -55},
    {-43, 115, 72, 112},
    {-5, -6, 116, 55},
    {-94, 62, -64, 22},
    {82, -76, -127, -93},
    {-6, 2, -54, 62},
    {69, 35, 82, 17},
    {-107, -10, 117, -31},
    {-30, 119, -14, 42},
    {-2, -117, 111, -11},
    {-6, -65, 39, 43},
    {38, 105, -120, 46},
    {-55, -16, -126, -111},
    {-13, -10, -106, -35},
    {-81, 34, -106, -122},
    {-71, 7, 30, -40},
    {-113, 93, 53, 26},
    {-86, 112, 47, -91},
    {47, -26, 13, 72},
    {-49, -90, 35, -119},
    {-25, -59, -94, -64},
    {94, 54, 57, 24},
    {64, -59, 56, -99},
    {-97, 4, -111, -46},
    {-110, 27, 69, -85},
    {52, -104, 124, 97},
    {-105, -9, 28, -52},
    {103, 64, -24, 108},
    {-89, 87, 80, 4},
    {-33, -26, 39, 4},
    {30, -61, 4, -122},
    {73, -99, 79, -2},
    {51, 99, -27, -14},
    {83, 62, 33, -83},
    {-44, 67, 33, -106},
    {59, -95, -105, -60},
    {27, 7, -102, -11},
    {61, -40, -105, 45},
    {32, 109, 28, -65},
    {17, 108, 74, -94},
    {-10, 80, -117, 85},
    {-111, 103, 17, 100},
    {-124, -12, -124, 29},
    {31, 12, -37, -48},
    {-67, -8, 91, 32},
    {-26, 121, 5, -107},
    {97, 46, -68, 116},
    {81, 85, -86, -8},
    {40, 101, -11, 69},
    {83, -30, -36, -95},
    {47, -113, -124, 85},
    {121, -41, -1, -14},
    {123, 39, 2, -53},
    {-13, 90, 37, -48},
    {-104, -7, 92, 24},
    {-47, -24, 19, 43},
    {-73, 70, 52, 2},
    {111, -104, -119, 117},
    {70, 67, 28, 85},
    {-78, 83, 83, 96},
    {-93, -68, 14, 78},
    {94, -118, -51, -47},
    {-10, -119, 73, 70},
    {123, -46, -59, 10},
    {79, 76, -66, -67},
    {30, 48, 54, 44},
    {-24, 43, -127, 34},
    {-26, 99, 58, -42},
    {-87, -6, 80, -76},
    {34, 67, -5, 50},
    {-120, 98, -95, -2},
    {-39, 26, -66, -61},
    {-84, 7, -59, 124},
    {-37, -106, 61, 80},
    {46, -72, -50, -65},
    {-61, -76, -8, -28},
    {-50, -107, 59, -80},
    {78, -9, 54, 122},
    {125, -29, 80, -2},
    {5, 83, 73, 107},
    {-30, 110, 36, -68},
    {56, -6, -43, 114},
    {107, 37, -128, 27},
    {35, 4, -11, -29},
    {69, -80, 31, 52},
    {-39, 98, 98, -110},
    {-82, 94, 10, 48},
    {8, -121, 122, 28},
    {-85, -83, 2, 85},
    {-44, -110, -32, 27},
    {-104, -22, 95, 74},
    {1, -101, 73, 72},
    {100, -11, 30, 19},
    {-33, -39, -10, -7},
    {1, -112, 22, 39},
    {-31, -128, 0, 70},
    {-62, -13, 80, -33},
    {-31, -10, -51, -116},
    {126, 23, -2, 45},
    {-55, 90, 118, 93},
    {-88, -81, -31, -99},
    {-76, 86, 54, 49},
    {-74, -69, -42, -23},
    {-124, -24, -80, -101},
    {31, -31, -18, 58},
    {30, 62, 79, -44},
    {-32, 84, -108, -47},
    {-110, 126, -67, 65},
    {-39, -24, -10, 103},
    {-68, 71, -116, 106},
    {-67, 10, 23, 50},
    {-27, -23, -88, 68},
    {-123, 51, -47, 59},
    {-85, 101, -113, 89},
    {33, 42, 76, 109},
    {-73, -108, -9, 120},
    {-25, 119, 109, -2},
    {24, -99, 67, 107},
    {-36, -95, -58, -11},
    {80, -128, -20, -10},
    {-71, 107, 120, 77},
    {18, 0, 25, -101},
    {123, 19, 31, -56},
    {83, 24, 107, -31},
    {45, 56, 25, 126},
    {-10, -102, -36, -45},
    {-48, 124, 40, 74},
    {52, 79, 98, 36},
    {125, -115, 24, 49},
    {76, 94, -122, 7},
    {-99, -29, -91, 1},
    {-16, 104, 117, -13},
    {-39, -22, -108, 120},
    {121, -5, 19, -60},
    {-46, -75, -98, 19},
    {100, 54, -105, 90},
    {-112, -88, -34, 34},
    {77, -33, -98, -98},
    {123, 88, -47, -84},
    {-68, -21, 89, -127},
    {-115, -124, -28, 66},
    {-47, -41, -32, -19},
    {-49, -33, 61, -84},
    {-7, -56, 49, -9},
    {47, 31, 107, -121},
    {-63, 102, -26, -47},
    {-99, -9, 3, -102},
    {21, 98, 0, -22},
    {-100, 43, 43, 104},
    {54, -51, -16, 98},
    {-62, 60, -74, 47},
    {67, -81, 45, 106},
    {-104, 7, -15, -31},
    {3, 27, -29, -49},
    {-84, -117, 20, 30},
    {39, -43, 100, 68},
    {125, 27, 9, -69},
    {87, -51, -94, 36},
    {118, -36, -122, 82},
    {113, -18, -119, -35},
    {78, 117, 125, -54},
    {113, 60, 91, 16},
    {-29, 33, 53, -4},
    {94, 121, 19, -100},
    {44, -98, 28, -8},
    {-8, 101, -83, -35},
    {-111, 92, -100, 12},
    {-45, -7, -102, 91},
    {-92, 70, -30, -112},
    {-11, 72, 64, 76},
    {42, 92, 28, -67},
    {21, -58, 3, 43},
    {47, -14, 101, 42},
    {72, 63, 107, 126},
    {-116, 54, 83, 74},
    {-57, -47, -56, 48},
    {-48, 40, 54, -114},
    {-103, 11, 73, 1},
    {91, 25, 41, 94},
    {-53, 120, 22, 100},
    {102, -28, 113, -79},
    {69, -73, -60, 65},
    {85, -47, 67, 47},
    {-66, 123, -12, 13},
    {28, 99, -111, 72},
    {31, 117, 99, -60},
    {-34, 91, 15, 69},
    {-15, 55, 100, -78},
    {-53, -86, -125, 58},
    {-12, 92, -95, -6},
    {72, 84, -16, -86},
    {-9, 90, -90, 44},
    {116, 51, 35, 9},
    {-80, -82, 86, -67},
    {-49, -24, -8, -114},
    {72, -43, 60, 107},
    {106, -11, 44, 57},
    {34, -22, 56, 62},
    {124, 113, -33, -99},
    {-56, -126, -85, -1},
    {-80, 117, -63, 125},
    {-10, 101, 14, -121},
    {-121, -26, -58, -108},
    {-50, 103, 121, 78},
    {51, -71, -127, 114},
    {31, -128, -26, 99},
    {-44, 54, 46, 96},
    {89, -104, -115, 44},
    {-73, 57, -102, 126},
    {-112, 106, -121, 1},
    {65, -35, -38, 19},
    {107, 26, -41, 36},
    {-123, -77, -11, 50},
    {-119, 4, -32, -23},
    {12, 68, 35, 79},
    {-126, -126, 96, 71},
    {93, -127, 111, -104},
    {-20, 58, 16, -17},
    {-102, 37, 29, 122},
    {77, -63, 112, 95},
    {30, -76, -7, 19}
};

#endif // DATASET_H
