/*
	.....................
	Estrutura de Dados
	Autor: Karim Homaissi
	Data: 03/05/2019
	.....................
	
*/

#include <iostream>
using namespace std;

struct No{

private:
	int val;
	No* prox;
	No* ant;

public:
	
	No(){
		this->prox = NULL;
		this->ant = NULL;
	}
	
	void setVal(int val){
		this->val = val;
	}
	
	int getVal(){
		return this->val;
	}
	
	void setProx(No* prox){
		this->prox = prox;
	}
	
	No* getProx(){
		return this->prox;
	}
	
	void setAnt(No* ant){
		this->ant = ant;
	}
	
	No* getAnt(){
		return this->ant;
	}
};

struct Lista{

private:
	
	No* aux;
	No* prim;
	
	void setAux(No* aux){
		this->aux = aux;
	}
	
	No* getAux(){
		return this->aux;
	}
	
	void setPrim(No* prim){
		this->prim = prim;
	}
	
	No* getPrim(){
		return this->prim;
	}
	
	
public:
	
	
	bool isVoid(){
		if(this->getPrim())
			return false;
		return true;
	}
	
	void push(int val){
		
		No* novo = new No();
		novo->setVal(val);
			if(this->isVoid()){
				this->setPrim(novo);
				this->setAux(novo);
			}else{
				
				novo->setAnt(this->getAux());
				this->getAux()->setProx(novo);
				this->setAux(novo);
				
			}
	}
	
	void show(){
		
		No* aux = this->getPrim();
		
		while(aux){
			cout<<aux->getVal()<<endl;
			aux = aux->getProx();
		}
		
	}
	
	int showByIndex(int index){
		
		int cont = 0;
		No* aux = this->getPrim();
		
		while(aux){	
			
			if(cont == index)
				return aux->getVal();
				
			aux=aux->getProx();	
			cont++;
		}			
	}
	
	void showReversed(){
		
		No* aux = this->getAux();
		
		while(aux){
			cout<<aux->getVal()<<endl;
			aux = aux->getAnt();
		}
		
	}
	
	
	int length(){
		int cont = 0;
		for(No* n = this->getPrim(); n != NULL; n=n->getProx())
			 ++cont;
		return cont;
	}
	
	
};

int main(int argc, char* argv[]){
	
	Lista* l = new Lista();
	cout<<"Vazio? "<<l->isVoid()<<endl<<endl;
	
	l->push(10);
	l->push(20);
	
	cout<<"Mostrando em Ordem Crescente:"<<endl;
	l->show();
	
	cout<<endl<<"Mostrando em Ordem Decrescente: "<<endl;
	l->showReversed();
	
	cout<<endl<<"Vazio: "<<l->isVoid()<<endl;
	cout<<"Tamanho: "<<l->length()<<endl;
	cout<<"Posicao 2: "<<l->showByIndex(1);
	
}
