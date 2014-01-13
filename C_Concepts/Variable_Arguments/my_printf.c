#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

char* convert(uint64_t num, int base){
	static char buf[65];
	char *ptr;

	ptr = &buf[sizeof(buf)-1];
	*ptr = '\0';
	
	do{
		*--ptr = "0123456789ABCDEF"[num%base];
		num = num/base;
	}while(num);

	return ptr;
}


void my_printf(const char *fmt, ...){
	const char *p;
	char *s;
	int i;
	uint64_t addr;

	// Initializing the variable argument pointer
	va_list arg_ptr;

	// Setting arg_ptr to format string
	va_start(arg_ptr, fmt);

	p = fmt;
	for(; *p != '\0'; p++){
		if(*p != '%'){
			putchar(*p);
			continue;
		}

		switch(*p){
			case 'c':	/*
					Even for char, we tell va_arg to get an int because, it is 
					the C standard which says when a char is passed a variable
					argument, it is promoted to int.
					*/
					i = va_arg(arg_ptr, int);
					/*
					If the arg_ptr is pointing to address 100, it now fetches
					4 bytes from arg_ptr and increments arg_ptr so that it points
					to 104.
					*/
					putchar(i);
					break; 

			case 'd':	i = va_arg(arg_ptr, int);
					puts(convert(i,10));
					break;
			
			case 's':	s = va_arg(arg_ptr, char*);
					puts(s);
					break;

			case 'p':	addr = va_arg(arg_ptr, uint64_t);
					puts(convert(addr, 16));
					break;
		}
			
	}
}

int main(int argc, char *argv[]){
	if(argc < 2){
		my_printf("Program must have atleast 1 argment\n\n");
		exit(0);
	}
	int a=0;
	printf("Good. %d  %p\n",atoi(argv[1]), &a);
	return 0;
}
