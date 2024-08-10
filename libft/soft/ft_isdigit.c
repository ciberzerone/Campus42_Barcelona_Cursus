#include <stdio.h>
#include <unistd.h>

int ft_isdigit(int c)
{
	if( c >= '0' && c <= '9')
		return 1;
	return 0;
}

int main()
{
	int n = '7';
	printf("%d\n",ft_isdigit(n));
	return 0;
	}
