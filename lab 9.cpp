#include <stdio.h>
#include <stdlib.h>

int** generatePascalsTriangle(int numRows, int* returnSize, int** returnColumnSizes) {
    // Asignar memoria para el triángulo
    int** triangle = (int**)malloc(numRows * sizeof(int*));
    *returnColumnSizes = (int*)malloc(numRows * sizeof(int));
    *returnSize = numRows;

    for (int i = 0; i < numRows; i++) {
        // Crear una nueva fila con el tamaño adecuado
        triangle[i] = (int*)malloc((i + 1) * sizeof(int));
        (*returnColumnSizes)[i] = i + 1;

        // Inicializar los extremos de la fila a 1
        triangle[i][0] = 1;
        triangle[i][i] = 1;

        // Calcular los valores intermedios de la fila
        for (int j = 1; j < i; j++) {
            triangle[i][j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
        }
    }

    return triangle;
}

void freeMemory(int** triangle, int* returnColumnSizes, int numRows) {
    for (int i = 0; i < numRows; i++) {
        free(triangle[i]); // Liberar memoria de cada fila
    }
    free(triangle); // Liberar memoria del triángulo
    free(returnColumnSizes); // Liberar memoria de tamaños de columna
}

int main() {
    int choice;

    do {
        int numRows;
        printf("Introduce el numero de filas del triangulo de Pascal (entre 1 y 30): ");
        scanf("%d", &numRows);

        // Validar la entrada
        if (numRows < 1 || numRows > 30) {
            printf("Por favor, introduce un numero valido entre 1 y 30.\n");
            continue;
        }

        int returnSize;
        int* returnColumnSizes;

        // Generar el triángulo de Pascal
        int** triangle = generatePascalsTriangle(numRows, &returnSize, &returnColumnSizes);

        // Imprimir el triángulo
        printf("Triangulo de Pascal con %d filas:\n", numRows);
        for (int i = 0; i < returnSize; i++) {
            for (int j = 0; j < returnColumnSizes[i]; j++) {
                printf("%d ", triangle[i][j]);
            }
            printf("\n");
        }

        // Liberar la memoria del triángulo actual
        freeMemory(triangle, returnColumnSizes, returnSize);

        // Preguntar si desea continuar
        printf("\n¿Deseas generar otro triangulo? (1: Si, 0: No): ");
        scanf("%d", &choice);

    } while (choice == 1);

    printf("Adios");
    return 0;
}

