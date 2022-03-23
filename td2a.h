//Partie prog. procedurale : tout est pareil sauf que : 

//la fonction DeformImage recoit maintenant une fonction d'interpolation
void DeformImage(Image* im                                  , 
	         Image* resDeforme                          , 
                 Image* resMask                             ,  
                 double* param                              , 
                 double (*inter)(Image*,double,double,int*));


//costFunction recoit maintenant  une fonction d'interpolation et un critere de similarite
double costFunction(Image *I                                       , 
                    Image *Iref                                    ,  
                    double* param                                  ,
                    double (*sim) (Image *,Image *,Image *,Image *),
	            double (*inter)(Image*,double,double,int*)    );


//la fonction optimize recoit maintenant  une fonction d'interpolation et un critere de similarite. De plus, le premier argument est modifie car il doit correspondre au prototype de la fonction costFunction (attention aux yeux!!) -> vive le C++!
void optimize(  
          double (*f)(Image *I                                       , 
                      Image *Iref                                    ,
                      double* param                                  ,
                      double (*sim) (Image *,Image *,Image *,Image *),
                      double (*inter)(Image*,double,double,int*)   ) ,
	  Image *I                                                   ,
	  Image *Iref                                                , 
	  double *paramRes                                           ,
	  double (*sim) (Image *,Image *,Image *,Image *)            ,
          double (*inter)(Image*,double,double,int*)                ); 

//la fonction recalage recoit maintenant  une fonction d'interpolation et un critere de similarite
void recalage(Image *I                                       , 
              Image *Iref                                    ,
	      double *paramRes                               ,
	      double (*sim) (Image *,Image *,Image *,Image *),
	      double (*inter)(Image*,double,double,int*)    );








          



















