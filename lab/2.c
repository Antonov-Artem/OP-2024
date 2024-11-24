#include <math.h>
#include <stdio.h>

int main() {
  double a, b, dx, min, max;

  do {
    printf("Enter a (a != 0):");
    scanf("%f", &a);
  } while (a == 0);

  do {
    printf("Enter b (b != 0):");
    scanf("%f", &b);
  } while (b == 0);

  double inf = (9 - 135 * a * b) / 5;
  double sup = INFINITY;

  do {
    printf("Enter min, max:");
    scanf("%f %f", &min, &max);
  } while (max <= min || !(inf <= min && min <= sup) || !(inf <= max && max <= sup));

  do {
    printf("Enter dx (dx > 0, dx > max - min):");
    scanf("%f", &dx);
  } while(dx <= 0 || dx > max - min);


  printf("\tx  y\n");

  for (int x = min; x <= max; x += dx) {
    double y = 3 * sqrt(((5 * x - 9) / (7.5 * a * b)) + 18) + exp(2 * x + 0.5 / a);

    printf("%6.2f\t%.2f\n", x, y);
  }

  return 0;
}
