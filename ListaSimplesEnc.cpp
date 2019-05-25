#include<iostream>
using namespace std;

struct no{
private:	
	int val;
	no* prox;
	
public:
	
	no(){
		this->prox = NULL;
	}
	
	void setVal(int val){
		this->val = val;
	}
	
	int getVal(){
		return this->val;
	}
	
	void setProx(no* prox){
		this->prox = prox;
	}
	
	no* getProx(){
		return this->prox;
	}
	
};

struct Lista{
private:
	no* aux;
	
public:
	
	Lista(){
		this->aux = NULL;
	}
	
	void setAux(no* aux){
		this->aux = aux;
	}
	
	no* getAux(){
		return this->aux;
	}
	
	void push(int val){
		
		no* novo = new no();
		novo->setVal(val);
		
		if(this->getAux() == NULL){
			this->setAux(novo);
		}else{
			novo->setProx(this->getAux());
			this->setAux(novo);
		}
	}
	
	void show(){
		
		Lista* lista = new Lista();
		lista->setAux(this->getAux());
		
		while(lista->getAux() != NULL){
			cout<<lista->getAux()->getVal()<<endl;
			
			if(lista->getAux()->getProx() == NULL)break;
				
			lista->setAux(lista->getAux()->getProx());
		}
	}
	
	void pop(){
		
		Lista* lista = new Lista();
		lista->setAux(this->getAux());
		
		this->setAux(this->getAux()->getProx());
		
		delete lista;
	}
	
};

int main(int argc, char* argv[]){
	Lista* nova = new Lista();
	nova->push(10);
	nova->push(20);
	nova->push(30);
	
	nova->show();
	
	nova->pop();
	
	cout<<endl;
	
	nova->show();

	
	return 0;
}
