/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmafueni <jmafueni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 15:28:33 by jmafueni          #+#    #+#             */
/*   Updated: 2024/06/21 15:13:03 by jmafueni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_param(t_list **lst)
{
	t_list	*tmp;
	t_list	*last;

	if (!lst || !*lst || (*lst)->next == NULL)
		return ;
	tmp = *lst;
	*lst = (*lst)->next;
	last = ft_lstlast(*lst);
	tmp->next = NULL;
	last->next = tmp;
}

void	do_ra(t_list **a)
{
	if (!a)
		return ;
	rotate_param(a);
	ft_putstr("ra\n");
}

void	do_rb(t_list **b)
{
	if (!b)
		return ;
	rotate_param(b);
	ft_putstr("rb\n");
}

void	do_rr(t_list **a, t_list **b)
{
	if (!a || (*a)->next == NULL || !b || (*b)->next == NULL)
		return ;
	rotate_param(a);
	rotate_param(b);
	ft_putstr("rr\n");
}
