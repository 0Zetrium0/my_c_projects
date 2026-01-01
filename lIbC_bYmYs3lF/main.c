// Test de la fonction atointeger de mylibc

#include <stdio.h>
#include "mylibc.c"

void test();

int main(){
	printf("Début du programme...\n");
	test();
	printf("Fin du programme...\n");
}

void test(){
	char* source = "-12b3";
	int result = atointeger(source);
	printf("Voici l'entier de source %d\n", result);
}
