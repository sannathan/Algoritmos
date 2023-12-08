#include <iostream>
#include <cstring>

using namespace std;

int main() {
    string line;

    // Loop para processar vários casos de teste
    while (cin >> line) {
        string beiiuText = "";
        string text = "";
        bool homePressed = false;

        // Iterar sobre cada caractere da linha
        for (char c : line) {
            if (c == '[') {
                homePressed = true;
            } 
            else if (c == ']') {
                homePressed = false;
            } 
            else if (homePressed){ //Se a tecla home for pressionada, receber o texto
                text += c;
            } 
            else {
                // Adicionar o caractere à string Beiiu se a tecla "Home" não estiver pressionada
                if (!homePressed) {
                    beiiuText += c;
                }
            }
            
        }
        text += beiiuText;
        // Imprimir o texto Beiiu para o caso atual
        cout << text << endl;
    }

    return 0;
}
