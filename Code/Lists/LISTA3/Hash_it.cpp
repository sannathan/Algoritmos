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

    int Hash(string key){
        int hashKey{};
            for(int i{}; i < key.length(); i++){
                int ascii = key[i];
                hashKey += ascii * (i+1);
            }
        return (19 * hashKey) % 101;
    }
}Dictionary;

Dictionary *create_dict(){
    Dictionary *d = new Dictionary;
    d->m = 101;
    d->cnt = 0;
    d->H = new Entry[101];
    return d;
}

int find(Dictionary *d, string k){
    int hashKey = d->Hash(k);
    if(d->H[hashKey].value == k){
        return hashKey;
    }
    else{
        int newIndex;
        for(int j = 1; j <= 19; j++){
            newIndex = ((hashKey) + (j*j) + (23*j))%101;
            if(d->H[newIndex].value == k){
                return newIndex;
            }
        }
    }
    return -1;
}

void insert(Dictionary *d, string k){
    int newPos, pos;
    if(find(d,k) == -1 && d->cnt < d->m){
        pos = d->Hash(k);
        
        if(d->H[pos].value.empty() || d->H[pos].value == "deleted"){
            d->H[pos].value = k;
            d->cnt++;
        }
        else{
            for(int j{}; j < 20; j++){
                newPos = ((pos) + (j*j) + (23 *j)) % 101;
                if(d->H[newPos].value.empty() || d->H[newPos].value == "deleted"){
                    d->H[newPos].value = k;
                    d->cnt++;
                    break;
                }
            }
        }
        
    }
}

void remove(Dictionary *d, string k){
    if(find(d,k) != -1){
        d->H[find(d,k)].value = "deleted";
        d->cnt--;
    }
}

// void desalocar(Dictionary *d){
//     delete d->H;
//     delete d;
// }
int main(void){
    int t, n1, starPos1 = 0, lenght1 = 3, starPos2 = 4, size = 101;
    cin >> t;

    for(int i{}; i < t; i++){
        Dictionary *d = create_dict();
        string nome;

        cin >> n1;
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

        //desalocar(d);
    }
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