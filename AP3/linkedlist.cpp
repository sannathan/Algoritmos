#include <iostream>

using namespace std;

struct Link{
    int element;
    struct Link next;
};

typedef struct{
    Link *head;
    Link *tail;
    Link *curr;
    int cnt;
}List;

List *create_list(){
    List *l = new List;
    l->head = create_link(0, 0);
    l->tail = l->head;
    l->curr = l->tail;
    l->cnt = 0;

    return l;
}

Link *create_link(int it, Link *nextval){
    Link *n = new Link;
    n->element = it;
    n->next = &nextval;

    return n;
}

void insert(List *l, int it){
    l->curr.next = create_link(it, l->curr.next);

    if(l->tail.element == l->curr.element){
        l->tail = l->curr.next;
    }
    l->cnt++;
}

void moveToStar(List *l){
    l->curr = l->head;
}

void prev(List *l){
    if(l->curr.element == l->head.element){
        return;
    }
    Link temp = l->head;

    while(temp.next != l->curr.element){
        temp = temp.next;
    }
    l->curr = temp;
}

void next(List *l){
    if(l->curr.element != l->tail.element){
        l->curr.next;
    }
}

int remove(List *l){
    if(l->curr.next == NULL){
        return NULL;
    }
    int it = l->curr.next.element;

    if(l->tail == l->curr.next){
        l->tail = l->curr;
    }
    l->curr.next = l->curr.next.next;
    l->cnt--;

    return it;
}
int main(void){
    int c;
    cin >> c;
    int n[c];
    List *lista = create_list();
    for(int x = 0; x < c; x++){
        cin >> n[x];
        string op;
        int valor;
        for(int y = 0; y < n[x]; y++){
            cin >> op;
            cin >> valor;

            if(op == "insert"){
                insert(lista, valor);
            }
            else if(op == "remove"){
                recebe = remove(lista);
            }
            else if(op == "count"){
                numIguais[i] = count(lista, valor);
                i++;
                vezes++;
            }
            else if(op == "prev"){
                prev(lista);
            }
            else if(op == "next"){
                next(lista);
            }
        }
    }
    return 0;
}