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

char dequeue(Queue *q){
    char it;    
    if(!(q->size == 0)){
        it = q->front->next->element;
        Link *cache = q->front->next;
        q->front->next = q->front->next->next;
        delete cache;

        if(q->front->next == NULL){
            q->rear = q->front;
            q->size--;
        }
    }
    return it;
}
int main(void){
    //Queue *Fila = new Queue;

    string S;

    while(cin){
        cin >> S;
    }

    //enqueue(Fila, )


    return 0;
}

// 1º Passo: Criar a fila a qual será inserida a string. FEITO
// 2° Passo: receber a string. FEITO
// 3° Passo: inserir a string na fila 
// 4° Passo: fazer a operação de remoção da string "ABC"
// 5° Passo: printar a string final




// char S[200000];
// cin >> S;


// //Lista *abc = create_list(sizeof(S));
// typedef struct{
//     int maxSize;
//     int listSize;
//     int curr;
//     string *listArray;
// }Lista;

// Lista* create_list(int size){
//     Lista* l = new Lista;
//     l->maxSize = size;
//     l->curr = 0;
//     l->listSize = l->curr;
//     l->listArray = new string[size];
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

// void *moveToStart(Lista *l){
//     l->curr = 0;
// }

// void *moveToEnd(Lista *l){
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