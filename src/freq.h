#pragma once

typedef struct {
  int *f_arr;
  char *words;
} Freq;

Freq *GetFreq(char *file);
