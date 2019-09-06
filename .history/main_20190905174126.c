/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 07:09:07 by viwade            #+#    #+#             */
/*   Updated: 2019/09/05 17:41:26 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "source/ft_printf.h"
#include <stdio.h>
#include <locale.h>
#include <time.h>

#define T_D		(long long)va_arg(ap, long long)
#define T_O(a)	(((a) == 'o') ? (unsigned long long)va_arg(ap, unsigned long long) : T_D
#define T_U(a)	(((a) == 'u') ? (unsigned int)va_arg(ap, unsigned int) : T_O(a))
#define T_X(a)	(((a) == 'x') ? (unsigned long)va_arg(ap, unsigned long) : T_U(a))
#define T_C(a)	(((a) == 'c') ? (char)va_arg(ap, char) : T_X(a))
#define T_S(a)	(((a) == 's') ? (char *)va_arg(ap, char *) : T_C(a))
#define T_P(a)	(((a) == 'p') ? (unsigned long long)va_arg(ap, unsigned long long) : T_S(a))
#define T_F(a)	(((a) == 'f') ? (double)va_arg(ap, double) : T_P(a))
#define TYPE(a) (((a) == '%') ? (char)va_arg(ap, char) : T_F(a))

static void
	stopwatch(clock_t a, clock_t b)
{
	printf(
		"\n""[%.3f%%] speed\n",
		((double)a / (double)b) * 100
	);
	fflush(stdout);
}

static void
	counter_test(void *fmt, ...)
{
	int		re[2];
	char	*display_format = "\n%-16s[%-24s%4s";
	char	*return_display = "++ return[1]: %d""\n++ return[2]: %d""\n";
	char	*rfmt;
	clock_t	timer[2];
	va_list	ap[2];

	rfmt = ft_append(fmt, "]", 0);
	va_start(ap[0], fmt);
	va_copy(ap[1], ap[0]);
	{	printf(display_format, "printf[int]:", rfmt, "|");
		timer[0] = clock();
		re[0] = vprintf(fmt, ap[0]);
		timer[0] = clock() - timer[0];
		va_end(ap[0]);
	}
	{	printf(display_format, "ft_printf[int]:", rfmt, "|");
		fflush(stdout);
		timer[1] = clock();
		re[1] = ft_vprintf(fmt, ap[1]);
		timer[1] = clock() - timer[1];
		va_end(ap[1]);
	}
	stopwatch(timer[0], timer[1]);
	printf(return_display, re[0], re[1]);
	fflush(stdout);
	ft_memdel((void**)&rfmt);
}//*/
/*
static void
	series_test(FT_STR fmt, ...)
{
	va_list	ap;
	char	c;
	size_t	count;
	void	*input;

	count = 0;
	va_start(ap, fmt);
	if (fmt)
		while ((c = fmt[0]))
	{
		if (c == '%' && (count += count < -1ULL))
			while ((c = (fmt += !!fmt[0])[0]))
				if (c == 'd' || c == 'i' || c == 'o' || c == 'u' || c == 'x' || c == 'X' || c == 'c' || c == 'C' || c == 's' || c == 'S' || c == 'p' || c == 'f' || c == '%')
					break ;
		if (c)
			ft_printf((char[]){'%', c, '\n' , 0},  TYPE(c));
	}
	va_end(ap);
}//*/

