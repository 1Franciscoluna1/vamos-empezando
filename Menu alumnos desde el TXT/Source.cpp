#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#pragma warning(disable : 4996)
#pragma warning(disable : 6387)




char* BuscarComando(FILE*);
void Pedirnumeros(int* numero1, int* numero2);
int sumar(int, int);
int restar(int, int);
int multiplicar(int, int);
float dividirlos(int, int);


int main(void) {
    FILE* arc;
    char* comando;
    arc = fopen("C:\\Users\\pacol\\source\\repos\\Menu alumnos desde el TXT\\Menu alumnos desde el TXT\\mellevalaverga.h", "r");
    comando = BuscarComando(arc);
    if (!strcmp(comando, "pedirNumeros\n")) {
        int numero1, numero2;
        Pedirnumeros(&numero1, &numero2);
        comando = BuscarComando(arc);
        if (!strcmp(comando, "sumarlos\n")) {
            int suma = sumar(numero1, numero2);
            printf("\n\nLa suma de los numeros es:\t\t%i", suma);
        }
        comando = BuscarComando(arc);
        if (!strcmp(comando, "restarlos\n")) {
            int resta = restar(numero1, numero2);
            printf("\n\nLa resta de los numeros es:\t\t%i", resta);
        }
        comando = BuscarComando(arc);
        if (!strcmp(comando, "multiplicarlos\n")) {
            int multiplo = multiplicar(numero1, numero2);
            printf("\n\nEl multiplicar los numeros da:\t\t%i", multiplo);
        }
        comando = BuscarComando(arc);
        if (!strcmp(comando, "dividirlos\n")) {
            float division = dividirlos(numero1, numero2);
            printf("\n\nEl dividir los numeros da:\t\t%0.3f", division);
        }
        comando = BuscarComando(arc);
        if (!strcmp(comando, "profe")) {
            printf("\n\nPor que saque 74??, no sea puto\n\n");
        }
    }
    printf("\n\n\n");
    system("pause");
    return 0;
}


char* BuscarComando(FILE* instruccion) {
    char* c;
    c = (char*)malloc(sizeof(char)*20);
    fgets(c,20 ,instruccion);
    //printf("%s",c);
    return c;
    free(c);
}

void Pedirnumeros(int* numero1, int* numero2) {
    printf("\n\nIngrese el numero 1\t");
    scanf_s("%i", numero1);
    printf("\n\nIngrese el numero 2\t");
    scanf_s("%i", numero2);
}

int sumar(int a, int b) {
    return (a + b);
}

int restar(int a, int b) {
    return (a - b);
}

int multiplicar(int a, int b) {
    return (a * b);
}

float dividirlos(int a, int b) {
    float x, y;
    x = (float)a;
    y = (float)b;
    return (x / y);
}