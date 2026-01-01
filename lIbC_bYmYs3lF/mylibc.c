/*
================================================
               .__  ._____.           
  _____ ___.__.|  | |__\_ |__   ____  
 /     <   |  ||  | |  || __ \_/ ___\ 
|  Y Y  \___  ||  |_|  || \_\ \  \___ 
|__|_|  / ____||____/__||___  /\___  >
      \/\/                  \/     \/ 


      	        mylibc
	 Librairie standard C 
	Développé par z3trium

------------------------------------------------

Reimplémentation personnel de quelques
fonctions de la lib standard C
pour apprendre, maîtriser et mieux 
comprendre le bas niveau ainsi que
le langage C.

================================================
*/


#include "mylibc.h"
#include <stdlib.h>

// strlength fonctionnel

int strlength(char* s){
	int length = 0;

	for (int i = 0; *(s+i) != '\0'; i++){
		length++;	
	}

	return length;
}

// stringcopy fonctionnel

char* stringcopy(char* s1, char* s2){
	int i = 0;
	while (s1[i] != '\0'){
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return s2;
}

// stringcmp fonctionnel

int stringcmp(char* s1, char* s2){
	int i = 0;
	while (s1[i] == s2[i]){
		if (s1[i] == '\0' && s2[i] == '\0'){
			return 0; 
		}
		i++;
	}
	return 1;
}

// stringchr à améliorer => priorité moyenne

int stringchr(char* s, char c){
	for (int i = 0; *(s+i)!='\0'; i++){
		if (*(s+i) == c){
			return i+1;
		}
	}
	return -1;
}

// memory_copy fonctionnel

void* memory_copy(void* destination, const void* source, size_t num_bytes){
	if (num_bytes == 0 &&  (destination == NULL || source == NULL)){
		return NULL;
	}
	else if (num_bytes == 0){
		return destination;	
	}
	unsigned char *p_destination = destination;
	const unsigned char *p_source = source;
	for (size_t i = 0; i<num_bytes; i++){
		p_destination[i] = p_source[i];
	}
	return destination;
}

// atointeger amélioré (plus qu\'à optimiser tout ceci, la boucle for est exactement la même dans chaque test conditionnel)

int atointeger(char* str){
	int result = 0;
	if (str[0] == '-'){
		for (int i = 1; str[i] != '\0'; i++){
         		if (str[i] == ' ' || str[i] == '\t'){
                        	continue;
               		}
			if (str[i] < '0' || str[i] > '9'){
                                return -1;
                        }
               		int digit = *(str+i) - '0';
                	result = result * 10 + digit;
        	}
		result = -result;
		return result;
	}
	else {
		for (int i = 0; str[i] != '\0'; i++){
			if (str[i] == ' ' || str[i] == '\t'){
				continue;
			}
			if (str[i] < '0' || str[i] > '9'){
                                return -1;
                        }
			int digit = *(str+i) - '0';
			result = result * 10 + digit;
		}
		return result;
	}
}
