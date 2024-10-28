#include <bits/stdc++.h>
using namespace std;

// Estructura para un ítem que almacena peso y valor correspondiente
struct Item {
    int profit, weight;
    
    // Constructor
    Item(int profit, int weight)
    {
        this->profit = profit;
        this->weight = weight;
    }
};

// Función de comparación para ordenar los artículos según la relación profit/peso
static bool cmp(struct Item a, struct Item b)
{
    double r1 = (double)a.profit / (double)a.weight;
    double r2 = (double)b.profit / (double)b.weight;
    return r1 > r2;
}

// Función principal para resolver el problema
double fractionalKnapsack(int W, struct Item arr[], int N)
{
    // Ordenar artículos en función de la relación profit/peso
    sort(arr, arr + N, cmp);
    
    double finalvalue = 0.0;
    
    // Recorremos todos los artículos
    for (int i = 0; i < N; i++) {
        
        // Si se puede agregar completamente, lo hacemos
        if (arr[i].weight <= W) {
            W -= arr[i].weight;
            finalvalue += arr[i].profit;
        }
        
        // Si no se puede agregar completamente, agregamos una fracción
        else {
            finalvalue += arr[i].profit * ((double)W / (double)arr[i].weight);
            break;
        }
    }
    
    // Devolvemos el valor final
    return finalvalue;
}

int main()
{
    // Definir los 20 artículos
    Item arr[] = { {100, 10}, {60, 20}, {120, 30}, {90, 40}, {200, 50},
                   {150, 35}, {180, 25}, {75, 15}, {85, 10}, {95, 30},
                   {105, 20}, {125, 25}, {80, 35}, {70, 45}, {130, 55},
                   {110, 50}, {90, 60}, {140, 40}, {50, 10}, {160, 30} };
    
    int N = sizeof(arr) / sizeof(arr[0]);

    // Para W = 50
    int W1 = 50;
    clock_t start1 = clock();
    cout << "Valor máximo para W=50: " << fractionalKnapsack(W1, arr, N) << endl;
    clock_t end1 = clock();
    double time1 = double(end1 - start1) / CLOCKS_PER_SEC;
    cout << "Tiempo de ejecución para W=50: " << time1 << " segundos." << endl;

    // Para W = 80
    int W2 = 80;
    clock_t start2 = clock();
    cout << "Valor máximo para W=80: " << fractionalKnapsack(W2, arr, N) << endl;
    clock_t end2 = clock();
    double time2 = double(end2 - start2) / CLOCKS_PER_SEC;
    cout << "Tiempo de ejecución para W=80: " << time2 << " segundos." << endl;

    return 0;
}

