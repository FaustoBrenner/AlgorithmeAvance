#include <iostream>
using namespace std;

//template
template <class Function,class TypeEntree,class TypeSortie> 
	TypeEntree optimize (Function &f,TypeEntree min, TypeEntree max)
{

TypeEntree res = min;
TypeSortie minFunction = f(min);
TypeSortie c;
for (int i=1;i<11;i++)
	{
	TypeEntree b = min + i * (max-min)/10;	
	c = f(b);
	if (c<minFunction)
		{
		minFunction = c;
		res = b;
		}
	}
return res;
}

//heritage
class function
{
   public : 
	virtual double operator () (double) const = 0;
};

class monFoncteur : public function
{
public :
	double operator () (double value) const {return (value-2)*(value-2);}
};


double optimize2( const function & f, double min, double max)
{
double res = min;
double minFunction = f(min);
double c;
for (int i=1;i<11;i++)
	{
	double b = min + i * (max-min)/10;	
	c = f(b);
	if (c<minFunction)
		{
		minFunction = c;
		res = b;
		}
	}
return res;
}


double optimizeC( double (*f)(double), double min, double max)
{
double res = min;
double minFunction = f(min);
double c;
for (int i=1;i<11;i++)
	{
	double b = min + i * (max-min)/10;	
	c = f(b);
	if (c<minFunction)
		{
		minFunction = c;
		res = b;
		}
	}
return res;
}

double myFunction(double value)
{
    return (value-2)*(value-2);
}

int main()
{
monFoncteur f;
double res = optimize<monFoncteur,double,double> (f,0.,10.);
double res2 = optimize2 (f,0.,10.);
double res3 = optimizeC(myFunction,0.,10.);
std::cout << res << " " << res2 << " " << res3 << std::endl;

}
