#include <stdio.h>
#include <unistd.h>

int ft_isalpha(int c)
{
	if((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
	{
		return 1;
	}
	return 0;
}

int main()
{
int i;
i = 'j';
printf("%d/n", ft_isalpha(i));
return 0;

}
