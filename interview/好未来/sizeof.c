#include <stdio.h>
#include <stdint.h>

typedef struct A
{
	double a;
	char c;
	double b;
	char d;
}ST_A;

//#define STRUCT_OFFSET(TYPE, MEMBER) ((unsigned long)(&(((TYPE*)0)->MEMBER)))

#define OFFSET(TYPE , MEMBER)((int64_t)(&(((TYPE *)0)->MEMBER)))

int main(void)
{
	int64_t offset = OFFSET(ST_A, d);

	printf("%lld\n", offset);
	
	ST_A sta;

	offset = (unsigned long)(&(sta.a)) - (unsigned long)(&(sta.c));

	printf("%p\n", &sta);
	printf("%p\n", &(sta.c));
	printf("%lld\n", offset);


	return 0;
}
