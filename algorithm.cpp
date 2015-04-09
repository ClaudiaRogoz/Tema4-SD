#include<string>
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<iostream>

#include "algorithm.h"
#include "Trie.h"

using namespace std;

Algorithm::Algorithm(void){
//Trie *trie = new Trie;

}

Algorithm::~Algorithm(void){
	//delete trie;

}

Trie *trie= new Trie;

void Algorithm::resolve(const std::string &row){
	int n,i,m; 
	char *fisier = strdup(row.c_str()); 
	freopen(fisier,"r",stdin);
	cin >> n;
	
	std::string word,no;
	char w[20];
	// se citesc primele n cuvinte pentru a le insera 
	for (i= 0; i< n;i++){
		std::cin>>word >> no;
		
		char *cuv= strdup(word.c_str());
		strcpy(w,cuv);
		char *no1 = strdup(no.c_str());
		int nr = atoi(no1);
		
		printf("new TRIE:\n");
		trie->insert(trie,w+0,make_pair(nr,cuv));
	
		free(cuv);
		free(no1);
		}
	cin>> m;
	// se apeleaza functia find pentru gasirea 
	// echivalentului sirului de caractere citit
	for (i = 0; i< m;i++){
		std::cin>> word;
		char *cuv = strdup(word.c_str());
		char *cuv_tok = strtok(cuv,"* ");
		strcpy(w,cuv_tok);		
		char *K;
		if ((K=strtok(NULL," "))== NULL){
		 			
			trie->find(trie,w+0,0);		
		}		
		else {
			int ky = atoi(K);
		
			trie->find(trie,w+0,ky);
		}
		free(cuv);
	}
	free(fisier);

}

