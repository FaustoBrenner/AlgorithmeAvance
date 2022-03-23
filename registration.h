#include "nr3.h"
#include "amoeba.h"

struct Point
{
    int x, y;
    Point(VecDoub point);
    VecDoub toVecDoub();
};

struct Parameters
{
    double tx, ty, theta;
    Parameters(VecDoub params);
    void updateAll(double tx, double ty, double theta);
    VecDoub toVecDoub();
};

class Image
{
public:
    NRmatrix im;
    NRmatrix mask;

    Image(string filename);
    Image(int rows, int cols);

    NRmatrix readFromFile(string filename);
    void writeToFile(string filename);

    int nrows();
    int ncols();

    Image deform(Parameters param, InterpolationFunction interpolation);

private:
    Point applyTransformation(Point p, Parameters param);
};



class Function
{
    public : 
	virtual double operator () (double) const = 0;
};

class SimilarityCriterium : Function
{
public :
	double operator () (Image im1, Image im2);
};

class InterpolationFunction : Function
{
public :
	double operator () (Image image, Point p, int *OK);
};

class CostFunction : Function
{
public :
	double operator () (Image I, Image Iref, Parameters param, SimilarityCriterium similarity, InterpolationFunction interpolation);
};

Parameters registration(Image I, Image Iref, SimilarityCriterium similarity, InterpolationFunction interpolation);

Parameters optimize(CostFunction costFunc, Image I, Image Iref, Parameters param);

