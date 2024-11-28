// Bibliotecas usadas para el sort
#include <iostream>
#include <vector>
// Bibliotecas para crear un arreglo desordenado
#include <algorithm>
#include <random>
// Bibliotecas para medir el tiempo de ejecución
#include <chrono> // Biblioteca para tomar el tiempo
#include <iomanip> // Biblioteca para manipular la salida (para que el tiempo salga siempre en decimales)

void insertionSort(std::vector<int>& arreglo) {
    for (int i = 1; i < arreglo.size(); ++i) {
        int llave = arreglo[i], j = i - 1;
        while (j >= 0 && arreglo[j] > llave) {
            arreglo[j + 1] = arreglo[j];
            --j;
        }
        arreglo[j + 1] = llave;
    }
}

int main() {
    // Crear arreglo desordenado (genera el mismo arreglo cada vez que se ejecuta)
    int n = 15;
    std::vector<int> arreglo(n);

    for (int i = 0; i < n; ++i) {
        arreglo[i] = i + 1; // Llenar el arreglo con números del 1 al n
    }

    std::mt19937 rng(12345); // Semilla fija
    std::shuffle(arreglo.begin(), arreglo.end(), rng); // Desordenar el arreglo

    // Imprimir arreglo desordenado
    // std::cout << "Arreglo desordenado: ";
    // for (int num : arreglo) std::cout << num << " ";
    // std::cout << std::endl;

    // Iniciar el reloj
    auto start = std::chrono::high_resolution_clock::now();
    
    // Ejecutar algoritmo
    insertionSort(arreglo);

    // Detener el reloj
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start; // Calcular el tiempo transcurrido
    std::cout << std::fixed << std::setprecision(20); // Mostrar siempre 20 decimales
    std::cout << "Tiempo de ejecución: " << elapsed.count() << " segundos" << std::endl; // Mostrar el tiempo transcurrido

    // Imprimir el arreglo ordenado
    // std::cout << "Arreglo Ordenado: ";
    // for (int num : arreglo) std::cout << num << " ";

    return 0;
}
