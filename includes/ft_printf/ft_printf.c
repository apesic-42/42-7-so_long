
#include "ft_printf.h"

/* int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (!s)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}

long	ft_putnbr_base(long n, int baseSize, char *baseChars)
{
	int		count;

	count = 0;
	if (n < 0 && baseSize == 10)
	{
		write(1, "-", 1);
		return (ft_putnbr_base(-n, baseSize, baseChars) + 1);
	}
	else if (n < 0 && baseSize == 16)
		return (ft_putnbr_base(-n, baseSize, baseChars) + 1);
	else if (n < baseSize)
		return (ft_putchar(baseChars[n]));
	else
	{
		count = ft_putnbr_base(n / baseSize, baseSize, baseChars);
		return (count + ft_putnbr_base(n % baseSize, baseSize, baseChars));
	}
}

t_ok	ft_putptr(void *n, unsigned long baseSize, char *baseChars)
{
	unsigned long		count;
	static int			check;
	unsigned long		ln;

	if (!n)
	{
		write(1, "(nil)", 5);
		return (3);
	}
	check = 0;
	if (check == 0)
		(write(1, "0x", 2), check = 1);
	ln = (long)n;
	count = 0;
	if (ln < 0)
		return (ft_putnbr_base(-ln, baseSize, baseChars) + 1);
	else if (ln < baseSize)
		return (ft_putchar(baseChars[ln]));
	else
	{
		count = ft_putnbr_base(ln / baseSize, baseSize, baseChars);
		return (count + ft_putnbr_base(ln % baseSize, baseSize, baseChars));
	}
} */

int	ft_p100(char cara, va_list ap)
{
	int	count;

	count = 0;
	if (cara == 'c')
		return (count += ft_putchar(va_arg(ap, int)));
	else if (cara == 's')
		return (count += ft_putstr(va_arg(ap, char *)));
	else if (cara == 'p')
		return (count += ft_putptr(va_arg(ap, void *),
				16, "0123456789abcdef") + 2);
	else if (cara == 'd' || cara == 'i')
		return (count += ft_putnbr_base(va_arg(ap, int), 10, "0123456789"));
	else if (cara == 'u')
		return (count += ft_putnbr_base(va_arg(ap, unsigned int),
				10, "0123456789"));
	else if (cara == 'x')
		return (count += ft_putnbr_base(va_arg(ap, unsigned int),
				16, "0123456789abcdef"));
	else if (cara == 'X')
		return (count += ft_putnbr_base(va_arg(ap, unsigned int),
				16, "0123456789ABCDEF"));
	else if (cara == '%')
		return (count += ft_putchar('%'));
	else
		return (count += ft_putchar('%'), count += ft_putchar(cara));
}

int	ft_printf(const char *s, ...)
{
	va_list	ap;
	int		count;
	size_t	i;

	if (!s)
		return (-1);
	va_start(ap, s);
	count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i + 1] && s[i] == '%')
		{
			count += ft_p100(s[i + 1], ap);
			i++;
		}
		else
		{
			ft_putchar(s[i]);
			count++;
		}
		i++;
	}
	va_end(ap);
	return (count);
}
/* #include <stdio.h>
int	main(void)
{
	// printf("%d\n", ft_printf("OUIOUI\n%s%!\n", "mafoi"));
	// ft_printf("%d\n", ft_printf("OUIOUI\n%s%!\n", "mafoi"));
	// printf("%d\n", printf("OUIOUI\n%s%!\n", "mafoi"));
	// ft_printf("%d\n", printf("OUIOUI\n%s%!\n", "mafoi"));

	// int	a = ft_printf("%x\n", -123456);
	// int	b = printf("%x\n", -123456);
	// ft_printf("%x\n", a);
	// printf("%x\n", b);

	// int	a = ft_printf("%");
	// int	b = printf("%");
	// printf("mon printf : %d\n le printf : %d\n", a, b);

	// printf("%d\n", ft_printf("ouioui %u ok ok\n", 456789));
	// printf("%d\n", printf("ouioui %u ok ok\n", 456789));

	// printf("%d\n", ft_printf(" NULL %s NULL \n", NULL));
	// printf("%d", printf(" NULL %s NULL \n", NULL));

	printf("%d\n", ft_printf("ok %%%cz%d %u %x %X %p\n", 'd', -7, 23, -8, 9, 42));
	printf("%d\n", printf("ok %%%cz%d %u %x %X %p\n", 'd', -7, 23, -8, 9, 42));

	ft_printf("%d\n", printf("%p\n", -42));
	printf("%d\n", printf("%p\n", -42));
} */
