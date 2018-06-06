/* 30-10-2014 */
/* billy */
/* 01_input.c */
#include <snes.h>

extern char snesfont;

int main (void) {
  unsigned short pad0;
  unsigned short pausa = 0;
  int x = 0, y = 0;
  char cad[16];

  consoleInit();
  consoleInitText(0, 0, &snesfont);

  setMode(BG_MODE1,0);
  bgSetDisable(1);
  bgSetDisable(2);

  setBrightness(0xF);

  while(1) {
    pad0 = padsCurrent(0); //Agafem el mando 0
    consoleDrawText(x, y, " ");
    sprintf(cad, "x = %.2d, y = %.2d", x, y);
    consoleDrawText(0, 1, cad);
    if (pausa == 0)
      consoleDrawText(0, 2, "          ");
    else
      consoleDrawText(0, 2, "Joc pausat");

    switch (pad0) {
    case KEY_RIGHT:
      if ((x < 31) && (pausa == 0))
	x = x + 1;
      consoleDrawText(x, y, "+");
      break;
    case KEY_LEFT:
      if ((x > 0) && (pausa == 0))
	x = x - 1;
      consoleDrawText(x, y, "+");
      break;
    case KEY_DOWN:
      if ((y < 27) && (pausa == 0))
	y = y + 1;
      consoleDrawText(x, y, "+");
      break;
    case KEY_UP:
      if ((y > 0) && (pausa == 0))
	y = y - 1;
      consoleDrawText(x, y, "+");
      break;
    case KEY_A: 
      consoleDrawText(x, y, "A");
      break;
    case KEY_B: 
      consoleDrawText(x, y, "B");
      break;
    case KEY_SELECT: 
      x = y = 0;
      break;
    case KEY_START: 
      if (pausa == 0)
	pausa = 1;
      else
	pausa = 0;
      break;
    case KEY_R: 
      consoleDrawText(x, y, "R");
      break;
    case KEY_L: 
      consoleDrawText(x, y, "L");
      break;
    case KEY_X: 
      consoleDrawText(x, y, "X");
      break;
    case KEY_Y: 
      consoleDrawText(x, y, "Y");
      break;
    default: 
      consoleDrawText(x, y, "+");
      break;
    }
    WaitForVBlank();
  }
  return 0;
}
