/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpochlau <poechlauerbe@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 11:54:37 by bpochlau          #+#    #+#             */
/*   Updated: 2023/11/19 19:39:00 by bpochlau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_init_index(t_list *s)
{
	t_list	*new;

	new = s;
	s = s->next;
	while (s)
	{
		if (new->num == s->num)
			return (NUM_ALREADY_EXISTS);
		else if (new->num > s->num)
			new->i += 1;
		else
			s->i += 1;
		s = s->next;
	}
	return (OK);
}

int	ft_iter_str_num(char **str, char **start)
{
	while (**str == ' ' || **str == '\n' || **str == '\t'
		|| **str == '\r' || **str == '\f' || **str == '\v')
		*str += 1;
	*start = *str;
	if (**str == '-' || **str == '+')
	{
		*str += 1;
		if (**str == '-' || **str == '+' || **str == ' ' || **str == '\0')
			return (INPUT_IS_NOT_CORRECT);
	}
	while (ft_isdigit(**str))
		*str += 1;
	return (OK);
}

int	check_str_is_num(char *str, t_list **s1)
{
	int		errcd;
	char	*flag;
	char	*start;

	if (!str)
		return (STRING_ERROR);
	while (*str)
	{
		flag = str;
		errcd = ft_iter_str_num(&str, &start);
		if (flag == str || errcd != OK)
			return (INPUT_IS_NOT_CORRECT);
		if (start != str)
		{
			errcd = ft_add_num_to_list(start, s1);
			if (errcd != OK)
				return (errcd);
			errcd = ft_init_index(*s1);
			if (errcd != OK)
				return (errcd);
		}
	}
	return (OK);
}

int	ft_add_num_to_list(char *str, t_list **s1)
{
	int		num;
	int		errcd;
	t_list	*new;

	errcd = ft_atoi_w_err(str, &num);
	if (errcd != OK)
		return (errcd);
	new = ft_lstnew(num);
	if (!new)
		return (MALLOC_NEW_LIST_FAIL);
	if (*s1 == NULL)
		ft_lstadd_back(s1, new);
	else
		ft_lstadd_front(s1, new);
	return (OK);
}

int	check_input(int argc, char **argv, t_list **s1)
{
	int		errcd;
	int		i;

	i = 1;
	while (i < argc)
	{
		errcd = check_str_is_num(argv[i], s1);
		if (errcd != OK)
			return (errcd);
		i++;
	}
	return (OK);
}
