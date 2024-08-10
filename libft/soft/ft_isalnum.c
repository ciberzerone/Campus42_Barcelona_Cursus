#include <stdio.h>
#include <unistd.h>

int ft_isdigit(int c)
{
	if( c >= '0' && c <= '9')
		return 1;
	return 0;
}

int ft_isalpha(int c)
{
	if((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
	{
		return 1;
	}
	return 0;
}

int ft_isalnum(int c)
{
	if (ft_isalpha(c) || ft_isdigit(c))
		return (1);
	return(0);
}

int main()
{
	int o = 'T';
	printf("%d\n", ft_isalnum(o));
	return 0;
}
