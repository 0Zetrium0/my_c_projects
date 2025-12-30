#include "mylibc.h"

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
	s2 = s1;
	return s2;
}

// strcmp fonctionnel (peut-être pas très optimisé)

int stringcmp(char* s1, char* s2){
	int result = 1;
	if (strlength(s1) != strlength(s2)){
		return result;
	}
	else if (strlength(s1) == 0 && strlength(s2) == 0){
		return -1;
	}
	for (int i = 0; *(s1+i) != '\0'; i++){
		if (*(s1+i) == *(s2+i)){
			result = 0;
			continue;
		}
		result = 1;
		break;
	}
	return result;
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
