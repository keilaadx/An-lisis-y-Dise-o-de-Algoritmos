#include <stdio.h>
#include <stdlib.h>

// Función de comparación para qsort
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int teamChemistry(int* skill, int skillSize) {
    // Ordenar el array de habilidades
    qsort(skill, skillSize, sizeof(int), compare);

    int total_sum = 0;
    int target_sum = skill[0] + skill[skillSize - 1];

    for (int i = 0, j = skillSize - 1; i < j; i++, j--) {
        if (skill[i] + skill[j] != target_sum) {
            return -1; // No se pueden formar equipos con suma igual
        }
        total_sum += skill[i] * skill[j];
    }
    
    return total_sum;
}

int main() {
    int n;

    // Pedir al usuario la cantidad de jugadores (debe ser par)
    printf("Ingrese el numero de jugadores: ");
    scanf("%d", &n);

    if (n % 2 != 0) {
        printf("El numero de jugadores debe ser par.\n");
        return 1;
    }

    int *skill = (int*)malloc(n * sizeof(int)); // Asignación dinámica de memoria

    // Pedir al usuario que ingrese los valores del array
    printf("Ingrese las habilidades de los jugadores: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &skill[i]);
    }

    // Calcular la suma de la química de los equipos
    int result = teamChemistry(skill, n);
    
    // Mostrar el resultado
    printf("Resultado: %d\n", result);

    free(skill); // Liberar la memoria asignada
    return 0;
}
