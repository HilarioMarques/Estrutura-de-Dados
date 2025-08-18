# Estrutura-de-Dados

# Estrutura `realType` em C

Este projeto demonstra como representar números reais em C utilizando uma `struct` que separa a parte inteira e a parte fracionária.

---

## Estrutura

```c
typedef struct {
    int esquerda;  // Parte inteira (esquerda do ponto decimal)
    int direita;   // Parte fracionária (direita do ponto decimal)
} realTipo;

Item (a) - Criar número real a partir de string

A função criarReal recebe uma string com um número real (ex: "12.34") e converte para a estrutura realTipo.

realTipo criarReal(const char *entrada);


Exemplo:

Entrada: "12.34"
Estrutura: esquerda = 12, direita = 34

Item (b) - Converter estrutura para número real

A função structPaReal recebe uma struct realTipo e retorna o número real (double) correspondente.

double structPaReal(realTipo numero);


Exemplo:

Entrada: esquerda = 12, direita = 34
Saída: 12.34

Item (c) - Operações matemáticas

Foram implementadas três funções para realizar operações entre dois números representados pela estrutura realTipo:

realTipo add(realTipo a, realTipo b);       // soma
realTipo subtract(realTipo a, realTipo b);  // subtração
realTipo multiply(realTipo a, realTipo b);  // multiplicação

Funcionamento

Convertem a estrutura para double usando structPaReal;

Realizam a operação matemática;

Convertem o resultado de volta para realTipo.