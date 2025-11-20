#include <iostream>
#include <stack>
using namespace std;

class BSTNode{
    public:
        int key;
        int element;
        int height;
        BSTNode *left;
        BSTNode *right;
};

class BST{
    public:
        BSTNode *root; //Raiz da arvore
        int nodecount; //Qtd de nós da árvore

    BST *create_bst(){
        BST *bst = new BST;
        bst->root = NULL;
        bst->nodecount = 0;
        return bst;
    }
};

BSTNode *create_bstnode(int k, int e){
    BSTNode *n = new BSTNode;
    n->key = k;
    n->element = e;
    n->left = NULL;
    n->right = NULL;
    n->height = 0;
    return n;
}

int h(BSTNode *rt){
    if(rt == NULL){
        return -1;
    }
    return rt->height;
}

int getBalance(BSTNode *rt){
    if(rt == NULL){
        return 0;
    }
    else{
        return h(rt->left) - h(rt->right); 
    }
}

BSTNode *leftRotate(BSTNode *rt){
    BSTNode *r = rt->right;
    BSTNode *rl = r->left;
    
    r->left = rt;
    rt->right = rl;
    
    rt->height = max(h(rt->left), h(rt->right)) + 1;
    r->height = max(h(r->left), h(r->right)) + 1;
    
    return r;
}

BSTNode *rightRotate(BSTNode *rt){
    BSTNode *l = new BSTNode;
    BSTNode *lr = new BSTNode;
    l = rt->left;
    lr = l->right;
    l->right = rt;
    rt->left = lr;
    rt->height = max(h(rt->left), h(rt->right)) + 1;
    l->height = max(h(l->left), h(l->right)) + 1;
    return l;
}

BSTNode *inserthelp(BSTNode *rt, int k, int e){
    if(rt == NULL){
        return create_bstnode(k, e);
    }
    if(rt->key > k){
        rt->left = inserthelp(rt->left, k, e);
    }
    else if(k > rt->key){
        rt->right = inserthelp(rt->right, k, e);
    }
    else{
        return rt;
    }

    rt->height = 1 + max(h(rt->left), h(rt->right));

    int balance = getBalance(rt); 

    if(balance > 1 && k < rt->left->key){
        return rightRotate(rt);
    }

    if(balance < -1 && k >= rt->right->key){
        return leftRotate(rt);
    }

    if(balance > 1 && k >= rt->left->key){
        rt->left = leftRotate(rt->left);
        return rightRotate(rt);
    }
    if(balance < -1 && k <rt->right->key){
        rt->right = rightRotate(rt->right);
        return leftRotate(rt);
    }
    return rt;
}

void insert(BST *bst, int k, int e){
    bst->root = inserthelp(bst->root, k, e);

    bst->nodecount++;
}

int encontrarIndice(BSTNode *root, int x){
    int index = 1;
    BSTNode *current = root;
    while(current != NULL){
        if(x == current->element){
            return index; 
        }
        else if(x > current->element){
            current = current->left;
            index++;
        }
        else{
            if(current->right != NULL){
                index += (current->left != NULL ? current->left->key : 0) + 1;
                current = current->right;
            }
            else{
                break;
            }
        }
    }
    return -1;
}

/*void updateKeys(BSTNode* root) {
  int index = 1; // inicia o índice com 1
  BSTNode* current = root; // inicia o nó atual com a raiz
  stack<BSTNode*> stack; // cria uma pilha para armazenar os nós visitados
  while (current != NULL || !stack.empty()) { // enquanto o nó atual não for nulo ou a pilha não estiver vazia
    while (current != NULL) { // enquanto o nó atual não for nulo
      stack.push(current); // empilha o nó atual
      current = current->left; // vai para a subárvore esquerda
    }
    current = stack.top(); // desempilha o nó atual
    stack.pop(); // remove o nó atual da pilha
    current->key = index; // atribui o índice à chave do nó atual
    index++; // incrementa o índice
    current = current->right; // vai para a subárvore direita
  }
}
*/
// int chaveLivre(BSTNode *root){
//     int chave = 1; // inicia a chave com 1
//     BSTNode *atual = root; // inicia o nó atual com a raiz
//     stack<BSTNode*> pilha; // cria uma pilha para armazenar os nós visitados
//     while (atual != NULL || !pilha.empty()){ // enquanto o nó atual não for nulo ou a pilha não estiver vazia
//         while (atual != NULL){ // enquanto o nó atual não for nulo
//             pilha.push(atual); // empilha o nó atual
//             atual = atual->left; // vai para a subárvore esquerda
//         }
//         atual = pilha.top(); // desempilha o nó atual
//         pilha.pop(); // remove o nó atual da pilha
//         if (atual->key == chave){ // se a chave do nó atual for igual à chave
//             chave++; // incrementa a chave
//         }
//         else if (atual->key > chave){ // se a chave do nó atual for maior que a chave
//             return chave; // retorna a chave como uma chave livre
//         }
//         atual = atual->right; // vai para a subárvore direita
//     }
//     return chave; // se não encontrar uma chave livre, retorna a próxima chave disponível
// }


int main(void){
    int Q, op, x, k;

    cin >> Q;

    BST *avl = new BST;
    avl->create_bst();

    for(int i = 1; i <= Q; i++){
        cin >> op >> x;

        switch (op){
            case 1:
                insert(avl, i, x);
                //updateKeys(avl->root);
                break;
            case 2:
                k = encontrarIndice(avl->root, x);
                if(k == -1){
                    cout << "Data tidak ada" << endl;
                }
                else{
                    cout << k << endl;
                }
                break;
            default:
                break;
        }
    }
    return 0;
}