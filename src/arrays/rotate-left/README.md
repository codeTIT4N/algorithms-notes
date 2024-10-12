# Rotate an Array by d – Counterclockwise or Left

```
Given an array of integers arr[] of size n, the task is to rotate the
array elements to the left by d positions.

Example:
Input: arr[] = {1, 2, 3, 4, 5, 6}, d = 2
Output: {3, 4, 5, 6, 1, 2}
```

- Naive approach: [`rotate_left_naive.c`](./rotate_left_naive.c)
- Temporary array approach: [`rotate_left_tmp.c`](./rotate_left_tmp.c)

### Complexities

- Time complexity:
  - Naive approach: `O(n * d)`
  - Temporary array approach: `O(n)`
- Space complexity:
  - Naive approach: `O(1)`
  - Temporary array approach: `O(n)`