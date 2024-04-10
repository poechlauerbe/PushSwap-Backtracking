/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpochlau <bpochlau@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 13:06:29 by bpochlau          #+#    #+#             */
/*   Updated: 2023/10/23 18:30:41 by bpochlau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_bufferline(int fd, t_buff **buffer)
{
	char	*str;
	int		rd_val;

	if (!buffer)
		return (VAR_ERROR);
	while (!(ft_found_nl(*buffer)))
	{
		str = malloc((BUFFER_SIZE + 1) * sizeof(char));
		if (!str)
			return (MALLOC_ERROR);
		rd_val = read(fd, str, BUFFER_SIZE);
		if (rd_val == 0)
		{
			free(str);
			return (OK);
		}
		if (rd_val < 0)
		{
			free(str);
			return (READ_ERROR);
		}
		str[rd_val] = '\0';
		ft_lstadd_back_str(buffer, str);
	}
	return (OK);
}

char	*ft_fetch_line(t_buff *buffer)
{
	int		len;
	char	*str;

	len = 0;
	if (!buffer)
		return (NULL);
	len = ft_strlen_nl(buffer);
	str = malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	ft_copystr(buffer, str);
	return (str);
}

void	ft_free_buff(t_buff **buffer, t_buff *new_buff, char *buff_str)
{
	t_buff	*temp;

	if (!buffer)
		return ;
	while (*buffer)
	{
		temp = buffer[0]->next;
		free(buffer[0]->str);
		free(*buffer);
		*buffer = temp;
	}
	*buffer = NULL;
	if (new_buff && buff_str)
	{
		if (new_buff->str[0])
			*buffer = new_buff;
		else
		{
			free(new_buff);
			free(buff_str);
		}
	}
}

void	ft_clean_buffer(t_buff **buffer)
{
	t_buff	*new_buff;
	t_buff	*last_node;
	char	*buff_str;
	int		i;
	int		j;

	last_node = ft_lstlast_buff(*buffer);
	new_buff = malloc(sizeof(t_buff));
	if (!new_buff)
		return ;
	buff_str = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff_str)
		return (free(new_buff));
	i = 0;
	j = 0;
	while (last_node->str[i] && last_node->str[i] != '\n')
		i++;
	while (last_node->str[i] && last_node->str[++i])
		buff_str[j++] = last_node->str[i];
	buff_str[j] = '\0';
	new_buff->str = buff_str;
	new_buff->next = NULL;
	ft_free_buff(buffer, new_buff, buff_str);
}

char	*get_next_line(int fd)
{
	static t_buff	*buffer = NULL;
	char			*line;
	int				errcd;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		if (buffer)
			ft_free_buff(&buffer, NULL, NULL);
		return (NULL);
	}
	errcd = ft_bufferline(fd, &buffer);
	if (!buffer)
		return (NULL);
	if (errcd)
	{
		if (buffer)
			ft_free_buff(&buffer, NULL, NULL);
		return (NULL);
	}
	line = ft_fetch_line(buffer);
	ft_clean_buffer(&buffer);
	return (line);
}

// #include <fcntl.h>
// #include <stdio.h>
// int main (void)
// {
// 	int fd;
// 	char *ptr;
// 	fd = open("../map/test1map.ber", O_RDONLY);
// 	ptr = get_next_line(fd);
// 	if(ptr)
// 	{
// 		printf("%s", ptr);
// 		free(ptr);
// 	}
// 	ptr = get_next_line(fd);
// 	if (ptr)
// 	{
// 		printf("%s", ptr);
// 		free(ptr);
// 	}
// 	ptr = get_next_line(fd);
// 	if (ptr)
// 	{
// 		printf("%s", ptr);
// 		free(ptr);
// 	}
// 	ptr = get_next_line(fd);
// 	if (ptr)
// 	{
// 		printf("%s", ptr);
// 		free(ptr);
// 	}
// 	ptr = get_next_line(fd);
// 	if (ptr)
// 	{
// 		printf("%s", ptr);
// 		free(ptr);
// 	}
// 	ptr = get_next_line(fd);
// 	if (ptr)
// 	{
// 		printf("%s", ptr);
// 		free(ptr);
// 	}
// 	ptr = get_next_line(fd);
// 	if (ptr)
// 	{
// 		printf("%s", ptr);
// 		free(ptr);
// 	}
// 	close(fd);
// }
