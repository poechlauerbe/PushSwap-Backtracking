/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpochlau <bpochlau@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 18:32:40 by bpochlau          #+#    #+#             */
/*   Updated: 2023/10/03 09:00:24 by bpochlau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_unsigned(unsigned int numb, int *totlen)
{
	unsigned int	temp;
	int				len;

	len = 0;
	temp = numb;
	if (numb == 0)
		len = 1;
	while (temp)
	{
		temp /= 10;
		len++;
	}
	while (--len >= 0)
	{
		temp = numb / ft_pot(10, len);
		if (len == 0)
			temp = numb;
		ft_putchar_fd(temp + '0', 1);
		numb -= temp * ft_pot(10, len);
		*totlen += 1;
	}
}

void	ft_signcheck(char *s, va_list prints, size_t *i, int *totlen)
{
	if (s[*i + 1] == 'c')
		ft_putchar_fd((char)va_arg(prints, int), 1);
	else if (s[*i + 1] == 's')
		ft_printstr(va_arg(prints, char *), totlen);
	else if (s[*i + 1] == 'p')
		ft_print_add(va_arg(prints, void *), totlen);
	else if (s[*i + 1] == 'd' || s[*i + 1] == 'i')
		ft_printnbr(va_arg(prints, int), totlen);
	else if (s[*i + 1] == 'u')
		ft_print_unsigned(va_arg(prints, int), totlen);
	else if (s[*i + 1] == 'x' || s[*i + 1] == 'X')
		ft_printhex(va_arg(prints, int), s[*i + 1], totlen);
	else if (s[*i + 1] == '%')
		ft_putchar_fd('%', 1);
	else
	{
		*i += 1;
		return ;
	}
	if (s[*i + 1] == 'c' || s[*i + 1] == '%')
		*totlen += 1;
	*i += 2;
}

char	*ft_malloc_string(char *str)
{
	size_t	len;
	size_t	i;
	char	*ptr;

	if (!str)
		return (NULL);
	len = ft_strlen(str);
	ptr = malloc((len + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	i = -1;
	while (str[++i])
		ptr[i] = str[i];
	ptr[i] = '\0';
	return (ptr);
}

int	ft_check_and_print(va_list prints, char *str)
{
	size_t	i;
	int		totlen;

	i = 0;
	totlen = 0;
	while (str[i] != '\0')
	{
		while (str[i] != '%' && str[i])
		{
			ft_putchar_fd(str[i], 1);
			i++;
			totlen++;
		}
		if (str[i] == '%')
			ft_signcheck(str, prints, &i, &totlen);
	}
	return (totlen);
}

int	ft_printf(const char *str, ...)
{
	va_list	prints;
	char	*ptr;
	int		totlen;

	if (!str)
		return (-1);
	ptr = ft_malloc_string((char *)str);
	if (!ptr)
		return (-1);
	va_start(prints, str);
	totlen = ft_check_and_print(prints, ptr);
	va_end(prints);
	if (ptr)
		free(ptr);
	return (totlen);
}

// #include <limits.h>
// #include <stdio.h>
// int main(void)
// {
// 	// char test1[20] = "This is a test";
// 	// long int myint = 0;
// 	// char mychar = 'Z';
// 	// char *myptr;
// 	int len = 0;
// 	// myptr = test1;
// 	len = ft_printf("%p \n", (void *)(-1));
// 	printf("\n\n%i\n", len);
// 	// ft_printhex(2147483648, 'X');
// 	len = printf("%p \n", (void *)(-1));
// 	printf("\n%i\n", len);
// 	return (OK);
// }
