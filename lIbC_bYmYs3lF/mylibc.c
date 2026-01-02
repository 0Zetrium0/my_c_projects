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

// stringchr fonctionnel

char* stringchr(char* s, char c){
	int i = 0;
	for (i; s[i]!='\0'; i++){
		if (s[i] == c){
			return &s[i];
		}
	}
	if (c == '\0'){
		return &s[i];
	}
	return NULL;
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

// atointeger fonctionnel

int atointeger(char* str){
        int result = 0;
        int i = 0;
        int condition_1 = str[0] == '-' || str[0] == '+';
        int condition_2 = str[0] == '-';
        if (condition_1){
                i = 1;
        }
        for (i; str[i] != '\0'; i++){
                if (str[i] == ' ' || str[i] == '\t'){
                        continue;
                }
                if (str[i] < '0' || str[i] > '9'){
                        return -1;
                }
                int digit = *(str+i) - '0';
                result = result * 10 + digit;
        }
        if (condition_2){
                result = -result;
        }
        return result;
}
