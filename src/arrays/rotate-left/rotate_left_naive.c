// Naive approach:

// Rotate one by one

#include "../../../utils/arrays.h"
#include <criterion/criterion.h>

void rotateArrayLeft(int *arr, int n, int d) {

  if (n == 0) {
    return;
  }

  for (int i = 0; i < d; i++) {

    int first = arr[0];
    for (int j = 0; j < n - 1; j++) {
      arr[j] = arr[j + 1];
    }
    arr[n - 1] = first;
  }
}

// -----------------------------------------------------------------

void assert_arrays_eq(int *arr, int *expected, int size) {
  for (int i = 0; i < size; i++) {
    cr_assert_eq(arr[i], expected[i], "Element %d is %d but expected %d", i,
                 arr[i], expected[i]);
  }
}

Test(rotateArrayLeft, test_1) {
  printf("Test 1\n");
  int arr[] = {1, 2, 3, 4, 5};
  int size = sizeof(arr) / sizeof(arr[0]);
  int d = 2; // Positions to rotate by to the left

  printf("Original array: ");
  display_arr_1D(arr, size);
  endl();

  rotateArrayLeft(arr, size, d);

  printf("Rotated array(by %d): ", d);
  display_arr_1D(arr, size);
  endl();

  int expected[] = {3, 4, 5, 1, 2};

  assert_arrays_eq(arr, expected, size);
}

Test(rotateArrayLeft, test_2) {
  printf("Test 2\n");
  int arr[] = {2, 6, 9, 1, 7, 0, 3, 4, 8, 5};
  int size = sizeof(arr) / sizeof(arr[0]);
  int d = 3; // Positions to rotate by to the left

  printf("Original array: ");
  display_arr_1D(arr, size);
  endl();

  rotateArrayLeft(arr, size, d);

  printf("Rotated array(by %d): ", d);
  display_arr_1D(arr, size);
  endl();

  int expected[] = {1, 7, 0, 3, 4, 8, 5, 2, 6, 9};

  assert_arrays_eq(arr, expected, size);
}

Test(rotateArrayLeft, test_3) {
  printf("Test 3\n");
  int arr[] = {0};
  int size = sizeof(arr) / sizeof(arr[0]);
  int d = 4; // Positions to rotate by to the left

  printf("Original array: ");
  display_arr_1D(arr, size);
  endl();

  rotateArrayLeft(arr, size, d);

  printf("Rotated array(by %d): ", d);
  display_arr_1D(arr, size);
  endl();

  int expected[] = {0};

  assert_arrays_eq(arr, expected, size);
}

Test(rotateArrayLeft, test_4) {
  printf("Test 4\n");
  int arr[] = {};
  int size = sizeof(arr) / sizeof(int);
  int d = 5; // Positions to rotate by to the left

  printf("Original array: ");
  display_arr_1D(arr, size);
  endl();

  rotateArrayLeft(arr, size, d);

  printf("Rotated array(by %d): ", d);
  display_arr_1D(arr, size);
  endl();

  int expected[] = {};

  assert_arrays_eq(arr, expected, size);
}
