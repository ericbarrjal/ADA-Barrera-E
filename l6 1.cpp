#include <stdio.h>

// Funci�n para encontrar el �rea m�xima de agua que puede contener el contenedor
int maxArea(int* height, int heightSize) {
    int i = 0;                    // Puntero al inicio
    int j = heightSize - 1;       // Puntero al final
    int max_area = 0;             // �rea m�xima inicializada en 0

    // Bucle mientras los punteros no se crucen
    while (i < j) {
        // Calcula el �rea actual entre los punteros i y j
        int h = height[i] < height[j] ? height[i] : height[j];
        int width = j - i;
        int current_area = h * width;

        // Actualiza el �rea m�xima si el �rea actual es mayor
        if (current_area > max_area) {
            max_area = current_area;
        }

        // Mueve el puntero que apunta a la l�nea m�s baja
        if (height[i] < height[j]) {
            i++;
        } else {
            j--;
        }
    }

    return max_area;
}

int main() {
    // Ejemplo de uso
    int height[] = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    int heightSize = sizeof(height) / sizeof(height[0]);

    int result = maxArea(height, heightSize);
    printf("La m�xima cantidad de agua que puede contener es: %d\n", result);

    return 0;
}

