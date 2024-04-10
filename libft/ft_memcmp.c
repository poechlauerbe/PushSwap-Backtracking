/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpochlau <bpochlau@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 14:04:16 by bpochlau          #+#    #+#             */
/*   Updated: 2023/09/15 11:45:40 by bpochlau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;
	int				ret;
	size_t			i;

	i = 0;
	str1 = (unsigned char *) s1;
	str2 = (unsigned char *) s2;
	while (i < n)
	{
		ret = str1[i] - str2[i];
		if (ret != 0)
			return (ret);
		i++;
	}
	return (0);
}

// int main (void)
// {
// 	char s1[] = {-128, 0, 127, 0};
// 	char s2[] = {0, 0, 127, 0};
// 	int ret;
// 	int val = 1;
// 	ret = memcmp(s1, s2, val);
// 	printf("Original: %d \n", ret);
// 	ret = ft_memcmp(s1, s2, val);
// 	printf("Mine: %d \n", ret);
// }
	// char *s1 ="abc de";
	// char *s2 ="dbdc de";
	// int *s1;
	// int var1 = 4000000;
	// int *s2;
	// int var2 = 4210000;
	// s1 = &var1;
	// s2 = &var2;
	// char *s1 ="abc de";
	// char *s2 ="dbdc de";
