#include "maze-defs.h"
#include <stdlib.h>

maze *allocateMaze(size2d requestedSize)
{
  maze *newMaze = malloc(sizeof(maze));
  newMaze->size = requestedSize;
  newMaze->num_cells = computeArea(&(newMaze->size));
  newMaze->cells = malloc(sizeof(cell) * newMaze->num_cells);
  clearMazeCells(newMaze);
  newMaze->num_walls = calculateWallCount(newMaze->size);
  newMaze->walls = malloc(sizeof(wall) * newMaze->num_walls);

  initializeWalls(newMaze);
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

void initWall(wall &w, cell *a, cell *b)
{
  w.active = true;
  w.sides[0] = a;
  w.sides[1] = b;
}

int getOffset(size2d s, pos2d p)
{
  if (p.x >= s.w || p.x < 0 || p.y >= s.h || p.y < 0) {
    return -1; //error
  } // implicit else
  return ((p.y * s.w) + p.x);
}

cell *getCell(maze *m, pos2d position)
{
  int offset = getOffset(m->size, position);
  if (offset == -1) {
    return NULL:
  } // implicit else
  return m->cells[offset];
}

void dealocateMaze(maze *m)
{
  //TODO: finish this
}
