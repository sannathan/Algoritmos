# Algoritmos e Estruturas de Dados

Repositório contendo códigos de estudo da disciplina **CIN0135 - Estruturas de Dados Orientadas a Objetos** e **IF672 - Algoritmos e Estruturas de Dados**, incluindo implementações em C e C++ de diversos algoritmos clássicos, estruturas de dados e exercícios práticos.

## 📁 Estrutura do Projeto

```
Algoritmos/
├── Code/                              # Códigos de exercícios e avaliações
│   ├── APs/                          # Avaliações Práticas (AP1-AP12)
│   ├── EPs/                          # Exercícios Práticos (EP1-EP4)
│   ├── Lists/                        # Listas de Exercícios (LISTA1-LISTA8)
│   └── PRATICA/                      # Exemplos práticos e POO
│
└── DataStructuresImplementation/     # Implementações de estruturas de dados
    ├── ArrayBasedStack.h             # Interface da pilha baseada em array
    └── ArrayBasedStack.cpp           # Implementação da pilha
```

## 🔍 Principais Tópicos Implementados

### Algoritmos de Ordenação
- **Merge Sort** (`Code/APs/AP1/merge_sort.c`)
- **Quick Sort** (`Code/APs/AP2/quicksort.c`)
- **Selection Sort** (`Code/PRATICA/Selection_sort.c`)

### Algoritmos de Busca
- **Busca Binária** (`Code/APs/AP2/binary_search.c`)

### Estruturas de Dados
- **Pilhas (Stack)**
  - Implementação com array (`DataStructuresImplementation/ArrayBasedStack.cpp`)
  - Exemplos práticos (`Code/Lists/LISTA1/BalancedBrackets.cpp`)
- **Listas**
  - ArrayList (`Code/APs/AP3/arraylist.cpp`)
  - LinkedList (`Code/APs/AP3/linkedlist.cpp`)
- **Tabelas Hash** (`Code/APs/AP6/hashtables1.cpp`, `Code/Lists/LISTA3/Hash_it.cpp`)
- **Árvores** (`Code/Lists/LISTA3/Traversing_Tree.cpp`)

### Grafos
- **Algoritmo de Dijkstra** (`Code/APs/AP11/Dijkstra.cpp`)
- **Representação de grafos** (`Code/Lists/LISTA5/graph.cpp`)

### Programação Orientada a Objetos
- Exemplos práticos em C++ (`Code/PRATICA/POO1.CPP`, `POO2.cpp`, `POO3.cpp`)
- Templates e classes abstratas (`DataStructuresImplementation/`)

## 🚀 Como Compilar e Executar

### Compilar arquivos C
```bash
gcc arquivo.c -o executavel
./executavel
```

### Compilar arquivos C++
```bash
g++ arquivo.cpp -o executavel
./executavel
```

### Usando estruturas de dados implementadas
```cpp
#include "DataStructuresImplementation/ArrayBasedStack.h"

int main() {
    AStack<int> pilha;
    pilha.push(10);
    pilha.push(20);
    cout << pilha.pop() << endl;  // 20
    return 0;
}
```

## 📚 Objetivo

Este repositório serve como:
- 📖 Base de estudos e consulta de algoritmos fundamentais
- 💻 Prática de implementação de estruturas de dados
- 🎯 Preparação para avaliações acadêmicas
- 🏆 Treino para competições de programação

## 📝 Observações

- Arquivos executáveis e pastas `output/` são ignorados pelo Git
- Implementações seguem padrões de POO quando aplicável
- Código documentado e organizado para facilitar o aprendizado