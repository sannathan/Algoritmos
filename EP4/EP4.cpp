#include <iostream>

using namespace std;

typedef struct bstnode{
    int key;
    int element;
    int height;
    struct bstnode *left;
    struct bstnode *right;
}BSTNode;

typedef struct{
    BSTNode *root; //Raiz da arvore
    int nodecount; //Qtd de nós da árvore
}BST;

BST *create_bst(){
    BST *bst = new BST;
    bst->root = NULL;
    bst->nodecount = 0;
    return bst;
}

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

BSTNode *leftRotate(BSTNode *rt){
    BSTNode *r = rt->right;
    BSTNode *rl = r->left;
    
    r->left = rt;
    rt->right = rl;
    
    rt->height = max(h(rt->left), h(rt->right)) + 1;
    r->height = max(h(r->left), h(r->right)) + 1;
    
    return r;
}

BSTNode *inserthelp(BSTNode *rt, int k, int e){
    if(rt == NULL){
        return create_bstnode(k, e);
    }
    if(rt->key > k){
        rt->left = inserthelp(rt->left, k, e);
    }
    else{
        rt->right = inserthelp(rt->right, k, e);
    }
    rt->height = 1 + max(h(rt->left), h(rt->right));
    int balance = getBalance(rt); 
    if(balance < -1 && k >= rt->right->key){
        return leftRotate(rt);
    }
    if(balance > 1 && k < rt->left->key){
        return rightRotate(rt);
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

void preorder(BSTNode *rt){
    if(rt != NULL){
        cout << rt->key << endl;
        preorder(rt->left);
        preorder(rt->right);
    }
}
int main(void){
    int c, key;
    cin >> c;
    int n;

    for(int i{}; i < c; i++){
        cin >> n;
        BST *a1 = create_bst();
        for(int j{}; j < n; j++){
            cin >> key;
            insert(a1, key, key);
        }
        preorder(a1->root);
        cout << "END" << endl;
        delete a1;
        a1 = NULL;
    }


    return 0;
}




