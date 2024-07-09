/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmafueni <jmafueni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 15:41:42 by jmafueni          #+#    #+#             */
/*   Updated: 2024/06/18 17:13:57 by jmafueni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rev_rotate_param(t_list **lst)
{
	t_list	*tmp;
	t_list	*last;
	t_list	*before_last;

	if (!lst || (*lst)->next == NULL)
		return ;
	last = ft_lstlast(*lst);
	before_last = get_lst_before_last(*lst);
	tmp = *lst;
	*lst = last;
	(*lst)->next = tmp;
	before_last->next = NULL;
}

void	do_rra(t_list **a)
{
	if (!a || (*a)->next == NULL)
		return ;
	rev_rotate_param(a);
	ft_putstr("rra\n");
}

void	do_rrb(t_list **b)
{
	if (!b || (*b)->next == NULL)
		return ;
	rev_rotate_param(b);
	ft_putstr("rrb\n");
}

void	do_rrr(t_list **a, t_list **b)
{
	if (!a || (*a)->next == NULL || !b || (*b)->next == NULL)
		return ;
	rev_rotate_param(a);
	rev_rotate_param(b);
	ft_putstr("rrr\n");
}
