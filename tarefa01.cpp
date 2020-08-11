#include <iostream>
using namespace std;

struct celula
{
    string nome;
    celula *proxima;
};

void imprimir (celula*L)
{

while (L != NULL)
    {
    cout << L->nome<<endl;
    L=L->proxima;
    }

};


int main ()

{

celula *lista;
lista = NULL;
celula *nova = new celula;

nova-> nome = "Nayara";
nova-> proxima = NULL;

lista = nova;


nova = new celula;//alocar um espaço
nova->nome = "Marcus";//colocar os valores
nova->proxima = lista;//colocar os valores
lista = nova;



imprimir (lista);

return 0;
}
