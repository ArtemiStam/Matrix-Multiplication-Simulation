#ifndef DATASET_H
#define DATASET_H

#define SPARSE_ROWS 32
#define SPARSE_COLS 64
#define METADATA_COLS 32
#define DENSE_ROWS 64
#define DENSE_COLS 32

int8_t sparse_matrix[32][64] = {
    {-35, 0, 65, 0, 0, -71, 63, 0, -75, 0, 0, 40, 16, 0, 0, -53, 0, 0, -53, -91, 0, 0, -27, -102, 0, -75, 0, 103, 0, -84, -81, 0, 86, -27, 0, 0, 0, -29, 35, 0, -106, 0, 0, 44, 85, 0, 16, 0, 118, 0, -87, 0, 0, 50, 0, 73, 0, 81, 0, -11, -112, -40, 0, 0},
    {95, 0, 0, 59, 0, 0, -106, -111, -112, 0, 0, -67, 0, -106, 0, -19, 0, 0, 41, -123, 0, -88, -28, 0, 0, -70, 45, 0, 3, 0, 0, -70, 27, 80, 0, 0, 36, 122, 0, 0, 0, 17, 0, -73, -86, 0, 0, 50, 0, 31, -46, 0, -63, 0, 0, -77, 0, 0, -24, -104, -23, 12, 0, 0},
    {0, -109, 6, 0, 0, -124, 63, 0, -17, 15, 0, 0, 0, 104, 0, -89, 26, 0, 0, 90, -99, 0, -49, 0, 0, -106, 0, 84, 66, 0, -120, 0, 0, 18, 0, 117, 0, 0, 22, -111, 0, 0, -76, -24, 0, -1, 0, -77, 0, 122, 0, -64, 90, 44, 0, 0, 0, -107, 46, 0, 59, 0, 0, 28},
    {0, 0, -24, 45, 0, 67, 0, -65, 100, -47, 0, 0, -56, 0, 71, 0, 76, 0, -85, 0, 44, 0, 0, 13, 0, 0, 92, -22, 89, -22, 0, 0, 62, 0, 0, 119, -65, 0, 0, 50, -70, -19, 0, 0, 25, 0, 23, 0, 0, 0, 96, -120, 0, -68, 48, 0, 73, 0, 0, -42, 27, 41, 0, 0},
    {9, 0, 0, -123, 0, 54, -51, 0, 0, 0, 61, 36, 0, -34, -127, 0, 102, 0, 0, -115, 0, -93, 0, -65, 0, 5, -127, 0, -124, 0, 0, -39, 0, -111, -87, 0, -79, 0, 0, 0, 0, -74, 0, 68, 0, -42, 0, 90, 0, -17, 0, 58, 6, 0, 0, -47, 0, 0, -126, -85, -104, 0, -93, 0},
    {67, 0, 126, 0, -33, 0, 0, 60, 73, 0, 0, -64, 0, 9, -25, 0, 0, 0, 55, 13, 41, 36, 0, 0, -30, 0, 3, 0, 0, 0, 28, 55, 0, 14, 0, 123, 0, 115, 21, 0, 0, 43, 30, 0, 0, 0, -96, 44, 0, -12, 0, -88, -26, 0, -29, 0, 0, 42, 40, 0, 0, -70, -19, 0},
    {-57, 0, -48, 0, -88, 0, 0, 75, 0, 0, 109, 100, 99, -123, 0, 0, 0, 60, 94, 0, -14, 0, 91, 0, -84, 0, -96, 0, 0, 0, -49, -102, 89, 0, 39, 0, 0, -94, -104, 0, 95, 0, 91, 0, -12, 0, 0, -106, 53, 110, 0, 0, 28, 0, 0, 34, 82, -23, 0, 0, -123, 0, 63, 0},
    {50, -13, 0, 0, 85, 0, 0, -53, 0, -60, 97, 0, 0, 0, -67, -80, 48, 0, -85, 0, 110, 75, 0, 0, -68, -63, 0, 0, 0, 80, 0, 111, -64, 0, 110, 0, 77, -4, 0, 0, 41, 0, 34, 0, 33, 0, 0, 13, 0, 0, 5, -48, -57, -71, 0, 0, 99, 0, 0, 24, 0, 0, 125, 7},
    {0, 77, -15, 0, 0, -68, 124, 0, 68, 0, 4, 0, 0, 50, 0, -124, 0, 0, 84, -70, 0, 0, -93, 122, -33, 0, 0, 118, 0, 0, -15, 57, -119, -60, 0, 0, 115, 73, 0, 0, -101, 0, 117, 0, -117, 0, 0, 37, 0, 0, 69, -116, -113, 5, 0, 0, 0, 0, 3, 80, 0, 0, -10, -19},
    {0, -28, 0, 9, -127, -108, 0, 0, 0, 0, -27, 27, 0, 33, -73, 0, -45, 0, -19, 0, 0, 0, -55, -124, 0, 0, 31, -69, 0, 0, 25, -38, -42, 0, 0, 85, -113, -23, 0, 0, 127, 0, 0, -7, 0, 0, 46, 112, -13, 0, 0, -121, 125, 0, 0, -71, 28, -52, 0, 0, 0, -68, 0, -91},
    {0, 0, -126, 48, -33, 83, 0, 0, -24, 0, 0, 70, 91, 0, 64, 0, 0, -31, 0, 38, -8, 87, 0, 0, 0, -94, -51, 0, 0, -53, 44, 0, 0, 0, 37, -70, 0, -87, 0, 45, -69, 0, 26, 0, -69, 0, 0, 0, -25, -59, 0, 0, 0, -86, 0, -11, 0, -53, 0, -56, 2, 0, -18, 0},
    {-34, -17, 0, 0, -119, 94, 0, 0, 2, 0, 61, 0, 0, 0, 1, 110, 21, 0, 0, -27, 0, 15, 30, 0, 103, 0, -128, 0, 0, 74, 29, 0, 0, 67, 0, 0, -11, 99, 0, 0, 0, 71, 0, -5, 0, 0, 53, 52, 10, 47, 0, 0, 127, 67, 0, 0, 0, 90, 0, 10, 0, 22, 17, 0},
    {69, -20, 0, 0, 0, 0, 63, 127, -30, 0, -22, 0, 0, 0, 12, -61, 12, 0, -109, 0, 33, 81, 0, 0, 65, 0, 0, -6, 0, 0, 48, 85, -90, 0, 0, -78, -82, 0, 124, 0, 109, 0, 0, -36, 0, 0, -72, -5, -63, 97, 0, 0, 0, 110, 0, 108, 0, -42, -9, 0, 60, 0, 0, 73},
    {-84, -96, 0, 0, 0, -114, -107, 0, -2, 0, 0, 32, 0, 0, -31, -57, 0, 96, -121, 0, 111, -90, 0, 0, 0, -117, 0, 99, 0, 79, 0, -113, 0, -121, 0, 95, 0, -32, 67, 0, -61, 0, 5, 0, -62, 0, 0, -13, 0, 0, -103, 125, -56, 0, 0, -22, -110, 0, -65, 0, -84, 101, 0, 0},
    {-15, 0, 1, 0, 0, 0, 23, -68, 0, 0, 19, 32, 0, 14, 0, -20, -37, 47, 0, 0, 0, -116, 0, -123, 5, -84, 0, 0, 106, 0, -78, 0, 105, 0, 37, 0, 110, 0, 0, -118, 77, 0, 44, 0, 0, 0, 122, 127, 0, -116, 7, 0, 0, 0, -118, 45, -127, 0, 127, 0, -62, -65, 0, 0},
    {0, -19, 35, 0, 0, 59, 0, -45, -77, 111, 0, 0, 0, -98, 0, -113, 27, 0, 0, -120, -55, -2, 0, 0, 65, 0, 0, -78, 0, 0, 11, 89, 0, 0, 11, 92, 0, 0, 70, 63, -24, 64, 0, 0, 0, 41, 0, -56, 0, -31, -29, 0, 79, 0, -61, 0, -126, -71, 0, 0, -89, 37, 0, 0},
    {0, 26, -127, 0, 0, 123, 0, 36, -89, 0, 28, 0, 0, 71, 0, -81, 0, 40, 95, 0, 123, 0, 0, 2, 0, 0, 4, -52, 0, 126, 52, 0, 0, 0, -108, 37, -67, 0, 0, -44, 0, -85, 54, 0, 22, 0, 0, 81, 0, 0, -110, -52, 0, 0, 30, 27, 57, 0, 0, -77, 0, -68, 26, 0},
    {0, 0, 123, -104, 0, -111, 8, 0, 0, -8, 0, -27, 0, 76, 0, 118, 0, 89, 0, 28, 16, 111, 0, 0, 0, 109, 116, 0, -128, 0, 52, 0, 64, 0, 0, -112, 0, 49, 0, 83, 0, 82, 0, 36, 114, 0, -24, 0, 0, 17, -51, 0, -56, 0, 0, -26, 0, 34, -86, 0, -103, -102, 0, 0},
    {-72, -70, 0, 0, 0, 0, -37, -34, 69, 0, 0, 116, 0, -20, 0, 8, -10, -76, 0, 0, 0, 0, 81, -61, 0, 103, 0, 45, 0, 24, 0, 25, 0, 19, 0, -66, 0, -119, -24, 0, 0, 0, -97, -36, 0, 0, -122, 44, -101, 86, 0, 0, -52, 2, 0, 0, 1, 0, -66, 0, 0, 0, -4, 17},
    {0, -22, 0, -123, 0, -30, -109, 0, -87, 0, 0, 119, 48, -89, 0, 0, 0, 0, -3, -35, 0, 0, 29, -58, 0, 0, 89, 34, 83, 58, 0, 0, -121, 0, 0, 67, 0, 110, 0, -38, 0, 0, 54, -29, 0, 0, 16, 21, -9, 0, 0, 104, 0, 127, 0, -50, 52, 54, 0, 0, 0, 35, 3, 0},
    {6, 28, 0, 0, 56, 0, 99, 0, -38, 10, 0, 0, -31, 20, 0, 0, -122, -43, 0, 0, 26, 0, 114, 0, 0, 0, 34, 62, 0, -71, 0, -49, 0, 122, 82, 0, 0, 114, 116, 0, 0, 0, 71, 11, 0, 95, -16, 0, 0, 0, 77, 0, 0, -39, 0, 50, 0, 0, 41, -85, 10, 56, 0, 0},
    {92, 0, 0, 125, -57, 127, 0, 0, 0, 4, 0, -2, 70, 0, 0, -20, 8, 0, 0, 40, -22, 0, 0, -87, 0, 63, 0, 24, 13, 0, 0, 127, 0, 25, 65, 0, -75, -49, 0, 0, 45, 0, 0, -29, 0, 0, 68, -27, 0, -21, 0, 86, 66, 120, 0, 0, 5, 85, 0, 0, 0, 127, -57, 0},
    {0, 44, -19, 0, 68, 0, 52, 0, 0, 0, 62, -77, 0, 116, -54, 0, 0, 1, -69, 0, -12, 88, 0, 0, 0, 92, 0, -22, 0, 0, -118, 119, 0, 0, -128, 33, 118, -120, 0, 0, 87, 0, 85, 0, 87, -122, 0, 0, -66, 65, 0, 0, -15, 4, 0, 0, -58, 0, -128, 0, -47, 0, -95, 0},
    {99, -122, 0, 0, -47, 9, 0, 0, 0, 0, -5, 122, 3, 0, -95, 0, 26, 0, 0, 79, 7, 0, 0, 64, 32, 0, 72, 0, 0, 0, 83, 60, 89, 0, -115, 0, 116, 0, 0, 27, 0, 90, 0, 62, -33, 74, 0, 0, -114, 0, 0, 69, 0, 0, -66, 4, -70, -67, 0, 0, 54, 63, 0, 0},
    {0, 77, 0, 57, -49, 0, 5, 0, 0, 75, -54, 0, 7, 0, -67, 0, -100, 0, -19, 0, 0, 0, 109, 68, 0, 34, 42, 0, 0, 0, -89, 120, 65, 0, -68, 0, -103, 0, -56, 0, 0, 41, 0, -95, 0, 0, 38, 20, -39, 48, 0, 0, -76, 0, -21, 0, 0, -67, 25, 0, -67, 0, -90, 0},
    {0, 0, -119, 23, 0, -73, 44, 0, -3, 114, 0, 0, 0, 0, 60, 31, 0, 0, -54, 120, 0, -9, 0, -59, -2, 0, 0, 101, 0, -48, 118, 0, -74, -90, 0, 0, 0, -122, 0, -66, 0, 23, 27, 0, 0, -9, 0, -85, 0, 98, 97, 0, 0, 121, 0, -51, -7, 0, 0, 59, -15, 0, -48, 0},
    {0, 0, 60, 73, 55, 0, 14, 0, 72, 0, 0, -27, -81, 0, -44, 0, 0, -52, -52, 0, -3, -17, 0, 0, 0, 78, 0, 34, 0, 92, 0, 36, 0, -83, 62, 0, 0, 93, -44, 0, 0, 87, 26, 0, 0, 0, 46, -128, 63, 108, 0, 0, 0, -93, -26, 0, -75, 0, 71, 0, 92, 0, 102, 0},
    {0, 83, 0, -83, 0, 95, -34, 0, 0, 88, 28, 0, 0, -14, -100, 0, 0, 0, 67, -95, 0, 0, 73, -53, 0, 31, -68, 0, 0, -89, 22, 0, -112, 0, 0, -4, -106, 0, 0, -57, 0, 117, 43, 0, 0, 0, -78, 117, -82, -85, 0, 0, -56, 0, -38, 0, -51, 0, 0, -123, 0, 97, -86, 0},
    {0, 0, 31, -99, 35, 0, 53, 0, -63, 0, 0, -1, 0, -37, 0, -18, -116, 0, -123, 0, 0, 0, -92, -58, 105, 0, 0, -37, -58, 0, 78, 0, -120, 37, 0, 0, 0, -52, 0, -58, -122, 57, 0, 0, 0, -105, -20, 0, -38, 0, 0, -105, 0, 0, 0, 102, -1, 0, -15, 0, 0, 0, 111, 41},
    {105, 0, 0, -120, 118, 0, 0, -56, -8, -121, 0, 0, 0, -49, 0, 30, 0, -57, 0, -104, 47, 0, 42, 0, 0, -123, 79, 0, -20, 0, 26, 0, 0, -29, -67, 0, -121, 0, 107, 0, -83, 0, -106, 0, 55, -67, 0, 0, -59, 0, 0, 115, 0, 68, 51, 0, 0, 0, -71, -50, 0, -105, 0, 29},
    {0, -30, 0, -107, 0, 0, -16, 114, 39, 0, 0, -119, 0, 0, 76, -74, -66, 0, -17, 0, -9, 0, 0, 126, 0, 0, -80, 31, 54, 0, 23, 0, 0, 90, 0, -98, 0, -46, 0, 33, -19, 0, 0, -72, 0, -120, -63, 0, -14, 0, 74, 0, 0, 21, -68, 0, 0, 54, 102, 0, 0, 122, 0, -74},
    {0, 0, 32, -122, 0, -110, 0, 15, -8, 0, 0, -26, 0, 0, -4, 126, 0, 0, -57, 6, 0, 0, -19, 29, 0, -40, 0, -98, 0, -72, 0, -12, 90, 0, 0, -26, -101, 0, -113, 0, 0, -30, 0, 52, -67, -98, 0, 0, 0, 103, -35, 0, 105, -51, 0, 0, -114, 0, 0, 97, 0, -122, -94, 0}
};

