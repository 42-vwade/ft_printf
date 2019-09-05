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
	int		ln;
	char	*string = "1234567890";
	wchar_t	*wstring = L"🤗 💯 🌍 🚀 🔴 ";
	char	**fmt;

	setlocale(LC_ALL, "");

	fmt = (char *[]){
		(char[]){"\n"},
		(char[]){"%0s"},		/*/	zero flag (does nothing)	/*/
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
		printf("|[%i]\n", printf((fmt++)[0], NULL));
	//printf(" [%i][wchr*]\n",
	printf(" [%i]\n",
		printf(
			"%032S",
			wstring
		)
	);
	printf(" [%i]\n", printf("%032s", ""));
	printf(" [%i]\n",
		printf(
			"%032.5S",
			wstring
		)
	);
	printf(" [%i]\n",
		printf(
			"memory test\n%n"
			"%#010x",
			&ln,
			(42)
		) - ln
	);
	//)
	;
	fmt = (char *[]){
		(char[]){"%0i"},		/*/	zero flag (does nothing)	/*/
		(char[]){"%014i"},		/*/	zero flag, 14 width	/*/
		(char[]){"%0-14i"},		/*/	minus-zero flag, 14 width, 4 precision	/*/
		(char[]){"%-014.4i"},	/*/	zero-minus flag, 14 width	/*/
		(char[]){"%-014.4i"},	//	minus-zero flag, 14 width, 4 precision
		(char[]){"%0.4i"},		//	zero flag, 4 precision
		(char[]){"% #-032.9i"},	//	space-hash-minus-zero flag, 32 width, 9 precision
		(char[]){"%0.0i"},		//	zero flag, 0 precision
		(char[]){"%0.i"},		//	zero flag, <absentee> precision
		/*	INTEGER PADDING	TEST	*/
		NULL
	};

	long long	i = -31415926, count;

	while (fmt[0]){
		count = printf((fmt++)[0], (int)i * 3 );
		fflush(stdout);
		printf("|[%i] \n", count);
	}
}
