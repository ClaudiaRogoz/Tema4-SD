#ifndef _TRIE_H
#define _TRIE_H

#include "Treap.h"

struct Trie{
private:
	int current, no_son;
	Trie *son[8];
	
	bool ok;
	int total;
	Treap< pair<int,string> > *treap;

	int is_character(char *s){
		if ( *s >= 'a' && *s <= 'z')
			return 1;;
		return 0;

	}

public:
	Trie(){
		current = no_son;
		memset( son, 0, sizeof(son) );
		treap = new Treap< pair<int,string> >;
		ok = 0;
		total = 0;
	}
	
	~Trie(){
		delete[] treap;	
	}

	// analogie litera - numar (0 - 7)
	int convert(char *s){
	if (*s>= 'a' &&  *s<='c' )
		return 0;
	else if (*s >= 'd' && *s <='f')
		return 1;
	else if (*s >= 'g' && *s<= 'i')
		return 2;
	else if ( *s >= 'j' && *s <= 'l')
		return 3;
	else if ( *s >= 'm' && *s <= 'o')
		return 4;
	else if ( *s>= 'p' && *s<='s')
		return 5;
	else if ( *s >= 't' && *s <= 'v' )
		return 6;
	else 	return 7; 
	}

	
 	void insert(Trie *&nod, char *s, pair<int, std::string> key)
	{

	if (*s==' ' || *s =='\n' || *s<'a' || *s >'z' ){
		// daca s-a ajuns la sfarsitul 
		// cuvantului se poate insera in Treap-ul 
		//nodului curent
		nod->current++;
		nod->ok = 1;
		nod->treap->insert(nod->treap, key,rand()%1000);
		//nod->treap->insert(nod->treap, key)
		nod->total ++;
		nod->treap->preOrder();
	

		return;
	}
	// se aloca memorie pentru un nou fiu 
	// daca e cazul 
	if (nod->son[convert(s)] == 0){
	
		nod->son[ convert(s)] = new Trie;
		nod->no_son ++;
	}

	insert(nod->son[convert(s)], s+1, key);

	}
	
	int find(Trie *&nod,char *s,int nr_crt){		
		
	return 0;
	}	
};
#endif
