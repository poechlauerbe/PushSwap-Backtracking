/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpochlau <bpochlau@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 14:41:38 by bpochlau          #+#    #+#             */
/*   Updated: 2023/09/15 15:28:34 by bpochlau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t		len;
	char		*ptr;
	size_t		i;

	if (!s)
		return (NULL);
	len = ft_strlen((char *) s);
	ptr = (char *) malloc((len + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	i = 0;
	while (s[i])
	{
		ptr[i] = f(i, s[i]);
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

// char ft_test(unsigned int i, char c)
// {
// 	if(i % 2)
// 		c = ft_toupper(c);
// 	else
// 		c = ft_tolower(c);
// 	return (c);
// }
// int main (void)
// {
// 	char s[30] = "";
// 	char *ptr;
// 	ptr = ft_strmapi(s, ft_test);
// 	printf("%p\n", ptr);
// 	free(ptr);
// }
