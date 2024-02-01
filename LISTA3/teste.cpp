#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <random>

using namespace std;

struct Entry{
    int key;
    string value;
};

typedef struct{
    int m;
    int cnt;
    Entry *H;
    vector<int> Perm;

    int Hash(string key) {
        int hashKey{};
        for (int i = 1; i <= key.length(); i++) {
            int ascii = key[i - 1];  // Ajuste aqui
            hashKey += ascii * i;
        }
        return (19 * hashKey) % 101;
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
    d->Perm = d->createPermutation(100);
    return d;
}

bool find(Dictionary *d, string k){
    int hashKey = d->Hash(k);
    if(d->H[hashKey].value == k){
        return true;
    }
    else{
        for(int j = 1; j <= 19; j++){
            if(d->H[(hashKey + j*j + 23*j)%101].value == k){
                return true;
            }
        }
    }
    return false;
}



void insert(Dictionary *d, string k) {
    int offset, newPos, pos;
    if (!find(d, k)) {
        pos = d->Hash(k);
        int i{};
        do {
            i = i + 1;
            offset = d->Perm[i - 1];
            newPos = (pos + offset) % d->m;
        } while (d->H[newPos].value != "deleted" && !d->H[newPos].value.empty());
        pos = newPos;

        d->H[pos].key = pos;
        d->H[pos].value = k;
        d->cnt++;
    }
}

void remove(Dictionary *d, string k) {
    int hashKey = d->Hash(k);
    if (find(d, k)) {
        for (int j = 0; j < 19; j++) {  // Ajuste aqui
            int newPos = (hashKey + j * j + 23 * j) % d->m;
            if (d->H[newPos].value == k) {
                d->H[newPos].value = "deleted";
                d->cnt--;
                break;
            }
        }
    }
}


void desalocar(Dictionary *d){
    delete d->H;
    delete d;
}
int main(void){
     int t, n1, starPos1 = 0, lenght1 = 3, starPos2 = 4;
     string nome;
     int size = 101;
     Dictionary *d = create_dict();

     cin >> t >> n1;

     for(int i{}; i < n1; i++){
        cin >> nome;

        string opcao = nome.substr(starPos1, lenght1);
        string chave = nome.substr(starPos2);

        if(opcao == "ADD"){
            insert(d, chave);
        }
        else if(opcao == "DEL"){
            remove(d, chave);
        }
    }

    cout << d->cnt << endl;
    for(int i{}; i < d->m; i++){
        if(d->H[i].value != "deleted" && !d->H[i].value.empty()){
            cout << i << ":" << d->H[i].value << endl;
        }
    }

    desalocar(d);
    return 0;
}
//Insert
// int offset, newPos, pos;
//     if(!find(d,k)){
//         pos = d->Hash(k);
//         if(d->H[pos].value == "deleted" || d->H[pos].value.empty()){
//             int i{};
//             do{
//                 i = i+1;
//                 offset = d->Perm[i-1];
//                 newPos = (pos + offset)%d->m;
//             }while((d->H[newPos].value != "deleted" && !d->H[newPos].value.empty()));
//             pos = newPos;
//         }
//         d->H[pos].key = pos;
//         d->H[pos].value = k;
//         d->cnt++;
//     }

//Remove
// int hashKey = d->Hash(k);
//     if(d->H[hashKey].value == k){
//         d->H[hashKey].value = "deleted";
//         d->cnt--;
//     }
//     else{
//         for(int j{}; j < 19; j++){
//             if(d->H[(hashKey + j*j + 23*j)%101].value == k){
//                 d->H[(hashKey + j*j + 23*j)%101].value = "deleted";
//                 d->cnt--;
//                 break;
//             }
//         }
//     }