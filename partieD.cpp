#include "registration.h"
#include <cmath>


double MySimilarityCriterium::operator () (const Image &im1, const Image &im2)
{
    double sum = 0;

    const int rows = im1.nrows();
    const int cols = im1.ncols();

    for (int row = 0; row < rows; row++)
    {
        for (int col = 0; col < cols; col++)
        {
            if (im1.isValidPoint(row,col) && im2.isValidPoint(row,col))
            {
                sum += std::pow(im1.im[row,col] - im2.im[row,col], 2);
            }
        }
    }

    return sum / (rows*cols);
}

CostFunction::CostFunction(const Image *I, const Image *Iref, SimilarityCriterium *similarity, InterpolationFunction *interpolation, Transform *transform)
{
    this->I = I;
    this->Iref = Iref;
    this->similarity = similarity;
    this->interpolation = interpolation;
    this->transform = transform;
}

double CostFunction::operator() (const Parameters &param)
{
    Image Idef;
    I->deform(Idef, param, interpolation, transform);
    return (*similarity)(*Iref, Idef);
}