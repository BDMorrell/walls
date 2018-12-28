#include "maze-defs.h"
#include <stdlib.h>

maze *allocateMaze(size2d requestedSize) {
  maze *newMaze = malloc(sizeof(maze));
  newMaze->size = requestedSize;
  newMaze->num_cells = computeArea(&(newMaze->size));
  newMaze->cells = malloc(sizeof(cell) * newMaze->num_cells);
  clearMazeCells(newMaze);
  newMaze->num_walls = calculateWallCount(newMaze->size);
  newMaze->walls = malloc(sizeof(wall) * newMaze->num_walls);
  //TODO: link walls to cells
}

int calculateWallCount(size2d size) {
  return ((size.w)-1)*size.h + ((size.h)-1)*size.w;
}

void dealocateMaze(maze *m) {
  //TODO: finish this
}
