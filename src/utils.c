/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmafueni <jmafueni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 19:33:05 by jmafueni          #+#    #+#             */
/*   Updated: 2024/07/01 14:46:06 by jmafueni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_list(t_list **lst)
{
	t_list	*tmp;

	if (!lst || !*lst)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		free(*lst);
		*lst = tmp;
	}
	*lst = NULL;
	free(*lst);
}

void	error(t_list **lst_a, t_list **lst_b)
{
	if (lst_a == NULL || *lst_a != NULL)
		free_list(lst_a);
	if (lst_b == NULL || *lst_b != NULL)
		free_list(lst_b);
	write(2, "Error\n", 6);
	exit (1);
}

long int	ft_atoi(const char *nptr)
{
	int			i;
	int			sign;
	long int	value;

	i = 0;
	value = 0;
	sign = 1;
	while (nptr[i] && ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	while (is_digit(nptr[i]))
	{
		value = value * 10 + nptr[i] - '0';
		i++;
	}
	return (value * sign);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

int	abs_value(int nb)
{
	if (nb < 0)
		return (nb * -1);
	return (nb);
}
