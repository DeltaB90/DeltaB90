#include <stdio.h>

int main() {

    char letra;
    int total = 0, contador = 0;
    int letranum = 0;
    int numI = 0, numV = 0, numX = 0, numL = 0, numC = 0, numD = 0, numM = 0;

    while(contador < 10) {  // Bucle que se rompe si se ingresa 'Q'

        printf("Ingresa una letra romana: ");
        scanf(" %c", &letra); 
        printf("Contador general %d\n", contador);

        if(letra == 'Q') {
            break;  // Salir del bucle si se ingresa 'Q'
        }

        switch(letra) {  
            case 'I':
                printf("contador I %d\n", numI);
                letranum += 1;
                contador++;
                numI++;
                break;
            case 'V':
                numV++;
                letranum += 5;
                contador++;
                break;
            case 'X':
                numX++;
                letranum += 10;
                contador++;
                break;
            case 'L':
                numL++;
                letranum += 50;
                contador++;
                break;
            case 'C':
                numC++;
                letranum += 100;
                contador++;
                break;
            case 'D':
                numD++;
                letranum += 500;
                contador++;
                break;
            case 'M':
                numM++;
                letranum += 1000;
                contador++;
                break;
            default:
                printf("Letra inválida\n");
        }

        if(numI > 4  || numV > 4 || numX > 4 || numL > 4 || numC > 4 || numD > 4 || numM > 4) {
            break;
        }

        total = letranum;  // Sumar el valor retornado por la función romano
    }


    printf("El valor total es: %d\n", total);  // Imprimir la suma total

    return 0; 
}

