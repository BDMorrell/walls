#ifndef MAZE_DEFS
#include <stddef.h>
#include <stdbool.h>
#include <stdio.h>

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
  struct pos2d pos; // TODO: This may not be needed
  bool active;
} wall;

typedef struct maze {
  struct size2d size;
  size_t num_cells, num_walls;
  struct cell *cells;
  struct wall *walls;
} maze;

// Assumptions:
// We're going to be drawing a rectangular grid maze.
// It's going to be drawn in quadrant 4; left to right then top to bottom.

static inline size_t computeArea(size2d *point)
{
  return point->w * point->h;
}
//maze-operations.c
cell *getParent(cell *c);
bool try_destroy(wall *w); // returnes if a wall was destroied
void clearMazeCells(maze *m);
void completeMaze(maze *m);
void printMaze(maze *m, FILE *stream);
int randomCompare(const void *a, const void *b);
void *mempattern(void * destination, size_t destinationSize, void * source, size_t sourceSize);
char *generatePatternString(size_t requestedSize, char *source, size_t sourceSize);

//maze-allocation.c
maze *allocateMaze(size2d requestedSize);
void deallocateMaze(maze *m);
int calculateWallCount(size2d size);
void initializeWalls(maze *m);
void initWall(wall *w, cell *a, cell *b);
int getOffset(size2d s, int x, int y);
cell *getCell(maze *m, int x, int y);

//TODO: add edge conditions
//TODO: get wall destruction priorites in check
#define MAZE_DEFS
#endif
