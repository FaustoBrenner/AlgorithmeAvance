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

    void readFromFile(string filename);
    void writeToFile(string filename);

    int nrows();
    int ncols();

    void deform(Image &outImg, const Parameters &param, InterpolationFunction *interpolation, Transform *transform);
};


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

class CostFunction
{
    public : 
	virtual double operator () (const Parameters &param) const = 0;
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

class MyCostFunction : CostFunction
{
public :
    MyCostFunction(const Image &I, const Image &Iref, SimilarityCriterium *similarity, InterpolationFunction *interpolation);
	double operator () (const Parameters &param);
};

// in : images I and Iref, and cost, similarity and interpolation functions
// out : estimated parameters outParam
void run(const Image &I, const Image &Iref, const Parameters &inParam, Parameters &outParam, MyCostFunction costFunc, SimilarityCriterium *similarity, InterpolationFunction *interpolation);
