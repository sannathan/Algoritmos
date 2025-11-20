#include <iostream>
#include <stack>
using namespace std;

class BSTNode {
public:
    int key;
    int element;
    int height;
    int size; // Adiciona o tamanho da subárvore
    BSTNode *left;
    BSTNode *right;

    BSTNode(int k, int e) : key(k), element(e), height(1), size(1), left(nullptr), right(nullptr) {}
};

class BST {
public:
    BSTNode *root; // Raiz da árvore

    BST() : root(nullptr) {}

    // Insere um novo nó na árvore
    void insert(int k, int e) {
        root = inserthelp(root, k, e);
    }

private:
    // Retorna a altura do nó
    int height(BSTNode *rt) {
        if (rt == nullptr) return 0;
        return rt->height;
    }

    // Retorna o tamanho da subárvore
    int getSize(BSTNode *rt) {
        if (rt == nullptr) return 0;
        return rt->size;
    }

    // Realiza a rotação para a esquerda
    BSTNode* leftRotate(BSTNode *rt) {
        BSTNode *r = rt->right;
        BSTNode *rl = r->left;

        r->left = rt;
        rt->right = rl;

        rt->height = max(height(rt->left), height(rt->right)) + 1;
        r->height = max(height(r->left), height(r->right)) + 1;

        rt->size = getSize(rt->left) + getSize(rt->right) + 1;
        r->size = getSize(r->left) + getSize(r->right) + 1;

        return r;
    }

    // Realiza a rotação para a direita
    BSTNode* rightRotate(BSTNode *rt) {
        BSTNode *l = rt->left;
        BSTNode *lr = l->right;

        l->right = rt;
        rt->left = lr;

        rt->height = max(height(rt->left), height(rt->right)) + 1;
        l->height = max(height(l->left), height(l->right)) + 1;

        rt->size = getSize(rt->left) + getSize(rt->right) + 1;
        l->size = getSize(l->left) + getSize(l->right) + 1;

        return l;
    }

    // Insere um novo nó recursivamente
    BSTNode* inserthelp(BSTNode *rt, int k, int e) {
        if (rt == nullptr) return new BSTNode(k, e);

        if (k < rt->key) rt->left = inserthelp(rt->left, k, e);
        else if (k > rt->key) rt->right = inserthelp(rt->right, k, e);
        else return rt; // Ignora chaves duplicadas

        // Atualiza a altura do nó atual
        rt->height = max(height(rt->left), height(rt->right)) + 1;

        // Atualiza o tamanho da subárvore
        rt->size = getSize(rt->left) + getSize(rt->right) + 1;

        int balance = height(rt->left) - height(rt->right);

        // Caso de desbalanceamento para esquerda
        if (balance > 1 && k < rt->left->key)
            return rightRotate(rt);

        // Caso de desbalanceamento para direita
        if (balance < -1 && k > rt->right->key)
            return leftRotate(rt);

        // Caso de desbalanceamento esquerda-esquerda
        if (balance > 1 && k > rt->left->key) {
            rt->left = leftRotate(rt->left);
            return rightRotate(rt);
        }

        // Caso de desbalanceamento direita-direita
        if (balance < -1 && k < rt->right->key) {
            rt->right = rightRotate(rt->right);
            return leftRotate(rt);
        }

        return rt;
    }
};

// Encontra o índice de um elemento na árvore
int encontrarIndice(BSTNode *root, int x) {
    int index = 1;
    BSTNode *current = root;
    while (current != nullptr) {
        if (x == current->element) {
            index += (current->left != nullptr ? current->left->size : 0); 
            return index;
        } else if (x < current->element) {
            current = current->left;
            index++;
        } else {
            index += (current->left != nullptr ? current->left->size : 0) + 1;
            current = current->right;
        }
    }
    return -1;
}

int main(void) {
    int Q, op, x, k;

    cin >> Q;

    BST avl;

    for (int i = 1; i <= Q; i++) {
        cin >> op >> x;

        switch (op) {
            case 1:
                avl.insert(i, x);
                break;
            case 2:
                k = encontrarIndice(avl.root, x);
                if (k == -1)
                    cout << "Data tidak ada" << endl;
                else
                    cout << k << endl;
                break;
            default:
                break;
        }
    }

    return 0;
}
