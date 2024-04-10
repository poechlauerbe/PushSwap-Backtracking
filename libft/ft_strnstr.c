/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpochlau <bpochlau@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 13:31:19 by bpochlau          #+#    #+#             */
/*   Updated: 2023/09/15 16:07:45 by bpochlau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <bsd/string.h>
#include <stdio.h>
#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	lilen;

	i = 0;
	if (*little == '\0')
		return ((char *) big);
	if (len == 0)
		return (NULL);
	lilen = ft_strlen((char *)little);
	while ((char)big[i] && i < (len - lilen + 1))
	{
		j = 0;
		while ((char)big[i + j] == (char)little[j])
		{
			j++;
			if (lilen == j)
				return ((char *)&big[i]);
		}
		i++;
	}
	return (NULL);
}

// int	main(void)
// {
// 	char *ptr;
// 	int n = 10;
// 	char	str[30] = "12345678901234567890";
// 	char	to_find[10] = "7890";
// 	ptr = strnstr(str, to_find, n);
// 	printf("Original: %s\n", ptr);
// 	ptr = ft_strnstr(str, to_find, n);
// 	printf("Mine:     %s\n", ptr);
// }
