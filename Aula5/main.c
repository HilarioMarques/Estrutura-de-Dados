#include "listaSequencial.h"

int main (int argc, char *argv[])
{
    //criando uma nova lista (é preciso utilizar a função malloc)

    Lista * l = (Lista *) malloc(sizeof(Lista));
    if(l == NULL){
        printf("Erro ao alocar memória\n");
    }

    novaLista(l);
    
    Item x = 1;
    Item y = 5;
    Item z = 2;
    inserir(l, x);
    inserir(l, y);
    inserir(l, z);

    printf("Listas após inserções: ");
    imprimir(l);
    
    remover(l, x);
    printf("Listas após remover x: ");
    imprimir(l);

    //é preciso liberar o espaço com a função free (que foi requisitado coma função malloc)
    free(l);

    printf("\nFIM\n\n");

    return 0;
}
