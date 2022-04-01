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
    MatDoub im;
    MatDoub mask;

    Image(string filename);
    Image(int rows, int cols);

    int nrows();
    int ncols();

    void deform(Image &outImg, const Parameters &param, InterpolationFunction *interpolation, Transform *transform);
};

void readFromFile(Image &im, string filename);
void writeToFile(const Image &im, string filename);
 
// Abstract function classes
class Transform
{
    public : 
	virtual void operator () (Point p, const Parameters &param) const = 0;
};

class SimilarityCriterium
{
    public : 
	virtual double operator () (const Image &im1, const Image &im2) const = 0;
};

class InterpolationFunction
{
    public : 
	virtual double operator () (const Image &image, const Point &p, int &OK) const = 0;
};

// Concrete classes that define the functions we will use
class MyTransform : Transform
{
    public : 
	Point operator () (Point p, const Parameters &param);
};

class MySimilarityCriterium : SimilarityCriterium
{
public :
	double operator () (const Image &im1, const Image &im2);
};

class MyInterpolationFunction : InterpolationFunction
{
public :
	double operator () (const Image &image, const Point &p, int &OK);
};

class CostFunction
{
public :
    CostFunction(const Image &I, const Image &Iref, SimilarityCriterium *similarity);
	double operator () (const Parameters &param);
};

// in : images I and Iref, and cost, similarity and interpolation functions
// out : estimated parameters outParam
void run(const Image &I, const Image &Iref, const Parameters &inParam, Parameters &outParam, CostFunction costFunc, SimilarityCriterium *similarity, InterpolationFunction *interpolation);
