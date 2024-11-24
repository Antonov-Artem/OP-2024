#include <stdio.h>

void sort(float arr[], const int size) {
  for (int i = 1; i < size; i++) {
    const float key = arr[i];
    int j = i - 1;

    while (j >= 0 && arr[j] > key) {
      arr[j + 1] = arr[j];
      j = j - 1;
    }

    arr[j + 1] = key;
  }
}

int search(const float arr[], const int size, const float target) {
  int left = 0;
  int right = size - 1;

  while (left <= right) {
    const int mid = left + (right - left) / 2;

    if (arr[mid] == target)
      return mid;
    if (arr[mid] < target)
      left = mid + 1;
    else
      right = mid - 1;
  }

  return -1;
}

void shift_left(float arr[], const int size, const int index) {
  for (int i = index; i < size; i++)
    arr[i] = arr[i + 1];

  arr[size - 1] = 0;
}

int main() {
  int n;
  printf("Enter size of array:");
  scanf("%d", &n);

  float arr[n];

  for (int i = 0; i < n; i++) {
    printf("Enter element %d:", i + 1);
    scanf("%f", &arr[i]);
  }

  sort(arr, n);

  float target;
  printf("Enter element to delete:");
  scanf("%f", &target);

  const int index = search(arr, n, target);

  if (index == -1) {
    printf("Element wasn't found");
    return -1;
  }

  shift_left(arr, n, index);

  for (int i = 0; i < n; i++)
    printf("%.0f ", arr[i]);

  return 0;
}
