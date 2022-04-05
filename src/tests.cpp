#include <math.h>
#include "../include/registration.h"
#include "../include/nr3.h"

int main()
{   int q;
    // std::cin >> q;
    
    // Read images from files
    Image *I_float = new Image("data/floating.pgm");
    const Image* I_ref = new Image("data/reference.pgm");

    // Define parameters
    Parameters params(10,10,45);


    // Applies transform
    Transform* T = new MyTransform();
    InterpolationFunction* IntFunc = new MyInterpolationFunction();
    Image I_result;


    I_float->deform(I_result, params, IntFunc, T);
    writeToFile(I_result.im,"result.pgm");

    // Test Cost Function
    SimilarityCriterium* SimCrit = new MySimilarityCriterium();
    std::cout << (*SimCrit)(*I_ref, I_result) << std::endl;
    CostFunction Cost(I_float, I_ref, SimCrit, IntFunc, T);

    double cost = Cost(params.toVecDoub());
    std::cout << "Cost is " << cost << std::endl;

    
    //run(inParams, outParams, *cost);

    return 1;
}