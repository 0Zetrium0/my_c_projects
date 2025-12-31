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

// strcmp fonctionnel

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

//strchr fonctionnel

int stringchr(char* s, char c){
	for (int i = 0; *(s+i)!='\0'; i++){
		if (*(s+i) == c){
			return i+1;
		}
	}
	return -1;
}

void* memory_copy(void* destination, void* source, int num_bytes){
	char *p_destination = destination;
	char *p_source = source;
	for (int i = 0; i<num_bytes; i++){
		*(p_destination+i) = *(p_source+i);
	}
	return destination;
}

// atointeger fonctionnel

int atointeger(char* str){
	int result = 0;
	for (int i = 0; *(str+i) != '\0'; i++){
		int digit = *(str+i) - '0';
		result = result * 10 + digit;
	}
	return result;
}
