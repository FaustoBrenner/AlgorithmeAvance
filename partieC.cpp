#include "registration.h"
#include <math.h>
#include "nr3.h"

#define PI 3.14159265

Point MyTransform :: operator () (Point p, const Parameters &param)
{
    int new_x = (int) param.tx
                        + p.x*cos(param.theta*PI/180) - 
                        - p.y*sin(param.theta*PI/180);

    int new_y = (int) param.ty
                        + p.y*cos(param.theta*PI/180) - 
                        + p.x*sin(param.theta*PI/180);
    
    Point new_p = Point(new_x, new_y);

    return new_p;
}

void run(const Image &I, const Image &Iref, const Parameters &inParam, Parameters &outParam, 
CostFunction costFunc, SimilarityCriterium *similarity, InterpolationFunction *interpolation)
{
    Amoeba opt(0.01);
    VecDoub finalParam(3);
    finalParam = opt.minimize(inParam.toVecDoub(), 3., costFunc);
    outParam = Parameters(finalParam);
}

