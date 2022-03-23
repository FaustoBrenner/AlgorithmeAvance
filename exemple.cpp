#include "nr3.h"
#include "amoeba.h"
#include <iostream>
using namespace std; 
/* exemple d'utilisation pour l'algorithme d'optimisation 
et de la classe NRmatrix (pour contenir des images)*/



void affiche(const NRmatrix<double> &im);

struct monFoncteur
{	
	Doub operator() (const VecDoub& u) const
		{
		return u[0]*u[0]+u[1]*u[1]; //minimisation de la fonction x*x+y*y
		}
};


int main()
{
monFoncteur m;

//0.01 est la taille du simplex minimale avant arrêt de l'algo
Amoeba opt(0.01);

/*Point de départ*/
VecDoub ystart(2);
//Initialisation
ystart[0]=10;
ystart[1]=8;

/*resultat*/
VecDoub yfinal1(2);

yfinal1 = opt.minimize(ystart,2.,m); //2 est la taille du simplex au départ
std::cout << yfinal1[0] << " " << yfinal1[1] << " " << m(yfinal1) << std::endl;



/*Utilisation d'une matrice */

NRmatrix<double> im(2,3,120); //Image de taille 2x3 initialisee avec la constante 10
im[1][2]=12;
affiche(im);
return 1;
}

void affiche(const NRmatrix<double> &im)
{
for (int i=0;i<im.nrows();i++)
 {
  for (int j=0;j<im.ncols();j++)
   cout << im[i][j] << " ";
  cout << endl;
 }
}



