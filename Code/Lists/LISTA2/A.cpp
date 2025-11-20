#include <iostream>
#include <cstring>

using namespace std;

typedef struct link{
    char element;
    struct link *next;
}Link;

typedef struct{
    Link *head;
    Link *tail;
    Link *curr;
    int cnt;
}List;

List *create_list(){
    List *l = new List;
    l->head = new Link;
    l->head->next = NULL;
    l->tail = l->head;
    l->curr = l->tail;
    l->cnt = 0;

    return l;
}

void insert(List *l, char it){
    Link *newLink = new Link;
    newLink->element = it;
    newLink->next = l->curr->next;
    l->curr->next = newLink;
    if(l->curr == l->tail){
        l->tail = l->curr->next;
    }
    l->cnt++;
}

void moveToStart(List *l){
    l->curr = l->head;
}

void moveToEnd(List *l){
    l->curr = l->tail;
}

int main() {
    string line;

    // Loop para processar vários casos de teste
    while (getline(cin, line)) {
        List *lista = create_list();
        // Iterar sobre cada caractere da linha
        for (char c : line) {
            if (c == '[') {
                moveToStart(lista);
            } 
            else if (c == ']') {
                moveToEnd(lista);
            } 
            else {
                // Adicionar o caractere à string Beiiu se a tecla "Home" não estiver pressionada
                insert(lista, c);
            }
        }
        Link *temp = lista->head->next;
        while(temp != NULL){
            cout << temp->element;
            temp = temp->next;
        }
        cout << endl;
    }
    return 0;
}
