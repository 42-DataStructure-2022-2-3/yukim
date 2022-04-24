#include "linkedstack.h"

int main()
{
	char		*str0 = "{AB(CDE)[\\]}";
	char		*str1 = "A[B(CDE)]";
	char		*str2 = "A{B(CDE)]";
	char		*str3 = "A{[B(CDE)]}";
	char		*str4 = "A{B(CDE)]]]}";

	printf("str%d : %s\t Result BOOL : %d\n", 0, str0, checkBracket(str0));
	printf("str%d : %s\t Result BOOL : %d\n", 1, str1, checkBracket(str1));
	printf("str%d : %s\t Result BOOL : %d\n", 2, str2, checkBracket(str2));
	printf("str%d : %s\t Result BOOL : %d\n", 3, str3, checkBracket(str3));
	printf("str%d : %s\t Result BOOL : %d\n", 4, str4, checkBracket(str4));
	
	return 0;
}