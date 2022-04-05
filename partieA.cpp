#include <iostream>
#include <fstream>
#include <string>
#include "registration.h"
#include "nr3.h"

// Structure Point
Point::Point(VecDoub point)
{
  x = point[0];
  y = point[1];
}

Point::Point(int a, int b)
{ 
  x = a;
  y = b;
}

VecDoub Point::toVecDoub() const
{
  VecDoub vec = VecDoub(2);
  vec[0] = x;
  vec[1] = y;
  return vec;
}

// Structure Parameters
Parameters::Parameters(VecDoub params)
{
  tx = params[0];
  ty = params[1];
  theta = params[2];
}

Parameters::Parameters(double tx, double ty, double theta)
{
  this->tx = tx;
  this->ty = ty;
  this->theta = theta;
}

VecDoub Parameters::toVecDoub() const
{
  VecDoub vec = VecDoub(3);
  vec[0] = tx;
  vec[1] = ty;
  vec[2] = theta;
  return vec;
}

// Fonction readFromFile
void readFromFile(MatDoub &im, string filename)
{
  ifstream infile(filename); // ouverture de l'image .pgm

  // On récupère les dimensions de l'image
  string line;
  getline (infile, line);    // récupère la 1è ligne et la met dans line
  char del = ' ';
  vector<string> words{};
  stringstream sstream(line);
  string word;
  while (std::getline(sstream, word, del)) //parse la 1è ligne suivant les délimiteurs del 
  {
    words.push_back(word); // chaque mot de la ligne est mis dans la liste words
  }

  int n = stoi(words[1]); // nombre de lignes 
  int m = stoi(words[2]); // nombre de colonnes 
  im.resize(n, m); // on met l'image à la bonne taille

  // On récupère les valeurs des chaque pixel
  stringstream ss;
  ss << infile.rdbuf();

  for(int i = 0; i < n; ++i)
  {
    for (int j = 0; j < m; ++j)
    {
      ss >> im[i][j];
    }
  }

  // On ferme le fichier
  infile.close();
}