/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fun_base.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpochlau <bpochlau@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 11:50:47 by bpochlau          #+#    #+#             */
/*   Updated: 2023/11/21 16:57:38 by bpochlau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_rev_r(t_list **s)
{
	t_list	*temp;
	t_list	*temp2;

	if (!s)
		return (ERR_IN_R);
	if (!(*s))
		return (NOTHING_DONE);
	if (!(*s)->next)
		return (NOTHING_DONE);
	temp = (*s)->next;
	if (!temp)
		return (NOTHING_DONE);
	temp2 = ft_lstlast(*s);
	if (!temp2)
		return (NOTHING_DONE);
	temp2->next = *s;
	(*s)->next = NULL;
	*s = temp;
	return (OK);
}

int	ft_r(t_list **s)
{
	t_list	*temp;
	t_list	*temp2;

	if (!s)
		return (ERR_IN_R);
	if (!(*s))
		return (NOTHING_DONE);
	if (!(*s)->next)
		return (NOTHING_DONE);
	temp = ft_lstlast(*s);
	if (!temp)
		return (NOTHING_DONE);
	temp2 = ft_lstsecondlast(*s);
	if (!temp2)
		return (NOTHING_DONE);
	temp2->next = NULL;
	temp->next = *s;
	*s = temp;
	return (OK);
}

int	ft_p(t_list **s_push, t_list **s_deliv)
{
	t_list	*temp_p;
	t_list	*temp_d;

	if (!s_deliv || !s_push)
		return (ERR_IN_P);
	if (!*s_deliv)
		return (NOTHING_DONE);
	if (!(*s_deliv)->next)
	{
		temp_p = ft_lstlast(*s_push);
		temp_p->next = *s_deliv;
		*s_deliv = NULL;
	}
	else
	{
		temp_p = ft_lstlast(*s_push);
		if (!temp_p)
			*s_push = ft_lstlast(*s_deliv);
		else
			temp_p->next = ft_lstlast(*s_deliv);
		temp_d = ft_lstsecondlast(*s_deliv);
		temp_d->next = NULL;
	}
	return (OK);
}

int	ft_s(t_list **s)
{
	t_list	*last;
	t_list	*newlast;
	t_list	*temp;

	if (!s)
		return (ERR_IN_S);
	if (!(*s)->next)
		return (NOTHING_DONE);
	if (!(*s)->next->next)
	{
		newlast = *s;
		last = (*s)->next;
		last->next = newlast;
		newlast->next = NULL;
		*s = last;
		return (OK);
	}
	temp = *s;
	while (temp->next->next->next)
		temp = temp->next;
	last = temp->next->next;
	newlast = temp->next;
	newlast->next = NULL;
	last->next = newlast;
	temp->next = last;
	return (OK);
}
