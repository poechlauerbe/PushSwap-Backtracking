/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpochlau <bpochlau@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 08:16:21 by bpochlau          #+#    #+#             */
/*   Updated: 2023/11/24 16:08:22 by bpochlau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define OK 0
# define TOO_LESS_ARGS 1000
# define STRING_ERROR 1100
# define INPUT_IS_NOT_CORRECT 1110
# define MALLOC_NEW_LIST_FAIL 1120
# define INTEGER_OVERFLOW_OR_UNDERFLOW 1130
# define NUM_ALREADY_EXISTS 1200
# define ERR_IN_S 1310
# define ERR_IN_P 1410
# define ERR_IN_R 1510
# define ERR_IN_REV 1610
# define MALLOC_T_CHECK_FAILED 1700

# define NOTHING_DONE 100

# define RR 0
# define RRR 1
# define RB 2
# define RRB 3
# define RA 4
# define RRA 5
# define SA 6
# define SB 7
# define NO_OP 10
# define MAX_BACKTRACK_OPS 10

# define FOUND 1

# include "./libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_list
{
	int				num;
	int				i;
	struct s_list	*next;
}	t_list;

typedef struct s_check
{
	int				step;
	t_list			*ca;
	t_list			*cb;
	int				operation;
	int				found;
	struct s_check	*next[7];
	struct s_check	*last;
}	t_check;

typedef struct s_vars
{
	int		h_a;
	int		h_b;
	int		nums;
	int		pos;
	int		steps;
	int		unsorted;
	int		found;
	int		count;
	t_list	*a;
	t_list	*b;
	t_check	*turk;
}	t_vars;

typedef struct s_back
{
	int				operation;
	struct s_back	*next;
}	t_back;

void	ft_print_stack(t_list *stack);

int		ft_iter_str_num(char **str, char **start);
int		check_str_is_num(char *str, t_list **s1);
int		ft_add_num_to_list(char *str, t_list **s1);
int		check_input(int argc, char **argv, t_list **s1);

void	ft_exit(t_vars **vars, int errcd);
void	ft_free_list(t_list **path);
void	err_mes(int errcd);

int		ft_rev_r(t_list **s);
int		ft_r(t_list **s);
int		ft_p(t_list **s_p, t_list **s2);
int		ft_s(t_list **s);

int		ft_rra(t_vars **vars);
int		ft_rrb(t_vars **vars);
int		ft_rrr(t_vars **vars);

int		ft_ra(t_vars **vars);
int		ft_rb(t_vars **vars);
int		ft_rr(t_vars **vars);

int		ft_sa(t_vars **vars);
int		ft_sb(t_vars **vars);
int		ft_ss(t_vars **vars);
int		ft_pa(t_vars **vars);
int		ft_pb(t_vars **vars);

t_list	*ft_lstnew(int num);
void	ft_lstadd_front(t_list **lst, t_list *new);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstsecondlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);

void	ft_sort_i_3(t_list *a, t_vars **vars);
void	ft_sort_i_2(t_list *a, t_vars **vars);
void	ft_sort_i_1(t_list *a, t_vars **vars);
void	ft_sort_i_0(t_list *a, t_vars **vars);

void	ft_check_pos_ret(t_vars **vars, int i, int *a_top_i, int *a_low_i);
void	ft_ret_b_a(t_vars **vars);
void	ft_sort_a_3(t_vars **vars);

void	ft_jump_back(t_check *last, t_vars **vars);
void	ft_turk_check_sorting(t_check *turk, t_vars **vars);
void	ft_init_turk(t_check *new, t_check *last, int step, int operation);
void	ft_turksort(t_vars **vars, t_check *turk);

void	ft_turk_loop(t_check *turk, t_vars **vars);

t_list	*ft_copy_list(t_list *stack);
int		ft_atoi_w_err(const char *nptr, int *num);

#endif
