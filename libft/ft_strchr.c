/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpochlau <bpochlau@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 12:16:08 by bpochlau          #+#    #+#             */
/*   Updated: 2023/09/21 12:33:32 by bpochlau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (i <= ft_strlen(s))
	{
		if (s[i] == (const char) c)
			return (&((char *)s)[i]);
		i++;
	}
	return (NULL);
}

// int main (void)
// {
// 	char *str = "This is a test";
// 	char c = 'i';
// 	char *buff;
// 	printf("Adress start: %p \n", str);
// 	buff = ft_strchr(str, c);
// 	printf("Adress found: %p (my function) \n", buff);
// 	buff = strchr(str, c);
// 	printf("Adress found: %p (original) \n", buff);
// }
