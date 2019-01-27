#include "maze-defs.h"
#include <stdlib.h>

maze *allocateMaze(size2d requestedSize)
{
  maze *newMaze = malloc(sizeof(maze));
  newMaze->size = requestedSize;
  newMaze->num_cells = computeArea(&(newMaze->size));
  newMaze->cells = calloc(newMaze->num_cells, sizeof(cell));
  clearMazeCells(newMaze);
  newMaze->num_walls = calculateWallCount(newMaze->size);
  newMaze->walls = calloc(newMaze->num_walls, sizeof(wall));
  // TODO: split up this function?
  initializeWalls(newMaze);

  return newMaze;
}

int calculateWallCount(size2d size)
{
  return ((size.w)-1)*size.h + ((size.h)-1)*size.w;
}

void initializeWalls(maze *m)
{
  wall *it = m->walls; // iterator
  int row;
  for (row = 0; row < m->size.h; row++) {
    int col;
    // link right
    for (col = 0; col < m->size.w-1; col++) { // right-most doesn't have a right
      initWall(it++, getCell(m, col, row), getCell(m, col + 1, row));
    }
    // link down
    if (row != m->size.h - 1) { // if we aren't in the bottom row
      for (col = 0; col < m->size.w; col++) {
        initWall(it++, getCell(m, col, row), getCell(m, col, row + 1));
      }
    }
  }
}

void initWall(wall *w, cell *a, cell *b)
{
  w->active = true;
  w->sides[0] = a;
  w->sides[1] = b;
}

int getOffset(size2d s, int x, int y)
{
  if (x >= s.w || x < 0 || y >= s.h || y < 0) {
    return -1; //error
  } // implicit else
  return ((y * s.w) + x);
}

cell *getCell(maze *m, int x, int y)
{
  int offset = getOffset(m->size, x, y);
  if (offset == -1) {
    return NULL;
  } // implicit else
  return m->cells + offset; // &(m->cells[offset])
}

void deallocateMaze(maze *m)
{
  free(m->walls);
  free(m->cells);
  free(m);
}
