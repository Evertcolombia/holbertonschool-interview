#ifndef GAME_LINE
#define GAME_LINE

#include <stdbool.h>
#include <stdio.h>

#ifndef SLIDE_LEFT
#define SLIDE_LEFT 0

#ifndef SLIDE_RIGHT
#define SLIDE_RIGHT 1

int slide_line(int *line, size_t size, int direction);

#endif /* SLIDE_RIGHT */
#endif /* SLIDE_LEFT */
#endif /* GAME_LINE */
