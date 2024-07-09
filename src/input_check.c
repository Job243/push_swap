/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmafueni <jmafueni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 20:10:08 by jmafueni          #+#    #+#             */
/*   Updated: 2024/07/09 13:48:33 by jmafueni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	arg_is_num(char *av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		if ((av[i] >= 9 && av[i] <= 13) || av[i] == 32)
			i++;
		if (is_sign(av[i]) && av[i + 1] != '\0')
			i++;
		if (!is_digit(av[i]))
			return (0);
		i++;
	}
	return (1);
}

int	is_duplicate(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		j = 1;
		while (av[j])
		{
			if (j != i && nbstr_cmp(av[i], av[j]) == 1)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	is_zero(char *av)
{
	int	i;

	i = 0;
	if (is_sign(av[i]))
		i++;
	while (av[i] && av[i] == '0')
		i++;
	if (av[i] != '\0')
		return (0);
	return (1);
}

int	is_correct_input(char **av)
{
	int	i;
	int	nb_zero;

	nb_zero = 0;
	i = 0;
	while (av[i])
	{
		if (!arg_is_num(av[i]))
			return (0);
		nb_zero += is_zero(av[i]);
		i++;
	}
	if (nb_zero > 1)
		return (0);
	if (is_duplicate(av))
		return (0);
	return (1);
}

/*int main(void) {
    char **av;
    int i = 0;

    av = ft_split("156165 45454 44 774 5b 44", ' ');

    if (av == NULL) {
        printf("Error: Failed to split the input string.\n");
        return 1;
    }

    printf("Split input into words:\n");
    while (av[i]) {
        printf("Word %d: %s\n", i, av[i]);
        i++;
    }
	if (is_correct_input(av))
        printf("Good!!!\n");
    else
        printf("Error\n");

    i = 0;
    while (av[i]) {
        free(av[i]);
        i++;
    }
    free(av);

    return 0;
}*/
