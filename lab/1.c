#include <stdio.h>

int main() {
  double x, y, d, c;

  printf("Enter x:");
  scanf("%f", &x);
  printf("Enter y:");
  scanf("%f", &y);
  printf("Enter d:");
  scanf("%f", &d);
  printf("Enter c:");
  scanf("%f", &c);

  if (x == 0 && y == 0)
    printf("Point belongs to A and B");
  else if (x >= -d && x < 0 && y >= -c && y < 0)
    printf("Point belongs to A");
  else if (x > 0 && x <= d && y > 0 && y <= c)
    printf("Point belongs to B");
  else
    printf("Point belongs neither to A nor to B");

  return 0;
}
