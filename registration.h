#include "nr3.h"
#include "amoeba.h"

class Image;
class Transform;
class InterpolationFunction;
class SimilarityCriterium;

struct Point
{
    int x, y;
    Point(int a, int b);
    Point(VecDoub point);
    VecDoub toVecDoub() const;
};

struct Parameters
{
    double tx, ty, theta;
    Parameters(double tx, double ty, double theta);
    Parameters(VecDoub params);
    VecDoub toVecDoub() const;
};

class Image
{
public:
    MatDoub im;
    MatDoub mask;

    Image();
    Image(string filename);
    Image(int rows, int cols);

    int nrows () const;
    int ncols () const;

    void setMask(int row, int col, double value);

    bool isValidPoint(int row, int col) const;
    void deform(Image &outImg, const Parameters &param, InterpolationFunction *interpolation, Transform *transform) const;
};

void readFromFile(MatDoub &im, string filename);
void writeToFile(const MatDoub &im, string filename);
 
// Abstract function classes
class Transform
{
    public : 
	virtual Point operator () (Point p, const Parameters &param) const = 0;
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
	Point operator () (Point p, const Parameters &param) const;
};

class MySimilarityCriterium : SimilarityCriterium
{
public :
	double operator () (const Image &im1, const Image &im2) const;
};

class MyInterpolationFunction : InterpolationFunction
{
public :
	double operator () (const Image &image, const Point &p, int &OK) const;
};

class CostFunction
{
private :
    const Image *I;
    const Image *Iref;
    SimilarityCriterium *similarity;
    InterpolationFunction *interpolation;
    Transform *transform;
public :
    CostFunction(const Image *I, const Image *Iref, SimilarityCriterium *similarity, InterpolationFunction *interpolation, Transform *transform);
	double operator () (const Parameters &param);
};

// in : images I and Iref, and cost, similarity and interpolation functions
// out : estimated parameters outParam
void run(const Parameters &inParam, Parameters &outParam, CostFunction costFunc);