static void
	basic_tests(void)
{
	const long double		PI = 3.141592653589793238462643383279502884197169399375105820974944592307816406286L;
	unsigned	i;

	i = 0;
	fflush(stdout);
	printf("[%i]\n", (int)write_infinite_double((double)PI + -4U, 16 << 2));
	fflush(stdout);

	counter_test("%s", NULL);
/*/	counter_test("%0f", (double)PI);
	counter_test("%03f", (double)PI);
/*/	counter_test("%03.f|", (double)PI);
/*/	i++;
	while (i++ < 24){
		printf("\n>\t%+0*.*Lf|[%%%i]", i << 1, i, PI, i);
		ft_printf("\nft>\t%+0*.*Lf|[%%%i]\n", i << 1, i, (double)PI, i);//*/
	//ft_printf()

	// int		test = 0;

//		counter_test("%x",42);
//		counter_test("%X",42);
//		counter_test("%x",0);
//		counter_test("%X",0);
//		counter_test("%x",-42);
//		counter_test("%X",-42);
//		counter_test("%x",4294967296);
//		counter_test("%X",4294967296);
//		counter_test("%x",test);
//		counter_test("%10x",42);
//		counter_test("%-10x",42);
//		counter_test("%lx",4294967296);
//		counter_test("%llX",4294967296);
//		counter_test("%hx",4294967296);
//		counter_test("%hhX",4294967296);
//		counter_test("%jx",4294967295);
//		counter_test("%jx",4294967296);
//		counter_test("%jx",-4294967296);
//		counter_test("%jx",-4294967297);
//		counter_test("%llx",9223372036854775807);
//		counter_test("%llx",9223372036854775808);
//		counter_test("%010x",542);
//		counter_test("%-15x",542);
//		counter_test("%2x",542);
//		counter_test("%.2x",5427);
//		counter_test("%5.2x",5427);
//		counter_test("%#llx",9223372036854775807);
//		counter_test("%#x",0);
//		counter_test("%#8x",42);
//		counter_test("%#08x",42);
//		counter_test("%#-08x",42);
	counter_test("@moulitest:%#.x%#.0x",0,0);
	counter_test("@moulitest:%.x%.0x",0,0);
	counter_test("@moulitest:%5.x%5.0x",0,0);
	counter_test("%5c",42);
	counter_test("%-5c",42);
	counter_test("@moulitest:%c",0);
	counter_test("%2c",0);
	counter_test("null%candtext",0);
	counter_test("%c",0);
	counter_test("%5o",41);
	counter_test("%05o",42);
	counter_test("%-5o",2500);
	counter_test("%#6o",2500);
	counter_test("%-#6o",2500);
	counter_test("%-05o",2500);
	counter_test("%-5.10o",2500);
	counter_test("%-10.5o",2500);
	counter_test("@moulitest:%.o%.0o",0,0);
	counter_test("@moulitest:%5.o%5.0o",0,0);
	counter_test("@moulitest:%#.o%#.0o",0,0);
	counter_test("@moulitest:%.10o",42);
	counter_test("%d",-1);
	counter_test("%d",-4242);
	counter_test("%d",2147483648);
	counter_test("%d",-2147483648);
	counter_test("%d",-42);
	counter_test("%+d",-42);
		/*	counter_test("%+d",4242424242424242424242);		*/
	counter_test("%+i",-42);
	counter_test("%+#o",-42);
	counter_test("%+u",-42);
	counter_test("%+x",-42);
	counter_test("%++d",-42);
	counter_test("%0d",-42);
	counter_test("%00d",-42);
	counter_test("%5d",42);
	counter_test("%05d",42);
	counter_test("%0+5d",42);
	counter_test("%5d",-42);
	counter_test("%05d",-42);
	counter_test("%0+5d",-42);
	counter_test("%-5d",42);
	counter_test("%-05d",42);
	counter_test("%-5d",-42);
	counter_test("%-05d",-42);
	counter_test("%hd",32768);
	counter_test("%hhd",128);
	counter_test("%hhd",-128);
	counter_test("%ld",-2147483648);
	counter_test("%ld",2147483648);
	counter_test("%ld",-2147483649);
	counter_test("%lld",9223372036854775807);
	 	/*	counter_test("%lld",-9223372036854775808);		*/
	counter_test("%jd",9223372036854775807);
	 	/*	counter_test("%jd",-9223372036854775808);		*/
	counter_test("%zd",4294967295);
	counter_test("%zd",4294967296);
	counter_test("%zd",-1);
	counter_test("%d%d",1,-2);
	counter_test("%d%d%d",1,-2,33);
	counter_test("%d%d%d%d",1,-2,33,42);
	counter_test("%d%d%d%dgg!",1,-2,33,42,0);
	counter_test("%4.15d",42);
	counter_test("%.10d",4242);
	counter_test("%10.5d",4242);
	counter_test("%-10.5d",4242);
	counter_test("%10.5d",4242);
	counter_test("%+10.5d",4242);
	counter_test("%-+10.5d",4242);
	counter_test("%03.2d",0);
	counter_test("%03.2d",1);
	counter_test("%03.2d",-1);
	counter_test("@moulitest:%.10d",-42);
	counter_test("@moulitest:%.d%.0d",0,0);
	counter_test("@moulitest:%5.d%5.0d",0,0);
	counter_test("%15u",4294967295);
	counter_test("%-15u",4294967295);
	counter_test("%015u",4294967295);
	counter_test("%u",4294967295);
	counter_test("%+u",4294967295);
	counter_test("%lu",4294967296);
	counter_test("%lu",-42);
	counter_test("%llu",4999999999);
	counter_test("%ju",4999999999);
	counter_test("%ju",4294967296);
	counter_test("%U",4294967295);
	counter_test("%hU",4294967296);
	counter_test("%U",4294967296);
	counter_test("@moulitest:%.5u",42);
}//*/
/*
static void
	basic_multi_var_tests(void)
{
	char	*string = "string";

	printf("\n""printf[multivar]:\n");
	printf("%s%s","this","is");
	printf("%s%s%s","this","is","a");
	printf("%s%s%s%s","this","is","a","multi");
	//printf("%s%s%s%sstring.gg!","this","is","a","multi","string");
	printf("%s%s%s%s%s","this","is","a","multi","string");
	printf("%s%s",NULL,string);

	printf("\n""ft_printf[multivar]:\n");
	ft_printf("%s%s","this","is");
	ft_printf("%s%s%s","this","is","a");
	ft_printf("%s%s%s%s","this","is","a","multi");
	ft_printf("%s%s%s%sstring.gg!","this","is","a","multi","string");
	ft_printf("%s%s%s%s%s","this","is","a","multi","string");
	ft_printf("%s%s",NULL,string);
}//*/

