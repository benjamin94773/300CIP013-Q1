

# π 300CIP013-Q1

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
```
## Ejecución
```bash
# Ejecutar Taylor con N iteraciones
./taylorpi N

# Ejecutar Monte Carlo con N puntos
./montepi N

# Ejecutar Carlo con N rectángulos y T hilos
./carlopi N T
```
## Ejemplos
```bash
./taylorpi 10000000
./montepi 10000000
./carlopi 10000000 10
```
## 📊 Rendimiento de `carlopi` con diferentes hilos

| # Hilos | Aproximación de π | Error absoluto | Tiempo CPU (s) |
|---------|------------------|----------------|----------------|
| 1       | 3.1422688        | 0.0006761      | 0.136839       |
| 2       | 3.1423848        | 0.0007921      | 0.131554       |
| 4       | 3.1418924        | 0.0002997      | 0.124163       |
| 8       | 3.1418092        | 0.0002165      | 0.138597       |
| 16      | 3.1415332        | 0.0000594      | 0.121191       |

---

## 📈 Análisis de rendimiento

1. **Precisión**  
   - El error disminuye al aumentar el número de hilos.  
   - Con **16 hilos** se obtiene el error más bajo (≈ 5.9e-05).  

2. **Tiempo de ejecución**  
   - Hay una **mejora clara de 1 → 4 hilos**, pasando de ~0.137s a ~0.124s.  
   - Con **8 hilos** el tiempo aumenta ligeramente (~0.139s), mostrando sobrecarga de sincronización.  
   - Con **16 hilos** el tiempo baja de nuevo (~0.121s), siendo el mejor resultado.  

3. **Escalabilidad**  
   - El programa escala bien hasta cierto punto, pero no de forma lineal.  
   - A partir de 8 hilos se nota la **sobrecarga por creación de hilos y coordinación**, lo que limita la ganancia en tiempo.  
   - Sin embargo, la precisión mejora porque más hilos permiten repartir la carga de forma más uniforme y cubrir mejor el intervalo.  

---

## 📝 Conclusión

- La versión paralela con **4 a 16 hilos** es más eficiente que la secuencial (1 hilo).  
- El **tiempo más bajo** se logró con **16 hilos (0.121s)**.  
- El **error más pequeño** también se alcanzó con **16 hilos (5.9e-05)**.  
- Sin embargo, la escalabilidad no es perfecta: al aumentar hilos, la sobrecarga de sincronización puede incluso empeorar el tiempo (caso de 8 hilos).  
- En general, el método de **Monte Carlo paralelo (carlopi)** se beneficia de múltiples hilos, pero el **número óptimo depende del hardware y del balance entre cómputo y comunicación**.  


