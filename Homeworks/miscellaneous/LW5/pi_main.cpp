#include <iostream>
#include <iomanip>
#include <limits>
#include "pi.h"

using namespace std;

typedef struct input {
    unsigned seed = 0;
    unsigned n = 1;
} input;

int main() {
    const int MAX_PRECISION = numeric_limits<long double>::digits10 + 1;

    const input inputs[] = {
        // {seed, n}
        {0, 1},
        {0, 10},
        {0, 100}
        // TODO(student): add more input pairs
    };

    // hacky hackery to get number of inputs
    // sizeof(inputs) is the number of bytes allocated for the array
    //   (#elements * sizeof(element))
    // sizeof(input) is the number of bytes required to store a single element
    //   (sizeof(element))
    // #elements * sizeof(element) / sizeof(element) = #elements
    const size_t NUM_INPUTS = sizeof(inputs) / sizeof(input);

    // run through every input pair
    for (size_t i = 0; i < NUM_INPUTS; ++i) {
        // alias for element at index i
        const input& in = inputs[i];

        // aliases for input values
        const unsigned& seed = in.seed;
        const unsigned& n = in.n;

        // print inputs
        cout << "seed = " << seed << ", ";
        cout << "n = " << n << " --> ";

        // print output
        cout << "pi ≈ ";
        cout << setprecision(MAX_PRECISION) << approx_pi(seed, n) << endl;
    }
}
