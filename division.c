#include <stdio.h>
#include <limits.h>

int division(int dividendo, int divisor) {
    // Caso especial: desbordamiento si dividendo es INT_MIN y divisor es -1
    if (dividendo == INT_MIN && divisor == -1) {
        return INT_MAX; // El resultado sería 2^31, que excede INT_MAX
    }

    // Manejo de los signos
    int signo = 1;
    if (dividendo < 0) {
        signo = -signo;
        dividendo = -dividendo; // Hacer el dividendo positivo
    }
    if (divisor < 0) {
        signo = -signo;
        divisor = -divisor; // Hacer el divisor positivo
    }

    // Realizamos la división mediante resta repetida
    int cociente = 0;
    while (dividendo >= divisor) {
        dividendo -= divisor;
        cociente++;
    }

    if (signo == -1) {
        cociente = -cociente;
    }

    // Verificar si el cociente está dentro del rango de 32 bits con signo
    if (cociente > INT_MAX) {
        return INT_MAX;
    } else if (cociente < INT_MIN) {
        return INT_MIN;
    }

    return cociente;
}

int main() {
    int dividendo, divisor;
    
    printf("Ingrese el dividendo: ");
    scanf("%d", &dividendo);
    
    printf("Ingrese el divisor: ");
    scanf("%d", &divisor);

    if (divisor == 0) {
        printf("ERROR, no se puede dividir entre cero.\n");
    } else {
        int resultado = division(dividendo, divisor);
        printf("El resultado de la division es: %d\n", resultado);
    }

    return 0;
}
