#include <iostream>
#include "../include/registration.h"

Image::Image()
{
  im.assign(1,1,0);
  mask.assign(1,1,0);
  
}


Image::Image(string filename)
{
    readFromFile(im,filename);
    readFromFile(mask,filename);
    mask.assign(mask.nrows(),mask.ncols(),0);
}
Image::Image(int rows, int cols)
{
    im.assign(rows,cols,0);
    mask.assign(rows,cols,0);
}


int Image::nrows() const
{
  return im.nrows();
}
int Image::ncols() const
{
  return im.ncols();
}

bool Image::isValidPoint(int row,int col) const
{
  int val = mask[row][col];
  if (val==1)
    return true;
  else
    return false;
}

void Image::deform(Image &outImg, const Parameters &param, InterpolationFunction *interpolation, Transform *transform) const
{
  outImg.im.resize(nrows(),ncols());
  for (int i=0;i<nrows();i++)
    {for (int j=0;j<ncols();j++)
      {VecDoub vec(i,j);
      Point p(vec);
      Point p_trans = (*transform)(p,param);
      int ok=0;
      outImg.im[i][j] = (*interpolation)(*this,p_trans,ok);
      }
      }
    }
