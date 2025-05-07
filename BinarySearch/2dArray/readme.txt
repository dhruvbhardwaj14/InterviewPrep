To traverse a 2D matrix as a 1D array in C++ using two pointers (start = 0 and end = m * n), you can use the following formula to access the 2D indices (i, j) from a 1D index k:
int i = k / n;  // Row index
int j = k % n;  // Column index
Where:

k is the 1D index ranging from 0 to m * n - 1

m is the number of rows in the matrix

n is the number of columns in the matrix

