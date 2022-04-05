#include <iostream>
#include "registration.h"
#include <fstream>

void writeToFile(const Image &im, string filename)
{
  ofstream MyFile(filename + ".pgm");
  MyFile << "P2 " << im.nrows() <<" "<< im.ncols()<< " 255\n";
  for (int i=0;i<im.nrows();i++)
    {
      for (int j=0;im.ncols();j++)
        {
          MyFile << im.im[i][j] << " ";
        }
    }
  MyFile.close();
}