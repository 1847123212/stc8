#include "reg51.h"

sfr P6=0xe8;

void main()
{
	long int i=0;
	P6=0xfe;
	while(1)
	{
		for(i=0;i<100000;i++);
		P6=P6<<1;
		if(P6==0) P6=0xfe;
	}
}
