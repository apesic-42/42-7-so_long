
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

typedef unsigned long	t_ok;

int		ft_printf(const char *s, ...)__attribute__((format(printf, 1, 2)));
int		ft_putchar(char c);
int		ft_putstr(char *s);
long	ft_putnbr_base(long n, int baseSize, char *baseChars);
t_ok	ft_putptr(void *n, unsigned long baseSize, char *baseChars);

#endif
