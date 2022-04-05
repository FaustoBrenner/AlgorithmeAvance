//Gestion des images
typedef struct 
  {  
    double** data;
    int width;
    int height;
  }Image;
Image* allocImage(int width  ,
                  int height);
void desallocImage(Image *);
Image* readFromFile(char* fileName); //utilisation de allocImage
void writeInFile(char* fileName, 
                 Image *       );

//Interpolation: compute the value of image im at coordinate (x,y), OK=false if coordinate outside the support of the image
double interpole(Image *im, 
                 double x ,
                 double y , 
                 int *OK  );

//Apply transformation: xres,yres is obtained by applying the transfo to (x,y) with param the transformation parameters
void applyTransfo(double* param, 
                  double x     ,
                  double y     , 
                  double *xres , 
                  double *yres);

//Deformation de l'image im suivant la transformation rigide de parametre param. Le resultat est mis dans resDeforme et resMask (qui sont supposes alloues et de taille convenable)
void DeformImage(Image* im        , 
                 Image* resDeforme,  
                 Image* resMask   , 
                 double* param   );
//utilise interpole et applyTransfo

//calcule du critere de similarite
double ComputeSimilarity(Image * im1   ,
                         Image * mask1 ,
                         Image * im2   ,
                         Image * mask2);

//calcul de la fonction de cout (les images I et Iref sont de meme taille)
double costFunction(Image *I      , 
                    Image *Iref   ,  
                    double* param);
//utilise la fonction allocImage pour creer 2 images de meme taille que I ou Iref
//utilise la fonction DeformImage 
//utilise la fonction ComputeSimilarity
//utilise la fonction desallocImage pour les deux images prealablement creees

//Algo d'optimisation. On est oblige de passer Iref et I a la fonction optimize pour pouvoir utiliser la fonction de cout "f"
//les parametres optimaux sont mis dans paramRes
//!! pas tres generique si l'on veut reutiliser la methode d'optimisation! Ce sera plus simple en C++
void optimize( double (*f)(Image *I, Image *Iref,  double* param),
               Image *I                                          ,
               Image *Iref                                       , 
               double *paramRes                                 ); 

//Algo de recalage. Les parametres optimaux sont mis dans paramRes (les images I et Iref sont de meme taille)
void recalage(Image *I        , 
              Image *Iref     ,
              double *paramRes)
//Utilisation de la fonction optimize 

