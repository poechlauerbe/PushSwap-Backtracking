/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpochlau <bpochlau@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 13:13:03 by bpochlau          #+#    #+#             */
/*   Updated: 2023/09/15 16:00:42 by bpochlau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	Compares two string and returns the difference between the Ascii values
	first difference, max until n

*/

#include <string.h>
#include <stdio.h>
#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	ret;

	i = 0;
	ret = 0;
	if (!n)
		return (0);
	while (s1[i] && s2[i] && n > 1)
	{
		ret = (unsigned char) s1[i] - (unsigned char) s2[i];
		if (ret != 0)
			return (ret);
		i++;
		n--;
	}
	ret = (unsigned char) s1[i] - (unsigned char) s2[i];
	if (ret != 0)
		return (ret);
	return (0);
}

// int	main(void)
// {
// 	unsigned int n = 5;
// 	int comp;
// 	char	str1[20] = "abcdef";
// 	char	str2[20] = "abc\375xx";

// 	comp = ft_strncmp(str1, str2, n);
// 	printf("ft_strncmp: %i\n", comp);
// 	comp = strncmp(str1, str2, n);
// 	printf("strncmp: %i\n", comp);
// }
