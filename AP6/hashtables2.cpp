#include <iostream>
#include <list>

using namespace std;


typedef Entry{
    int key;
    int valor;
};
struct Link{
    int element;
    struct Link next;
};

typedef struct{
    Link *head;
    Link *tail;
    Link *curr;
    int cnt;//Quantidade de elementos da lista
}List;

typedef struct{
    int m;
    int cnt;
    List *H;
    int h;
}Dictionary;


int hashFunction(int key){
    return abs(key)%10;
}

Link *create_link(int it, Link *nextval){
    Link *n = new Link;
    n->element = it;
    n->next = nextval;

    return n;
}

List *create_list(){
    List *l = new List;
    l->head = create_link(0, 0);
    l->tail = l->head;
    l->curr = l->tail;
    l->cnt = 0;

    return l;
}

Dictionary *create_dict(int size){
    Dictionary *d = new Dictionary;
    d->m = size;
    d->cnt = 0;
    d->H = new List[size];

    for(int i{}; i <= size - 1; i++){
        d->H[i] = create_list();
    }
    return d; 
}

bool find(Dictionary *d, int key){
    int chave = hashFunction(key);

    if(d->H[chave].head->element == key){
        return true;
    }
    return false;
}

void 
void Insert(Dictionary *d, int key){
    int hashKey = hashFunction(key);

    if(!find(d, hashKey)){
        int pos = hashFunction(key);
        int L = d->H[pos];
        create_entry(hashKey, key);
    }
}

int main(void){
    int n{};
    int v{};

    cin >> n;

    Dictionary *d = create_dict(10);

    for(int i{}; i < n; i++){
        cin >> v;
        Insert(d, v)
    }

    return 0;
}