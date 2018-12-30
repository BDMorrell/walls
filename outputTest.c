#include <stdio.h>
#include <stdlib.h>
#include "maze-defs.h"

// Low level fucntion, and hasn't been tested with edge cases.
void *mempattern(void * destination, size_t destinationSize, void * source, size_t sourceSize)
{
  char *i = destination;
  char *j = source;
  while ((void *)i < destination + destinationSize) {
    *(i++) = *(j++);
    if ((void *)j >= source + sourceSize) {
      j = source;
    }
  }
  return destination;
}

char *generatePatternString(size_t requestedSize, char *source, size_t sourceSize)
{
  char *ret = malloc(requestedSize + 1); // for '\0'
  if (ret != NULL) {
    mempattern(ret, requestedSize, source, sourceSize);
    ret[requestedSize] = '\0';
  }
  return ret;
}

char *createMazeTemplate(size2d desiredSize) {
  char *str = malloc(computeArea(desiredSize))
}

int main()
{
  int mazeWidth = 9;
  int mazeHeight = 4;
  char *hLine = generatePatternString(mazeWidth*2-1, "+-", 2); // 2 excludes '\0'
  char *vLine = generatePatternString(mazeWidth*2-1, "| ", 2); // 2 excludes '\0'
  int y;
  for (y = 0; y < mazeHeight; y++) {
    printf("%s\n%s\n", hLine, vLine);
  }
  printf("%s\n", hLine);
  return 0;
}
