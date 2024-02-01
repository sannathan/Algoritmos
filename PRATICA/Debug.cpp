#include <iostream>

using namespace std;

int Somar(int n){
    return n + 5;
}
int main(void){
    int n;

    cin >> n;

    int resultado = Somar(n);

    cout << "O resultado foi: " << resultado << endl;

    return 0;
}