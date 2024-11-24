#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(NULL));

  int n, m;
  scanf("%d %d", &n, &m);

  int a[n][m];

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      a[i][j] = rand() % (10 - (-10) + 1) + (-10);
      printf("%d\t", a[i][j]);
    }
    printf("\n");
}

  int result = 0;

  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      if (a[i][j] > a[i - 1][j] && a[i][j] > a[i + 1][j])
        result++;

  printf("%d", result);

  return 0;
}
