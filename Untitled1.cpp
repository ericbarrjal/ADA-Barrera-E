#include <stdio.h>
#include <time.h>

// Funci�n recursiva para calcular el n-�simo n�mero de Fibonacci
long long fibonacci(int n) {
    if (n <= 1) {
        return n;
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

int main() {
    int n;
    clock_t inicio, fin;
    double tiempo_total;
    
    printf("Ingrese el valor de n: ");
    scanf("%d", &n);

    // Medir el tiempo de ejecuci�n para el c�lculo del n-�simo n�mero de Fibonacci
    inicio = clock();
    long long resultado = fibonacci(n);
    fin = clock();

    // Calcular el tiempo total en segundos
    tiempo_total = ((double)(fin - inicio)) / CLOCKS_PER_SEC * 1000; // Convertido a milisegundos
    
    // Imprimir el resultado y el tiempo de ejecuci�n
    printf("Fibonacci(%d) = %lld\n", n, resultado);
    printf("Tiempo de ejecucion: %.5f ms\n", tiempo_total);

    return 0;
}

