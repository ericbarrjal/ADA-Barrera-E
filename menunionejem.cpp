#include <stdio.h>
#include <stdlib.h>  // Para malloc y free

// Función para calcular el número de subarreglos válidos
int numOfSubarrays(int* arr, int arrSize, int k, int threshold) {
    // Calcular la suma mínima requerida basada en el umbral
    int required_sum = threshold * k;
    
    // Calcular la suma de la primera ventana de tamaño k
    int current_sum = 0;
    for (int i = 0; i < k; i++) {
        current_sum += arr[i];
    }
    
    // Inicializar contador de subarreglos válidos
    int count = 0;
    
    // Si la primera ventana cumple con el umbral, imprimirla
    if (current_sum >= required_sum) {
        count++;
        printf("Subarreglo valido: ");
        for (int i = 0; i < k; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }
    
    // Deslizar la ventana a través del arreglo
    for (int i = k; i < arrSize; i++) {
        // Actualizar la suma al mover la ventana
        current_sum += arr[i] - arr[i - k];
        
        // Verificar si la nueva ventana cumple con el umbral
        if (current_sum >= required_sum) {
            count++;
            printf("Subarreglo valido: ");
            for (int j = i - k + 1; j <= i; j++) {
                printf("%d ", arr[j]);
            }
            printf("\n");
        }
    }
    
    return count;
}

int main() {
    int n, k, threshold;
    int opcion;
    
    // Mostrar menú
    do {
        printf("\nSelecciona una opcion:\n");
        printf("1. Ejecutar Ejemplo 1\n");
        printf("2. Ejecutar Ejemplo 2\n");
        printf("3. Salir\n");
        printf("Opcion: ");
        scanf("%d", &opcion);
        
        switch (opcion) {
            case 1: {
                // Ejemplo 1
                printf("\nEjemplo 1:\n");
                printf("Ingrese el tamano del arreglo: ");
                scanf("%d", &n);
                
                // Asignar memoria dinámica para el arreglo
                int* arr1 = (int*)malloc(n * sizeof(int));
                if (arr1 == NULL) {
                    printf("Error al asignar memoria.\n");
                    return 1;  // Salir si falla la asignación de memoria
                }
                
                printf("Ingrese los elementos del arreglo:\n");
                for (int i = 0; i < n; i++) {
                    scanf("%d", &arr1[i]);
                }
                
                printf("Ingrese el tamano del subarreglo k: ");
                scanf("%d", &k);
                
                printf("Ingrese el umbral: ");
                scanf("%d", &threshold);
                
                int result1 = numOfSubarrays(arr1, n, k, threshold);
                printf("Numero de subarreglos que cumplen el umbral para el Ejemplo 1: %d\n", result1);
                
                // Liberar memoria
                free(arr1);
                break;
            }
            
            case 2: {
                // Ejemplo 2
                printf("\nEjemplo 2:\n");
                printf("Ingrese el tamano del arreglo: ");
                scanf("%d", &n);
                
                // Asignar memoria dinámica para el arreglo
                int* arr2 = (int*)malloc(n * sizeof(int));
                if (arr2 == NULL) {
                    printf("Error al asignar memoria.\n");
                    return 1;  // Salir si falla la asignación de memoria
                }
                
                printf("Ingrese los elementos del arreglo:\n");
                for (int i = 0; i < n; i++) {
                    scanf("%d", &arr2[i]);
                }
                
                printf("Ingrese el tamano del subarreglo k: ");
                scanf("%d", &k);
                
                printf("Ingrese el umbral: ");
                scanf("%d", &threshold);
                
                int result2 = numOfSubarrays(arr2, n, k, threshold);
                printf("Numero de subarreglos que cumplen el umbral para el Ejemplo 2: %d\n", result2);
                
                // Liberar memoria
                free(arr2);
                break;
            }
            
            case 3:
                // Salir
                printf("¡Gracias por usar el programa! Hasta luego.\n");
                break;
            
            default:
                printf("Opción no valida. Intenta nuevamente.\n");
        }
        
    } while (opcion != 3);  // Continuar hasta que el usuario elija salir
    
    return 0;
}


