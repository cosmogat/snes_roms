/* 06-11-2014 */
/* billy */
/* 05_mandelbrot.c */
#include <snes.h>
#define RES_X 256.0
#define RES_Y 224.0
#define LIM   4.0
#define ITER  50
extern char snesfont;
extern char p0;

int main (void) {
  int i, j, k, mandel = 0;
  float min_re = -2.0, max_re = 1.0, min_im = -1.0, max_im = 1.0;
  float tam_re = max_re - min_re;
  float tam_im = max_im - min_im;
  float dif = tam_re / RES_X;
  float c_re = 0.0, c_im = 0.0, z_re = 0.0, z_im = 0.0, real = 0.0, imag = 0.0;
  int resolucio_y = (int) ((tam_im / tam_re) * RES_X);

  consoleInit();
  pixSetMode(&p0);

  for (i = 0; i < RES_X; i = i + 1)
    for (j = 0; j < resolucio_y; j = j + 1) {
      mandel = 0;
      c_re = min_re + (dif * i);
      c_im = min_im + (dif * j);
      z_re = z_im = 0.0;
      k = 0;
      while ((k < ITER) && (mandel == 0)) {
	real = (z_re * z_re) - (z_im * z_im);
	imag = (z_re * z_im) + (z_im * z_re);
	z_re = real + c_re;
	z_im = imag + c_im;
	if (((z_re * z_re) + (z_im * z_im)) > LIM)
	  mandel = 1;  
	k++;
      }
      if (mandel == 0)
	pixSetPixel(i, j, 2);
      else
	pixSetPixel(i, j, 3);
    }

  while (1)
    WaitForVBlank();
 
  return 0;
}
