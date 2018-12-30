#include <stddef.h>
#include <stdbool.h>

typedef struct size2d {
  size_t w, h;
} size2d;

// TODO: change to int2d
typedef struct pos2d {
  int x, y;
} pos2d;

typedef struct cell {
  struct cell *parent;
} cell;

typedef struct wall {
  struct cell sides[2];
  struct pos2d pos; // This may not be needed
  bool active;
} wall;

typedef struct maze {
  struct size2d size;
  size_t num_cells, num_walls;
  struct cell *cells;
  struct wall *walls;
} maze;

inline size_t computeArea(size2d *point)
{
  return point->w * point->h;
}

// Assumptions:
// We're going to be drawing a rectangular grid maze.
// It's going to be drawn in quadrant 4; left to right then top to bottom.

//maze-operations.c
cell *getParent(cell *c);
bool try_destroy(wall *w); // returnes if a wall was destroied
void clearMazeCells(maze *m);

//maze-allocation.c
maze *allocateMaze(size2d requestedSize);
void dealocateMaze(maze *m);
int calculateWallCount(size2d size);
void initializeWalls(maze *m);
void initWall(wall &w, cell *a, cell *b);
int getOffset(size2d s, pos2d p);
cell *getCell(maze *m, pos2d position);

//TODO: get wall destruction priorites in check
//TODO: draw maze
