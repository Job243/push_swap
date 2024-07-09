/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmafueni <jmafueni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 12:18:11 by jmafueni          #+#    #+#             */
/*   Updated: 2024/06/25 13:48:07 by jmafueni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* do_rev_rotate_both:
 *	Reverse rotates both list A and B until one of them is in position.
 *	The given cost is negative since both positions are in the bottom half
 *	of their respective lists. The cost is increased as the lists are
 *	rotated, when one reaches 0, the list has been rotated as far as possible
 *	and the top position is correct.
 */

void	do_rev_rotate_both(t_list **a, t_list **b, int *cost_a, int *cost_b)
{
	while (*cost_a < 0 && *cost_b < 0)
	{
		(*cost_a)++;
		(*cost_b)++;
		do_rrr(a, b);
	}
}

/* do_rotate_both:
 *	Rotates both list A and B until one of them is in position.
 *	The given cost is positive since both positions are in the top half
 *	of their respective lists. The cost is decreased as the lists are
 *	rotated, when one reaches 0, the list has been rotated as far as possible
 *	and the top position is correct.
 */

void	do_rotate_both(t_list **a, t_list **b, int *cost_a, int *cost_b)
{
	while (*cost_a > 0 && *cost_b > 0)
	{
		(*cost_a)--;
		(*cost_b)--;
		do_rr(a, b);
	}
}

/* do_rotate_a:
 *	Rotates list A until it is in position. If the cost is negative,
 *	the list will be reverse rotated, if it is positive, it will be
 *	rotated.
 */

void	do_rotate_a(t_list **a, int *cost)
{
	while (*cost)
	{
		if (*cost > 0)
		{
			do_ra(a);
			(*cost)--;
		}
		else if (*cost < 0)
		{
			do_rra(a);
			(*cost)++;
		}
	}
}

/* do_rotate_b:
 *	Rotates list B until it is in position. If the cost is negative,
 *	the list will be reverse rotated, if it is positive, it will be
 *	rotated.
 */

void	do_rotate_b(t_list **b, int *cost)
{
	while (*cost)
	{
		if (*cost > 0)
		{
			do_rb(b);
			(*cost)--;
		}
		else if (*cost < 0)
		{
			do_rrb(b);
			(*cost)++;
		}
	}
}

/* do_move:
 *	Chooses which move to make to get the B list element to the correct
 *	position in list A.
 *	If the costs of moving list A and B into position match (i.e. both negative
 *	or both positive), both will be	rotated or reverse rotated at the same time.
 *	They might also be rotated separately,
		before finally pushing the top B element
 *	to the top list A.
 */

void	do_move(t_list **a, t_list **b, int cost_a, int cost_b)
{
	if (cost_a < 0 && cost_b < 0)
		do_rev_rotate_both(a, b, &cost_a, &cost_b);
	else if (cost_a > 0 && cost_b > 0)
		do_rotate_both(a, b, &cost_a, &cost_b);
	do_rotate_a(a, &cost_a);
	do_rotate_b(b, &cost_b);
	do_pa(a, b);
}
