/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpochlau <bpochlau@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 13:25:40 by bpochlau          #+#    #+#             */
/*   Updated: 2023/10/23 11:23:17 by bpochlau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_buff	*ft_lstlast_buff(t_buff *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_lstadd_back_str(t_buff **lst, char *str)
{
	t_buff	*ptr;
	t_buff	*new;

	new = malloc(sizeof(t_buff));
	if (!new)
		return ;
	new->str = str;
	new->next = NULL;
	if (lst && *lst)
	{
		ptr = ft_lstlast_buff(*lst);
		ptr->next = new;
	}
	else
		*lst = new;
}

int	ft_found_nl(t_buff *buffer)
{
	int	i;
	int	strlen;

	if (!buffer || !buffer->str)
		return (0);
	buffer = ft_lstlast_buff(buffer);
	strlen = 0;
	while (buffer->str[strlen])
	{
		strlen++;
	}
	i = 0;
	while (i <= strlen)
	{
		if (buffer->str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

int	ft_strlen_nl(t_buff *buffer)
{
	int	i;
	int	len;

	len = 0;
	while (buffer)
	{
		i = 0;
		while (buffer->str[i] && buffer->str[i] != '\n')
		{
			i++;
			len++;
		}
		if (buffer->str[i] == '\n')
		{
			len++;
			return (len);
		}
		buffer = buffer->next;
	}
	return (len);
}

void	ft_copystr(t_buff *buffer, char *str)
{
	int	i;
	int	j;

	j = 0;
	while (buffer)
	{
		i = 0;
		while (buffer->str[i])
		{
			if (buffer->str[i] == '\n')
			{
				str[j] = '\n';
				str[j + 1] = '\0';
				return ;
			}
			str[j] = buffer->str[i];
			i++;
			j++;
		}
		buffer = buffer->next;
	}
	str[j] = '\0';
}
