/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_divide_16.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isainz-r <isainz-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 12:14:16 by isainz-r          #+#    #+#             */
/*   Updated: 2024/02/28 17:55:40 by isainz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_negative_16(size_t nb, char *number)
{
	if (nb < 0)
	{
		number[0] = '-';
		return (0);
	}
	return (1);
}

char	ft_up_10(int aux)
{
	int	i;
	int	ascii;

	i = 10;
	ascii = 97;
	while (i != aux)
	{
		i++;
		ascii++;
	}
	return ((char)ascii);
}

char	*ft_fill_16(size_t nb, int n_number)
{
	char	*number;
	int		aux;

	number = ft_calloc(n_number + 1, 1);
	if (!number)
		return (0);
	if (ft_negative_16(nb, number) == 0)
		nb = -nb;
	while (nb > 15)
	{
		aux = nb % 16;
		if (aux < 10)
			number[n_number - 1] = (aux + '0');
		else
			number[n_number - 1] = ft_up_10(aux);
		nb = nb / 16;
		n_number--;
	}
	if (nb < 10)
		number[n_number - 1] = (nb + '0');
	else
		number[n_number - 1] = ft_up_10(nb);
	return (number);
}

int	ft_count_numbers_16(size_t nb)
{
	int	contador;

	contador = 0;
	if (nb < 0)
	{
		nb = -nb;
		contador++;
	}
	while (nb > 15)
	{
		nb = nb / 16;
		contador++;
	}
	contador++;
	return (contador);
}

char	*ft_divide_16(size_t nb)
{
	char	*n_str;
	int		n_number;

	n_number = ft_count_numbers_16(nb);
	n_str = ft_fill_16(nb, n_number);
	if (!n_str)
		return (0);
	return (n_str);
}
