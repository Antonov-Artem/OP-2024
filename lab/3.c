#include <stdio.h>

int main() {
  int n;
  scanf("%d", &n);

  int a[n];
  int b[n];

  for (int i = 0; i < n; i++)
    scanf("%d", &a[i]);

  for (int i = 0; i < n; i++) {
    b[i] = a[i];

    if (a[i] % 2 == 0) {
      for (int j = i + 1; j < n; j++)
        if (a[j] % 2 != 0) {
          b[i] = a[i] + a[j];
          break;
        }
    }
    else
      b[i] = a[i] * 2;
  }

  for (int i = 0; i < n; i++)
    printf("%d ", b[i]);

  return 0;
}
