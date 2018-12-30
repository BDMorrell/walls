#include <stdio.h>
#include "maze-defs.h"

int main()
{
  size2d sizeRequest;
  sizeRequest.w = 9;
  sizeRequest.h = 5;
  maze *myMaze = allocateMaze(sizeRequest);
  completeMaze(myMaze);
  printMaze(myMaze, stdout);
  deallocateMaze(myMaze);
  return 0;
}
