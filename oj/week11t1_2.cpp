/**
 * 快速排序 （C/C++语言）
 * 请实现下方的两个比较函数和C99中的qsort函数，函数的签名与含义见下方注释和
 * https://en.cppreference.com/w/c/algorithm/qsort。
 * 你不能修改main函数，实现函数过程中不能使用任何库函数。
 * */
#include <stdio.h>

/**
 * Sorts the given array pointed to by ptr in ascending order.
 * The array contains count elements of size bytes.
 * Function pointed to by comp is used for object comparison.
 * 1. ptr - pointer to the array to sort
 * 2. count - number of element in the array
 * 3. size - size of each element in the array in bytes
 * 4. comp - comparison function which returns a negative integer
 * value if the first argument is less than the second, a positive integer value
 * if the first argument is greater than the second and zero if the arguments
 * are equal. The function must not modify the objects passed to it and must
 * return consistent results when called for the same objects, regardless of
 * their positions in the array. * */
void my_swap(const void *a, const void *b, size_t size)
{
    char *x = (char*)a;
    char *y = (char*)b;
    char tmp;
    for (int i = 0; i < size; i++)
    {
        tmp = *(x + i);
        *(x + i) = *(y + i);
        *(y + i) = tmp;
    }
}
void qsort(void *ptr, size_t count, size_t size,
           int (*comp)(const void *, const void *))
{
    if (count <= 0) return;
    int l = 0, r = count - 1;
    while (l < r)
    {
        while (l < r && comp(ptr + l * size, ptr + r * size) < 0) r--;
        if (l < r) my_swap(ptr + l * size, ptr + r * size, size), l++;
        while (l < r && comp(ptr + l * size, ptr + r * size) < 0) l++;
        if (l < r) my_swap(ptr + l * size, ptr + r * size, size), r--;
    }
    qsort(ptr, l, size, comp);
    qsort(ptr + (l + 1) * size, count - l - 1, size, comp);
}

/**
 * Return a negative value if the integer a points to is smaller than that of b.
 * Return a positive value if the integer a points to is larger than that of b.
 * Return zero if the integers a and b point to are equal.
 * */
int less(const void *a, const void *b)
{
    int x = *(const int*)a;
    int y = *(const int*)b;
    return (x < y) ? -1 : 1;
}

/**
 * Return a negative value if the real number (double) a points to is larger
 * than that of b. Return a positive value if the real number (double) a points
 * to is smaller than that of b. Return zero if the real number (double) a and b
 * point to are equal.
 * */
int greater(const void *a, const void *b)
{
    double x = *(const double*)a;
    double y = *(const double*)b;
    return (x > y) ? -1 : 1;
}

int a[100005] = {};
double b[100005] = {};

int main() {
  int T = 0;
  scanf("%d", &T);
  while (T--) {
    int i = 0, type = 0, n = 0;
    scanf("%d%d", &type, &n);
    if (type == 1) {
      for (i = 0; i < n; ++i) {
        scanf("%d", a + i);
      }
      qsort(a, n, sizeof(int), less);
      for (i = 0; i < n; ++i) {
        printf("%d ", a[i]);
      }
      printf("\n");
    } else {
      for (i = 0; i < n; ++i) {
        scanf("%lf", b + i);
      }
      qsort(b, n, sizeof(double), greater);
      for (i = 0; i < n; ++i) {
        printf("%.3lf ", b[i]);
      }
      printf("\n");
    }
  }
  return 0;
}