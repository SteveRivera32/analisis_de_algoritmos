// Bibliotecas usadas para el sort
#include <iostream>
#include <vector>
// Bibliotecas para crear un arreglo desordenado
#include <algorithm>
#include <random>
// Bibliotecas para medir el tiempo de ejecución
#include <chrono> // Biblioteca para tomar el tiempo
#include <iomanip> // Biblioteca para manipular la salida (para que el tiempo salga siempre en decimales)

void merge(std::vector<int>& arreglo, int izq, int mid, int der) {
    std::vector<int> temp(der - izq + 1);
    int i = izq, j = mid + 1, k = 0;

    while (i <= mid && j <= der) {
        if (arreglo[i] <= arreglo[j]) temp[k++] = arreglo[i++];
        else temp[k++] = arreglo[j++];
    }
    while (i <= mid) temp[k++] = arreglo[i++];
    while (j <= der) temp[k++] = arreglo[j++];

    for (int t = 0; t < temp.size(); ++t) arreglo[izq + t] = temp[t];
}

void mergeSort(std::vector<int>& arreglo) {
    int n = arreglo.size();
    for (int size = 1; size < n; size *= 2) {
        for (int izq = 0; izq < n - size; izq += 2 * size) {
            int mid = izq + size - 1;
            int der = std::min(izq + 2 * size - 1, n - 1);
            merge(arreglo, izq, mid, der);
        }
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

    //Imprimir arreglo desordenado
    //std::cout << "Arreglo desordenado: ";
    //for (int num : arreglo) std::cout << num << " ";
    //std::cout << std::endl;

    // Iniciar el reloj
    auto start = std::chrono::high_resolution_clock::now();
    
    // Ejecutar algoritmo
    mergeSort(arreglo);

    // Detener el reloj
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start; // Calcular el tiempo transcurrido
    std::cout << std::fixed << std::setprecision(20); // Mostrar siempre 20 decimales
    std::cout << "Tiempo de ejecución: " << elapsed.count() << " segundos" << std::endl; // Mostrar el tiempo transcurrido

    // Imprimir el arreglo ordenado
    //std::cout << "Arreglo Ordenado: ";
    //for (int num : arreglo) std::cout << num << " ";

    return 0;
}
