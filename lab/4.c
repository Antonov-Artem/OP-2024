#include <stdio.h>

int main() {
  int n, m;
  scanf("%d %d", &n, &m);

  int a[n][m];

  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      scanf("%d", &a[i][j]);

  for (int i = 0; i < n; i++) {
    int max_col = 0;
    int max = a[i][max_col];

    for (int j = 0; j < m; j++) {
      if (max < a[i][j]) {
        max = a[i][j];
        max_col = j;
      }
    }

    int b = 0;

    for (int j = 0; j < n; j++) {
      if (max > a[j][max_col]) {
        break;
      }

      b++;
    }

    if (b == n) {
      printf("%d ", i + 1);
    }
  }

  return 0;
}
