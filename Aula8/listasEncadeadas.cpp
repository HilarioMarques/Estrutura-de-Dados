#include <iostream>
using namespace std;

// Estrutura do nó
struct Node {
    int valor;
    Node* prox;
};

// Inserção ordenada na lista
void inserirOrdenado(Node*& head, int x) {
    Node* novo = new Node;
    novo->valor = x;
    novo->prox = nullptr;

    // Se a lista estiver vazia ou o novo elemento for menor que o primeiro
    if (head == nullptr || x < head->valor) {
        novo->prox = head;
        head = novo;
    } else {
        Node* atual = head;
        // Avança até achar a posição correta
        while (atual->prox != nullptr && atual->prox->valor < x) {
            atual = atual->prox;
        }
        novo->prox = atual->prox;
        atual->prox = novo;
    }
}

// Busca ordenada (retorna true se encontrar)
bool buscarOrdenado(Node* head, int x) {
    Node* atual = head;
    while (atual != nullptr && atual->valor <= x) {
        if (atual->valor == x)
            return true;
        atual = atual->prox;
    }
    return false;
}

// Remoção ordenada
bool removerOrdenado(Node*& head, int x) {
    if (head == nullptr) return false;

    // Se o elemento a remover for o primeiro
    if (head->valor == x) {
        Node* temp = head;
        head = head->prox;
        delete temp;
        return true;
    }

    Node* atual = head;
    while (atual->prox != nullptr && atual->prox->valor < x) {
        atual = atual->prox;
    }

    if (atual->prox != nullptr && atual->prox->valor == x) {
        Node* temp = atual->prox;
        atual->prox = atual->prox->prox;
        delete temp;
        return true;
    }

    return false;
}

// Impressão da lista
void imprimirLista(Node* head) {
    cout << "Lista: ";
    Node* atual = head;
    while (atual != nullptr) {
        cout << atual->valor << " ";
        atual = atual->prox;
    }
    cout << endl;
}

// Liberação da memória da lista
void liberarLista(Node*& head) {
    Node* atual = head;
    while (atual != nullptr) {
        Node* temp = atual;
        atual = atual->prox;
        delete temp;
    }
    head = nullptr;
}

int main() {
    Node* lista = nullptr;

    // Testando inserção
    inserirOrdenado(lista, 10);
    inserirOrdenado(lista, 5);
    inserirOrdenado(lista, 20);
    inserirOrdenado(lista, 15);
    inserirOrdenado(lista, 7);

    imprimirLista(lista);

    // Testando busca
    cout << "Buscando 15: " << (buscarOrdenado(lista, 15) ? "Encontrado" : "Nao encontrado") << endl;
    cout << "Buscando 99: " << (buscarOrdenado(lista, 99) ? "Encontrado" : "Nao encontrado") << endl;

    // Testando remoção
    cout << "Removendo 10..." << endl;
    removerOrdenado(lista, 10);
    imprimirLista(lista);

    cout << "Removendo 99 (inexistente)..." << endl;
    removerOrdenado(lista, 99);
    imprimirLista(lista);

    // Liberando memória
    liberarLista(lista);

    return 0;
}
