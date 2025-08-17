#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cerr << "Uso: " << argv[0] << " <numero_de_lanzamientos>\n";
        return 1;
    }

    long long n = atoll(argv[1]);  // número de puntos aleatorios
    long long count_in_circle = 0;

    // Semilla aleatoria
    srand(time(NULL));

    clock_t start = clock();

    for (long long i = 0; i < n; i++) {
        double x = (double) rand() / RAND_MAX;
        double y = (double) rand() / RAND_MAX;

        if (x*x + y*y <= 1.0)
            count_in_circle++;
    }

    double pi = 4.0 * (double) count_in_circle / (double) n;

    clock_t end = clock();
    double tiempo = double(end - start) / CLOCKS_PER_SEC;

    cout.precision(15);
    cout << "Aproximacion de pi = " << pi << endl;
    cout << "Error absoluto    = " << fabs(M_PI - pi) << endl;
    cout << "Tiempo CPU (s)    = " << tiempo << endl;

    return 0;
}
