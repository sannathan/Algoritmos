#include <iostream>

using namespace std;

class Aviao{

public:
    int vel = 0;
    int velMax;
    string tipo;
    void ini(int tp);

private:

};

void Aviao::ini(int tp){
    if(tp == 1){
        this->velMax = 800;
        this->tipo="Jato";
    }
    else if(tp == 2){
        this->velMax = 350;
        this->tipo = "Monomotor";
    }
    else if(tp == 3){
        this->velMax = 180;
        this->tipo = "Planador";
    }
}

int main(){

    Aviao *cesna = new Aviao();
    Aviao *dodo = new Aviao();

    cesna->ini(3);
    dodo->ini(1);

    cout << cesna->tipo << endl;
    cout << dodo->tipo << endl;

    return 0;
}