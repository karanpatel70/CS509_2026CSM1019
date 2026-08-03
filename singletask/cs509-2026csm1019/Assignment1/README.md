
# Assignment 01 - General Matrix Multiplication (GEMM)

## Assignment Mode

Single (Individual)

---

## Objective

Implement two matrix multiplication algorithms and compare their execution time.

Algorithms implemented

- Simple GEMM
- Blocking GEMM

Both implementations produce identical output matrices while their execution time is measured independently.

---

## Algorithm / Approach

### Simple GEMM

Uses the classical three nested loop implementation.

Each element of the result matrix is computed as

```
C[i][j] += A[i][k] * B[k][j]
```

---

### Blocking GEMM

The matrices are divided into fixed-size blocks.

Each block is processed independently to improve cache locality and reduce cache misses.

Block Size Used

```
32 × 32
```

---

## Input Format

Input File

```
M K N

Matrix A

Matrix B
```

where

- A is M × K

- B is K × N

- Result matrix is M × N

Example

```
2 3 2

1 2 3

4 5 6

7 8

9 10

11 12
```

---

## Helper Functions

### Matrix Class

Responsible for

- Reading matrix input
- Storing matrices A and B
- Returning matrix dimensions

---

### Timer Class

Measures only the algorithm execution time.

The following are excluded from timing

- File reading
- Parsing
- Output writing
- Memory allocation

---

## File Structure

```
assignment_01/

│── driver/
│      driver.cpp

│── include/
│      Matrix.h
│      GEMM.h
│      Timer.h

│── src/
│      Matrix.cpp
│      GEMM.cpp

│── tests/
│      gemm_test_01.txt
│      gemm_test_02.txt

│── outputs/
│      gemm_test_01_output.txt
│      gemm_test_02_output.txt
```

---

## Compilation

```
g++ driver/driver.cpp src/Matrix.cpp src/GEMM.cpp -o main
```

---

## Execution

```
./main
```

---

## Test Cases and Result Table

| Test File | Input Size | Expected Output | Actual Output | Simple Time (ms) | Blocking Time (ms) | Block Size | Status |
|------------|------------|-----------------|---------------|-----------------:|-------------------:|-----------:|:------:|
| gemm_test_01.txt | 2 × 3, 3 × 2 | Matrix | Matrix | 1.01ms |0 ms | 32 | Pass |
| gemm_test_02.txt | 128 × 128, 128 × 128 | Matrix | Matrix | 120.254 | 94.328 | 32 | Pass |
| gemm_test_03.txt | 256 × 256, 256 × 256 | Matrix | Matrix | 319.999 | 451.038 | 32 | Pass |



---

## Complexity

### Simple GEMM

Time Complexity

```
O(M × K × N)
```

Space Complexity

```
O(M × N)
```

---

### Blocking GEMM

Time Complexity

```
O(M × K × N)
```

Space Complexity

```
O(M × N)
```

---

## References

- CS509 Course Material
- C++ Reference
- GeeksforGeeks – Matrix Multiplication
