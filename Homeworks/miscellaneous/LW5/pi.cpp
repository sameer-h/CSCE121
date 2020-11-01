#include <cstdlib>
#include <cmath>
#include "pi.h"

using namespace std;

double approx_pi(const unsigned seed, unsigned n) {
   // seed the random number generator
    srand(seed);
    int hits = 0;
    double x, y, area;
    // simulate the dart-throwing process
    // estimate the area of the quadrant
    // estimate the value of pi
    // return the estimated value of pi
    for(int i = 0; i < n; i++){
        x = static_cast<double>(rand())/RAND_MAX;
        y = static_cast<double>(rand())/RAND_MAX;
        if(sqrt(x*x + y*y) < 1){
            hits++;
        }
    }
    area = static_cast<double>(hits)/n;
    return area*4;
}
