#include <iostream>
using namespace std;

class No
{
private:
	No *esq, *dir;
	int chave;

public:
	No(int chave)
	{
		this->chave = chave;
		esq = NULL;
		dir = NULL;
	}

	int getChave()
	{
		return chave;
	}
	
	// funções getters e setters

	No* getEsq()
	{
		return esq;
	}

	No* getDir()
	{
		return dir;
	}

	void setEsq(No *no)
	{
		esq = no;
	}

	void setDir(No *no)
	{
		dir = no;
	}
};

class Arvore
{
private:
	No *raiz;

public:
	Arvore()
	{
		raiz = NULL;
	}

	void inserir(int chave)
	{
		if(raiz == NULL) // verifica se a árvore está vazia
			raiz = new No(chave); // cria um novo nó
		else
			inserirAux(raiz, chave);
	}

	void inserirAux(No *no, int chave)
	{
		// se for menor, então insere à esquerda
		if(chave < no->getChave())
		{
			// verifica se a esquerda é nulo
			if(no->getEsq() == NULL)
			{
				No *novo_no = new No(chave);
				no->setEsq(novo_no); // seta o novo_no à esquerda
			}
			else
			{
				// senão, continua percorrendo recursivamente
				inserirAux(no->getEsq(), chave);
			}
		}
		// se for maior, então insere à direita
		else if(chave > no->getChave())
		{
			// verifica se a direita é nulo
			if(no->getDir() == NULL)
			{
				No *novo_no = new No(chave);
				no->setDir(novo_no); // seta o novo_no à direita
			}
			else
			{
				// senão, continua percorrendo recursivamente
				inserirAux(no->getDir(), chave);
			}
		}
		// se for igual, não vai inserir
		// não pode existir 2 chaves iguais
	}

	No* getRaiz()
	{
		return raiz;
	}

	
	void emOrdem(No* no)
	{
		if(no != NULL)
		{
			emOrdem(no->getEsq());
			cout << no->getChave() << " ";
			emOrdem(no->getDir());
		}
	}
	
	
	void mostrarFolha(No* no)
	{
		if(no != NULL)
		{
			mostrarFolha(no->getEsq());
			if(no->getEsq() == NULL && no->getDir() == NULL)
			cout << no->getChave() << " ";
			mostrarFolha(no->getDir());
		}
	}
	
	
	void preOrdem(No* no)
	{
		if(no!=NULL)
		{
			cout<< no->getChave() << " ";
			preOrdem(no->getEsq());
			preOrdem(no->getDir());
		}
	}
	
	
	void posOrdem(No* no)
	{
		if(no!=NULL)
		{
			posOrdem(no->getEsq());
			posOrdem(no->getDir());
			cout<< no->getChave() << " ";
		}
	}
	
	
	void maiorArvore(No* no)
	{
		if(no != NULL)
		{
			maiorArvore(no->getDir());
			if(no->getDir() == NULL)
			cout<<endl<<"Maior: "<<no->getChave();
		}
	}
	
	
	void menorArvore(No* no)
	{
			if(no != NULL)
		{
			menorArvore(no->getEsq());
			if(no->getEsq() == NULL)
			cout<<endl<<"Menor: "<<no->getChave();
			
		}
	}
	
	
	void mostrarFilhos(No* no, int num)
	{
		if(no != NULL)
		{
			mostrarFilhos(no->getEsq(), num);
			if(no->getChave() == num)
			{
				if(no->getEsq() != NULL && no->getDir() != NULL)
				{
					cout<<endl<<"filhos: "<<no->getEsq()->getChave()<< " ";
					cout<<no->getDir()->getChave();
				}
				
				if(no->getEsq() != NULL && no->getDir() == NULL)
					cout<<"filhos: "<<no->getEsq()->getChave();
				
				
				if(no->getEsq() == NULL && no->getDir() != NULL)
					cout<<"filhos: "<<no->getDir()->getChave();
				
			}
			mostrarFilhos(no->getDir(), num);
		}
		
	}
	
};

int main(int argc, char *argv[])
{
	Arvore arv;
	unsigned int opcao;
	
	do
	{
		system("cls");
		system("color 70");
		cout<<"1) Inserir"<<endl;
		cout<<"2) Mostrar em Ordem"<<endl;
		cout<<"3) Mostrar em Pre Ordem"<<endl;
		cout<<"4) Mostrar em Pos Ordem"<<endl;
		cout<<"5) Menor Numero"<<endl;
		cout<<"6) Maior Numero"<<endl;
		cout<<"7) Mostrar Raiz"<<endl;
		cout<<"8) Mostrar Folhas"<<endl;
		cout<<"9) Mostrar Filhos"<<endl;
		cout<<"10) Sair"<<endl<<endl;
		cout<<"Opcao: ";
		cin>>opcao;
		
		switch(opcao)
		{
			case 1:
			{
				int x;
				cout<<endl<<"Chave: ";
				cin>>x;
				arv.inserir(x);
				break;		
			}
			
			case 2:
			{
				cout<<endl<<"Mostrando em Ordem..."<<endl;
				arv.emOrdem(arv.getRaiz());
				cout<<endl<<endl;
				system("PAUSE");
				break;
			}
			
			case 3:
			{
				cout<<endl<<"Mostrando em Pre Ordem..."<<endl;
				arv.preOrdem(arv.getRaiz());
				cout<<endl<<endl;
				system("PAUSE");
				break;	
			}
			
			case 4:
			{
				cout<<endl<<"Mostrando em Pos Ordem..."<<endl;
				arv.posOrdem(arv.getRaiz());
				cout<<endl<<endl;
				system("PAUSE");
				break;
			}
			
			case 5:
			{
				cout<<endl<<"Mostrando Menor Numero..."<<endl;
				arv.menorArvore(arv.getRaiz());
				cout<<endl<<endl;
				system("PAUSE");
				break;
			}
			
			case 6:
			{
				cout<<endl<<"Mostrando Maior Numero..."<<endl;
				arv.maiorArvore(arv.getRaiz());
				cout<<endl<<endl;
				system("PAUSE");
				break;		
			}
			
			case 7:
			{
				cout<<endl<<"Mostrando Raiz..."<<endl;
				cout<<endl<<"Raiz: "<<arv.getRaiz()->getChave();
				cout<<endl<<endl;
				system("PAUSE");
				break;
			}
			
			case 8:
			{
				cout<<endl<<"Mostrando Folhas..."<<endl;
				arv.mostrarFolha(arv.getRaiz());
				cout<<endl<<endl;
				system("PAUSE");
				break;
			}
			
			case 9:
			{
				int x;
				cout<<endl<<"Digite a Chave: ";
				cin>>x;
				arv.mostrarFilhos(arv.getRaiz(), x);
				cout<<endl<<endl;
				system("PAUSE");
				break;
			}
			
			case 10:
				break;
			
			default:
				break;
		}
	}while(opcao!=10 && opcao<=10 && opcao>=1);

	
	return 0;
}
