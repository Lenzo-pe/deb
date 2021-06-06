#include "ft_printf.h"
int		main(void)
{
	int i;
	/*
	i = ft_printf("oi%05d", 4); printf(" %d\n", i);
	i = printf("oi%05d", 4); printf(" %d\n", i);
	i = ft_printf("%.*d", 7, 51234); printf(" %d\n", i);
	i = printf("%.*d", 7, 51234); printf(" %d\n", i);
	i = ft_printf("%.*s", 3, "bonodia"); printf(" %d\n", i);
	i = printf("%.*s", 3, "bonodia"); printf(" %d\n", i);

	i = ft_printf("%%-5.3s LYDI == |%-5.3s|\n", "LYDI");
	i = printf("%%-5.3s LYDI == |%-5.3s|\n", "LYDI");
	i = ft_printf("%%04.5i 42 == |%04.5i|\n", 42);
	i = printf("%%04.5i 42 == |%04.5i|\n", 42);

	i = ft_printf("%%04.3i 42 == |%04.3i|\n", 42);
	i = printf("%%04.3i 42 == |%04.3i|\n", 42);

	i = ft_printf("|%04.2i|\n", 42);
	i = printf("|%04.2i|\n", 42);  

	i = ft_printf("%.*s", 0, "hello2");
	i = printf("%.*s", 0, "hello1");

	i = ft_printf("%.*i\n", 6, -3);
	printf("%.*i\n", 6, -3);

	i = ft_printf("%0*i\n", 7, -54);
	printf("%0*i\n", 7, -54);

	ft_printf("%*sa\n", -32, "abc");
	printf("%*sa\n", -32, "abc");
	ft_printf("%-*sa\n", -32, "abc");
	printf("%-*sa\n", -32, "abc");

	ft_printf("%-*.*sa\n", -7, -3, "yolo");
	printf("%-*.*sa\n", -7, -3, "yolo");
	ft_printf("%*ia\n", -14, 94827);
	printf("%*ia\n", -14, 94827);
	ft_printf("%0*ia\n", -7, -54);
	printf("%0*ia\n", -7, -54);

	ft_printf("%.6d\n", -3);
	printf("%.6d\n", -3);

	ft_printf("%.s\n", "hello");
	printf("%.s\n", "hello");
	ft_printf("%.0s\n", "hello");
	printf("%.0s\n", "hello");

	i = ft_printf("%32s", NULL); printf(" %d\n", i);
	i = ft_printf("%2s", NULL); printf(" %d\n", i);
	i = ft_printf("%-32s", NULL); printf(" %d\n", i);
	i = ft_printf("%-16s", NULL); printf(" %d\n", i);

	i = printf("%32s", NULL); printf(" %d\n", i);
	i = printf("%2s", NULL); printf(" %d\n", i);
	i = printf("%-32s", NULL); printf(" %d\n", i);
	i = printf("%-16s", NULL); printf(" %d\n", i);

	static char *s_hidden = "hi low\0don't print me lol\0";
	i = ft_printf("%.03s", s_hidden); printf(" %d\n", i);
	i = ft_printf("%.09s", s_hidden); printf(" %d\n", i);
	i = ft_printf("%.03s", NULL); printf(" %d\n", i);
	i = ft_printf("%.09s", NULL); printf(" %d\n", i);

	i = printf("%.03s", s_hidden); printf(" %d\n", i);
	i = printf("%.09s", s_hidden); printf(" %d\n", i);
	i = printf("%.03s", NULL); printf(" %d\n", i);
	i = printf("%.09s", NULL); printf(" %d\n", i);

	i = ft_printf("%3.s", s_hidden); printf(" %d\n", i);
	i = ft_printf("%10.s", s_hidden);printf(" %d\n", i);
	i = ft_printf("%3.s", NULL);printf(" %d\n", i);
	i = ft_printf("%10.s", NULL);printf(" %d\n", i);
	i = ft_printf("%1.s", "\0");printf(" %d\n", i);
	i = ft_printf("%2.s", "\0");printf(" %d\n", i);
	i = ft_printf("%9.s", "\0");printf(" %d\n", i);
	printf("----------------\n");
	i = printf("%3.s", s_hidden); printf(" %d\n", i);
	i = printf("%10.s", s_hidden);printf(" %d\n", i);
	i = printf("%3.s", NULL);printf(" %d\n", i);
	i = printf("%10.s", NULL);printf(" %d\n", i);
	i = printf("%1.s", "\0");printf(" %d\n", i);
	i = printf("%2.s", "\0");printf(" %d\n", i);
	i = printf("%9.s", "\0");printf(" %d\n", i);

	i = ft_printf("%.03s", NULL); printf(" %d\n", i);
	i = ft_printf("%.09s", NULL); printf(" %d\n", i);
	static char *s_hidden = "hi low\0don't print me lol\0";

	i = ft_printf("%09s", s_hidden);printf(" %d\n", i);
	i = ft_printf("%-09s", s_hidden);printf(" %d\n", i);
	i = ft_printf("%00-s", s_hidden);printf(" %d\n", i);
	i = ft_printf("%0-0s", s_hidden);printf(" %d\n", i);
	i = ft_printf("%0000s", s_hidden);printf(" %d\n", i);

	i = printf("%09s", s_hidden);printf(" %d\n", i);
	i = printf("%-09s", s_hidden);printf(" %d\n", i);
	i = printf("%00-s", s_hidden);printf(" %d\n", i);
	i = printf("%0-0s", s_hidden);printf(" %d\n", i);
	i = printf("%0000s", s_hidden);printf(" %d\n", i);
	
	i = ft_printf("%-00s", s_hidden);printf(" %d\n", i);
	i = printf("%-00s", s_hidden);printf(" %d\n", i);

	i = ft_printf("%5%");printf(" %d\n", i);
	i = ft_printf("%-5%");printf(" %d\n", i);
	i = ft_printf("%05%");printf(" %d\n", i);
	i = ft_printf("%-05%");printf(" %d\n", i);

	i = printf("%5%");printf(" %d\n", i);
	i = printf("%-5%");printf(" %d\n", i);
	i = printf("%05%");printf(" %d\n", i);
	i = printf("%-05%");printf(" %d\n", i);

	i = ft_printf("%-f", 42.5);printf(" %d\n", i);
	i = printf("%-f", 42.5);printf(" %d\n", i);

	i = ft_printf("%%-i 42 == %-i", 42);printf(" %d\n", i);
	i = ft_printf("%%-d 42 == %-d", INT_MIN);printf(" %d\n", i);
	i = ft_printf("%%-i -42 == %-i", -42);printf(" %d\n", i);

	i = printf("%%-i 42 == %-i", 42);printf(" %d\n", i);
	i = printf("%%-d 42 == %-d", INT_MIN);printf(" %d\n", i);
	i = printf("%%-i -42 == %-i", -42);printf(" %d\n", i);
	
	i = ft_printf("%5p", NULL);printf(" %d\n", i);
	i = ft_printf("%2p", NULL);printf(" %d\n", i);
	i = printf("%5p", NULL);printf(" %d\n", i);
	i = printf("%2p", NULL);printf(" %d\n", i);

	
	i = ft_printf("%.6d", -3); printf(" %d\n", i);
	i = printf("%.6d", -3); printf(" %d\n", i);
	i = ft_printf("%.4d", -2372); printf(" %d\n", i);
	i = printf("%.4d", -2372); printf(" %d\n", i);
*/
	/*
	i = ft_printf("%.3d\n", 18); 
	i = ft_printf("%.3d\n", -18);
	i = ft_printf("%.5d\n", 12345);
	i = ft_printf("%.5d\n", -12345);

	i = printf("%.3d\n", 18); 
	i = printf("%.3d\n", -18);
	i = printf("%.5d\n", 12345);
	i = printf("%.5d\n", -12345);

	i = ft_printf("%7d", -14); printf(" %d\n", i);
	i = printf("%7d", -14); printf(" %d\n", i);

	i = ft_printf("%-7d", -14); printf(" %d\n", i);
	i = printf("%-7d", -14); printf(" %d\n", i);

	i = ft_printf("%-5d", -2562); printf(" %d\n", i);
	i = printf("%-5d", -2562); printf(" %d\n", i);

	i = ft_printf("%07d", -54); printf(" %d\n", i);
	i = printf("%07d", -54); printf(" %d\n", i);

	i = ft_printf("%8.5d", 34); printf(" %d\n", i);
	i = ft_printf("%10.5d", -216); printf(" %d\n", i);
	i = ft_printf("%8.5d", 0); printf(" %d\n", i);
	i = printf("%8.5d", 34); printf(" %d\n", i);
	i = printf("%10.5d", -216); printf(" %d\n", i);
	i = printf("%8.5d", 0); printf(" %d\n", i);

	i = ft_printf("%8.3d", 8375); printf(" %d\n", i);
	i = ft_printf("%8.3d", -8473); printf(" %d\n", i);
	i = printf("%8.3d", 8375); printf(" %d\n", i);
	i = printf("%8.3d", -8473); printf(" %d\n", i);

	i = ft_printf("%-8.5d", 34);printf(" %d\n", i);
	i = ft_printf("%-10.5d", -216);printf(" %d\n", i);
	i = ft_printf("%-8.5d", 0);printf(" %d\n", i);

	i = printf("%-8.5d", 34);printf(" %d\n", i);
	i = printf("%-10.5d", -216);printf(" %d\n", i);
	i = printf("%-8.5d", 0);printf(" %d\n", i);
	*//*
	i = ft_printf("%07d", -54); printf(" %d\n", i);
	i = printf("%07d", -54); printf(" %d\n", i);

	i = ft_printf("%08.5d", 34); printf(" %d\n", i);
	i = ft_printf("%010.5d", -216); printf(" %d\n", i);
	i = ft_printf("%08.5d", 0); printf(" %d\n", i);
	i = ft_printf("%08.3d", 8375); printf(" %d\n\n", i);
	i = printf("%08.5d", 34); printf(" %d\n", i);
	i = printf("%010.5d", -216); printf(" %d\n", i);
	i = printf("%08.5d", 0); printf(" %d\n", i);
	i = printf("%08.3d", 8375); printf(" %d\n", i);
	printf("\n");
	i = ft_printf("%08.3d", -8473); printf(" %d\n", i);
	i = ft_printf("%03.7d", 3267); printf(" %d\n", i);
	i = ft_printf("%03.7d", -2375); printf(" %d\n\n", i);
	i = printf("%08.3d", -8473); printf(" %d\n", i);
	i = printf("%03.7d", 3267); printf(" %d\n", i);
	i = printf("%03.7d", -2375); printf(" %d\n", i);

	i = ft_printf("%0-8.5d", 34); printf(" %d\n", i);
	i = printf("%0-8.5d", 34); printf(" %d\n", i);

	
	i = ft_printf("%5.0d", 0); printf(" %d\n", i);
	i = printf("%5.0d", 0); printf(" %d\n", i);

	i = ft_printf("|%-5.3s|\n", "LYDI"); printf(" %d\n", i);
	i = printf("|%-5.3s|\n", "LYDI"); printf(" %d\n", i);
	*//*
	i = ft_printf("|%04i|", 42); printf(" %d\n", i);
	i = ft_printf("|%05i|", 42); printf(" %d\n", i);

	i = ft_printf("|%04.3i|", 42); printf(" %d\n", i);
	i = ft_printf("|%04.2i|", 42); printf(" %d\n", i);
	i = ft_printf("%%-d 42 == %-d", INT_MIN); printf(" %d\n", i);
	i = ft_printf("%d", INT_MAX + 1); printf(" %d\n", i);
	i = ft_printf("%d", INT_MIN); printf(" %d\n", i);

	i = printf("|%04i|", 42); printf(" %d\n", i);
	i = printf("|%05i|", 42); printf(" %d\n", i);
	i = printf("|%04.3i|", 42); printf(" %d\n", i);
	i = printf("|%04.2i|", 42); printf(" %d\n", i);
	i = printf("%%-d 42 == %-d", INT_MIN); printf(" %d\n", i);
	i = printf("%d", INT_MAX + 1); printf(" %d\n", i);
	i = printf("%d", INT_MIN); printf(" %d\n", i);
	*///FIX I
	/*
	i = ft_printf("%.6i", -3); printf(" %d\n", i);
	i = printf("%.6i", -3); printf(" %d\n", i);*/
	//FIX S
	/*
	i = ft_printf("%.0s", "hello"); printf(" %d\n", i);
	i = printf("%.0s", "hello"); printf(" %d\n", i);

	i = ft_printf("%7.5s", "yolo"); printf(" %d\n", i);
	i = printf("%7.5s", "yolo"); printf(" %d\n", i);
	i = ft_printf("%-7.5s", "yolo"); printf(" %d\n", i);
	i = printf("%-7.5s", "yolo"); printf(" %d\n", i);

	i = ft_printf("%3.1s", NULL); printf(" %d\n", i);
	i = printf("%3.1s", NULL); printf(" %d\n", i);
	i = ft_printf("%9.1s", NULL); printf(" %d\n", i);
	i = printf("%9.1s", NULL); printf(" %d\n", i);
	i = ft_printf("%3.6s", NULL); printf(" %d\n", i);
	i = printf("%3.6s", NULL); printf(" %d\n", i);
	i = ft_printf("%20.6s", NULL); printf(" %d\n", i);
	i = printf("%20.6s", NULL); printf(" %d\n", i);
	i = ft_printf("%-3.8s", NULL); printf(" %d\n", i);
	i = printf("%-3.8s", NULL); printf(" %d\n", i);
	i = ft_printf("%-10.8s", NULL); printf(" %d\n", i);
	i = printf("%-10.8s", NULL); printf(" %d\n", i);
	*//*
	static char *s_hidden = "hi low\0don't print me lol\0";
	i = ft_printf("%-.09s", s_hidden); printf(" %d\n", i);
	i = printf("%-.09s", s_hidden); printf(" %d\n", i);
	i = ft_printf("%.5u", 2); printf(" %d\n", i);
	i = printf("%.5u", 2); printf(" %d\n", i);
	i = ft_printf("%.3u", 0); printf(" %d\n", i);
	i = printf("%.3u", 0); printf(" %d\n", i);
	i = ft_printf("%2c", 'f'); printf(" %d\n", i);
	i = printf("%2c", 'f'); printf(" %d\n", i);

	i = ft_printf("%.3i", 0);
	i = ft_printf("%-2c%-3c", 'a', 'v');

	i = ft_printf("%.p", NULL);printf(" %d\n", i);
	i =	printf("%.p", NULL);printf(" %d\n", i);
	i = ft_printf("%5p", NULL);printf(" %d\n", i);
	i =	printf("%5p", NULL);printf(" %d\n", i);
	i =	ft_printf("%2.9p\n", 1234);printf(" %d\n", i);
	i =	printf("%2.9p\n", 1234);printf(" %d\n", i);
	(" %10p %-10p ", 0, 0)
	
	i = ft_printf(" %x ", 0);printf(" %d\n", i);
	i = printf(" %x ", 0);printf(" %d\n", i);printf(" %d\n", i);*/
	/*
	i = ft_printf(" %*.0s %.2s ", 10, "123", "4567");printf(" %d\n", i);
	i = printf(" %*.0s %.2s ", 10, "123", "4567");printf(" %d\n", i);
	i = ft_printf(" --0*%0*.0d*0 0*%0*.10d*0-- ", -21, INT_MAX, 21, INT_MIN);printf(" %d\n", i);
	i = printf(" --0*%0*.0d*0 0*%0*.10d*0-- ", -21, INT_MAX, 21, INT_MIN);printf(" %d\n", i);
	i = ft_printf("%09.0d", UINT_MAX);printf(" %d\n", i);
	i = printf("%09.0d", UINT_MAX);printf(" %d\n", i);

	i = ft_printf(" --0*%-0*.20d*0 0*%-0*.10d*0-- ", -21, CHAR_MAX, 21, CHAR_MIN);printf(" %d\n", i);
	i = printf(" --0*%-0*.20d*0 0*%-0*.10d*0-- ", -21, CHAR_MAX, 21, CHAR_MIN);printf(" %d\n", i);
	i = ft_printf(" --0*%-0*.2d*0 0*%-0*.2d*0-- ", -21, CHAR_MAX, 21, CHAR_MIN);printf(" %d\n", i);
	i = printf(" --0*%-0*.2d*0 0*%-0*.2d*0-- ", -21, CHAR_MAX, 21, CHAR_MIN);printf(" %d\n", i);
	i = ft_printf(" %p %p ", LONG_MIN, LONG_MAX);printf(" %d\n", i);
	i = printf(" %p %p ", LONG_MIN, LONG_MAX);printf(" %d\n", i);
	i = ft_printf("%-0*.20d %-0*.10d", -21, CHAR_MAX, 21, CHAR_MIN);printf(" %d\n", i);
	i = printf("%-0*.20d %-0*.10d", -21, CHAR_MAX, 21, CHAR_MIN);printf(" %d\n", i);
	i = ft_printf(" --0*%-0*.2d*0 0*%-0*.2d*0-- ", -21, CHAR_MAX, 21, CHAR_MIN);printf(" %d\n", i);
	i = printf(" --0*%-0*.2d*0 0*%-0*.2d*0-- ", -21, CHAR_MAX, 21, CHAR_MIN);printf(" %d\n", i);
	i = ft_printf(" --0*%-0*.3d*0 0*%-0*.3d*0-- ", -21, CHAR_MAX, 21, CHAR_MIN);printf(" %d\n", i);
	i = printf(" --0*%-0*.3d*0 0*%-0*.3d*0-- ", -21, CHAR_MAX, 21, CHAR_MIN);printf(" %d\n", i);
	i = ft_printf(" --0*%-0*.4d*0 0*%-0*.4d*0-- ", -21, CHAR_MAX, 21, CHAR_MIN);printf(" %d\n", i);
	i = printf(" --0*%-0*.4d*0 0*%-0*.4d*0-- ", -21, CHAR_MAX, 21, CHAR_MIN);printf(" %d\n", i);

	i = ft_printf("%-0*.3d", -21, CHAR_MAX);printf(" %d\n", i);
	i = printf("%-0*.3d", -21, CHAR_MAX);printf(" %d\n", i);

	i = ft_printf(" --0*%0*.0d*0 0*%0*.10d*0-- ", -21, LONG_MAX, 21, LONG_MIN);printf(" %d\n", i);
	i = printf(" --0*%0*.0d*0 0*%0*.10d*0-- ", -21, LONG_MAX, 21, LONG_MIN);printf(" %d\n", i);

	i = ft_printf(" %-3.2x %10.42x ", 10, -10); printf(" %d\n", i);
	i = printf(" %-3.2x %10.42x ", 10, -10); printf(" %d\n", i);
	i = ft_printf(" 0*%0-*.*x*0 0*%0*.*x*0 ", 2, 6, 102, 21, 10, -101); printf(" %d\n", i);
	i = printf(" 0*%0-*.*x*0 0*%0*.*x*0 ", 2, 6, 102, 21, 10, -101); printf(" %d\n", i);
	i = ft_printf(" 0*%-0*.10x*0 0*%-0*.0x*0 ", 21, 1021, 21, -1011); printf(" %d\n", i);
	i = printf(" 0*%-0*.10x*0 0*%-0*.0x*0 ", 21, 1021, 21, -1011); printf(" %d\n", i);
	i = ft_printf(" --0*%0*.0x*0 0*%0*.10x*0-- ", -21, INT_MAX, 21, INT_MIN); printf(" %d\n", i);
	i = printf(" --0*%0*.0x*0 0*%0*.10x*0-- ", -21, INT_MAX, 21, INT_MIN); printf(" %d\n", i);
	i = ft_printf(" --0*%-0*.20x*0 0*%-0*.10x*0-- ", -21, CHAR_MAX, 21, CHAR_MIN); printf(" %d\n", i);
	i = printf(" --0*%-0*.20x*0 0*%-0*.10x*0-- ", -21, CHAR_MAX, 21, CHAR_MIN); printf(" %d\n", i);
	i = ft_printf("%9.10x", UINT_MAX); printf(" %d\n", i);
	i = printf("%9.10x", UINT_MAX); printf(" %d\n", i);
	i = ft_printf("%10.10x", UINT_MAX); printf(" %d\n", i); 
	i = printf("%10.10x", UINT_MAX); printf(" %d\n", i); 
	i = ft_printf("%11.10x", UINT_MAX); printf(" %d\n", i); 
	i = printf("%11.10x", UINT_MAX); printf(" %d\n", i); 
	i = ft_printf("%-9.10x", UINT_MAX); printf(" %d\n", i); 
	i = printf("%-9.10x", UINT_MAX); printf(" %d\n", i); 
	i = ft_printf("%-10.10x", UINT_MAX); printf(" %d\n", i);
	i = printf("%-10.10x", UINT_MAX); printf(" %d\n", i); 
	i = ft_printf("%09.10x", UINT_MAX); printf(" %d\n", i); 
	i = printf("%09.10x", UINT_MAX); printf(" %d\n", i); 
	i = ft_printf("%010.10x", UINT_MAX); printf(" %d\n", i);
	i = printf("%010.10x", UINT_MAX); printf(" %d\n", i);  
	i = ft_printf("%011.10x", UINT_MAX); printf(" %d\n", i);
	i = printf("%011.10x", UINT_MAX); printf(" %d\n", i);

	i = ft_printf("%011.2x", UINT_MAX + 1);printf(" %d\n", i);
	i = printf("%011.2x", UINT_MAX + 1);printf(" %d\n", i);

	static char *s_hidden = "hi low\0don't print me lol\0";
	i = ft_printf("%-00s", s_hidden);printf(" %d\n", i);
	i = printf("%-00s", s_hidden);printf(" %d\n", i);
	i = ft_printf("%.5p", 0);printf(" %d\n", i);
	i = printf("%.5p", 0);printf(" %d\n", i);
	i = ft_printf(" 0*%-0*.10d*0 0*%-0*.0d*0 ", 21, 1021, 21, -1011);printf(" %d\n", i);
	i = printf(" 0*%-0*.10d*0 0*%-0*.0d*0 ", 21, 1021, 21, -1011);printf(" %d\n", i);
*/

	ft_printf("this %x number", 0);
	return (0);
}