int8_t metadata_matrix[32][32] = {
    {0, 2, 1, 2, 0, 3, 0, 3, 2, 3, 2, 3, 1, 3, 1, 2, 0, 1, 1, 2, 0, 3, 0, 2, 0, 2, 1, 3, 1, 3, 0, 1},
    {0, 3, 2, 3, 0, 3, 1, 3, 2, 3, 1, 2, 1, 2, 0, 3, 0, 1, 0, 1, 1, 3, 0, 3, 1, 2, 0, 3, 2, 3, 0, 1},
    {1, 2, 1, 2, 0, 1, 1, 3, 0, 3, 0, 2, 1, 3, 0, 2, 1, 3, 2, 3, 2, 3, 1, 3, 1, 3, 0, 1, 1, 2, 0, 3},
    {2, 3, 1, 3, 0, 1, 0, 2, 0, 2, 0, 3, 2, 3, 0, 1, 0, 3, 0, 3, 0, 1, 0, 2, 2, 3, 1, 2, 0, 3, 0, 1},
    {0, 3, 1, 2, 2, 3, 1, 2, 0, 3, 1, 3, 1, 2, 0, 3, 1, 2, 0, 2, 1, 3, 1, 3, 1, 3, 0, 3, 2, 3, 0, 2},
    {0, 2, 0, 3, 0, 3, 1, 2, 2, 3, 0, 1, 0, 2, 2, 3, 1, 3, 1, 2, 1, 2, 2, 3, 1, 3, 0, 2, 1, 2, 1, 2},
    {0, 2, 0, 3, 2, 3, 0, 1, 1, 2, 0, 2, 0, 2, 2, 3, 0, 2, 1, 2, 0, 2, 0, 3, 0, 1, 0, 3, 0, 1, 0, 2},
    {0, 1, 0, 3, 1, 2, 2, 3, 0, 2, 0, 1, 0, 1, 1, 3, 0, 2, 0, 1, 0, 2, 0, 3, 2, 3, 0, 1, 0, 3, 2, 3},
    {1, 2, 1, 2, 0, 2, 1, 3, 2, 3, 2, 3, 0, 3, 2, 3, 0, 1, 0, 1, 0, 2, 0, 3, 2, 3, 0, 1, 2, 3, 2, 3},
    {1, 3, 0, 1, 2, 3, 1, 2, 0, 2, 2, 3, 2, 3, 2, 3, 0, 3, 0, 1, 0, 3, 2, 3, 0, 3, 0, 3, 0, 1, 1, 3},
    {2, 3, 0, 1, 0, 3, 0, 2, 1, 3, 0, 1, 1, 2, 1, 2, 2, 3, 1, 3, 0, 2, 0, 1, 0, 1, 1, 3, 1, 3, 0, 2},
    {0, 1, 0, 1, 0, 2, 2, 3, 0, 3, 1, 2, 0, 2, 1, 2, 1, 2, 0, 1, 1, 3, 2, 3, 0, 1, 0, 1, 1, 3, 1, 2},
    {0, 1, 2, 3, 0, 2, 2, 3, 0, 2, 0, 1, 0, 3, 2, 3, 0, 3, 0, 2, 0, 3, 2, 3, 0, 1, 1, 3, 1, 2, 0, 3},
    {0, 1, 1, 2, 0, 3, 2, 3, 1, 2, 0, 1, 1, 3, 1, 3, 1, 3, 1, 2, 0, 2, 0, 3, 2, 3, 0, 3, 0, 2, 0, 1},
    {0, 2, 2, 3, 2, 3, 1, 3, 0, 1, 1, 3, 0, 1, 0, 2, 0, 2, 0, 3, 0, 2, 2, 3, 1, 2, 2, 3, 0, 2, 0, 1},
    {1, 2, 1, 3, 0, 1, 1, 3, 0, 3, 0, 1, 0, 3, 2, 3, 2, 3, 2, 3, 0, 1, 1, 3, 1, 2, 0, 2, 0, 1, 0, 1},
    {1, 2, 1, 3, 0, 2, 1, 3, 1, 2, 0, 3, 2, 3, 1, 2, 2, 3, 0, 3, 1, 2, 0, 3, 2, 3, 2, 3, 0, 3, 1, 2},
    {2, 3, 1, 2, 1, 3, 1, 3, 1, 3, 0, 1, 1, 2, 0, 2, 0, 3, 1, 3, 1, 3, 0, 2, 1, 2, 0, 3, 1, 2, 0, 1},
    {0, 1, 2, 3, 0, 3, 1, 3, 0, 1, 2, 3, 1, 3, 1, 3, 1, 3, 1, 2, 2, 3, 2, 3, 0, 1, 0, 1, 0, 2, 2, 3},
    {1, 3, 1, 2, 0, 3, 0, 1, 2, 3, 2, 3, 2, 3, 0, 1, 0, 3, 1, 3, 2, 3, 2, 3, 0, 3, 1, 3, 0, 1, 1, 2},
    {0, 1, 0, 2, 0, 1, 0, 1, 0, 1, 0, 2, 2, 3, 1, 3, 1, 2, 1, 2, 2, 3, 1, 2, 2, 3, 1, 3, 2, 3, 0, 1},
    {0, 3, 0, 1, 1, 3, 0, 3, 0, 3, 0, 3, 1, 3, 0, 3, 1, 2, 0, 1, 0, 3, 2, 3, 1, 3, 0, 1, 0, 1, 1, 2},
    {1, 2, 0, 2, 2, 3, 1, 2, 1, 2, 0, 1, 1, 3, 2, 3, 2, 3, 0, 1, 0, 2, 0, 1, 0, 1, 0, 1, 0, 2, 0, 2},
    {0, 1, 0, 1, 2, 3, 0, 2, 0, 3, 0, 3, 0, 2, 2, 3, 0, 2, 0, 3, 1, 3, 0, 1, 0, 3, 2, 3, 0, 1, 0, 1},
    {1, 3, 0, 2, 1, 2, 0, 2, 0, 2, 2, 3, 1, 2, 2, 3, 0, 2, 0, 2, 1, 3, 2, 3, 0, 1, 0, 2, 1, 2, 0, 2},
    {2, 3, 1, 2, 0, 1, 2, 3, 2, 3, 1, 3, 0, 3, 1, 2, 0, 1, 1, 3, 1, 2, 1, 3, 1, 2, 1, 3, 0, 3, 0, 2},
    {2, 3, 0, 2, 0, 3, 0, 2, 1, 2, 0, 1, 1, 3, 1, 3, 1, 2, 1, 2, 1, 2, 2, 3, 0, 1, 1, 2, 0, 2, 0, 2},
    {1, 3, 1, 2, 1, 2, 1, 2, 2, 3, 2, 3, 1, 2, 1, 2, 0, 3, 0, 3, 1, 2, 2, 3, 0, 1, 0, 2, 0, 3, 1, 2},
    {2, 3, 0, 2, 0, 3, 1, 3, 0, 2, 2, 3, 0, 3, 0, 2, 0, 1, 1, 3, 0, 1, 1, 2, 0, 3, 1, 3, 0, 2, 2, 3},
    {0, 3, 0, 3, 0, 1, 1, 3, 1, 3, 0, 2, 1, 2, 0, 2, 1, 2, 0, 2, 0, 2, 0, 1, 0, 3, 1, 2, 2, 3, 1, 3},
    {1, 3, 2, 3, 0, 3, 2, 3, 0, 2, 0, 3, 2, 3, 0, 2, 1, 3, 1, 3, 0, 3, 1, 2, 0, 2, 1, 2, 1, 2, 1, 3},
    {2, 3, 1, 3, 0, 3, 2, 3, 2, 3, 2, 3, 1, 3, 1, 3, 0, 3, 0, 2, 1, 3, 0, 1, 1, 2, 0, 1, 0, 3, 1, 2}
};

