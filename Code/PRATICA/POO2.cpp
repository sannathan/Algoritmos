/* Neste exemplo, a classe base é a "Conta bancária", que possui um 
saldo e os métodos "depositar" e "sacar". A classe derivada é a 
"Conta poupança", que herda da classe "Conta bancária" e adiciona 
um atributo "taxaJuros" e um comportamento diferente no método "depositar".

No programa principal, são criados dois objetos: um da classe 
"Conta bancária" e outro da classe "Conta poupança". Em seguida, 
são realizadas operações de depósito e saque em ambos os objetos. 
Observe que a implementação do método "depositar" na classe 
"Conta poupança" é diferente da implementação na classe base. 
Isso é possível graças ao recurso de polimorfismo, que permite que a
 classe derivada sobrescreva o comportamento de um método herdado da 
 classe base. */



#include <iostream>
using namespace std;

// classe base
class ContaBancaria {
  protected:
    double saldo;
  
  public:
    ContaBancaria(double s) {
      saldo = s;
    }

    virtual void depositar(double valor) {
      saldo += valor;
      cout << "Depósito de R$" << valor << " realizado. Novo saldo: R$" << saldo << endl;
    }

    virtual void sacar(double valor) {
      if (saldo >= valor) {
        saldo -= valor;
        cout << "Saque de R$" << valor << " realizado. Novo saldo: R$" << saldo << endl;
      } else {
        cout << "Saldo insuficiente para realizar o saque." << endl;
      }
    }
};

// classe derivada
class ContaPoupanca : public ContaBancaria {
  private:
    double taxaJuros;

  public:
    ContaPoupanca(double s, double tj) : ContaBancaria(s) {
      taxaJuros = tj;
    }

    void depositar(double valor) override {
      saldo += valor;
      cout << "Depósito de R$" << valor << " realizado na conta poupança. Novo saldo: R$" << saldo << endl;
      saldo += saldo * taxaJuros;
      cout << "Juros de R$" << saldo*taxaJuros << " adicionados à conta poupança. Novo saldo: R$" << saldo << endl;
    }
};

int main() {
  ContaBancaria* conta1 = new ContaBancaria(5000);
  ContaPoupanca* conta2 = new ContaPoupanca(2000, 0.05);

  conta1->depositar(1000);
  conta2->depositar(500);

  conta1->sacar(2000);
  conta2->sacar(10000);

  delete conta1;
  delete conta2;

  return 0;
}

