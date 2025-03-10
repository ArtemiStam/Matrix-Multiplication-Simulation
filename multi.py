import numpy as np

# Define the matrices
A = np.array([
    [0, 0, -22, 79, 0, -89, 0, 40, 0, 114, 85, 0, 0, -24, 0, 120, 0, 0, 85, 119, -83, 0, 14, 0, 0, 0, 20, -54, -85, 0, 91, 0],
    [80, 0, 0, 6, 0, 0, 100, 34, 0, -18, -32, 0, -33, 0, 0, -94, 0, 0, -94, 109, -7, 0, 0, -123, -11, 0, -107, 0, 0, 54, 0, 114],
    [0, -57, -24, 0, 0, 0, 23, -54, 0, 80, 0, 3, 0, 0, 110, -78, 115, 0, 0, 41, 45, 114, 0, 0, 0, -4, 0, 0, 0, 30, 4, 0],
    [2, 71, 0, 0, 0, 80, 6, 0, 0, -95, -121, 0, -121, 0, -92, 0, 0, 0, 91, -100, 0, 0, -50, 119, 0, 0, -9, -63, 0, 0, -87, -124],
    [100, 0, 0, -118, 0, 38, 72, 0, 0, -10, 0, -125, 0, -106, 122, 0, 0, 66, -29, 0, -18, -54, 0, 0, 58, 0, 45, 0, -6, 0, 0, -121],
    [0, 49, 0, -3, 0, 0, 67, -48, 0, -78, -116, 0, 36, -37, 0, 0, 50, 0, 0, 56, 0, 18, 100, 0, 0, 3, 13, 0, -36, 0, 103, 0],
    [0, 49, 110, 0, 0, 0, -69, -41, 10, 0, 36, 0, 0, -74, 0, -107, 0, 0, 47, -43, 0, 124, -89, 0, -57, -53, 0, 0, -11, 0, 0, 47],
    [0, -77, 0, -35, 0, -73, 0, 3, 0, -84, 0, -39, 0, 5, -4, 0, 0, 122, 0, 102, 0, -93, 0, 82, 0, -106, 0, 70, 54, 0, -8, 0],
    [0, 0, 6, -45, 45, 0, 107, 0, 40, 0, 0, -84, 0, 0, -68, -34, 0, 0, -10, -1, 0, 0, 111, 57, 124, -105, 0, 0, 35, 0, 0, -78],
    [10, 100, 0, 0, 0, 0, -65, -29, 0, -75, 115, 0, 0, 0, 35, 23, 0, 0, 64, 41, 26, 0, 55, 0, 19, -27, 0, 0, 11, 0, 0, -68],
    [-41, 0, 0, 52, -78, 1, 0, 0, 60, 0, 0, -2, 0, 0, 43, 121, -19, 0, 0, -81, 0, 0, 0, 68, -98, 0, 0, -41, 119, 0, -94, 0],
    [0, 0, 82, -77, 112, 0, 0, 14, 0, -118, 3, 0, 0, 12, 0, -75, 0, 0, -80, -47, 18, 0, -89, 0, 37, 0, 97, 0, 0, 0, -21, 23],
    [-128, 84, 0, 0, 3, -104, 0, 0, 0, 36, 0, 97, 0, 0, 16, -60, -52, 0, 0, 94, -112, 0, 47, 0, 0, 51, 0, -94, 0, 35, 90, 0],
    [0, 52, 0, 76, -57, -104, 0, 0, 0, -120, 58, 0, 11, 0, -75, 0, 0, -126, 0, 2, 119, -22, 0, 0, -61, 0, 4, 0, -102, 0, 0, -63],
    [0, 13, 0, 55, 0, 0, 28, 68, -66, -114, 0, 0, 0, 107, 0, 7, 0, 0, 72, -80, 0, 77, 0, 106, 0, 0, 83, -52, 115, 0, 108, 0],
    [0, 0, 45, 70, 0, -33, 0, 49, 0, 82, 0, -84, 0, 55, 0, 53, 0, 28, -73, 0, 0, 35, -23, 0, 0, 0, 115, -102, -66, -23, 0, 0]
])