int8_t dense_matrix[64][32] = {
    {32, 22, -42, -84, 57, 6, -47, 31, -16, -52, 44, -108, 98, -7, 26, 63, -71, 57, 83, -55, 14, -108, -86, -48, -85, -3, -10, 93, 92, 36, 86, -1},
    {-5, -10, -12, -41, -118, -93, 22, -19, -124, -99, 117, 120, -69, 31, 115, 57, -78, -62, 81, 89, -127, -57, 64, 56, -37, -116, 115, 73, 2, -85, -37, -80},
    {-68, -93, 92, 42, 73, 37, -108, -48, 34, 77, 29, 64, -84, -128, -39, 2, -55, 104, -22, 4, 21, -79, -32, 63, -15, -102, 82, 56, 125, 63, 102, 86},
    {-56, 15, -103, 59, -41, 83, 31, 46, -22, -95, 56, -78, -2, 84, 100, 4, -10, 53, 76, 119, 47, -104, 102, -73, 121, 24, -120, -86, -108, 44, 5, -13},
    {-12, 126, 97, -64, 43, 23, 110, -29, -95, -46, -53, 120, 122, -9, -65, -29, -29, 13, -58, 19, 5, 48, 46, -66, 106, -119, 111, -90, 105, -102, -38, 26},
    {68, -48, 29, -7, 34, -79, 20, -83, -29, -123, 4, 86, 31, 20, 39, 12, 49, 7, -34, -108, 99, -5, -32, 52, -42, 120, 78, -37, 64, 85, -119, 122},
    {78, -45, -126, -16, -74, 49, 109, 100, -41, -84, 2, 120, 76, -89, -96, -65, -66, 123, 73, -65, 37, 29, -28, -80, -78, -49, -110, -54, 107, -3, 26, 105},
    {-57, 81, -87, 112, 52, 51, 1, -61, -51, 0, -96, -122, 16, -123, -39, 68, -12, 85, -90, 29, 80, 25, -78, 27, -98, 96, 28, 52, -9, -40, -117, -30},
    {-31, 29, 122, -38, 21, -26, -128, 49, 96, 119, -69, 37, 4, -48, -80, -44, 1, -63, -67, -87, -37, -52, -32, 74, -110, 115, 108, 47, 34, -92, 67, 85},
    {-64, -58, 39, 11, 29, 114, -37, -27, 49, -38, -67, -54, -78, -116, -92, 19, -100, -65, -126, 120, 90, -96, 102, -25, 47, -117, -36, 125, -91, -67, 49, 121},
    {96, 66, 45, 85, 120, 19, -95, -13, 103, -121, 39, 25, -51, -51, -75, 121, -128, 5, 123, -73, 49, 22, -48, 91, -119, -128, 46, -108, 54, 104, -73, 16},
    {27, -21, -53, -30, 16, 38, 48, 45, 57, -6, 95, -102, -47, -102, -121, -52, 14, 84, -52, -114, 123, -64, -14, 63, -97, -54, 124, -92, -114, 4, -5, -91},
    {21, -63, 44, -63, -33, -5, 44, 28, -23, -3, -21, -64, -93, -76, 107, 104, 85, -43, -87, -46, -38, 49, 102, 59, 2, 22, -3, -115, 20, -67, -15, 120},
    {85, 89, -76, -91, 51, 26, -90, -94, -104, -124, -20, -40, 20, -33, 106, 69, 7, 3, -54, -53, 68, -5, -72, -126, 42, 53, -3, -113, -67, 59, 103, -45},
    {-79, 7, 5, 61, -101, 48, -73, -1, 103, 63, -105, 91, -17, 122, 113, -70, 2, 57, 5, 17, -79, -40, 54, 109, 24, -22, 70, 33, -63, -53, -67, -83},
    {-68, 26, 61, -5, -118, -91, 115, 90, -51, -34, 32, 118, -63, 45, 55, 87, -46, -72, 41, -91, -74, 2, 36, 43, 0, 58, 125, -21, 110, 62, 115, -97},
    {77, 99, -17, 55, -35, 25, 87, -44, 63, 12, -30, -1, 89, 77, -127, 31, -84, -57, 42, -40, -3, 122, 122, 106, -83, 76, -70, 21, -45, 81, 62, 59},
    {-55, -6, -67, -114, -23, -69, -38, -116, -104, 37, -8, -76, 20, 15, 49, -49, -122, -119, 47, 74, 122, -111, 15, -92, -42, -119, -112, -98, -8, -2, -35, -54},
    {66, -86, -29, 94, -75, -5, 27, -101, 93, -8, -106, 72, 63, 93, 8, -80, 15, 39, -98, 61, -38, 17, 90, 7, -88, -120, -61, -101, 46, -102, 109, 31},
    {14, 75, 35, 54, -25, -121, -1, -110, 121, -52, 66, -39, -70, 85, 116, 9, 99, 76, -128, -118, -110, -10, 6, -30, 38, -114, 5, 78, -72, 51, 89, 89},
    {86, -96, -10, -50, -59, -14, 104, -69, -100, -112, -102, 91, -28, 68, -76, 19, 5, -3, -52, 56, 42, -110, -69, 114, -89, 10, 68, 38, 92, -89, 32, 66},
    {-62, 6, 77, -96, -72, -71, 43, 17, 3, 77, 55, -114, -21, 64, -28, 65, 20, 24, -105, -96, 54, 65, 49, -33, -123, -75, -14, 85, 95, -106, -107, -2},
    {17, 125, 93, -29, 44, -38, 56, 124, 111, -82, -118, 6, 74, 52, 56, -78, 70, -76, 110, -8, -18, -84, -52, 66, -52, 46, 108, -115, 44, 22, -15, 101},
    {69, 81, 69, -87, -128, -125, -108, 68, -14, -80, -117, 21, -17, -64, 85, 95, 12, 17, 64, -1, -49, 80, 88, 9, -52, 18, -70, 35, 86, 36, 20, 111},
    {72, 106, 44, -35, 32, -114, -122, 82, -41, -95, 13, -88, 35, -77, 114, 19, -98, -93, -120, -56, 0, 42, -70, -43, 102, 60, 55, -37, 104, 101, 101, -96},
    {-67, -90, 115, -73, -65, -98, -64, -56, 117, -14, -120, -59, 7, -121, 47, 105, 80, 19, -105, -51, -37, -34, 102, -66, 89, -109, -90, 86, -119, 44, -33, 112},
    {121, 50, 16, -26, 88, -90, -30, -73, -121, -109, 92, 112, 5, 53, -14, -104, -19, 70, -98, -86, 26, -47, 1, 78, -123, 33, 104, 101, -25, 35, -9, 6},
    {-35, -101, 12, 17, 101, 85, -11, -29, -108, -4, 61, 59, 97, -67, -127, -84, 17, -27, 114, -25, -113, 72, 117, 111, -22, -1, -119, 114, -122, -96, 67, 39},
    {112, 85, -2, 66, 54, 116, -13, -26, -33, 40, 62, -46, 93, -71, -67, -121, -104, -107, -121, 123, 24, 58, 107, 57, 29, 0, -64, -60, -44, 99, -70, -2},
    {96, 31, -39, -92, 30, -117, 104, 65, 33, -69, -81, -115, 101, 100, -53, -35, 71, -25, 9, 112, 11, 84, -53, 72, -120, -39, -54, -95, 117, 20, 64, 11},
    {-35, -53, -50, 93, 14, 103, 69, -119, -116, 29, 3, 66, 46, -14, 104, -96, 0, -37, 50, -94, -38, -74, -78, -52, 53, 11, 114, -24, 94, -19, -65, 34},
    {-30, -58, -44, -92, 51, -84, 113, -10, 18, 79, 91, 118, -65, 46, 7, -106, -58, 66, -110, 23, -116, -53, -116, -85, -4, -50, -110, 67, 11, 37, 26, 104},
    {-96, 13, 94, -62, 81, -84, -86, 33, 9, 72, 72, -124, -17, -74, -15, -116, -85, -72, -21, -2, -98, -109, 29, 90, 17, -63, -90, -70, 69, 13, 7, -72},
    {107, 95, 12, -41, 62, -115, 1, 11, 103, 28, 57, 37, 119, 17, 43, 66, -125, 30, 7, -78, -120, 119, 96, -33, -32, -79, 25, 96, 78, 69, 93, 19},
    {58, -127, 65, -18, 50, 75, -51, 81, -39, 45, 109, 31, -125, 13, 43, 11, 66, 11, 0, 7, -18, -111, -84, -60, 1, -97, 109, -32, -65, 65, -12, -53},
    {16, 75, -120, 1, 106, 8, 114, -8, 95, 16, -53, 18, -117, 17, -35, -93, 119, 53, -63, -102, 14, 113, 107, 42, -120, -99, 50, 122, 12, -54, -16, 92},
    {122, -68, -42, 9, 73, 53, -40, -27, -4, 10, 126, 12, -89, 86, -43, -79, -109, 92, 37, 117, 99, -7, -7, -3, 6, -105, -38, -96, -111, -87, 16, 126},
    {-95, 2, -90, -73, 63, -79, 102, -16, 36, -107, 80, -93, -5, -118, -28, 122, -73, -68, -52, 115, -80, -22, 117, 82, -109, 89, 80, 60, 58, 121, 99, -35},
    {-59, 105, 17, 72, -14, -15, -98, 69, -1, -40, 117, -111, 124, 77, 56, 52, 100, 59, 35, 13, -91, -100, 38, -28, 39, 89, 59, -61, 120, 105, -94, 73},
    {107, 62, -43, 54, -27, 101, 98, -58, -96, 53, 46, -30, -113, -128, -63, -83, 62, -55, -116, -22, 97, 115, -95, -91, -62, 96, 26, -59, 80, -16, 100, 48},
    {-15, 97, 2, -84, 103, -18, 81, -24, 98, -14, 104, -24, 120, 99, -72, 78, -83, -79, 27, 33, 48, 8, 56, -34, 96, 52, 47, -123, 31, -14, 14, 71},
    {-54, -81, -21, -103, 77, -111, 33, -39, 30, -73, 73, -74, 15, -72, 17, -71, 122, 96, 16, -88, -77, 58, -61, -118, 0, 113, 98, 93, 12, 17, -46, 123},
    {-48, 55, -43, -68, -4, 53, -36, -44, 80, 31, 84, -127, 72, 55, -18, -118, 88, 95, -32, 114, -59, 50, -119, 111, -31, -26, -98, -50, 66, -52, -53, 62},
    {78, -25, 46, -72, 41, -25, 64, -116, -106, 10, 41, -89, -54, -128, -100, 21, -68, -120, 33, -36, -105, 120, -91, -24, 74, 109, -49, 64, 54, 95, -26, 70},
    {82, -96, -13, -52, 8, 41, 104, 85, 41, 28, 123, -117, 106, 31, -2, -128, -57, 31, -32, 36, 54, -112, 53, -83, 94, -1, 38, -35, -98, 124, -9, 9},
    {-62, -50, 64, -70, 69, -117, 91, -50, 12, 104, 83, -54, 36, -31, 39, -51, 47, 71, -13, -117, -15, -85, -62, -35, 61, 29, 77, -62, -30, 78, -70, 44},
    {-28, 14, -55, -56, -21, 125, 26, -107, 45, -84, -66, 98, -120, -69, 75, 125, -84, 50, 44, -120, 52, -75, -117, 113, 57, 63, 23, 47, -13, 87, -101, 45},
    {-57, -22, 65, -62, -80, 96, -86, 90, 43, 59, -65, -117, 126, 7, 46, -77, -125, -5, 87, 124, 67, 95, -54, 105, 103, -98, -106, 43, -2, -56, -103, -28},
    {17, -84, 99, 114, 113, 98, -126, -122, -113, 53, -33, -80, -95, -118, -26, -92, 112, -76, -39, -119, 64, 107, 116, 32, -38, 1, -109, -102, 78, -21, -67, 28},
    {126, -12, -120, -100, 58, 33, 109, 104, 32, -92, -111, 62, 100, 7, -22, -123, -77, 9, -101, 126, 35, 99, -29, 67, 52, -69, -65, -12, 15, -116, -54, 25},
    {-37, 44, 59, 79, 46, -122, -10, 43, 22, 123, 7, -93, 58, 25, -61, -6, 57, -65, -52, -22, 107, -5, -36, -27, -26, -11, -124, -84, 37, 60, 63, -127},
    {-116, 10, 10, 21, -29, -73, 28, 30, -39, 60, -126, 67, 109, 9, -92, -19, 41, 86, 49, 125, 61, -39, -47, 36, 70, 16, 103, -121, 82, -88, -84, -110},
    {107, -32, 100, 121, -107, 59, -92, 15, 0, -97, -101, 2, -110, -67, 33, -35, -34, 117, 98, -86, -46, 106, -67, -101, -123, -42, -124, 91, -60, -20, -50, -57},
    {-48, -49, 81, 21, -50, -69, 116, 106, 124, -33, -21, -5, -40, -3, -6, -85, -128, -101, 26, 99, -29, 113, 119, 77, 73, -38, 122, 116, 7, -95, 94, -25},
    {-123, -18, 48, 96, -41, -2, 72, 100, 103, 44, 23, -114, -29, 53, 72, 71, -81, 61, 114, 120, 35, -105, -5, -9, -68, 68, 41, 83, 38, 41, -40, -28},
    {-94, 90, -118, 84, -2, -102, -115, -8, 81, -96, 12, 106, -21, 52, -112, -35, -120, 106, 5, -23, -40, 58, 106, -58, 44, -105, 77, -102, 45, 106, -13, -17},
    {-93, 58, 72, 21, -61, -78, -112, 88, -70, -59, -78, -31, -78, -24, 19, 60, -108, -16, 119, 35, 53, -91, 100, -77, -83, -69, 91, 66, -77, -114, -126, -43},
    {-35, 8, 33, 14, -115, -93, -80, 25, -64, 44, -122, 115, -74, 17, 22, -11, 37, -74, 67, 114, -56, 2, 124, -69, 6, 17, -29, 120, -62, -16, -19, -108},
    {52, 1, -43, 65, 34, -97, 78, -58, 63, 89, 102, -20, -20, 37, 89, 65, 12, -126, 117, -74, 61, -10, 107, 52, 82, 81, 93, 108, -117, 70, -118, 94},
    {18, 108, -88, 18, -59, 45, -73, -20, -90, -75, 21, 27, 73, 119, 33, -97, -106, 112, -113, -18, -4, 99, -3, -25, -110, -100, -114, 110, -118, 71, 9, -32},
    {81, -50, 43, -34, -114, -5, 34, -122, -123, 9, -33, -16, 15, 68, 89, -21, 126, 38, -65, -15, -53, -35, -34, -47, 75, 20, -68, -64, -13, 86, -106, 30},
    {30, -75, 100, 6, 57, -72, -92, 7, 68, -104, 3, -69, -4, 76, 13, -122, 35, 18, 34, 16, 103, 10, -64, -77, -36, -43, 49, 6, -4, -112, 79, 72},
    {-86, -26, 102, 57, 90, 81, -48, 23, 116, 96, -21, -2, -100, -54, 97, -81, 89, 103, -38, 20, -92, -63, -91, -56, -93, 51, 59, 124, 51, 76, 10, -15},
    {-105, -58, -61, -17, -22, 16, 119, 105, 91, 89, 121, -36, -13, 125, -38, -95, 73, -53, 68, 99, 68, -21, 14, -93, -78, 58, 21, 120, 117, 14, 96, 7}
};

#endif // DATASET_H
