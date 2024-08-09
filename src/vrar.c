#include "compressor.h"
#include "files.h"
#include "freq.h"
#include <stdio.h>
#include <string.h>

int main(int argsc, char **argsv) {
  if (argsc < 2) {
    perror("Missing file name\n");
    return 1;
  }

  char *file_content = ReadFile(argsv[1]);

  int *freq = GetFreq(file_content);

  printf("%p\n", (void *)freq);

  int size = strlen(file_content) / sizeof(file_content[0]);

  char *cmp = HuffmanCodes(file_content, freq, size);

  WriteFile(cmp);

  return 0;
}
