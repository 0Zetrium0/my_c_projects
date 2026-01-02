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
	char* word = "bonjour";
	char c = 'c';
	char* result = stringchr(word, c);
	printf("Voici ce qui est retourné : %p\n", result);
}
