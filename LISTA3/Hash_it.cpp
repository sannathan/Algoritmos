#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <random>

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

struct Entry{
    int key;
    string value;
};

typedef struct{
    int m;
    int cnt;
    Entry *H;
    vector<int> Perm;

    int Hash(string key){
        int hashKey{};
            for(int i{}; i < key.length(); i++){
                if(i == 0){
                    int ascii = key[i];
                    hashKey += 19 * ascii * (i+1);
            }
            else{
                int ascii = key[i];
                hashKey += ascii * (i+1);
            }
        }
        return hashKey % 101;
    }

    vector<int> createPermutation(int size){
        vector<int> permutation(size + 1);
        for(int i{}; i <= size; i++){
            permutation[i] = i + 1;
        }
        random_device rd;
        mt19937 g(rd());
        shuffle(permutation.begin(), permutation.end(), g);
        return permutation;
    }
}Dictionary;

Dictionary *create_dict(){
    Dictionary *d = new Dictionary;
    d->m = 101;
    d->cnt = 0;
    d->H = new Entry[101];
    d->Perm = d->createPermutation(99);
    return d;
}

List *create_list(){
    List *l = new List;
    l->head = new Link;
    l->head->next = NULL;
    l->tail = l->head;
    l->curr = l->tail;
    l->cnt = 0;

    return l;
}

bool find(Dictionary *d, string k){
    int hashKey = d->Hash(k);
    if(d->H[hashKey].value == k){
        return true;
    }
    else{
        for(int j{}; j < 19; j++){
            if(d->H[(hashKey + j*j + 23*j)%101].value == k){
                return true;
            }
        }
    }
    return false;
}

void insert(Dictionary *d, string k){
    int offset, newPos, pos;
    if(find(d,k) == NULL){
        pos = d->Hash(k);
        if(d->H[pos].value != "deleted"){
            int i{};
            do{
                i = i+1;
                offset = d->Perm[i-1];
                newPos = (pos + offset)%d->m;
            }while(!(d->H[newPos].value == "deleted"));
        }
    }
    d->H[pos].key = pos;
    d->H[pos].value = k;
    d->cnt++;
}


int main(void){
     int t, n1, starPos = 0, lenght = 3;
     string nome;
     int size = 101;
     Dictionary *d = create_dict(size);

     cin >> t >> n1;

     for(int i{}; i < n1; i++){
        cin >> nome;

        string opcao = nome.substr(starPos, lenght);
        cout << opcao;
        if(opcao == "ADD"){
            insert(d, )
        }
        else if(opcao == "DEL"){
            cout << "DEL";
        }
    }

    return 0;
}