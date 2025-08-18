#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

typedef struct{
    int esquerda;
    int direita;
} realTipo;

realTipo criarReal(const char *entrada){
    realTipo num;

    char copia[50];
    strcpy(copia, entrada);

    char *parteInt = strtok(copia, ".");
    char *parteFracao = strtok(NULL, ".");

    num.esquerda = atoi(parteInt);
    num.direita = (parteFracao != NULL) ? abs(atoi(parteFracao)) : 0; //se houver parte fracionária, converte para int e garante que seja positiva com abs.

    return num;
}

double structPaReal(realTipo numero){
    double parteFracao = numero.direita;

    int casas = 0;
    int temp = numero.direita;
    while(temp > 0){
        temp /= 10;
        casas++;
    }

    parteFracao /= pow(10, casas);

    if (numero.esquerda < 0){
        return numero.esquerda - parteFracao;
    } else {
        return numero.esquerda + parteFracao;
    }
}

realTipo doublePaStruct(double valor){
    realTipo num;

    num.esquerda = (int) valor;

    double fracao = fabs(valor - num.esquerda);
    num.direita = (int)(fracao * 1000000);

    return num;
}

realTipo add(realTipo a, realTipo b){
    double x = structPaReal(a);
    double y = structPaReal(b);

    double soma = x + y;
    return doublePaStruct(soma);
}

realTipo subtract(realTipo a, realTipo b){
    double x = structPaReal(a);
    double y = structPaReal(b);

    double sub = x - y;
    return doublePaStruct(sub);
}
 
realTipo multiply(realTipo a, realTipo b){
    double x = structPaReal(a);
    double y = structPaReal(b);

    double mult = x * y;
    return doublePaStruct(mult);
}


int main(){
    char entrada[50];
    realTipo a = criarReal("2.25");
    realTipo b = criarReal("10.25");

    printf("Digite o número real: ");
    scanf("%s", entrada);

    realTipo n = criarReal(entrada); //item a
    printf("Parte inteira: %d\n", n.esquerda);
    printf("Parte fracionária: %d\n", n.direita);

    double valor = structPaReal(n); //item b
    printf("Número reconstruído: %.10g\n", valor);

    realTipo r1 = add(a, b);
    realTipo r2 = subtract(a, b);
    realTipo r3 = multiply(a, b);

    printf("Soma: %g\n", structPaReal(r1));
    printf("Subtração: %g\n", structPaReal(r2));
    printf("Multiplicação: %g\n", structPaReal(r3));

    return 0;
}
