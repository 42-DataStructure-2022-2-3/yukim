#include "linkedstack.h"

int main()
{
	char		*str0 = "{AB(CDE)[\\]}";
	char		*str1 = "A[B(CDE)]";
	char		*str2 = "A{B(CDE)]";
	char		*str3 = "A{[B(CDE)]}";
	char		*str4 = "A{B(CDE)]]]}";
	char		*str5 = "( ( A * B ) / C ) - { ( D + E ) && ( F – G ) }";
	char		*str6 = "( ( A * B ) / C - { ( D + E ) && ( F – G ) ) }";
	

	// printf("str%d : %s\t Result BOOL : %d\n", 0, str0, checkBracket(str0));
	// printf("str%d : %s\t Result BOOL : %d\n", 1, str1, checkBracket(str1));
	// printf("str%d : %s\t Result BOOL : %d\n", 2, str2, checkBracket(str2));
	// printf("str%d : %s\t Result BOOL : %d\n", 3, str3, checkBracket(str3));
	// printf("str%d : %s\t Result BOOL : %d\n", 4, str4, checkBracket(str4));
	// printf("str%d : %s\t Result BOOL : %d\n", 5, str5, checkBracket(str5));
	printf("str%d : %s\t Result BOOL : %d\n", 6, str6, checkBracket(str6));
	
	return 0;
}