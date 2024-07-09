/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmafueni <jmafueni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 14:16:01 by jmafueni          #+#    #+#             */
/*   Updated: 2024/07/01 14:58:33 by jmafueni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

t_list		*filllst(int ac, char **av);
t_list		*filllst2(int ac, char **av);
t_list		*ft_lstnew2(int n);
t_list		*ft_lstlast(t_list *lst);
t_list		*get_lst_before_last(t_list *lst);

char		**ft_split(char const *s, char c);
char		**check_single_arg(char *av);

int			abs_value(int nb);
int			get_lowest_index_position(t_list **lst);
int			is_correct_input(char **av);
int			is_digit(char c);
int			is_sign(char c);
int			is_sorted(t_list *lst);
int			is_space(char c);
int			ft_lst_size(t_list *lst);
int			nbstr_cmp(const char *s1, const char *s2);

long int	ft_atoi(const char *nptr);

size_t		ft_count_words2(char **words);

int			arg_is_num(char *av);
int			find_highest_index(t_list *lst);
int			get_target(t_list **a, int b_index,
				int target_index, int target_pos);
int			is_duplicate(char **av);
int			is_zero(char *av);

size_t		count_words(char const *s, char c);
size_t		ft_count_words(char **words);

void		do_rotate_a(t_list **a, int *cost);
void		do_rotate_b(t_list **b, int *cost);
void		do_rotate_both(t_list **a, t_list **b, int *cost_a, int *cost_b);
void		do_rev_rotate_both(t_list **a, t_list **b,
				int *cost_a, int *cost_b);
void		fill_tab(char *new, char const *s, char c);
void		ft_free_split(char **tab);
void		get_position(t_list **lst);
void		push_all_save_three(t_list **a, t_list **b);
void		push_param(t_list **src, t_list **dest);

void		push_swap(t_list **a, t_list **b, int lst_size);

void		rotate_param(t_list **lst);
void		rev_rotate_param(t_list **lst);
void		set_mem(char **tab, char const *s, char c);
void		shift_lst(t_list **a);
void		swap_param(t_list *lst);

void		assign_index(t_list *a, int lst_size);
void		do_cheapest_move(t_list **a, t_list **b);
void		do_move(t_list **a, t_list **b, int cost_a, int cost_b);
void		do_pa(t_list **a, t_list **b);
void		do_pb(t_list **a, t_list **b);
void		do_ra(t_list **a);
void		do_rb(t_list **b);
void		do_rr(t_list **a, t_list **b);
void		do_rra(t_list **a);
void		do_rrb(t_list **b);
void		do_rrr(t_list **a, t_list **b);
void		do_sa(t_list **a);
void		do_sb(t_list **b);
void		do_ss(t_list **a, t_list **b);
void		error(t_list **lst_a, t_list **lst_b);
void		free_list(t_list **lst);
void		ft_putstr(char *str);
void		ft_lstaddback(t_list **lst, t_list *new);
void		get_cost(t_list **a, t_list **b);
void		get_target_position(t_list **a, t_list **b);
void		sort(t_list **a, t_list **b);
void		three_sort(t_list **lst);

#endif
