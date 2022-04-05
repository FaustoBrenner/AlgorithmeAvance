#include <math.h>
#include "../include/registration.h"
#include "../include/nr3.h"

int main()
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
    
    // Estimate the transformation between the images
    run(inParams, outParams, myCostFunction);

    // Apply the estimated transformation to the non-reference image
    Image finalImg;
    I_float->deform(finalImg, outParams, IntFunc, T);
    writeToFile(finalImg.im, "data/final.pgm");

    std::cout << outParams.toVecDoub()[0] << std::endl;
    std::cout << outParams.toVecDoub()[1] << std::endl;
    std::cout << outParams.toVecDoub()[2] << std::endl;

    return 1;
}