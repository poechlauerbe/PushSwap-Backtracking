/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpochlau <bpochlau@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 12:16:08 by bpochlau          #+#    #+#             */
/*   Updated: 2023/09/15 16:30:21 by bpochlau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// The  strchr() function returns a pointer to the first occurrence of the
// character c in the string s.

#include <stdio.h>
#include <string.h>

char	*ft_strrchr(const char *s, int c)
{
	char	*buff;

	buff = NULL;
	while (c > 255)
		c -= 256;
	while (*s)
	{
		if (*s == (char) c)
			buff = (char *) s;
		s++;
	}
	if (c == '\0')
		return ((char *) s);
	return (buff);
}

// int main (void)
// {
// 	char *str = "teste";
// 	int c = 1125;
// 	char *buff;
// 	printf("Adress start: %p \n", str);
// 	buff = ft_strrchr(str, c);
// 	printf("Adress found: %p (my function) \n", buff);
// 	buff = strrchr(str, c);
// 	printf("Adress found: %p (original) \n", buff);
// }
