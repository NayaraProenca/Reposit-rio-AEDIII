#include <iostream>

using namespace std;

//(LISTA SIMPLESMENTE ENCADEADA)
class celula //(classe)
{

private://(só pode ver o que está dentro da própria classe)
	string nome;
	celula * proxima;

public://(visível em toda parte do programa)
	celula(){ // Método Construtor
    proxima = NULL;
	}

	celula(string n, celula * p){
	nome = n;
	proxima = p;
	}

	string getNome(){
	return nome;
	}
	void setNome(string n){
	nome = n;
	}

	celula * getProxima(){
	return proxima;
	}

	void setProxima(celula*l){
	proxima = l;
	}

};

class lista//criação da lista
{
 private:
     celula * inicio;

 public:
    lista(){//criar construtor = criar um método com mesmo nome da classe
    inicio = NULL;
    }

    lista (celula * i){
    inicio = i;
    }

    void inserirInicio(string n){
    celula * nova = new celula; //* = ponteiro / nova = nome
    nova->setNome(n);//vou colocar um nome nessa celula nova / (n) é o parâmetro dessa nova celula
    //como a celula nova é um ponteiro, eu tenho que trabalhar com o ponteiro
    nova->setProxima(inicio);//O campo próxima da minha nova celula, vai receber o enderço que está salvo no inicio
    inicio = nova;
    }

    void inserirFim(string n){
    celula * nova = new celula(n, NULL);
    if(inicio != NULL){
        celula * aux = inicio;
        while(aux->getProxima() != NULL){
        aux = aux -> getProxima();
        }
        aux->setProxima(nova);
    }

    else{
        inicio=nova;
    }
    }

    void imprimir(){//para mandar imprimir lista
    if(inicio == NULL){//se o inicio é igual a nulo então a lista esta vazia
    cout<<"lista vazia.\n";
    }
    else{
    celula * aux = inicio;
    while(aux != NULL){//enquanto não chegar no último elemento, mostra o que está no auxiliar get.nome e fala que o auxiliar recebe get.proxima
        cout<<aux->getNome()<<endl;
        aux=aux->getProxima();
    }
    }
    }



};



int main()
{
 lista listaAlunos;
 listaAlunos.inserirFim("Igor");
 listaAlunos.inserirFim("Nayara");
 listaAlunos.inserirFim("Marcus");
 listaAlunos.inserirInicio("Aurora");

 listaAlunos.imprimir();//imprimir a lista
 return 0;



}
