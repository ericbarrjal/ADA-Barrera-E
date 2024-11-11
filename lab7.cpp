#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* compress(const char* word) {
    int n = strlen(word);
    char* comp = (char*)malloc(2 * n + 1);  // Reservar espacio suficiente
    int compIndex = 0;

    for (int i = 0; i < n;) {
        int count = 1;
        
        // Contar el número de repeticiones consecutivas del carácter actual, hasta un máximo de 9
        while (i + count < n && word[i + count] == word[i] && count < 9) {
            count++;
        }
        
        // Escribir el conteo y el carácter en la cadena de salida
        compIndex += sprintf(comp + compIndex, "%d%c", count, word[i]);
        
        // Mover el índice principal `i` hacia adelante por el número de caracteres procesados
        i += count;
    }
    
    comp[compIndex] = '\0';  // Añadir el carácter nulo al final de la cadena
    return comp;
}

int main() {
    // Prueba del código
    const char* word1 = "abcde";
    char* result1 = compress(word1);
    printf("Input: %s, Output: %s\n", word1, result1);
    free(result1);  // Liberar memoria asignada dinámicamente

    const char* word2 = "aaaaaaaaaaaaaabb";
    char* result2 = compress(word2);
    printf("Input: %s, Output: %s\n", word2, result2);
    free(result2);  // Liberar memoria asignada dinámicamente

    return 0;
}

