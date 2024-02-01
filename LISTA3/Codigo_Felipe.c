#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Link{
   char *element;
   int key;
   struct Link *next;
};

typedef struct{
   struct Link *head;
   struct Link *tail;
   struct Link *curr;
   int cnt;
} List;

struct Dictionary{
   int m;
   int cnt;
   List **H;
};

typedef struct{
   int key;
   char *valor;
} Entry;

struct Link *create_link(Entry entry, struct Link *nextval);
struct Link *create_link2(struct Link *nextval);
List *create_list();
Entry removing(List *I);
int h2(char *K);
struct Dictionary *create_dict(int size);
void insert2(struct Dictionary *d, int k, char *e);
void insert1(List *I, Entry entry);
int find (struct Dictionary *d, int k, int op, char *K);
void moveToStart(List *I);
void prev(List *I);
void next(List *I);

int main(){
   struct Dictionary *d;
   char op[4];
   char entrada[16];
   int testes;
   int operacoes;
   int k;
   int aux;
   Entry aux2;
   scanf("%d", &testes);
   for (int x = 0; x < testes; x++){
      d = create_dict(101);
      scanf("%d", &operacoes);
      for (int y = 0; y < operacoes; y++){
         scanf(" %4[^\n]%s", op, entrada);
         k = h2(entrada);
         if (strcmp(op, "ADD:") == 0){
            aux = find(d, k, 1, entrada);
            if (aux != -1){
               insert2(d, aux, entrada);
            }
         } else {
            aux = find(d, k, 2, entrada);
            if (aux != -1){
               aux2 = removing(d->H[aux]);
               d->cnt--;
            }
         }
      }
      printf("%d\n", d->cnt);
      for (int a = 0; a < 101; a++){
         if (d->H[a]->curr->next != NULL){
            printf("%d:%s\n", d->H[a]->curr->next->key,d->H[a]->curr->next->element);
         }
      }
   }
   free(aux2.valor);
   for (int i = 0; i < 101; i++){
      free(d->H[i]);
   }
   free(d);
   return 0;
}

struct Link *create_link(Entry entry, struct Link *nextval){
   struct Link *n;
   n = malloc(sizeof(struct Link));
   n->element = malloc(strlen(entry.valor) + 1);
   strcpy(n->element, entry.valor);
   n->key = entry.key;
   n->next = nextval;
   return n;
}

struct Link *create_link2(struct Link *nextval){
   struct Link *n;
   n = malloc(sizeof(struct Link));
   n->next = nextval;
   return n;
}

List *create_list(){
   List* I;
   I = (List*) malloc(sizeof(List));
   I->curr = create_link2(NULL);
   I->tail = create_link2(NULL);
   I->head = create_link2(NULL);
   I->cnt = 0;
   return I;
}

Entry removing(List *I){
   Entry it;
   if (I->curr->next == NULL){
       it.valor = NULL;
       it.key = -1;
   }
   it.valor = I->curr->next->element;
   it.key = I->curr->next->key;
   if (I->tail == I->curr->next){
       I->tail = I->curr;
   }
   I->curr->next = I->curr->next->next;
   I->cnt -= 1;
   return it;
}

int h2(char *K){
   int aux = 0;
   int tam = strlen(K);
   for (int x = 0; x < tam; x++){
      aux += K[x] * (x + 1);
   }
   return ((aux * 19) % 101);
}

struct Dictionary *create_dict(int size){
   struct Dictionary *d;
   d = (struct Dictionary*)malloc(sizeof(struct Dictionary));
   d->m = size;
   d->cnt = 0;
   d->H = (List**) malloc(sizeof(List) * size);
   for (int i = 0; i <= size - 1; i++){
      d->H[i] = (List*) malloc(sizeof(List));
      d->H[i] = create_list();
   }
   return d;
}

void insert2(struct Dictionary *d, int k, char *e){
   int var = find(d, k, 2, e);
   Entry entry;
   if (var == -1){
      entry.key = k;
      entry.valor = e;
      insert1(d->H[k], entry);
      d->cnt++;
   }
}

void insert1(List *I, Entry entry){
   I->curr->next = create_link(entry, I->curr->next);
   if(I->tail == I->curr){
       I->tail = I->curr->next;
   }
   I->cnt++;
}

int find (struct Dictionary *d, int k, int op, char *K){
   int cnt = 0;
   int aux = k;
   int aux2 = 0;
   int aux3 = 0;
   if (op == 1){
      while (cnt < 20){
         if (d->H[aux]->curr->next != NULL){
            if (strcmp(K,d->H[aux]->curr->next->element) == 0){
               return -1;
            }
         }
         aux = (abs((k + (cnt * cnt) + (23 * cnt)) % 101));
         cnt++;
         if (aux2 == 0 && d->H[aux]->curr->next == NULL){
            aux2 = 1;
            aux3 = aux;
         }
      }
      aux = aux3;
      if (d->H[aux]->curr->next == NULL){
         return aux;
      } else {
         return -1;
      }
   } else if (op == 2){
      while(cnt < 20){
         aux = (abs((k + (cnt * cnt) + (23 * cnt)) % 101));
         if(d->H[aux]->curr->next != NULL){
            if(strcmp(K, d->H[aux]->curr->next->element) == 0){
               return aux;
            }
         }
         cnt++;
      }
      if (d->H[aux]->curr->next != NULL){
         if (strcmp(K, d->H[aux]->curr->next->element) == 0){
            return aux;
         }
      }
      return -1;
   }
}

void moveToStart(List *I){
   I->curr = I->head;
}

void prev(List *I){
   if (I->curr == I->head){
       return;
   }
   struct Link *temp = I->head;
}

void next(List *I){
   if (I->curr != I->tail){
       I->curr = I->curr->next;
   }
}
