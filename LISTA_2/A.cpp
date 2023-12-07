#include <iostream>
#include <string>

using namespace std;

int main() {
    string line;

    // Loop para processar vários casos de teste
    while (getline(cin, line)) {
        string beijuText = "";
        bool homePressed = false;

        // Iterar sobre cada caractere da linha
        for (char c : line) {
            if (c == '[') {
                homePressed = true;
            } else if (c == ']') {
                homePressed = false;
            } else {
                // Adicionar o caractere à string Beiju se a tecla "Home" não estiver pressionada
                if (!homePressed) {
                    beijuText += c;
                }
            }
        }

        // Imprimir o texto Beiju para o caso atual
        cout << beijuText << endl;
    }

    return 0;
}

// typedef struct{
//     int maxSize;
//     int listSize;
//     int curr;
//     int *listArray;
// }Lista;

// Lista* create_list(int size){
//     Lista* l = new Lista;
//     l->maxSize = size;
//     l->curr = 0;
//     l->listSize = l->curr;
//     l->listArray = new int[size];
//     return l;
// }

// void insert(Lista *l, char it){
//     if(l->listSize >= l->maxSize){
//         exit(1);
//     }
//     int i = l->listSize;

//     while(i > l->curr){
//         l->listArray[i] = l->listArray[i - 1];
//         i--;
//     }
//     l->listArray[l->curr] = it;
//     l->listSize++;
// }

// void moveToStart(Lista *l){
//     l->curr = 0;
// }

// void moveToEnd(Lista *l){
//     l->curr = l->listSize;
// }

// void prev(Lista *l){
//     if(l->curr != 0){
//         l->curr--;
//     }
// }

// void next(Lista *l){
//     if(l->curr < l->listSize){
//         l->curr++;
//     }
// }

// int remover(Lista *l){
//     if(l->curr < 0 || l->curr >= l->listSize){
//         return NULL;
//     }
//     int it = l->listArray[l->curr];
//     int i = l->curr;

//     while(i < l->listSize - 1){
//         l->listArray[i] = l->listArray[i+1];
//         i++;
//     }
//     l->listSize--;
//     return it;
// }

// int count(Lista *l, int x){
//     int count = 0;

//     for(int y = 0; y < l->listSize; y++){
//         if(x == l->listArray[y]){
//             count++;
//         }
//     }
//     return count;
// }

// bool find(Lista *l, int k){
//     int aux = k;
//     moveToStart(l);
//     while(l->curr < l->listSize){
//         if(k == l->listArray[aux]){
//             return true;
//         }
//         aux++;
//     }
//     return false;
// }
// int main(void){
//     char *text;
//     //Lista *Beiju = new Lista[100000];

//     // while(){
//     cin >> text;
//     int size = sizeof(text);
//     cout << size;
//     // Beiju = new Lista[sizeof(text)];

//     // for(unsigned int i{}; i < sizeof(text); i++){
//     //     insert(Beiju, text[i]);
//     // }

//     // for(int i{}; i < Beiju->listSize; i++){
//     //     cout << Beiju->listArray[i] << endl;
//     // }

//     delete[] Beiju->listArray;
//     delete Beiju;

//     return 0;
// }