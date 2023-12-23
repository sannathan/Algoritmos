#include <iostream>

using namespace std;

typedef struct bstnode{
    int key;
    int element;
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
    return n;
}

int findhelp(BSTNode *rt, int k){
    if(rt == NULL){
        return -1;
    }
    if(rt->key > k){
        return findhelp(rt->left, k);
    }
    else if(rt->key == k){
        return rt->element;
    }
    else{
        return findhelp(rt->right, k);
    }
}

int find(BST *bst,int k){
    return findhelp(bst->root, k);
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
    return rt;
}

void insert(BST *bst, int k, int e){
    bst->root = inserthelp(bst->root, k, e);
    bst->nodecount++;
}



void preorder(BSTNode *rt){
    if(rt != NULL){
        cout << rt->element << " ";
        preorder(rt->left);
        preorder(rt->right);
    }
}

void inorder(BSTNode *rt){
    if(rt != NULL){
        inorder(rt->left);
        cout << rt->element << " ";
        inorder(rt->right);
    }
}

void posorder(BSTNode *rt){
    if(rt != NULL){
        posorder(rt->left);
        posorder(rt->right);
        cout << rt->element << " ";
    }
}

int main(void){
    int n, data;
    BST *arvere = create_bst();
    cin >> n;

    for(int i{}; i < n; i++){
        cin >> data;
        insert(arvere, data, data);
    }

    cout << "Pre order : ";
    preorder(arvere->root);

    cout << endl;

    cout << "In order  : ";
    inorder(arvere->root);

    cout << endl;

    cout << "Post order: ";
    posorder(arvere->root);

    cout << endl;
    return 0;
}