#ifndef LISTA_SEQUENCIAL_H  // evita multiplas recompilacoes deste arquivo.
#define LISTA_SEQUENCIAL_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX 100 //define o valor para o número máximo de itens no array

/* Definir o tipo do item que será usado a lista  
 * Ex: int, float, string ou até estrutura complexa utilizando outro struct
*/
typedef /*TIPO_DO_ITEM*/ Item; 

/* Definir a estrutura da lista para ser um tipo abstrato de dados
 * Quais informações são necessárias guardar em uma lista sequencial?
 * dica: lembrar de utilizar o MAX definido na linha 8
*/

typedef int TipoElemento;


typedef struct {
    TipoElemento elementos[MAX];
    int qtd;
} Lista;


/* Criar a estrutura da lista
 * e inicializar qualquer valor definido na struct
*/
/*Lista *novaLista();
/* ou então: void novaLista(Lista *l);
 * a diferença é que a primeira precisa usar o malloc e o free, 
 * e o outro não, uma vez que a lista foi criada fora da função nova lista
*/

void novaLista(Lista *l);

/* Buscar um item na lista
*/
int buscar(Item x, Lista *l);

/* Inserir um item na lista
 * o booleano pode informar se deu certo ou não
*/
bool inserir(Lista *l, TipoElemento e); 

/* Remover um item na lista
 * o booleano pode informar se deu certo ou não
*/
bool remover(Lista *l, TipoElemento e);

/* Imprimir todos os itens da lista
*/
void imprimir(Lista *l);

/* É preciso utilizar a função free para liberar 
 * o espaço que tenha sido pedido com a função  malloc
 * Caso tenha utilizado a segunda opção de criação da lista, 
 * isto é, sem malloc, não precisa dessa função
*/
void liberarLista(Lista *l); 


// outras funções e procedimentos que considerar conveniente ...


#endif // LISTA_SEQUENCIAL_H
