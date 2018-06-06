/* 31-10-2014 */
/* billy */
/* 03_mates.c */
#include <snes.h>
//#include <float.h>

extern char snesfont;

int main (void) {
  int i, j, k;
  float a = 0.0, aux = 0.0;
  char cad[20];

  consoleInit();
  consoleInitText(0, 0, &snesfont);
  consoleDrawText(0, 1, "Calculs...");

  consoleDrawText(0, 3, "Multiplicacio");
  for (i = 0; i <= 10; i++) {
    j = 10 * i;
    sprintf(cad, "10 x %d = %d", i, j);
    consoleDrawText(0, 4 + i, cad);
  }
  consoleDrawText(0, 16, "Modul");
  for (i = 0; i <= 10; i++) {
    j = i % 5;
    sprintf(cad, "%d mod 5 = %d", i, j);
    consoleDrawText(0, 17 + i, cad);   
  }
  consoleDrawText(17, 3, "Divisio real");
  for (i = 0; i <= 10; i++) {
    a = 10 / ((float) i);
    j = (int) a;
    aux = a - j;
    k = (int) (aux * 1000);
    sprintf(cad, "10 / %d = %d.%03d", i, j, k);
    consoleDrawText(17, 4 + i, cad);   
  }
  consoleDrawText(17, 16, "Divisio entera");
  for (i = 0; i <= 10; i++) {
    j = 10 / i;
    sprintf(cad, "10 / %d = %d", i, j);
    consoleDrawText(17, 17 + i, cad);   
  }
  for (j = 3; j < 28; j++)
    consoleDrawText(15, j, "|");
  for (i = 0; i < 32; i++) {
    consoleDrawText(i, 2, "-");
    consoleDrawText(i, 15, "-");
  }

  setMode(BG_MODE1,0);
  bgSetDisable(1);
  bgSetDisable(2);
  setBrightness(0xF);  
	
  while(1) {
    WaitForVBlank();
  }
  return 0;
}
