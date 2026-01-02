#ifndef MYLIBC_H
#define MYLIBC_H

int strlength(char* s);
char* stringcopy(char* s1, char* s2);
int stringcmp(char* s1, char* s2);

char* stringchr(char* s, char c);
void* memory_copy(void* destination, const void* source, size_t num_bytes);
int atointeger(char* str);

#endif
