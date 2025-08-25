#include "listaSequencial.h"

void novaLista(Lista *l)
{
    l -> qtd = 0;
}

int buscar(Item x, Lista *l)
{
    //..
}

bool inserir(Lista *l, TipoElemento e)
{
    if(l -> qtd >= MAX){
        return 0; //lista cheia
    }

    int i = 0;

    while(i < l -> qtd && l -> elementos[i] < e){
        i++;
    }

    for(int j = l -> qtd; j > i; j--){
        l -> elementos[j] = l -> elementos[j-1];
    }

    l -> elementos[i] = e;
    l -> qtd++;
    return 1; //sucesso
}

bool remover(Lista *l, TipoElemento e)
{
    if(l -> qtd == 0){
        return 0; //lista vazia
    }

    int i = 0;

    while(i < l -> qtd && l -> elementos[i] != e){
        i++;
    }

    if(i == l -> qtd){
        return 0; //não achou
    }

    for(int j = i; j < l -> qtd - 1; j++){
        l -> elementos[j] = l -> elementos[j+1];
    }

    l -> qtd--;
    return 1; //sucesso
}

void imprimir(Lista *l)
{
    for(int i = 0; i < l->qtd; i++){
        printf("%d ", l -> elementos[i]);
    }

    printf("\n");
}

void liberarLista(Lista *l)
{
    //..
}