/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isainz-r <isainz-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 14:43:15 by isainz-r          #+#    #+#             */
/*   Updated: 2024/10/18 12:39:15 by isainz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_count_numbers_long(long n)
{
	int	contador;

	contador = 0;
	if (n <= LONG_MAX && n > LONG_MIN)
	{
		while (n >= 10)
		{
			n = n / 10;
			contador++;
		}
		contador++;
	}
	return (contador + 1);
}

char	*ft_long(long n)
{
	char	*number;
	int		n_number;

	n_number = ft_count_numbers_long(n);
	number = ft_calloc(n_number, sizeof(char));
	if (!number)
		return (NULL);
	while (n >= 10)
	{
		number[n_number - 2] = ((n % 10) + '0');
		n = (n / 10);
		n_number--;
	}
	number[n_number - 2] = ((n % 10) + '0');
	return (number);
}
