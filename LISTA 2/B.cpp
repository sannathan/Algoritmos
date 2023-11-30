#include <iostream>

using namespace std;

typedef struct{
    int maxSize;
    int listSize;
    int curr;
    string *listArray;
}Lista;

Lista* create_list(int size){
    Lista* l = new Lista;
    l->maxSize = size;
    l->curr = 0;
    l->listSize = l->curr;
    l->listArray = new string[size];
    return l;
}

void insert(Lista *l, char it){
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
    string S;
    cin >> S;

    Lista *abc = create_list(sizeof(S));


    return 0;
}