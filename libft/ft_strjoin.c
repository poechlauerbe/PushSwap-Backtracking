/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpochlau <bpochlau@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 15:44:59 by bpochlau          #+#    #+#             */
/*   Updated: 2023/09/21 12:33:09 by bpochlau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*ptr;
	unsigned int	len;
	unsigned int	i;

	len = ft_strlen((char *) s1) + ft_strlen((char *) s2) + 1;
	ptr = malloc(sizeof(char) * len);
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (*s1)
	{
		ptr[i++] = *s1;
		s1++;
	}
	while (*s2)
	{
		ptr[i++] = *s2;
		s2++;
	}
	ptr[i] = '\0';
	return (ptr);
}

// int main(void)
// {
// 	char *st1 = "";
// 	char *st2 = "string002";
// 	char *ptr;
// 	ptr = ft_strjoin(st1, st2);
// 	if (!ptr)
// 		return (-1);
// 	printf("%s\n", ptr);
// 	return (0);
// }
