/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpochlau <bpochlau@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:37:00 by bpochlau          #+#    #+#             */
/*   Updated: 2023/11/27 16:01:20 by bpochlau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_check_operations(t_back *temp, t_vars **vars)
{
	if (temp->operation == SA)
		ft_sa(vars);
	else if (temp->operation == SB)
		ft_sb(vars);
	else if (temp->operation == RA)
		ft_ra(vars);
	else if (temp->operation == RB)
		ft_rb(vars);
	else if (temp->operation == RR)
		ft_rr(vars);
	else if (temp->operation == RRA)
		ft_rra(vars);
	else if (temp->operation == RRB)
		ft_rrb(vars);
	else if (temp->operation == RRR)
		ft_rrr(vars);
}

void	ft_print_turk_movs(t_back *start, t_vars **vars)
{
	t_back	*temp;
	t_back	*temp2;

	while (start)
	{
		temp2 = NULL;
		temp = start;
		while (temp->next)
		{
			temp2 = temp;
			temp = temp->next;
		}
		ft_check_operations(temp, vars);
		if (temp2)
		{
			temp2->next = NULL;
			free(temp);
		}
		else
		{
			free (start);
			start = NULL;
		}
	}
	ft_pb(vars);
}

void	ft_assign_moves(t_check **new, int fun)
{
	if (fun == SA)
		ft_s(&(*new)->ca);
	else if (fun == SB)
		ft_s(&(*new)->cb);
	else if (fun == RA)
		ft_r(&(*new)->ca);
	else if (fun == RB)
		ft_r(&(*new)->cb);
	else if (fun == RR)
	{
		ft_r(&(*new)->ca);
		ft_r(&(*new)->cb);
	}
	else if (fun == RRA)
		ft_rev_r(&(*new)->ca);
	else if (fun == RRB)
		ft_rev_r(&(*new)->cb);
	else if (fun == RRR)
	{
		ft_rev_r(&(*new)->ca);
		ft_rev_r(&(*new)->cb);
	}
}

void	ft_check_if_found(t_vars **vars, t_check *new)
{
	t_list	*a;
	t_list	*temp;
	int		b_low_i;
	int		b_high_i;

	b_low_i = new->cb->i;
	b_high_i = b_low_i;
	temp = new->cb->next;
	while (temp)
	{
		if (b_low_i > temp->i)
			b_low_i = temp->i;
		else if (b_high_i < temp->i)
			b_high_i = temp->i;
		temp = temp->next;
	}
	a = ft_lstlast(new->ca);
	if ((a->i < new->cb->i && a->i > ft_lstlast(new->cb)->i)
		|| (b_low_i == new->cb->i
			&& (a->i < b_low_i || a->i > b_high_i)))
	{
		ft_jump_back(new, vars);
		new->found = FOUND;
	}
}

void	ft_new_check(t_check **last, int fun, t_vars **vars)
{
	t_check	*new;

	new = malloc(sizeof(t_check));
	if (!new)
		ft_exit(vars, MALLOC_T_CHECK_FAILED);
	ft_init_turk(new, *last, (*last)->step + 1, fun);
	if ((*vars)->steps < new->step)
		(*vars)->steps = new->step;
	new->ca = ft_copy_list((*last)->ca);
	new->cb = ft_copy_list((*last)->cb);
	ft_assign_moves(&new, fun);
	(*last)->next[fun] = new;
	ft_check_if_found(vars, new);
}

void	ft_jump_back(t_check *last, t_vars **vars)
{
	t_back	*new;
	t_back	*start;
	t_back	*temp;

	(*vars)->found = FOUND;
	start = NULL;
	while (last->last)
	{
		new = malloc(sizeof(t_back));
		if (!new)
			ft_exit (vars, MALLOC_T_CHECK_FAILED);
		new->operation = last->operation;
		new->next = NULL;
		if (!start)
			start = new;
		else
			temp->next = new;
		last = last->last;
		temp = new;
	}
	ft_print_turk_movs(start, vars);
}

void	ft_move_back_check(t_check *turk, int *check)
{
	int	i;

	i = -1;
	while (++i < 7)
		check[i] = 1;
	if (turk->operation == RR)
	{
		check[RRR] = 0;
		check[RRA] = 0;
		check[RRB] = 0;
	}
	else if (turk->operation == RRR)
	{
		check[RR] = 0;
		check[RA] = 0;
		check[RB] = 0;
	}
	else if (turk->operation == RA)
	{
		check[RRA] = 0;
		check[RB] = 0;
		check[RR] = 0;
		check[RRR] = 0;
	}
	else if (turk->operation == RB)
	{
		check[RRB] = 0;
		check[RA] = 0;
		check[RR] = 0;
		check[RRR] = 0;
	}
	else if (turk->operation == RRA)
	{
		check[RA] = 0;
		check[RRB] = 0;
		check[RR] = 0;
		check[RRR] = 0;
	}
	else if (turk->operation == RRB)
	{
		check[RB] = 0;
		check[RRA] = 0;
		check[RR] = 0;
		check[RRR] = 0;
	}

	if (turk->operation == SA)
		check[SA] = 0;
	if (turk->last)
	{
		i = -1;
		if (turk->last->operation == SA)
			while (++i < 7)
				check[i] = 0;

		if (turk->last->operation == RR)
		{
			check[RRR] = 0;
			check[RRA] = 0;
			check[RRB] = 0;
		}
		else if (turk->last->operation == RRR)
		{
			check[RR] = 0;
			check[RA] = 0;
			check[RB] = 0;
		}
		else if (turk->last->operation == RA)
		{
			check[RB] = 0;
			check[RRA] = 0;
			check[RR] = 0;
			check[RRR] = 0;
		}
		else if (turk->operation == RB)
		{
			check[RRB] = 0;
			check[RA] = 0;
			check[RR] = 0;
			check[RRR] = 0;
		}
	}
}

void	ft_turk_loop(t_check *turk, t_vars **vars)
{
	int	check[7];
	int	i;

	ft_move_back_check(turk, check);
	i = 0;
	while (i < 7 && (*vars)->found != FOUND)
	{
		if (turk->next[i] && check[i])
			ft_turk_loop(turk->next[i], vars);
		else if ((*vars)->found != FOUND && check[i])
			ft_new_check(&turk, i, vars);
		i++;
	}
}

void	ft_free_loop(t_check *turk)
{
	int	i;

	i = 0;

	if (!turk)
		return ;
	while (i < 7)
	{
		if (turk->next[i])
			ft_free_loop(turk->next[i]);
		i++;
	}
	if (turk->last)
	{
		if (turk->ca)
			ft_free_list(&turk->ca);
		if (turk->cb)
			ft_free_list(&turk->cb);
		free(turk);
	}
}

void	ft_find_low_and_high_i(t_list *temp, int *low_i, int *high_i)
{
	*low_i = temp->i;
	*high_i = temp->i;
	temp = temp->next;
	while (temp)
	{
		if (*low_i > temp->i)
			*low_i = temp->i;
		else if (*high_i < temp->i)
			*high_i = temp->i;
		temp = temp->next;
	}
}

void	ft_find_edge(t_vars **vars, int index, int low_i, int high_i)
{
	t_list	*t_b;

	t_b = (*vars)->b;
	if (index < low_i)
	{
		while (t_b->i != low_i)
		{
			(*vars)->count++;
			t_b = t_b->next;
		}
	}
	else
	{
		while (t_b->i != high_i)
		{
			(*vars)->count++;
			t_b = t_b->next;
		}
	}
	if ((*vars)->count < (*vars)->h_b - (*vars)->count)
		while ((*vars)->count-- > 0)
			ft_rrb(vars);
	else
	{
		(*vars)->count--;
		while (((*vars)->h_b - (*vars)->count++) > 0)
			ft_rb(vars);
	}
}

void	ft_simple_track(t_vars **vars)
{
	int		index;
	t_list	*t_b;
	int		low_i;
	int		high_i;

	// ft_print_stack((*vars)->a);
	// ft_print_stack((*vars)->b);
	(*vars)->count = 1;
	index = ft_lstlast((*vars)->a)->i;
	t_b = (*vars)->b;
	ft_find_low_and_high_i(t_b, &low_i, &high_i);
	if (index > high_i || index < low_i)
		ft_find_edge(vars, index, low_i, high_i);
	else
	{
		while (!(t_b->i < index && t_b->next && t_b->next->i > index))
		{
			(*vars)->count++;
			t_b = t_b->next;
		}
		if ((*vars)->count < (*vars)->h_b - (*vars)->count)
			while ((*vars)->count-- > 0)
				ft_rrb(vars);
		else
			while (((*vars)->h_b - (*vars)->count++) > 0)
				ft_rb(vars);
	}
	ft_pb(vars);
	// ft_print_stack((*vars)->a);
	// ft_print_stack((*vars)->b);
}

void	ft_turk_check_sorting(t_check *turk, t_vars **vars)
{
	t_list	*a;
	int		b_low_i;
	int		b_high_i;

	ft_init_turk(turk, NULL, 0, NO_OP);
	(*vars)->steps = 0;
	turk->ca = (*vars)->a;
	turk->cb = (*vars)->b;
	ft_find_low_and_high_i(turk->cb, &b_low_i, &b_high_i);
	a = ft_lstlast(turk->ca);
	if ((a->i < turk->cb->i && a->i > ft_lstlast(turk->cb)->i)
		|| (b_low_i == turk->cb->i
			&& (a->i < b_low_i || a->i > b_high_i)))
	{
		(*vars)->found = FOUND;
		ft_pb(vars);
	}
	else
		while ((*vars)->found == 0 && (*vars)->steps <= MAX_BACKTRACK_OPS)
			ft_turk_loop(turk, vars);
	ft_free_loop(turk);
	if ((*vars)->found == 0 && (*vars)->steps >= MAX_BACKTRACK_OPS)
		ft_simple_track(vars);
}

void	ft_init_turk(t_check *new, t_check *last, int step, int operation)
{
	int	i;

	i = 0;
	while (i < 7)
	{
		new->next[i] = NULL;
		i++;
	}
	new->last = last;
	new->operation = operation;
	new->ca = NULL;
	new->cb = NULL;
	new->step = step;
}

void	ft_turksort(t_vars **vars, t_check *turk)
{
	ft_pb(vars);
	ft_pb(vars);
	if ((*vars)->h_a < 210)
	{
		while ((*vars)->h_a > 3)
		{
			(*vars)->found = 0;
			ft_turk_check_sorting(turk, vars);
		}
	}
	else
		ft_exit(vars, 121);
	ft_sort_a_3(vars);
	while ((*vars)->b->i > ft_lstlast((*vars)->b)->i)
		ft_rrb(vars);
	// ft_print_stack((*vars)->a);
	// ft_print_stack((*vars)->b);
	ft_ret_b_a(vars);
}
