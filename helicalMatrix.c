#include <stdio.h>

#define N 4

int arr[N][N] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};

int main(int argc, char const *argv[]) {
// i is the iterator
// j minRow, k is MaxRow
// n minCol, m is MaxCol
  int i = 0, j = 0, k = N, m = N, n = 0;
  while (j < k && n < m) {
    // Fix minRow , iterate the col , this moves right
    for (i = n; i < m; i++) {
      printf("%d ", arr[j][i]);
    }
    j++;
    // Fix maxCol, iter the row .. this moves down
    for (i = j; i < k; i++)
      printf("%d ", arr[i][m - 1]);
    m--;
    // Fix maxRow, iter the col .. this moves left
    for (i = m; i > n; i--)
      printf("%d ", arr[k - 1][i - 1]);
    k--;
    // Fix  minCol, iter the row .. this moves up
    for (i = k; i > j; i--)
      printf("%d ", arr[i - 1][n]);
    n++;
  }
  return 0;
}
