#include <stdio.h>
#include <string.h>

int main() {
  char s1[10], s2[10];

  fgets(s1, sizeof(s1), stdin);
  fgets(s2, sizeof(s2), stdin);

  s1[strcspn(s1, "\n")] = 0;
  s2[strcspn(s2, "\n")] = 0;

  for (int i = 0; i < strlen(s1); i++)
    if (!strchr(s2, s1[i]))
      strcat(s2, &s1[i]);

  printf("%s", s2);

  return 0;
}
