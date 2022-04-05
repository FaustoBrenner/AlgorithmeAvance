#include "registration.h"
#include <math.h>
#include "nr3.h"

void main()
{
    Image* I_float = new Image("data/floating.pgm");
    const Image* I_ref = new Image("data/reference.pgm");

    const Parameters inParams = Parameters(0,0,0);
    Parameters outParams = Parameters(0,0,0);

    SimilarityCriterium* SimCrit = new MySimilarityCriterium();
    InterpolationFunction* IntFunc = new MyInterpolationFunction();
    Transform* T = new MyTransform();

    CostFunction myCostFunction = CostFunction(I_float, I_ref, SimCrit, IntFunc, T);
    //run()
    
}