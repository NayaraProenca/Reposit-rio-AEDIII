#include <iostream>

using namespace std;

//(LISTA SIMPLESMENTE ENCADEADA)
class celula //(classe)
{

private://(s� pode ver o que est� dentro da pr�pria classe)
	string nome;
	celula * proxima;

public://(vis�vel em toda parte do programa)
	celula(){ // M�todo Construtor
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

class lista//cria��o da lista
{
 private:
     celula * inicio;

 public:
    lista(){//criar construtor = criar um m�todo com mesmo nome da classe
    inicio = NULL;
    }

    lista (celula * i){
    inicio = i;
    }

    void inserirInicio(string n){
    celula * nova = new celula; //* = ponteiro / nova = nome
    nova->setNome(n);//vou colocar um nome nessa celula nova / (n) � o par�metro dessa nova celula
    //como a celula nova � um ponteiro, eu tenho que trabalhar com o ponteiro
    nova->setProxima(inicio);//O campo pr�xima da minha nova celula, vai receber o ender�o que est� salvo no inicio
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
    if(inicio == NULL){//se o inicio � igual a nulo ent�o a lista esta vazia
    cout<<"lista vazia.\n";
    }
    else{
    celula * aux = inicio;
    while(aux != NULL){//enquanto n�o chegar no �ltimo elemento, mostra o que est� no auxiliar get.nome e fala que o auxiliar recebe get.proxima
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
