#include <stdio.h>

// Función para eliminar duplicados en el sitio
int eliminarDuplicados(int nums[], int size) {
    // Si el tamaño del arreglo es 0, no hay elementos únicos
    if (size == 0) {
        return 0;
    }

    int k = 1; // El primer elemento siempre es único

    // Recorremos el arreglo desde el segundo elemento
    for (int i = 1; i < size; i++) {
        // Si encontramos un número diferente al anterior, lo movemos a la posición k
        if (nums[i] != nums[i - 1]) {
            nums[k] = nums[i];
            k++;
        }
    }

    // k es el número de elementos únicos
    return k;
}

int main() {
    // Ejemplo 1
    int nums1[] = {1, 1, 2};
    int size1 = sizeof(nums1) / sizeof(nums1[0]);
    int k1 = eliminarDuplicados(nums1, size1);
    printf("Numero de elementos unicos: %d\n", k1);
    for (int i = 0; i < k1; i++) {
        printf("%d ", nums1[i]);
    }
    printf("\n");

    // Ejemplo 2
    int nums2[] = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    int size2 = sizeof(nums2) / sizeof(nums2[0]);
    int k2 = eliminarDuplicados(nums2, size2);
    printf("Numero de elementos unicos: %d\n", k2);
    for (int i = 0; i < k2; i++) {
        printf("%d ", nums2[i]);
    }
    printf("\n");

    // Ejemplo 3 propio
    int nums3[] = {0,0,1,1,2,2,3,3,3,5,5,7,7,9,9,10,11};
    int size3 = sizeof(nums3) / sizeof(nums3[0]);
    int k3 = eliminarDuplicados(nums3, size3);
    printf("Numero de elementos unicos: %d\n", k3);
    for (int i = 0; i < k3; i++) {
        printf("%d ", nums3[i]);
    }
    printf("\n");

    return 0;
}

