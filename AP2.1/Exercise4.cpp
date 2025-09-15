#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <cctype>

using namespace std;

int main(void) {
  srand(time(NULL));
  while(true){
    int aleatoryNumber = (rand() % 15) + 1;
    string answer;
    for ( int i{}; i < 3; i++ ){
      int n;

      cin >> n;

      if(n == aleatoryNumber){
        cout << "Você acertou o numero, parabens!!" << endl;
        return 0;
      }
      else if ( n > aleatoryNumber){
        cout << "Você errou, o número é maior que o número certo" << endl;
      }
      else if ( n < aleatoryNumber){
        cout << "Você errou, o número é menor que o número certo" << endl;
      }
      if ( i < 2 ) {
        cout << "Tente novamente!!" << endl;
      }
    } 
    cout << "O numero aleatorio eh " << aleatoryNumber << endl;
    cout << "Deseja continuar?" << endl;
    cin >> answer;

    if(answer == "NAO" || answer == "Nao" || answer == "nao" || answer == "N"){
      break;
    }
    else {

      continue;

    }
  }

  return 0;
}
