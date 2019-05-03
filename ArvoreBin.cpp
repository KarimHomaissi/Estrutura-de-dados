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
	No* dir;
	No* esq;
	
public:
	
	No(){
		this->dir = NULL;
		this->esq = NULL;	
	}
	
	void setVal(int val){
		this->val = val;
	}
	
	int getVal(){
		return this->val;
	}
	
	void setDir(No* dir){
		this->dir = dir;
	}
	
	No* getDir(){
		return this->dir;
	}
	
	void setEsq(No* esq){
		this->esq = esq;
	}
	
	No* getEsq(){
		return this->esq;
	}
};

struct Arvore{

private:
	No* aux;
	
public:
	
	Arvore(){
		this->aux = NULL;
	}
	
	Arvore(No* aux){
		this->aux = aux;
	}
	
	void setAux(No* aux){
		this->aux = aux;
	}
	
	No* getAux(){
		return this->aux;
	}
	
	bool isVoid(){
		if(this->aux != NULL){
			return false;
		}else{
			return true;
		}
	}
	
	void push(int val){
		No* dado = new No();
		dado->setVal(val);
		Arvore* ar = new Arvore(this->getAux());
		
		if(this->isVoid()){
			this->setAux(dado);	
		}else{
			
			while(true){
		
				if(ar->getAux()->getVal() < dado->getVal()){
					if(ar->getAux()->getDir() != NULL){
						ar->setAux(ar->getAux()->getDir());
					}else{
						ar->getAux()->setDir(dado);
						break;
					}
				}
				
				
				if(ar->getAux()->getVal() > dado->getVal()){
					if(ar->getAux()->getEsq() != NULL){
						ar->setAux(ar->getAux()->getEsq());
					}else{
						ar->getAux()->setEsq(dado);
						break;
					}
				}
				
			}
							
		}
	}
	
	

};

int main(int argc, char* argv[]){
	
	Arvore* arv = new Arvore();
	arv->push(10);
	arv->push(20);
	arv->push(9);
	arv->push(30);
	arv->push(8);
	cout<<arv->getAux()->getVal();
	return 0;
}
