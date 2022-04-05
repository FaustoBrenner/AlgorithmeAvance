#include "registration.h"
#include <math.h>
#include "nr3.h"

void main()
{
    // Read images from files
    Image* I_float = new Image("data/floating.pgm");
    const Image* I_ref = new Image("data/reference.pgm");

    // Define starting parameters
    const Parameters inParams = Parameters(0,0,0);
    Parameters outParams = Parameters(0,0,0);

    // Defines 
    SimilarityCriterium* SimCrit = new MySimilarityCriterium();
    InterpolationFunction* IntFunc = new MyInterpolationFunction();
    Transform* T = new MyTransform();

    CostFunction myCostFunction(I_float, I_ref, SimCrit, IntFunc, T);
    //run()
    
}