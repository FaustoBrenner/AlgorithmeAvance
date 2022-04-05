#include "registration.h"

double MyInterpolationFunction::operator() (const Image &image, const Point &p, int &OK)
{
    int row = image.nrows(),  col = image.ncols();
    double x = p.x, y = p.y, res;

    if(x <0 || x > row-1 || y < 0 || x > col-1)
    {
        OK = 0;
        res = 0;
    }

    else
    {
        OK = 1;
        int i1,i2,j1,j2;
        double dx,dy,dfx,dfy,dfxy;

        i1 = floor(x);
        j1 = floor(y);
      
        if(i1 == row-1)
        {
            i1--;
        }
        if(j1 == col-1)
        {
            j1--;
        }

        i2 = i1 +1;
        j2 = j1+1;
      
        image.setMask(i1,j1,OK);
        image.setMask(i1,j2,OK);
        image.setMask(i2,j1,OK);
        image.setMask(i2,j2,OK);

        dx = x - i1;
        dy = y -j1;
        dfx = image.im[i2][j1] - image.im[i1][j1];
        dfy = image.im[i1][j2] - image.im[i1][j1];
        dfxy = image.im[i1][j1] + image.im[i2][j2] - image.im[i2][j1] - image.im[i1][j2];

        res = image.im[i1][j1] + dfx*dx + dfy*dy + dx*dy*dfxy;
        
    }

    
    return res;
}