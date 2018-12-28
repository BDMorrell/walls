#include <stdio.h>
#include <stdlib.h>


void *mempattern(void * destination, size_t destinationSize, void * source, size_t sourceSize)
{
  char * i = destination;
  char * j = source;
  while ((void *)i < destination + destinationSize) {
    *(i++) = *(j++);
    if ((void *)j >= source + sourceSize) {
      j = source;
    }
  }
  return destination;
}

// char *generateLine(int size) // TODO: update this
// {
//   char *ret = malloc(width * 2);
//   int i;
//   for (i = 0; i < width*2; i++) {
//
//   }
// }

int main()
{
  // int mazeWidth = 9;
  // int mazeHeight = 4;
  // char* hLine = generateLine(mazeWidth); // TODO: update this
  char str[] = "hello, this is a test of the system!";
  mempattern(str, 5, "ab", 2); // I know these are technically wrong
  printf("%s\n", str);
  //expected: "ababa, this is a test of the system!"
  return 0;
}
