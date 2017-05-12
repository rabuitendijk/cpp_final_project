#include <iostream>
#include <cstring>

#include "mVector.h"
#include "mMatrix.h"
#include "mMath.h"
#include "cg.cxx"

class Heat1D{
public:
    Heat1D() : alpha(1), dt(.1), n(0), M(0,0){}
    Heat1D(double _alpha, double _dt, int _n) : alpha(_alpha), dt(_dt), n(_n), M(_n, _n){
        
    }
    
private:
    double alpha;
    double dt;
    int n;
    mMatrix<double> M;
    
};