#include <iostream>
#include <stack>

using namespace std;

int main(void){
    stack <int> pilha1, pilha2;

    pilha1.push(10); //Método que faz inserção 
    pilha1.push(20);
    pilha1.push(30);

    pilha2.push(40);
    pilha2.push(50);
    pilha2.push(60);
    pilha2.emplace(70); //Método que também faz a inserção

    pilha2.swap(pilha1); //Método que troca todos os elementos da pilha2 para pilha1


    while(!pilha1.empty()){
        cout << pilha1.top() << endl; //Retorna uma referência para o topo da pilha
        pilha1.pop(); //Retira o elemento do topo da pilha
    }

    if(pilha1.empty()){
        cout << "Pilha vazia" << endl;
    }
    else{
        cout << "Pilha contem elementos" << endl;
    }
}