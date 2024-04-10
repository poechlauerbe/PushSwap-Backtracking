/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpochlau <bpochlau@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 16:05:59 by bpochlau          #+#    #+#             */
/*   Updated: 2023/09/14 08:39:46 by bpochlau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	while (s[i])
	{
		(*f)(i, (s + i));
		i++;
	}
	return ;
}

// void ft_test(unsigned int i, char *c)
// {
// 	if(i % 2)
// 		*c = ft_toupper(*c);
// 	else
// 		*c = ft_tolower(*c);
// 	return ;
// }
// int main (void)
// {
// 	char s[30] = "This is a test";
// 	ft_striteri(s, ft_test);
// 	printf("%s\n", s);
// }
