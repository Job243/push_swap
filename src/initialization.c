/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmafueni <jmafueni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 14:10:35 by jmafueni          #+#    #+#             */
/*   Updated: 2024/07/01 14:45:03 by jmafueni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*filllst(int ac, char **av)
{
	t_list		*a;
	long int	n;
	int			i;

	a = NULL;
	n = 0;
	i = 1;
	while (i < ac)
	{
		n = ft_atoi(av[i]);
		if (n > INT_MAX || n < INT_MIN)
		{
			error(&a, NULL);
			return (NULL);
		}
		if (i == 1)
			a = ft_lstnew2((int)n);
		else
			ft_lstaddback(&a, ft_lstnew2((int)n));
		i++;
	}
	return (a);
}

void	assign_index(t_list *a, int lst_size)
{
	t_list	*ptr;
	t_list	*highest;
	int		value;

	while (--lst_size > 0)
	{
		ptr = a;
		value = INT_MIN;
		highest = NULL;
		while (ptr)
		{
			if (ptr->value == INT_MIN && ptr->index == 0)
				ptr->index = 1;
			if (ptr->value > value && ptr->index == 0)
			{
				value = ptr->value;
				highest = ptr;
				ptr = a;
			}
			else
				ptr = ptr->next;
		}
		if (highest != NULL)
			highest->index = lst_size;
	}
}
