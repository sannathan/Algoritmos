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
        void insertItem(int key, string value);
        void removeItem(int key);
        string searchTable(int key);
        void printTable();
};

bool HashTable::isEmpty() const{
    int sum{};

    for(int i{}; i < hashGroups; i++){
        sum += table[i].size();
    }

    if(!sum){
        return true;
    }
    else{
        return false;
    }
}

int HashTable::hashFunction(int key){
    return abs(key)%hashGroups;
}

void HashTable::insertItem(int key, string value){
    int hashValue = hashFunction(key);
    auto& cell = table[hashValue];
    auto bItr = begin(cell);
    bool keyExist = false;

    for(; bItr != end(cell); bItr++){
        if(bItr->first == key){
            keyExist = true;
            bItr->second = value;
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
            bItr = cell.erase(bItr);
            cout << "[INFO] Par removido." << endl;
            break;
        }
    }

    if(!keyExist){
        cout << "[Aviso] Chave não encontrada. Par não removido" << endl;
    }
}

int main(void){


    return 0;
}