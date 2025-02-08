import numpy as np
import sys
import random

def generate_sparse_matrix(rows, cols):
    sparse_matrix = np.zeros((rows, cols), dtype=np.int8)
    metadata_matrix = np.full((rows, cols // 2), -1, dtype=np.int8)
    
    for i in range(rows):
        for j in range(0, cols, 4):
            nonzero_indices = random.sample(range(4), 2)
            nonzero_values = [random.randint(-128, 127) for _ in range(2)]
            
            metadata_matrix[i, j // 2] = nonzero_indices[0]
            metadata_matrix[i, j // 2 + 1] = nonzero_indices[1]
            
            sparse_matrix[i, j + nonzero_indices[0]] = nonzero_values[0]
            sparse_matrix[i, j + nonzero_indices[1]] = nonzero_values[1]
    
    return sparse_matrix, metadata_matrix

def generate_dense_matrix(rows, cols):
    return np.random.randint(-128, 127, (rows, cols), dtype=np.int8)

def write_header_file(filename, sparse, metadata, dense):
    with open(filename, 'w') as f:
        f.write("#ifndef DATASET_H\n#define DATASET_H\n\n")
        
        rows, cols = sparse.shape
        f.write(f"#define SPARSE_ROWS {rows}\n")
        f.write(f"#define SPARSE_COLS {cols}\n")
        f.write(f"#define METADATA_COLS {cols // 2}\n")
        f.write(f"#define DENSE_ROWS {cols}\n")
        f.write(f"#define DENSE_COLS {dense.shape[1]}\n\n")
        
        def array_to_c(arr, name):
            return f"static int8_t {name}[{arr.shape[0]}][{arr.shape[1]}] = {{\n" + ",\n".join(
                "    {" + ", ".join(map(str, row)) + "}" for row in arr
            ) + "\n};\n\n"
        
        f.write(array_to_c(sparse, "sparse_matrix"))
        f.write(array_to_c(metadata, "metadata_matrix"))
        f.write(array_to_c(dense, "dense_matrix"))
        
        f.write("#endif // DATASET_H\n")

def main():
    if len(sys.argv) != 5:
        print("Usage: python spare_matrix_generator.py <rows> <sparse_cols> <dense_cols> <X>")
        sys.exit(1)
    
    rows = int(sys.argv[1])
    sparse_cols = int(sys.argv[2])
    dense_cols = int(sys.argv[3])
    dataset_name = sys.argv[4]
    
    if rows % 4 != 0 or sparse_cols % 4 != 0 or dense_cols % 4 != 0:
        print("Error: All dimensions must be multiples of 4.")
        sys.exit(1)
    
    sparse_matrix, metadata_matrix = generate_sparse_matrix(rows, sparse_cols)
    dense_matrix = generate_dense_matrix(sparse_cols, dense_cols)
    
    header_filename = f"dataset{dataset_name}.h"
    write_header_file(header_filename, sparse_matrix, metadata_matrix, dense_matrix)
    print(f"Generated {header_filename}")

if __name__ == "__main__":
    main()
