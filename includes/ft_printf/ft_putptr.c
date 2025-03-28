
#include "ft_printf.h"

t_ok	ft_putptr(void *n, unsigned long baseSize, char *baseChars)
{
	unsigned long	count;
	static int		check;
	unsigned long	ln;

	if (!n)
	{
		write(1, "(nil)", 5);
		return (3);
	}
	check = 0;
	if (check == 0)
		(write(1, "0x", 2), check = 1);
	ln = (unsigned long)n;
	count = 0;
	if (ln < baseSize)
		return (ft_putchar(baseChars[ln]));
	else
	{
		count = ft_putnbr_base(ln / baseSize, baseSize, baseChars);
		return (count + ft_putnbr_base(ln % baseSize, baseSize, baseChars));
	}
}
