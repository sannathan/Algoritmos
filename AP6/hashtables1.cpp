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

    if(sum == 0){
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
    HashTable HT;

    if(HT.isEmpty()){
        cout << "Deu bom!" << endl;
    }else{
        cout << "Fiz merda :(" << endl;
    }

    HT.insertItem(1, "Nathan");
    HT.insertItem(2, "Maria");
    HT.insertItem(3, "Sarah");
    HT.insertItem(2, "Lara");

    HT.printTable();

    HT.removeItem(1);
    HT.removeItem(2);
    HT.removeItem(5);

    if(HT.isEmpty()){
        cout << "Ta errado boy :(" << endl;
    }else{
        cout << "Ta certo :)" << endl;
    }

    list <int> teste;
    auto iterador = begin(teste);
    return 0;
}