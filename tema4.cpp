#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
#include "algorithm.h"

using namespace std;

int main(int argc, char *argv[])
{
    /* aici fac verificarea sa fi primit exact 2 argumente */
	if (argc != 2)
	{
	        fprintf(stderr, "Usage : %s input_file\n", argv[0]);
	        exit(EXIT_FAILURE);
	}
	Algorithm homework;
	std::string fisier = argv[1];
	homework.resolve(fisier);
	return 0;
}

