#include "freq.h"
#include "files.h"
#include <stdlib.h>
#include <string.h>

Freq *GetFreq(char *file) {
  size_t increase = LOWER;
  size_t allocated = increase;
  Freq *freq = malloc(sizeof(Freq));
  freq->f_arr = calloc(allocated, sizeof(int));
  size_t total_file = strlen(file);
  size_t total;

  for (total = 0; total < total_file; total++) {
    freq->f_arr[file[total] - 'a']++;

    if (total >= allocated) {
      if (increase >= UPPER)
        increase = UPPER;

      allocated += increase;

      freq->f_arr = realloc(freq->f_arr, allocated);

      increase *= 2;
    }
  }

  for (size_t i = 0; i < total; i++) {
    printf("%c, %d\n", file[i], freq->f_arr[i]);
  }

  freq->f_arr = realloc(freq->f_arr, total);
  return freq;
}
