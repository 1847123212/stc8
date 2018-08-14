int main()
{
	int a,b,c,d,e,f;
	d=(a=10,b=100,c=1000);
	e=(a=100,a++,b=a,c=a*b);
	f=(a=10,b=a*30,c=a+b);
	return 0;
}
