#ifndef MAZE_DEFS
#define MAZE_DEFS
#include <stddef.h>
#include <stdbool.h>

typedef struct size2d {
  size_t w, h;
} size2d;

typedef struct pos2d {
  int x, y;
} pos2d;

typedef struct cell {
  struct cell *parent;
} cell;

typedef struct wall {
  struct cell sides[2];
  struct pos2d pos;
  bool active;
} wall;

typedef struct maze {
  struct size2d size;
  size_t num_cells, num_walls;
  struct cell *cells;
  struct walls *walls;
} maze;

inline size_t computeArea(size2d *point)
{
  return point->w * point->h;
}

//maze-operations.c
cell *getParent(cell *c);
bool try_destroy(wall *w); // returnes if a wall was destroied
void clearMazeCells(maze *m);

//maze-allocation.c
maze *allocateMaze(size2d requestedSize);
void dealocateMaze(maze *m);
int calculateWallCount(size2d size);

//TODO: initalize walls
//TODO: draw maze
//TODO: make and draw maze
#endif
