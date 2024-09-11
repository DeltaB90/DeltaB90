/*
 * Taller 2
 *
 *
 */

#include <stdio.h>
#include <stdlib.h>

//MACROS
#define Pause() system("pause")
#define Cls()   system("cls")

//PROTOTIPOS FUNCIONES

//Primer Punto
void Palindromos();

//Segundo Punto
void imprimirMatriz(int filas, int column, float matriz[filas][column]);
void ingresarMatriz(int filas, int column, float matriz [filas][column]);
void MulMatrix();

//Tercer Punto
void Proteinas();

int main() {
    int opcion = -1;
    while (opcion != 0) {
        printf("\n"
            "Menu Taller 2\n"
            "\t1.Palindromos\n"
            "\t2.Multiplicacion de matices\n"
            "\t3.Proteninas\n"
            "\t0.Salir\n");

        scanf(" %d", &opcion);

        switch (opcion) {
        case 1:
            Palindromos();
            break;

        case 2:
            MulMatrix();
            break;

        case 3:
            Proteinas();
            break;

        case 0:
            printf("Programa FINALIZADO\n");
            break;

        default:
            printf("¡INGRESE UNA OPCION VALIDA!\n");
            break;
        }
    }

}

//Primer Punto
void Palindromos()
{

	Cls();

    char palabra[10];

    printf("pon una palabra: ");
    scanf("%s", palabra);

    int longitud = 0;

    while (palabra[longitud] != '\0')
    {
        longitud++;
    }

    int estado = 1;
	
	int i;
    for ( i= 0; i < longitud / 2; i++)
    {
        if (palabra[i] != palabra[longitud - 1 - i])
        {
            estado = 0;
        }
    }

    if (estado == 1)
    {
        printf("La palabra %s es palindroma\n", palabra);
    }
    else
    {
        printf("La palabra %s no es palindroma\n", palabra);
    }

    Pause();
    Cls();

}


//Segundo Punto
void imprimirMatriz(int filas, int column, float matriz[filas][column]) {
    printf("\n");
    int i,j;
    for ( i = 0; i < filas; i++) {
        for (j = 0; j < column; j++) {
            printf("%f",(matriz[i][j]));
            if (j != column - 1){
             printf("\t");
            }
        }
        printf("\n");
    }
    printf("\n");

    Pause();
    Cls();
}

void ingresarMatriz(int filas, int column, float matriz [filas][column]) {
	int i,j;
        for ( i = 0; i < filas; i++) {
            for ( j = 0; j < column; j++) {
                printf("Ingrese dato en posicion (%d,%d): \n",i+1,j+1);
                scanf(" %f", &(matriz[i][j]));
            }
        }

}

void MulMatrix() {

    int filasP, columP;

    Cls();

    printf("Ingrese las dimensiones de la matriz #1 (use el formato FILASxCOLUMNAS): ");
    scanf("%dx%d", &filasP, &columP);

    int filasS, columS;
    printf("Ingrese las dimensiones de la matriz #2 (use el formato FILASxCOLUMNAS): ");
    scanf("%dx%d", &filasS, &columS);

    //Limite de dimensiones: FILAS
    if ( (filasS < 2 || filasP < 2 || filasP > 5 || filasS > 5) ||
        (columS < 2 || columP < 2 || columP > 5 || columS > 5)    ) {

        printf("dimensiones invalidas\n");

    } else {

        //Revisar si las matices pueden ser multiplicadas
        //numero de columnas m1 = numero de filas m2
        if (columP == filasS) {

            float matrizUno[filasP][columP];
            float matrizDos[filasS][columS];
            float resultado[filasP][columS];

            Cls();

            //ingresar datos a matrices
            printf("Matriz Uno\n");
            ingresarMatriz(filasP, columP, matrizUno);

            printf("\nRepresentacion Matriz Uno\n");
            imprimirMatriz(filasP, columP, matrizUno);

            //Ingresar datos de matriz dos
            printf("Matriz Dos\n");
            ingresarMatriz(filasS, columS, matrizDos);

            printf("\nRepresentacion Matriz Dos\n");
            imprimirMatriz(filasS, columS, matrizDos);
			int i,j,k;
            //Multiplicacion de matrices
            printf("\nMatriz Resultado\n");
            for ( i = 0; i < filasP; i++) {
                for ( j = 0; j < columS; j++) {

                    resultado[i][j] = 0;

                    for ( k = 0; k < columP; k++) {

                        resultado[i][j] += matrizUno[i][k] * matrizDos[k][j];
                        printf("%f x %f", matrizUno[i][k], matrizDos[k][j]);

                        if (k != columP - 1) {
                            printf(" + ");
                        }
                    }

                    printf(" = %f\n", resultado[i][j]);
                }
            }


            Pause();
            Cls();

            printf("\nRepresentacion Matriz resultado\n");
            imprimirMatriz(filasP, columS, resultado);


        } else {
            printf("Multiplicacion invalida\n");

            Pause();
        }
    }

}


