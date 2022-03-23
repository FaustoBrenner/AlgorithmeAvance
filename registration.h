#include "nr3.h"
#include "amoeba.h"

// Partie II
struct Point
{
    int x, y;
    Point(VecDoub point);
    VecDoub toVecDoub();    
};

// Partie II
struct Parameters
{
    double tx, ty, theta;
    Parameters(VecDoub params);
    void updateAll(double tx, double ty, double theta);
    VecDoub toVecDoub();
};

// Partie I
class Image
{
public:
    NRmatrix<double> im;
    NRmatrix<double> mask;

    Image(string filename);
    Image(int rows, int cols);

    void readFromFile(string filename, NRmatrix<double> &img);
    void writeToFile(string filename);

    int nrows();
    int ncols();

    void deform(NRmatrix<double> &img, Parameters param, InterpolationFunction *interpolation, Transform *trans);

private:
    Point applyTransformation(Point p, Parameters param, Transform *trans);
};

class Transform
{
    public : 
	virtual double operator () (Point p, Parameters param) const = 0;
};

class InterpolationFunction
{
    public : 
	virtual double operator () (Image &image, Point p, int &OK) const = 0;
};

class SimilarityCriterium
{
    public : 
	virtual double operator () (Image &im1, Image &im2) const = 0;
};

class CostFunction
{
    public : 
	virtual double operator () (Parameters param) const = 0;
};

class MyTransform : Transform
{
    public : 
	double operator () (Point p, Parameters param);
};

class MySimilarityCriterium : SimilarityCriterium
{
public :
	double operator () (Image &im1, Image &im2);
};

class MyInterpolationFunction : InterpolationFunction
{
public :
	double operator () (Image image, Point p, int &OK);
};

class MyCostFunction : CostFunction
{
public :
	double operator () (Parameters param);
};

// Partie IV
Parameters optimize(CostFunction *costFunc, Image &I, Image &Iref, Parameters param);

// Partie V
Parameters registration(Image &I, Image &Iref, SimilarityCriterium *similarity, InterpolationFunction *interpolation);


