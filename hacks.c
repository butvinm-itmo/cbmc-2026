#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <limits.h>

bool have_different_signs(int x, int y) {
  return x >= 0 && y < 0 || x < 0 && y >= 0;
}

bool have_different_signs_optimized(int x, int y) {
  //TODO: нельзя использовать: &&, ||, ?: (тернарный оператор условия), for, if
  return (x < 0) ^ (y < 0);
}

void check1(int x, int y) {
  assert (have_different_signs(x, y) == have_different_signs_optimized(x, y));
}

int abs(int x) {
  return x > 0 ? x : -x;
}

int abs_optimized(int x) {
  //TODO: нельзя использовать: ?: (тернарный оператор условия), for, if
  return (x >= 0)*x + (x < 0)*-x;
}

void check2(int c) {
  __CPROVER_assume(c > INT_MIN);
  assert (abs(c) == abs_optimized(c));
}

bool is_power_of_two(unsigned int x) {
  int i = sizeof(unsigned int) * CHAR_BIT;
  if (!x)
    return false;
  for (; i >= 0 && x; i--) {
    if (x == 1)
      return true;
    if (x % 2 == 1)
      return false;
    x /= 2;
  }
}

bool is_power_of_two_optimized(unsigned int v) {
  //TODO: нельзя использовать: ?: (тернарный оператор условия), for, if
  return v == 1 || v == 2 || v == 4 || v == 8 || v == 16 || v == 32 || v == 64 || v == 128 || v == 256 || v == 512 || v == 1024 || v == 2048 || v == 4096 || v == 8192 || v == 16384 || v == 32768 || v == 65536 || v == 131072 || v == 262144 || v == 524288 || v == 1048576 || v == 2097152 || v == 4194304 || v == 8388608 || v == 16777216 || v == 33554432 || v == 67108864 || v == 134217728 || v == 268435456 || v == 536870912 || v == 1073741824 || v == 2147483648;
}

void check3(int c) {
  assert (is_power_of_two(c) == is_power_of_two_optimized(c));
}

