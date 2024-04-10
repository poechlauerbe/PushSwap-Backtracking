/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpochlau <poechlauerbe@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 08:15:07 by bpochlau          #+#    #+#             */
/*   Updated: 2023/11/23 17:39:49 by bpochlau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort(t_vars **vars, t_check *turk)
{
	if ((*vars)->nums == 2)
		ft_sa(vars);
	else if ((*vars)->nums == 3)
		ft_sort_a_3(vars);
	else if ((*vars)->nums == 4)
	{
		if ((*vars)->a->i == 3)
			ft_sort_i_3((*vars)->a, vars);
		else if ((*vars)->a->i == 2)
			ft_sort_i_2((*vars)->a, vars);
		else if ((*vars)->a->i == 1)
			ft_sort_i_1((*vars)->a, vars);
		else if ((*vars)->a->i == 0)
			ft_sort_i_0((*vars)->a, vars);
	}
	else
		ft_turksort(vars, turk);
	ft_exit(vars, OK);
}

void	ft_check_sorted(t_vars *vars)
{
	t_list	*s;

	s = vars->a;
	vars->unsorted = 0;
	vars->nums = 1;
	while (s->next)
	{
		if (s->i < s->next->i)
			vars->unsorted += 1;
		vars->nums += 1;
		s = s->next;
	}
	vars->h_a = vars->nums;
	vars->h_b = 0;
	if (vars->unsorted == 0)
		ft_exit(&vars, OK);
}

int	main(int argc, char **argv)
{
	t_vars	*vars;
	t_vars	v;
	t_check	*turk;
	int		errcd;

	vars = &v;
	if (argc == 1)
		return (OK);
	v.a = NULL;
	v.b = NULL;
	turk = malloc(sizeof(t_check));
	if (!turk)
		ft_exit(&vars, MALLOC_T_CHECK_FAILED);
	v.turk = turk;
	ft_init_turk(turk, NULL, 0, NO_OP);
	errcd = check_input(argc, argv, &vars->a);
	if (errcd != OK)
		ft_exit(&vars, errcd);
	ft_check_sorted(vars);
	// ft_print_stack(vars->a);
	ft_sort(&vars, turk);
	return (OK);
}