B = np.array([
   [-96, 101, 45, -119, -111, 65, -60, 39, 94, -22, 30, -26, 104, -41, 36, -56],
    [-100, -58, -77, 84, 34, 8, -124, 39, 78, -125, 50, -29, -103, 71, 106, 52],
    [54, -8, -8, -8, -29, -64, -108, -125, -74, 35, -96, -72, 27, 67, 60, 106],
    [5, 91, 83, 125, 54, -56, -85, -104, 37, -50, 98, -7, -88, -6, 120, -53],
    [71, -1, 55, 57, -87, 51, -112, 16, -21, -122, 24, -94, 100, 99, 102, -87],
    [40, -35, -89, 125, 17, -105, 44, 14, 74, -97, -104, 23, -88, -42, 103, -48],
    [-55, 83, -31, -44, -70, -99, -73, 104, -72, -2, 126, -87, 45, 46, -32, 72],
    [-106, -51, -68, -22, -123, -51, 56, -74, 34, 107, 63, 27, 115, 89, -76, 83],
    [-19, -74, -8, -71, -126, 63, -105, 66, 20, -91, -58, 80, -65, 21, -22, -119],
    [65, -7, 118, 48, -7, -15, 23, 2, -10, 17, -69, -49, 64, -27, -110, 8],
    [-23, 89, -32, 94, -120, 20, -91, -74, 71, 89, 37, -37, -56, 28, 94, 71],
    [66, 84, 123, 69, 0, -27, 80, -119, -15, -100, -83, -79, 46, -27, -65, -40],
    [15, -19, -47, 6, -71, -65, 121, 47, 114, 120, 9, 81, -34, -44, 51, 45],
    [74, -5, -40, -114, 123, 56, -104, 21, 91, 26, -3, 122, 66, -43, 63, -17],
    [-1, 85, -46, 33, -117, 78, 97, 19, 81, -80, -32, 92, -29, 90, 31, -104],
    [-6, -40, -47, -74, -11, 115, 81, 38, 106, -3, -96, 40, 51, 87, 37, -21],
    [-64, -111, -119, -21, -89, -72, 55, -126, 101, 102, -75, 83, 8, -23, -70, 50],
    [-85, -47, -4, 69, 111, 49, 51, -98, -20, 67, -119, 20, 78, -108, 1, -45],
    [33, -109, 117, 57, -44, 15, -124, -21, -121, 0, -92, -113, -121, -83, -22, -50],
    [10, 31, -56, -84, -69, 3, 76, 65, -116, 78, 39, -109, -5, 48, -72, 54],
    [67, -35, 69, 16, -64, -53, 121, -67, 11, -64, 112, 67, -42, 104, -122, 33],
    [-14, -47, -27, 105, -31, -99, 62, 18, -45, 113, -24, -24, 10, -126, 48, -84],
    [58, 126, -63, 27, 72, -33, -111, -2, -122, 122, 61, 45, 12, 100, -113, -34],
    [54, 119, -69, -111, -39, -33, 47, 84, 65, -106, -46, 11, -57, 28, 97, -89],
    [115, 56, -27, 21, -102, 37, -13, -99, -119, -68, -26, -13, -101, 59, 81, 107],
    [-2, 39, 125, 13, 62, -126, -99, 96, 90, -56, 92, 111, -71, -88, 66, 100],
    [-87, 88, -43, -34, 16, -16, 96, 69, 1, -127, -18, -98, -48, 91, -107, -49],
    [-52, -57, -52, 123, 2, 112, -94, 120, 87, -18, 74, -28, 66, 33, 66, -82],
    [32, -68, -103, 119, 1, -78, 82, -75, -54, 8, -63, -77, 116, 106, -57, 120],
    [124, -101, 14, 98, -18, 27, -48, -21, 45, -71, 61, -47, -104, -51, 98, 5],
    [23, 120, -21, -111, 64, 12, 112, 94, -121, 95, -97, -62, 6, 52, -89, 84],
    [-55, 0, -97, 23, 58, -44, 52, 24, -44, 15, 21, -5, -61, 79, 29, -95]
])

# Perform matrix multiplication
result = np.matmul(A, B)
np.set_printoptions(threshold=np.inf)
# Show result
print(result)
