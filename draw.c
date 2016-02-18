#include <stdio.h>
#include <stdlib.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"

//Insert your line algorithm here
void draw_line(int x0, int y0, int x1, int y1, screen s, color c) {

  int x, y, A, B, d;
  float m;

  //Switch coors
  if (!(x1>x0)){
    int tx, ty;
    tx = x0; ty = y0;
    x0 = x1; y0 = y1;
    x1 = tx; y1 = ty;
  }

  //Vertical line, octants II and VII
  if ((x1-x0)==0){
    x = x0; y = y0;
    A = y1-y0; B = -(x1-x0);
    d = A+2*B;
    while(y <= y1){
      plot(s,c,x,y);
      y+=1;
      d+=2*B;
    }
    x = x0; y = y0;
    A = y1-y0; B = -(x1-x0);
    d = A-2*B;
    while(y >= y1){
      plot(s,c,x,y);
      y-=1;
      d-=2*B;
    }
    return;
  }

  m = ((float)(y1-y0))/((float)(x1-x0));

  //OCTANT I, V
  if ((m <= 1 && m >= 0)){
    x = x0; y = y0;
    A = y1-y0; B = -(x1-x0);
    d = 2*A + B;
    while(x <= x1){
      plot(s, c, x, y);
      if (d>0){
	y+=1;
	d+=2*B;
      }
      x+=1;
      d+=2*A;
    }
  }

  //OCTANT II, VI
  if ((m >= 1)){
    x = x0; y = y0;
    A = y1-y0; B = -(x1-x0);
    d = A+2*B;
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

  //OCTANT VIII, IV
  if ((m >= -1 && m <= 0 )){
    x = x0; y = y0;
    A = y1-y0; B = -(x1-x0);
    d = 2*A-B;
    while(x <= x1){
      plot(s,c,x,y);
      if (d<0){
	y-=1;
	d-=2*B;
      }
      x+=1;
      d+=2*A;
    }
  }

  //OCTANT VII, III
  if ((m <= -1 )){
    x = x0; y = y0;
    A = y1-y0; B = -(x1-x0);
    d = A-2*B;
    while(y >= y1){
      plot(s,c,x,y);
      if (d>0){
	x+=1;
	d+=2*A;
      }
      y-=1;
      d-=2*B;
    }
  }

}
