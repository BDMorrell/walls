#include "maze-defs.h"
#include <string.h>

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
