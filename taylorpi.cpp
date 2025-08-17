#include <iostream>
#include <cmath>
#include <ctime>   // para medir tiempo con clock()

using namespace std;

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cerr << "Uso: " << argv[0] << " <numero_de_iteraciones>\n";
        return 1;
    }

    long long n = atoll(argv[1]); // número de iteraciones
    double pi = 0.0;
    double sign = 1.0;

    // Medir tiempo de CPU
    clock_t start = clock();

    for (long long k = 0; k < n; k++) {
        pi += sign / (2.0 * k + 1.0);
        sign = -sign;  // alterna entre positivo y negativo
    }

    pi *= 4.0;

    clock_t end = clock();
    double tiempo = double(end - start) / CLOCKS_PER_SEC;

    cout.precision(15);
    cout << "Aproximacion de pi = " << pi << endl;
    cout << "Error absoluto    = " << fabs(M_PI - pi) << endl;
    cout << "Tiempo CPU (s)    = " << tiempo << endl;

    return 0;
}
