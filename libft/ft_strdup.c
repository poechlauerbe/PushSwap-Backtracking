/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpochlau <bpochlau@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 13:53:31 by bpochlau          #+#    #+#             */
/*   Updated: 2023/09/21 12:34:32 by bpochlau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <bsd/string.h>
#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		i;
	int		len;
	char	*ptr;

	ptr = (char *)s;
	len = ft_strlen(ptr) + 1;
	ptr = malloc(sizeof(char) * len);
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < len)
	{
		ptr[i] = s[i];
		i++;
	}
	return (ptr);
}

// int main(void)
// {
// 	char *str = "This is another test";
// 	char *dest;
// 	dest = strdup(str);
// 	printf("%s\n", dest);
// 	free(dest);
// 	dest = ft_strdup(str);
// 	printf("%s\n", dest);
// 	free(dest);
// }
