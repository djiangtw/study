# requirement
- [x] platform. workstation.
- [ ] hw simd?
- [x] data processing interface. given predefined pattern generator.
- [x] reference documtn. wiki page
- [x] anci c code.
- [x] data type. flexible to change data type.
- [x] numbers of operations, complexity.
- [x] logical errors.

# task
- C = A + S(A, B);
    - [x] good coding style.
    - [x] well commented code.
    - [x] test vectors.
    - [x] strassen algorithm.

# notes
- foo n ops breaks
    - n, dimension of test matrices, i.e. n-by-n.
        - the maximum dimension is 10000x10000.
    - ops, operations
        - 0, C = A + S(A, B) using strassen algorithm
        - 1, C = A + M(A, B) using common matrices multiplication.
        - 2, perform ops 0 and 1, and compare the results to verify the correctness.
        - 3, perform ops 2 and dump the result.
    - breaks,
        - the dimension of unit matrix for strassen algorithm.
        - defailt is 16, i.e. the dimension of unit matrix is 16x16.
    - patterns,
        - 0, random numbers. the range is from -46340 to 46340.
        - 1, all ones.
        - 2, sequential numbers. vector {0, 1, 2, .. , n - 1} for each row, there are totally n rows.

# usage
- `foo`
    - perform the verify-correctness operation with two 10-by-10 matrices.
    - the default strassen break is 16.
    - the default pattern is all-ones.
- `foo $n`
    - perform the verify-correctness operation with two $n-by$n matrices.
    - the default strassen break is 16.
    - the default pattern is all-ones.
- `foo $n $ops`
    - perform the $ops operation with two $n-by$n matrices.
    - the default strassen break is 16.
    - the default pattern is all-ones.
- `foo $n $ops $breaks`
    - perform the $ops operation with two $n-by$n matrices.
    - the strassen is $breaks.
    - the default pattern is all-ones.
- `foo $n $ops $breaks $pattern`
    - perform the $ops operation with two $n-by$n matrices.
    - the strassen is $breaks.
    - the pattern is $pattern.

# test vectors
- performance of strassen method,
- performance of common method,
- verification of correctness,

