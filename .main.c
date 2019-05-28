#include <stdlib.h>
#include <stdio.h>
#include <locale.h>

char
	*chr_replace(char *s, int c, int n)
{
	char	able = 0;
	ssize_t	i = 0;

	while (s[i])
	{
		if (s[i] == '%')
			able = 1;
		if (able && s[i] == c)
			s[i] = able = 0 || n;
		else
			i++;
	}
	return (s);
}

int
	main(void)
{
	char	*string = "1234567890";
	wchar_t	*wstring = L"🤗 💯 🌍 🚀 🔴 ";
	char	**fmt;

	setlocale(LC_ALL, "");

	fmt = (char *[]){
		(char[]){"%03.0%"},		/*/	zero flag (does nothing)	/*/
		(char[]){"%014s"},		/*/	zero flag, 14 width	/*/
		(char[]){"%0-14s"},		/*/	minus-zero flag, 14 width, 4 precision	/*/
		(char[]){"%-014.4s"},	/*/	zero-minus flag, 14 width	/*/
		(char[]){"%-014.4s"},	//	minus-zero flag, 14 width, 4 precision
		(char[]){"%0.4s"},		//	zero flag, 4 precision
		(char[]){"% #-032.9s"},	//	space-hash-minus-zero flag, 32 width, 9 precision
		(char[]){"%0.0s"},		//	zero flag, 0 precision
		(char[]){"%0.s"},		//	zero flag, <absentee> precision
		/*	STRING PADDING	TEST	*/
		NULL
	};

	printf("%-032.0c", 'c');
	while (fmt[0])
		printf("|[%i]\n", printf((fmt++)[0], string));
	//printf(" [%i][wchr*]\n",
	printf("%S", L"🤗 💯 🌍 🚀 🔴 ")
	//)
	;
	fmt = (char *[]){
		(char[]){"%0i\n"},		/*/	zero flag (does nothing)	/*/
		(char[]){"%014i\n"},		/*/	zero flag, 14 width	/*/
		(char[]){"%0-14i\n"},		/*/	minus-zero flag, 14 width, 4 precision	/*/
		(char[]){"%-014.4i\n"},	/*/	zero-minus flag, 14 width	/*/
		(char[]){"%-014.4i\n"},	//	minus-zero flag, 14 width, 4 precision
		(char[]){"%0.4i\n"},		//	zero flag, 4 precision
		(char[]){"% #-032.9i\n"},	//	space-hash-minus-zero flag, 32 width, 9 precision
		(char[]){"%0.0i\n"},		//	zero flag, 0 precision
		(char[]){"%0.i\n"},		//	zero flag, <absentee> precision
		/*	INTEGER PADDING	TEST	*/
		NULL
	};

	while (fmt[0])
		printf("[%i] ", printf(chr_replace((fmt++)[0], 's', 'S'), wstring));
}
