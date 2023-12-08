#include <iostream>
#include <cstring>

using namespace std;

typedef struct link{
    char element;
    link *next;
}Link ;

typedef struct{
    Link *front;
    Link *rear;
    int size;
}Queue;

Link *create_link(Link *nextval){
    Link *n = new Link;
    n->next = nextval;
    return n; 
}

Link *create_linkao(char it, Link *nextval){
    Link *n = new Link;
    n->element = it;
    n->next = nextval;
    return n;
}

Queue *create_queue(){
    Queue *q = new Queue;
    q->rear = create_link(NULL);
    q->front = q->rear;
    q->size = 0;
    return q;
}

void enqueue(Queue *q, char it){
    q->rear->next = create_linkao(it, NULL);
    q->rear = q->rear->next;
    q->size++;
}

void dequeue(Queue *q){
    char it;    
    if(q->size != 0){
        it = q->front->next->element;
        Link *cache = q->front->next;
        q->front->next = q->front->next->next;
        delete cache;

        if(q->front->next == NULL){
            q->rear = q->front;
        }
        q->size--;
    }
}
int main(void){
    Queue *Fila = create_queue();

    char S[200001];

    cin >> S;

    int tamString = sizeof(S);

    for(int i{}; i < tamString; i++){
        enqueue(Fila, S[i]);

        if(i > 2){
            if(S[i] == 'C' && S[i-1] == 'B' && S[i-2] == 'A'){
            dequeue(Fila);
            dequeue(Fila);
            dequeue(Fila);
            }
            else if(S[i] == 'B' && S[i-1] == 'A' && S[i+1] == 'C' && i < tamString - 1){
            dequeue(Fila); 
            dequeue(Fila);
            dequeue(Fila);
            }
            else if(S[i] == 'A' && S[i+1] == 'B' && S[i+2] == 'C' && i < tamString - 2){
            dequeue(Fila);
            dequeue(Fila);
            dequeue(Fila);
            }  
        }
    }

    cout << "Elementos da fila: ";
    
    while (Fila->front->next != NULL) {
        cout << Fila->front->next->element;
        dequeue(Fila);
    }

    cout << endl;

    while (Fila->front->next != NULL) {
        Link *temp = Fila->front->next;
        Fila->front->next = temp->next;
        delete temp;
    }

    delete Fila;

    return 0;
}

// 1º Passo: Criar a fila a qual será inserida a string. FEITO
// 2° Passo: receber a string. FEITO
// 3° Passo: inserir a string na fila FEITO
// 4° Passo: fazer a operação de remoção da string "ABC"
// 5° Passo: printar a string final

/* Se encontrar a e o próximo for b e o próximo do próximo for c{
        remove(a);
        remove(b);
        remove(c);
    }
    caso contrário, se encontra b, o anterior for a e o próximo c{
        remove(a);
        remove(b);
        remove(c);
    }
    caso contrário, se encontrar c, e o anterior for b e o anterior do anterior for a{
        remove(a);
        remove(b);
        remove(c);
    }


        while(i < tamString){
        if(S[i] == 'C' && S[i-1] == 'B' && S[i-2] == 'A'){
            dequeue(Fila);
            dequeue(Fila);
            dequeue(Fila);
            tamMax += 1;
            i -= 3;
        }
        else if(S[i] == 'B' && S[i-1] == 'A' && S[i+1] == 'C' && i < tamString - 1){
            dequeue(Fila); 
            dequeue(Fila);
            dequeue(Fila);
            tamMax += 1;
            i -= 3;
        }
        else if(S[i] == 'A' && S[i+1] == 'B' && S[i+2] == 'C' && i < tamString - 2){
            dequeue(Fila);
            dequeue(Fila);
            dequeue(Fila);
            tamMax += 1;
            i -= 3;
        }
        else{
            if(tamMax == valor && i == 0){
                i--;
            }
            else if(i == 0 && tamMax < valor){
                i = (tamString - 1) - (tamMax*3);
                
                while (Fila->front->next != NULL) {
                    cout << Fila->front->next->element << " ";
                    dequeue(Fila);
                }
                
                cout << endl;
            }
            else{
                i--;
            }

        }
    }
*/    