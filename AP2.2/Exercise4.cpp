/*



Create a function quadEquation() that calculates the solutions to quadratic
equations.The formula for calculating quadratic equations is shown opposite.
Arguments:
Returns:
The coefficients a, b, c and two pointers to both solutions.
false, if no real solution is available, otherwise true.
Test the function by outputting the quadratic equations on the opposite page
and their solutions.*



*/

#include <fstream>
#include <iostream>
#include <string>

using namespace std;

bool quadEquation(double a, double b, double c) {
  if (((b * b) - (4 * a * c)) >= 0) {
    return true;
  }
  return false;
};

int main(void) {
  ifstream arquivo("input.txt");
  string palavra;

  if (!arquivo) {
    cout << "Não foi possível abrir o arquivo :(" << endl;
    return 1;
  }

  int n;
  if (arquivo >> palavra) {
    n = stoi(palavra);
  } else {
    cerr << "Arquivo está vazio ou inválido." << endl;
    return 1;
  }

  for (int i{}; i < n; i++) {
    double a, b, c;

    if (arquivo >> a >> b >> c) {
      if (quadEquation(a, b, c)) {

        cout << "Conjunto" << i + 1 << ": Possui duas raízes reais distintas."
             << endl;
      } else {
        cout << "Conjunto" << i + 1
             << ": Não possui duas raízes reais distintas." << endl;
      }
    } else {
      cerr << "Erro ao ler dados para o conjunto " << i + 1 << "." << endl;
    }
  }
  arquivo.close();
  return 0;
}
