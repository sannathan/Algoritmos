/*Exercise 3
a. The version of the function swap() opposite can be compiled without
producing any error messages. However, the function will not swap the
values of x and y when swap(&x,&y); is called.What is wrong?
b. Test the correct pointer version of the function swap() found in this
chapter.Then write and test a version of the function swap() that uses
references instead of pointers.*/

#include <iostream>

using namespace std;

void swap(float *, float *);
void swap(float &, float &);

int main(void) {
  float x = 12.5, y = 13.75;

  cout << "Valores de x e y antes do swap " << x << " " << y << endl;
  cout << "Usando o swap por ponteiro " << endl;
  swap(&x, &y);

  cout << "Valores de x e y após a troca por ponteiros: " << x << " " << y
       << endl;

  cout << "Usando o swap por referencia" << endl;
  swap(x, y);

  cout << "Valores de x e y após a troca por referencia: " << x << " " << y
       << endl;

  return 0;
}
void swap(float *p1, float *p2) {
  float temp;

  temp = *p1;
  *p1 = *p2;
  *p2 = temp;
}

void swap(float &p1, float &p2) {
  float temp;

  temp = p1;
  p1 = p2;
  p2 = temp;
}

/* A: O erro é que estamos trocando os ponteiros e não os valores para onde eles
   apontam. Além disso, ao finalizar a função, as variáveis locais são
   destruidas e nada acontece

  B: Tá implementado ae em cima pae
  */