//Tercer Punto
void Proteinas() {

	Cls();

    int i;
    int reconocida = 1;
    char bio[16];
    int largo;
    printf("Ingrese su secuencia de RNA:\n");
    scanf("%s", bio);

    for (largo = 0; bio[largo] != '\0'; largo++);
    printf("Tam = %d \n", largo);

    Pause();

    printf("proteinas: ");
    for (i = 0; i + 2 < largo; i = i+3) {

        if (bio[i] == 'A' && bio[i + 1] == 'U' && bio[i + 2] == 'G') {
            printf("Methionine (%c%c%c), ", bio[i], bio[i+1], bio[i+2]);
        }

        else if ((bio[i] == 'U' && bio[i + 1] == 'U' && bio[i + 2] == 'C') ||
                 (bio[i] == 'U' && bio[i + 1] == 'U' && bio[i + 2] == 'U')) {
            printf("Phenylalanine (%c%c%c), ", bio[i], bio[i+1], bio[i+2]);
        }

        else if ((bio[i] == 'U' && bio[i + 1] == 'U' && bio[i + 2] == 'A') ||
                 (bio[i] == 'U' && bio[i + 1] == 'U' && bio[i + 2] == 'G')) {
            printf("Leucine (%c%c%c), ", bio[i], bio[i+1], bio[i+2]);
        }

		else if ((bio[i] == 'U' && bio[i + 1] == 'C' && bio[i + 2] == 'U') ||
                 (bio[i] == 'U' && bio[i + 1] == 'C' && bio[i + 2] == 'C') ||
			     (bio[i] == 'U' && bio[i + 1] == 'C' && bio[i + 2] == 'A') ||
                 (bio[i] == 'U' && bio[i + 1] == 'C' && bio[i + 2] =='G') ) {
			printf("Serine (%c%c%c), ", bio[i], bio[i+1], bio[i+2]);
        }

        else if ((bio[i] == 'U' && bio[i + 1] == 'A' && bio[i + 2] == 'U') ||
                 (bio[i] == 'U' && bio[i + 1] == 'A' && bio[i + 2] == 'C')) {
			printf("Tyrosine (%c%c%c), ",bio[i], bio[i+1], bio[i+2]);
		}

		else if ((bio[i] == 'U' && bio[i + 1] == 'G' && bio[i + 2] == 'U') ||
                 (bio[i] == 'U' && bio[i + 1] == 'G' && bio[i + 2] == 'C') ) {
			printf("Cysteine (%c%c%c), ",bio[i], bio[i+1], bio[i+2]);
		}

		else if((bio[i] == 'U') && (bio[i+1] == 'G') && (bio[i+2] == 'G') ) {
			printf("Tryptophan (%c%c%c), ",bio[i], bio[i+1], bio[i+2]);
		}

        else if((bio[i] == 'U' && bio[i + 1] == 'A' && bio[i + 2] == 'A') ||
                (bio[i] == 'U' && bio[i + 1] == 'A' && bio[i + 2] == 'G') ||
			    (bio[i] == 'U' && bio[i + 1] == 'G' && bio[i + 2] == 'A')) {
			printf("STOP (%c%c%c)\n",bio[i], bio[i+1], bio[i+2]);
			break;
		}

        else {
            reconocida = 0;
        }

        if (reconocida == 0) {
            //Devuelve una letra
            i--;
        }
    }

    printf("\n");

    Pause();
    Cls();
}
