import time


# Función para fusionar dos arreglos ordenados
def fusionar_y_ordenar(nums1, nums2):
    return sorted(nums1 + nums2)


# Función para calcular la mediana
def calcular_mediana(arr):
    n = len(arr)
    if n % 2 == 1:
        return arr[n // 2]
    else:
        return (arr[n // 2 - 1] + arr[n // 2]) / 2.0


# Función principal para encontrar la mediana de dos arreglos ordenados
def encontrar_mediana(nums1, nums2):
    # Fusionar ambos arreglos y ordenarlos
    fusionado = fusionar_y_ordenar(nums1, nums2)
    # Calcular la mediana del arreglo fusionado
    return calcular_mediana(fusionado)


# Ejemplo de uso y medición del tiempo
if __name__ == "__main__":
    nums1 = [1,3]
    nums2 = [2]

    # Medir el tiempo de ejecución
    inicio = time.time()

    mediana = encontrar_mediana(nums1, nums2)

    fin = time.time()
    tiempo_total = fin - inicio

    # Mostrar el resultado
    print(f"La mediana es: {mediana:.5f}")
    print(f"Tiempo de ejecución: {tiempo_total:.10f} segundos")
