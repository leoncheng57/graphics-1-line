from display import *

def draw_line( screen, x0, y0, x1, y1, color ):
# *_Algorithm_* (Octant 2)
#   (x_o, y_o) -> (x_1, y_1)
#   x=x_o, y=y_o
#   A = y_1 - y_o, B = -(x_1 - x_o)
#   d = A + 2B
#   while(y \leq y_1)
#     plot (x, y)
#     if (d<0)
#       x+=1
#       d+=2A
#     y+=1
#     d+=2B
#
# draw_line( screen, 0, 0, XRES - 75, YRES - 1, color )
    #Octant 2
    if ((x1>x0)==False):
        return
    if (((y1-y0)/(x1-x0)>1)==False):
        return
    x = x0
    y = y0
    A = y1-y0
    B = -(x1-x0)
    d = A + 2*B
    while(y <= y1):
        plot( screen, color, x, y )
        if (d<0):
            x+=1
            d+=2*A
        y+=1
        d+=2*B
    print("inside draw_line")
    return
