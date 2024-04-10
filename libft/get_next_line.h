/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpochlau <poechlauerbe@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 13:01:13 by bpochlau          #+#    #+#             */
/*   Updated: 2023/11/10 09:17:49 by bpochlau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFFER_SIZE 1
# define OK 0
# define READ_ERROR 10100
# define MALLOC_ERROR 10200
# define VAR_ERROR 10300

# include <stdlib.h>
# include <unistd.h>

typedef struct s_buff
{
	char			*str;
	struct s_buff	*next;
}		t_buff;

char	*get_next_line(int fd);
int		ft_bufferline(int fd, t_buff **buffer);
char	*ft_fetch_line(t_buff *buffer);
void	ft_free_buff(t_buff **buffer, t_buff *new_buff, char *buff_str);
void	ft_clean_buffer(t_buff **buffer);

t_buff	*ft_lstlast_buff(t_buff *lst);
int		ft_found_nl(t_buff *buffer);
void	ft_lstadd_back_str(t_buff **lst, char *str);
int		ft_strlen_nl(t_buff *buffer);
void	ft_copystr(t_buff *buffer, char *str);

#endif
