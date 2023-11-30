#include <iostream>
#include <list>
#include <cstring>
#include <cmath>

using namespace std;

class HashTable {
    private:    
        static const int hashGroups = 10;
        list<pair<int, string>> table[hashGroups];

    public:
        bool isEmpty() const;
        int hashFunction(int key);
        void insertItem(int valor);
        void removeItem(int key);
        void searchTable(int key);
        void printTable();
};

bool HashTable::isEmpty() const{
    int sum{};

    for(int i{}; i < hashGroups; i++){
        sum += table[i].size();
    }

    if(sum == 0){
        return true;
    }
    else{
        return false;
    }
}

int HashTable::hashFunction(int valor){
    return abs(valor)%hashGroups;
}

void HashTable::insertItem(int valor){
    int hashValue = hashFunction(valor); // h(k) = j
    auto& cell = table[hashValue];
    auto bItr = begin(cell);
    bool keyExist = false;

    for(; bItr != end(cell); bItr++){
        if(bItr->first == hashValue){
            keyExist = true;
            bItr->second = valor;
            cout <<"[AVISO] A chave existe. Valor trocado" << endl;
            break;
        }
    }

    if(!keyExist){
        cell.emplace_back(key, value);
    }
}

void HashTable::removeItem(int key){
    int hashValue = hashFunction(key);
    auto& cell = table[hashValue];
    auto bItr = begin(cell);
    bool keyExist = false;

    for(; bItr != end(cell); bItr++){
        if(bItr->first == key){
            keyExist = true;
            cout << "[INFO] Usuario a ser removido: " << bItr->second << endl;
            bItr = cell.erase(bItr);
            cout << "[INFO] Par removido." << endl;
            break;
        }
    }

    if(!keyExist){
        cout << "[Aviso] Chave nao encontrada. Par nao removido" << endl;
    }
}

void HashTable::searchTable(int key){
    int hashValue = hashFunction(key);

    if(table[hashValue].empty()){
        cout << "[INFO] A lista está vazia";
    }else{
        auto& posicao = table[hashValue];
        auto iterador = begin(posicao);
        bool keyExist = false;

        for(; iterador != end(posicao); iterador++){
            if(iterador->first == key){
                keyExist = true;
                cout << "[INFO] O elemento de chave:" << iterador->first << "Foi encontrado e guarda o valor:" << iterador->second << endl;
                break;
            }
        }

        if(!keyExist){
            cout << "[INFO] A chave não foi encontrada" << endl;
        }
    }
    
}

void HashTable::printTable(){
    for(int i{}; i < hashGroups; i++){
        if(table[i].size() == 0) continue;

        auto bItr = table[i].begin();
        for (; bItr != table[i].end(); bItr++) {
            cout << "[INFO] Chave: " << bItr->first << " Valor: "<< bItr->second << endl;
        }
    }
}


int main(void){
    HashTable OH;
    int n{};

    for(int i{}; i < n; i++){
        OH.insertItem()
    }
    
    return 0;
}