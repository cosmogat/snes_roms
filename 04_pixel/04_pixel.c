/* 01-11-2014 */
/* billy */
/* 04_pixel.c */
#include <snes.h>

extern char p0;

int main (void) {
  int i, j;

  consoleInit();

  pixSetMode(&p0);
  for (i = 0; i < 256; i += 3)
    for (j = 0; j < 224; j += 3)
      pixSetPixel(i, j, (i + j) % 4);

  while (1)
    WaitForVBlank();

  return 0;
}
