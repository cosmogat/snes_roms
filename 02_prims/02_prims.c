/* 30-10-2014 */
/* billy */
/* 02_prims.c */
#include <snes.h>

extern char snesfont;

int esPrim(int);

int main (void) {
  int i, num, fins = 10000;
  char cad1[40], cad2[40];

  consoleInit();
  consoleInitText(0, 0, &snesfont);
  consoleDrawText(0, 5, "Calculant nombres prims...");

  setMode(BG_MODE1,0);
  bgSetDisable(1);
  bgSetDisable(2);
  setBrightness(0xF);  
	
  while(1) {
    num = 0;
    for (i = 2; i < fins; i++)
      if (esPrim(i) != 0) {
	num++;
	sprintf(cad1, "Ultim nombre prim trobat: %d", i);
	sprintf(cad2, "Nombres prims trobats: %d", num);
	consoleDrawText(0, 10, cad1);
	consoleDrawText(0, 15, cad2);
      }
    WaitForVBlank();
  }
  return 0;
}

int esPrim(int n) {
  int d;
  /* for (d = 3; (d * d) <= n; d+= 2) */
  /*   if (n % d == 0) */
  /*     return 0; */
  /* return 1; */
  for (d = 2; d < (n / 2); d++)
    if (n % d == 0)
      return 0;
  return 1;
}
