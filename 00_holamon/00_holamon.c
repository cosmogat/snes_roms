/* 30-10-2014 */
/* billy */
/* 00_holamon.c */
#include <snes.h>

extern char snesfont;

int main (void) {
  consoleInit();
  consoleInitText(0, 0, &snesfont);
  consoleDrawText(10, 10, "Hola mon!");

  setMode(BG_MODE1,0);
  bgSetDisable(1);
  bgSetDisable(2);
  setBrightness(0xF);  
	
  while(1) {
    WaitForVBlank();
  }
  return 0;
}
