#include <iostream>
using namespace std;


// Estrutura de Pilha

struct Node {
    int valor;
    Node* prox;
};

struct Pilha {
    Node* topo;
};

// Inicializa
void inicializarPilha(Pilha &p) {
    p.topo = nullptr;
}

// Inserir
void push(Pilha &p, int valor) {
    Node* novo = new Node();
    novo->valor = valor;
    novo->prox = p.topo;
    p.topo = novo;
    cout << "Inserido na pilha: " << valor << endl;
}

// Remover 
void pop(Pilha &p) {
    if (p.topo == nullptr) {
        cout << "Pilha vazia!" << endl;
        return;
    }
    Node* temp = p.topo;
    cout << "Removido da pilha: " << temp->valor << endl;
    p.topo = p.topo->prox;
    delete temp;
}

// Imprimir pilha
void imprimirPilha(Pilha p) {
    cout << "Pilha: ";
    Node* atual = p.topo;
    while (atual != nullptr) {
        cout << atual->valor << " ";
        atual = atual->prox;
    }
    cout << endl;
}


// Estrutura de Fila
struct Fila {
    Node* frente;
    Node* tras;
};

// Inicializa 
void inicializarFila(Fila &f) {
    f.frente = f.tras = nullptr;
}

// Inserir 
void enqueue(Fila &f, int valor) {
    Node* novo = new Node();
    novo->valor = valor;
    novo->prox = nullptr;
    if (f.tras == nullptr) {
        f.frente = f.tras = novo;
    } else {
        f.tras->prox = novo;
        f.tras = novo;
    }
    cout << "Inserido na fila: " << valor << endl;
}

// Remover 
void dequeue(Fila &f) {
    if (f.frente == nullptr) {
        cout << "Fila vazia!" << endl;
        return;
    }
    Node* temp = f.frente;
    cout << "Removido da fila: " << temp->valor << endl;
    f.frente = f.frente->prox;
    if (f.frente == nullptr) {
        f.tras = nullptr;
    }
    delete temp;
}

// Imprimir fila
void imprimirFila(Fila f) {
    cout << "Fila: ";
    Node* atual = f.frente;
    while (atual != nullptr) {
        cout << atual->valor << " ";
        atual = atual->prox;
    }
    cout << endl;
}

int main() {
    Pilha p;
    Fila f;
    inicializarPilha(p);
    inicializarFila(f);

    // Testando a pilha
    cout << "=== Teste Pilha ===" << endl;
    push(p, 10);
    push(p, 20);
    push(p, 30);
    imprimirPilha(p);
    pop(p);
    imprimirPilha(p);

    // Testando a fila
    cout << "\n=== Teste Fila ===" << endl;
    enqueue(f, 1);
    enqueue(f, 2);
    enqueue(f, 3);
    imprimirFila(f);
    dequeue(f);
    imprimirFila(f);

    return 0;
}
