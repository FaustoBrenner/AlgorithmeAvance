#include "registration.h"
#include <math.h>
#include "nr3.h"

int main()
{   int q;
    std::cout << "1";
    std::cin >> q;
    
    // Read images from files
    Image *I_float = new Image("data/floating.pgm");
    const Image* I_ref = new Image("data/reference.pgm");

    std::cout << "2";
    // Define parameters
    Parameters params(10,10,45);


    std::cout << "3";
    // Applies transform
    Transform* T = new MyTransform();
    InterpolationFunction* IntFunc = new MyInterpolationFunction();
    Image I_result;

    std::cout << "4";

    I_float->deform(I_result, params, IntFunc, T);
    writeToFile(I_result.im,"result.pgm");

    std::cout << "5";
    // Test Cost Function
    SimilarityCriterium* SimCrit = new MySimilarityCriterium();
    CostFunction Cost(I_float, I_ref, SimCrit, IntFunc, T);

    std::cout << "6";
    double cost = Cost(params.toVecDoub());
    std::cout << "Cost is " << cost;

    
    //run(inParams, outParams, *cost);

    return 1;
}