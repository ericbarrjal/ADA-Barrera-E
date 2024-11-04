#include <stdio.h>

int maxArea(int* height, int heightSize) {
    int i = 0;                    
    int j = heightSize - 1;       
    int max_area = 0;             

    while (i < j) {
        int h = height[i] < height[j] ? height[i] : height[j];
        int width = j - i;
        int current_area = h * width;

        if (current_area > max_area) {
            max_area = current_area;
        }

        if (height[i] < height[j]) {
            i++;
        } else {
            j--;
        }
    }

    return max_area;
}

int main() {
    int height[] = {1, 1};  // Cambia aquí el arreglo para probar otros casos
    int heightSize = sizeof(height) / sizeof(height[0]);

    int result = maxArea(height, heightSize);
    printf("La máxima cantidad de agua que puede contener es: %d\n", result);

    return 0;
}

