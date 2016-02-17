#include <stdio.h>
#include <stdlib.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"

//Insert your line algorithm here
void draw_line(int x0, int y0, int x1, int y1, screen s, color c) {
  // *_Algorithm_* (Octant 2)
  //   (x_o, y_o) -> (x_1, y_1)
  //   x=x_o, y=y_o
  //   A = y_1 - y_o, B = -(x_1 - x_o)
  //   d = A + 2B
  //   while(y \leq y_1)
  //     plot (x, y)
  //     if (d<0)
  //       x+=1
  //       d+=2A
  //     y+=1
  //     d+=2B
  if (!(x1>x0))
    return;
  if (!((y1-y0)/(x1-x0)>=1))
    return;
  //OCTANT II
  int x = x0;
  int y = y0;
  int A = y1-y0;
  int B = -(x1-x0);
  int d = A+2*B;
  while(y <= y1){
    plot(s,c,x,y);
    if (d<0){
      x+=1;
      d+=2*A;
    }
    y+=1;
    d+=2*B;
  }

}
