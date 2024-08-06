#include "files.h"
#include <stdlib.h>
#include <string.h>

int *GetFreq(char *file) {
  size_t increase = LOWER;
  size_t allocated = increase;
  int *f_arr = calloc(allocated, sizeof(int));
  size_t total_file = strlen(file);
  size_t total;

  for (total = 0; total < total_file; total++) {
    f_arr[file[total] - 'a']++;

    if (total >= allocated) {
      if (increase >= UPPER)
        increase = UPPER;

      allocated += increase;

      f_arr = realloc(f_arr, allocated);

      increase *= 2;
    }
  }

  for (size_t i = 0; i < total; i++) {
    printf("%c, %d\n", file[i], f_arr[i]);
  }

  f_arr = realloc(f_arr, total);
  return f_arr;
}
