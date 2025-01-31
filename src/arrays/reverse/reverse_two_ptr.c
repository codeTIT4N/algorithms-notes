// 2 ptrs approach:

// Use 2 ptrs left at start and right at end of array. While left ptr is
// less than right ptr, swap the elements. Move ptrs after each swap.

#include "../../../utils/arrays.h"
#include <criterion/criterion.h>
#include <criterion/new/assert.h>

void swap(int *left, int *right) {
  int tmp = *left;
  *left = *right;
  *right = tmp;
}

void reverseArrayTwoPtr(int *arr, int n) {

  int left = 0;
  int right = n - 1;

  while (left < right) {
    swap(&arr[left], &arr[right]);
    left++;
    right--;
  }
}

// -----------------------------------------------------------------

Test(reverseArrayTwoPtr, test_1) {
  printf("Test 1\n");
  int arr[] = {1, 2, 3, 4, 5};
  int size = sizeof(arr) / sizeof(arr[0]);

  printf("Original array: ");
  display_arr_1D(arr, size);
  endl();

  reverseArrayTwoPtr(arr, size);

  printf("Reversed array: ");
  display_arr_1D(arr, size);
  endl();

  int expected[] = {5, 4, 3, 2, 1};

  cr_assert(eq(int[size], arr, expected));
}

Test(reverseArrayTwoPtr, test_2) {
  printf("Test 2\n");
  int arr[] = {0, 8, 4, 0, 2, 7, 1, 9, 6, 2};
  int size = sizeof(arr) / sizeof(arr[0]);

  printf("Original array: ");
  display_arr_1D(arr, size);
  endl();

  reverseArrayTwoPtr(arr, size);

  printf("Reversed array: ");
  display_arr_1D(arr, size);
  endl();

  int expected[] = {2, 6, 9, 1, 7, 2, 0, 4, 8, 0};

  cr_assert(eq(int[size], arr, expected));
}

Test(reverseArrayTwoPtr, test_3) {
  printf("Test 3\n");
  int arr[] = {0};
  int size = sizeof(arr) / sizeof(arr[0]);

  printf("Original array: ");
  display_arr_1D(arr, size);
  endl();

  reverseArrayTwoPtr(arr, size);

  printf("Reversed array: ");
  display_arr_1D(arr, size);
  endl();

  int expected[] = {0};

  cr_assert(eq(int[size], arr, expected));
}

Test(reverseArrayTwoPtr, test_4) {
  printf("Test 4\n");
  int arr[] = {};
  int size = sizeof(arr) / sizeof(int);

  printf("Original array: ");
  display_arr_1D(arr, size);
  endl();

  reverseArrayTwoPtr(arr, size);

  printf("Reversed array: ");
  display_arr_1D(arr, size);
  endl();

  int expected[] = {};

  int size_expected = sizeof(expected) / sizeof(int);
  cr_assert(eq(int, size, size_expected));
}
