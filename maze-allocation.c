#include "maze-defs.h"
#include <stdlib.h>

maze *allocateMaze(size2d requestedSize) {
  maze *newMaze = malloc(sizeof(maze));
  newMaze->size = requestedSize;
  newMaze->num_cells = computeArea(&(newMaze->size));
  newMaze->cells = malloc(sizeof(cell) * newMaze->num_cells);
  clearMazeCells(newMaze);
  //TODO: allocate walls
}

void dealocateMaze(maze *m) {
  //TODO: finish this
}
