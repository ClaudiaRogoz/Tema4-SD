
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string.h>

using namespace std;

template <typename T> struct Treap {
  T key;
  int priority;
  Treap<T> *left, *right;
  bool nil;
  T aux; 
  int nr_nodes;
  
  // Creaza un nod nil
  Treap() : priority(-1), left(NULL), right(NULL), nil(true), nr_nodes(0) {}

   ~Treap(){
	
	}
  void resize(){
	if (!this->isNil())
	this->nr_nodes = this->left->nr_nodes + this->right->nr_nodes + 1;
	}
  // Adaugam date, transformand un nod nil intr-un nod obisnuit
  void addData(T key, int priority) {
    this->nil = false;
    this->key = key;
    this->priority = priority;
    this->nr_nodes = 1;
    this->left = new Treap();
    this->right = new Treap();
  }


  bool isNil() {
    return this->nil;
  }

  bool find(T key) {
    if (this->isNil()) {
      return false;
    }
    if (this->key==key)
    {
	    return true;
    }
    if (this->key>key && this->left->isNil() == false )
	    return this->left->find(key);

    if (this->key<key && this->right->isNil() == false )
	    return this->right->find(key);

    return false;
  }

  void rotateRight(Treap<T> *&nod) {

    Treap<T> *tmp = nod->left;
    nod->left = tmp->right;
    tmp->right = nod;
    nod->resize();
    nod = tmp;
    nod->resize();
    }

  void rotateLeft(Treap<T> *&nod) {

    Treap<T> *tmp = nod->right;
    nod->right = tmp->left;
    tmp->left = nod;
    nod->resize();
    nod = tmp;
    nod->resize();
  
  }

  void insert(Treap<T> *&fatherPointer, T key, int priority) {
    if (this->isNil()) {
      this->addData(key, priority);
      return ;
    }
    if (key.first < this->key.first){

		this->left->insert(this->left, key,priority);
		this->resize();
		}
    else if (key.first > this->key.first)
		{		
		this->right->insert(this->right, key,priority);
		this->resize();
		}
	else if (key.first == this->key.first )
		{
		if (key.second > this->key.second){
			this->right->insert(this->right, key,priority);
			this->resize();
    		}else{ 
		this->left->insert(this->left, key,priority);
		this->resize();
		}}

    if (this->left->priority > this->priority) {
	rotateRight(fatherPointer);
	fatherPointer->resize();
    } else if (this->right->priority > this->priority) {
	rotateLeft(fatherPointer);
	fatherPointer->resize();
    }
}
   void delData() {
    this->nil = true;
    this->priority = -1;
    delete this->left;
    delete this->right;
    this->nr_nodes = 0;
  }

   void erase(Treap<T> *&fatherPointer, T key) {
    if (this->isNil()) {
      return ;
    }

    if (key.first < this->key.first) {
	fatherPointer->left->erase(fatherPointer->left, key);
	this->resize();
    } else if (key.first > this->key.first) {
	fatherPointer->right->erase(fatherPointer->right, key);
	this->resize();
    } else if (key.first == this->key.first){
	if ( key.second < this-> key.second ){
		fatherPointer->left->erase(fatherPointer->left, key);
		this->resize();
	}else if (key.second > this-> key.second){
		fatherPointer->right->erase(fatherPointer->right, key);
		this->resize();
	}else if (this->left->isNil() && this->right->isNil()) {
      		this->delData();
    	} else {
	if (this->left->priority > this->right->priority) {
		rotateRight(fatherPointer);
		fatherPointer->erase(fatherPointer, key);
		this->resize();
     	 } else {
		rotateLeft(fatherPointer);
		fatherPointer->erase(fatherPointer, key);
		this->resize();
      }
     }
    }
  }

  void inOrder() {
    if (this->isNil()) {
      return ;
    }
    if(this->left){
		this->left->inOrder();}
    cout<<"\n"<<this->key.first<<" "<<this->key.second<<"--"<<this->nr_nodes<<" "<<this->priority<<endl;
    if(this->right){
	    this->right->inOrder();}
  }

  void preOrder(int level = 0) {
    if (this->isNil()) {
      return ;
    }

    for (int i = 0; i < level; i++) {
      cout << ' ';
    }

    cout<<this->key.first<<" "<<this->key.second<<"--"<<this->nr_nodes<<" ("<<this->nr_nodes<<") "<<endl;
	if (left)
    this->left->preOrder(level+1);
	if (right)
    this->right->preOrder(level+1);
  }

  void findK(int k, int *nr, std::string *str) {
	/*int lower;	
	if (!this->right->isNil())
	 lower = this->right->nr_nodes + rest;
	else lower = 0 +rest;

	if (lower != k){		
		if (!this->left->isNil() && this->left->key.first == this->key.first )
			{
			this->left->findK(k,nr,str,1);
			}
		else {

			if (!this->right->isNil() && this->right->key.first == this->key.first){
			if (lower == this->right->nr_nodes){
			std::cout<<endl<<this->key.second;
			*nr = this->key.first;
			*str = this->key.second; 	}
			}
			else if (!this->left->isNil() && k > lower)
			{
			this->left->findK(k,nr,str,this->nr_nodes - this->left->nr_nodes);
			}
			else if (!this->right->isNil() && k < lower)
				{
				this->right->findK(k,nr,str,0);
				}
				else {
			std::cout<<endl<<this->key.second;
			*nr = this->key.first;
			*str = this->key.second; 
					}
		}		
	}
	else{	
			std::cout<<endl<<this->key.second;
			*nr = this->key.first;
			*str = this->key.second; 
}*/	
}
};
