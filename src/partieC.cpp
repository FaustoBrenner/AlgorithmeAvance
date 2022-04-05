#define _USE_MATH_DEFINES
#include <cmath>
#include "../include/registration.h"
#include "../include/nr3.h"

Point MyTransform :: operator () (Point p, const Parameters &param) const
{
    int new_x = (int) param.tx
                        + p.x*cos(param.theta*M_PI/180)
                        - p.y*sin(param.theta*M_PI/180);

    int new_y = (int) param.ty
                        + p.y*cos(param.theta*M_PI/180)
                        + p.x*sin(param.theta*M_PI/180);
    
    Point new_p = Point(new_x, new_y);

    return new_p;
}

void run(const Parameters &inParam, Parameters &outParam, CostFunction costFunc)
{
    Amoeba opt(0.01);
    VecDoub finalParam(3);
    finalParam = opt.minimize(inParam.toVecDoub(), 3., costFunc);
    outParam = Parameters(finalParam);
}

