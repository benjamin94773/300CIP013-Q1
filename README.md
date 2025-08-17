# π Approximation Project

Este proyecto implementa tres métodos diferentes para aproximar el valor de π usando C++:

1. **taylorpi.cpp** – Serie de Taylor (Método de Leibniz).
2. **montepi.cpp** – Método Monte Carlo.
3. **carlopi.cpp** – Método de integración de rectángulos, con soporte para **multithreading (pthreads)**.

---

## 🚀 Compilación

Todos los programas están escritos en C++ y se compilan con `g++`.  
El único que requiere la librería de **pthreads** es `carlopi`.

```bash
# Compilar taylorpi
g++ taylorpi.cpp -o taylorpi

# Compilar montepi
g++ montepi.cpp -o montepi

# Compilar carlopi (usa pthreads)
g++ carlopi.cpp -o carlopi -lpthread

# Ejecutar Taylor con N iteraciones
./taylorpi N

# Ejecutar Monte Carlo con N puntos
./montepi N

# Ejecutar Carlo con N rectángulos y T hilos
./carlopi N T

./taylorpi 10000000
./montepi 10000000
./carlopi 10000000 4