//*
static void actual_tests(void)
{
	return ;
	char	**fmt;
	size_t	i = 0;

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


	while (fmt[0]){
		counter_test((fmt++)[0], (int)i * 3 );
		fflush(stdout);
	}

}
//*/

int    main(void)
{
/*	char	*string = "AaBbCcDdEeFfGg...";
	printf("\n%s", string);
	printf("%32s", string);
	printf("%.32s", string);
	printf("%32.8s", string);
*/	//printf("%032s", string);

	actual_tests();
	basic_tests();
}
/*
{
    int			i;
	uint32_t	a = 0x2260;

    setlocale(LC_ALL, "");
	print_utf8((unsigned*)L"A");ft_putendl(0);
	write(1, (char[2]){'\xc3', '\x80'}, 2);ft_putendl(0);
	print_utf8((unsigned*)L"🔴"); ft_putendl(0);
	print_utf8((unsigned[2]){a, 0});ft_putendl(0);
	printf("%llX\n", (unsigned long long)&i);
    printf("Hello World!\n");
    printf("%s", "This is ");
    printf("%.*s\n", 9, "ft_printf and ft_dprintf");
    printf("%d\n", 123);
    printf("%05d\n", 42);
    printf("%+09d\n", 42);
    printf("%u\n", UINT_MAX);
    printf("%#o\n", 1039);
    printf("%#X\n", 16417188);
    printf("%p\n", &i);
    printf("%C %C %C\n", L'ä', L'ö', L'ü');
    printf("%4S\n", L"🤗 💯 🌍 🚀 🔴 ");

    ft_printf("Hello World!\n");
    ft_printf("%s", "This is ");
    ft_printf("%.*s\n", 9, "ft_printf and ft_dprintf");
    ft_printf("%d\n", 123);
    ft_printf("%05d\n", 42);
    ft_printf("%+09d\n", 42);
    ft_printf("%u\n", UINT_MAX);
    //ft_printf("%#b\n", 256);
    ft_printf("%#o\n", 1039);
    ft_printf("%#X\n", 16417188);
    ft_printf("%p\n", &i);
    ft_printf("%C %C %C\n", 0xe4, L'ö', L'ü');
    ft_printf("%.13S\n", L"🤗 💯 🌍 🚀 🔴 ");
    return (0);
}//*/
/*

void	mirror_char(char *fmt, int n)
{
	printf("char:\n");
	printf(fmt, n);
	ft_printf(fmt, n);
}

void	mirror_int(char *fmt, int n)
{
	printf("int:\n");
	printf(fmt, n);
	ft_printf(fmt, n);
}

void	mirror_str(char *fmt, char *n)
{
	printf("string:\n");
	printf(fmt, n);
	ft_printf(fmt, n);
}

void	mirror_lstr(char *fmt, int *n)
{
	printf("long string:\n");
	printf(fmt, n);
	ft_printf(fmt, n);
}

void	mirror_double(char *fmt, double n, size_t p)
{
	printf("double:\n");
	printf(fmt, p, n);
	print_double(n, p);
	ft_putendl(0);
}

int		main(int n, char **v)
{
	char	*format;
	char	*test;
	float	flo = -4.5253645;
	double	dou = -4.52536457869859501;

	test = "The quick brown fox needs a hug .w.";
	format = "test: %S\n";
	if (n == 1)
	{/ *
		ft_printf("start: FT_PRINTF\n");
		ft_printf(format, test);
		test = "Lazy eye mozambique";
		ft_printf(format, test);
		format = "test: %%\n";
		ft_printf(format, test);
		printf("start: PRINTF\n");
		printf(format, test);
		* /
		//
		mirror_char("%lC\n",  L'ä');
		mirror_lstr("%llS\n", L"ä\xEF\xB7\xB0z");
		mirror_double("printf:\n%.*f\n", flo, 54);
		mirror_double("printf:\n%.*f\n", dou, 54);
	}
	if (n == 2)
	{
		printf(format, v[1]);
		printf("\n:: TEST STRING INPUT ::\n""FT_PRINTF ::\n\t");
		ft_printf(format, v[1]);
	}
	if (n == 3)
	{
		printf(ft_strjoin("::PRINTF::\n\t{",ft_strjoin(v[1],"}\n")), v[2]);
		ft_printf(ft_strjoin("::FT_PRINTF::\n\t{",ft_strjoin(v[1],"}\n")), v[2]);
	}
}
*/
