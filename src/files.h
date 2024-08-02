
#include <stdio.h>
#define LOWER 1024
#define UPPER 65536

typedef struct {
  char *content;
  size_t total;
} FileContent;

FileContent *ReadFile(char *file_name);
