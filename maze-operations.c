#include "maze-defs.h"
#include <string.h>
#include <stdlib.h>

cell *getParent(cell *c)
{
  if (c->parent == NULL) {
    return c;
  }
  return (c->parent = getParent(c->parent)); //update for faster lookups later
}

bool try_destroy(wall *w)
{
  if (w->active == false) { // if the wall is already destroied
    return false;
  }
  cell *first_group = getParent(&(w->sides[0]));
  if (first_group != getParent(&(w->sides[1]))) { // if different group
    w->active = false;
    first_group->parent = w->sides[0].parent;
    return true;
  }
  return false;
}

void clearMazeCells(maze *m)
{
  // maybe this would be better ot just loop?
  memset(m->cells, 0, (sizeof(cell) * m->num_cells));
}

void completeMaze(maze *m)
{
  //TODO: make biasing mazes a thing
  wall **wallsToTest = malloc(sizeof(wall *) * m->num_walls);
  int i;
  for (i = 0; i < m->num_walls; i++) {
    wallsToTest[i] = &(m->walls[i]);
  }
  // There may be better, *provably* random algorithms to shuffle
  qsort(wallsToTest, m->num_walls, sizeof(wall *), randomCompare);
  for (i = 0; i < m->num_walls; i++) {
    try_destroy(wallsToTest[i]);
  }

  free(wallsToTest);
}

int randomCompare(const void *a, const void *b)
{
  return rand() % 2;
}

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
