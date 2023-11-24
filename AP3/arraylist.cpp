#include <iostream>

using namespace std;

typedef struct{
    int maxSize;
    int listSize;
    int curr;
    int *listArray;
}Lista;

Lista* create_list(int size){
    Lista* l = new Lista;
    l->maxSize = size;
    l->curr = 0;
    l->listSize = l->curr;
    l->listArray = new int[size];
    return l;
}

void insert(Lista *l, int it){
    if(l->listSize >= l->maxSize){
        exit(1);
    }
    int i = l->listSize;

    while(i > l->curr){
        l->listArray[i] = l->listArray[i - 1];
        i--;
    }
    l->listArray[l->curr] = it;
    l->listSize++;
}

void *moveToStart(Lista *l){
    l->curr = 0;
}

void *moveToEnd(Lista *l){
    l->curr = l->listSize;
}

void prev(Lista *l){
    if(l->curr != 0){
        l->curr--;
    }
}

void next(Lista *l){
    if(l->curr < l->listSize){
        l->curr++;
    }
}

int remover(Lista *l){
    if(l->curr < 0 || l->curr >= l->listSize){
        return NULL;
    }
    int it = l->listArray[l->curr];
    int i = l->curr;

    while(i < l->listSize - 1){
        l->listArray[i] = l->listArray[i+1];
        i++;
    }
    l->listSize--;
    return it;
}

int count(Lista *l, int x){
    int count = 0;

    for(int y = 0; y < l->listSize; y++){
        if(x == l->listArray[y]){
            count++;
        }
    }
    return count;
}
int main(void){
    int c, vezes = 0, recebe, i = 0;
    cin  >> c;

    Lista *l = create_list(c);

    for(int x = 0; x < c; x++){
        cin >> l->maxSize;
        vezes = 0;
        string op;
        int valor, numIguais[l->maxSize];

        for(int y = 0; y < l->maxSize; y++){
            cin >> op;
            cin >> valor;

            if(op == "insert"){
                insert(l, valor);
            }
            else if(op == "remove"){
                recebe = remover(l);
            }
            else if(op == "count"){
                numIguais[i] = count(l, valor);
                i++;
                vezes++;
            }
            else if(op == "prev"){
                prev(l);
            }
            else if(op == "next"){
                next(l);
            }
        }
        cout << "Caso " << x+1 << ": " << endl;
        for(int z = 0; z < vezes; z++){
            cout << numIguais[z] << endl;
        }
    }

    delete[] l->listArray;
    delete l;

    return 0;
}