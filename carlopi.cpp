#include <iostream>
#include <pthread.h>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

// Variables globales
long long total_points;
int num_threads;
long long *counts; // resultados parciales por hilo

// Función de los hilos
void* montecarlo(void* arg) {
    long long thread_id = (long long) arg;
    unsigned int seed = time(NULL) ^ thread_id; // semilla única por hilo

    long long points_per_thread = total_points / num_threads;
    long long local_count = 0;

    for (long long i = 0; i < points_per_thread; i++) {
        double x = (double) rand_r(&seed) / RAND_MAX;
        double y = (double) rand_r(&seed) / RAND_MAX;
        if (x*x + y*y <= 1.0)
            local_count++;
    }

    counts[thread_id] = local_count;
    pthread_exit(NULL);
}

int main(int argc, char* argv[]) {
    if (argc < 3) {
        cerr << "Uso: " << argv[0] << " <numero_de_puntos> <numero_de_hilos>\n";
        return 1;
    }

    total_points = atoll(argv[1]);
    num_threads = atoi(argv[2]);
    counts = new long long[num_threads];

    pthread_t threads[num_threads];

    clock_t start = clock();

    // Crear hilos
    for (long long i = 0; i < num_threads; i++) {
        pthread_create(&threads[i], NULL, montecarlo, (void*) i);
    }

    // Esperar hilos
    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    // Combinar resultados
    long long total_in_circle = 0;
    for (int i = 0; i < num_threads; i++) {
        total_in_circle += counts[i];
    }

    double pi = 4.0 * (double) total_in_circle / (double) total_points;

    clock_t end = clock();
    double tiempo = double(end - start) / CLOCKS_PER_SEC;

    cout.precision(15);
    cout << "Aproximacion de pi = " << pi << endl;
    cout << "Error absoluto    = " << fabs(M_PI - pi) << endl;
    cout << "Tiempo CPU (s)    = " << tiempo << endl;

    delete[] counts;
    return 0;
}
