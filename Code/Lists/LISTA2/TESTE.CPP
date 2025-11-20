#include <iostream>

using namespace std;

typedef struct link{
    char element;
    link *next;
}Link;

typedef struct{
    Link *top;
    int size;
}Stack;

Stack *create_stack(){
    Stack *s = new Stack;
    s->top = NULL;
    s->size = 0;

    return s;
}

Link *create_link(char it, Link *nextval){
    Link *n = new Link;
    n->element = it;
    n->next = nextval;
    return n;
}

void push(Stack *s, char it){
    s->top = create_link(it, s->top);
    s->size++;
}

void pop(Stack *s){
    if(s->top != NULL){
        s->top = s->top->next;
        s->size--;
    }
}
    
int main(void){
    Stack *pilha = create_stack();

    string S;

    cin >> S;

    for(char c : S){
        if(c == 'C') {
            if(pilha->size != 0 && pilha->top->element == 'B'){
                pop(pilha);

                if(pilha->size != 0 && pilha->top->element == 'A'){
                    pop(pilha);
                }
                else{
                    push(pilha, 'B');
                    push(pilha, c);
                }
            }
            else{
                push(pilha, c);
            }   
        }
        else{
            push(pilha, c);
        }
        
    }

    string resultado = "";
    while(pilha->size != 0){
        resultado = pilha->top->element + resultado;
        pop(pilha);
    }

    cout << resultado << endl;

    delete pilha;

    return 0;
}