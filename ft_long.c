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

/**
 * @brief Counts the number of digits in a long integer.
 * 
 * Calculates how many characters are needed to represent the long integer `n`
 * in base 10. Always returns at least 2 to allow space for the final null
 * terminator when used for string conversion.
 * 
 * @param n The long integer to evaluate.
 * 
 * @return Number of characters required to represent `n`, plus one extra.
 */
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

/**
 * @brief Converts a long integer to a newly allocated decimal string.
 * 
 * Allocates and returns a string representation of the long integer `n`.
 * The result includes only digits (no sign) and is null-terminated.
 * 
 * @param n The long integer to convert.
 * 
 * @return Pointer to the newly allocated string, or NULL on failure.
 */
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
