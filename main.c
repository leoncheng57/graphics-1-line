#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"

int main() {

  screen s;
  color c;


  c.red = 0;
  c.green = MAX_COLOR;
  c.blue = 0;

  clear_screen(s);

  int i, j;
  j=YRES;
  for (i=0; i<=XRES; i+=20){
    draw_line(0, 0, i, j, s, c);
    c.red = (c.red+20)%255;
    c.green = (c.green+10)%255;
  }
  i=XRES;
  for (j=0; j<=YRES; j+=20){
    draw_line(0, 0, i, j, s, c);
    c.red = (c.red+20)%255;
    c.blue = (c.blue+10)%255;
  }



  c.red = MAX_COLOR;
  c.green = 0;
  c.blue = 0;

  int x0, y0, x1, y1;
  x0 = 0;
  y0 = YRES/2;
  x1 = 0;
  y1 = YRES;
  while(y0<=YRES){
    draw_line(x0, y0, x1, y1, s, c);
    y0+=5;
    x1+=5;
    c.red = (c.red+2)%255;
    c.blue = (c.blue+7)%255;
    c.green = (c.green+5)%255;
  }
  


/*   DW TEST CODE BELOW    */
/*
  //octant 1
  draw_line( 0, 0, XRES-1, YRES - 75, s, c);
  //octant 2
  draw_line( 0, 0, XRES - 75, YRES-1, s, c);
  // octant 8
  draw_line( 0, YRES-1, XRES-1, 75, s, c);
  //octant 7
  draw_line( 0, YRES-1, XRES - 75, 0, s, c);

  c.green = 0;
  c.blue = MAX_COLOR;
  //octant 5
  draw_line( XRES - 1, YRES - 1, 0, 75, s, c);
  //octant 6
  draw_line( XRES - 1, YRES -1, 75, 0, s, c);
  //octant 4
  draw_line( XRES - 1, 0, 0, YRES - 75, s, c);
  //octant 3
  draw_line( XRES - 1, 0, 75, YRES - 1, s, c);

  c.blue = 0;
  c.red = MAX_COLOR;
  //y = x, y = -x
  draw_line( 0, 0, XRES - 1, YRES - 1, s, c);
  draw_line( 0, YRES - 1, XRES - 1, 0, s, c);

  //horizontal, vertical line
  draw_line( 0, YRES / 2, XRES - 1, YRES / 2, s, c);
  draw_line( XRES / 2, 0, XRES / 2, YRES - 1, s, c);
*/

  display(s);
  save_extension(s, "lines.png");
}
