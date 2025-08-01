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

/**
 * @brief Handles negative numbers for hexadecimal conversion.
 * 
 * If the input `nb` is negative, writes a '-' sign at the start of `number`
 * and returns 0. Otherwise, returns 1. This function assumes `number` has
 * enough allocated space.
 * 
 * @param nb The number to check.
 * @param number The string buffer to store the '-' sign if needed.
 * 
 * @return 0 if `nb` is negative, 1 otherwise.
 */
int	ft_negative_16(size_t nb, char *number)
{
	if (nb < 0)
	{
		number[0] = '-';
		return (0);
	}
	return (1);
}

/**
 * @brief Converts a number >= 10 to its lowercase hexadecimal character.
 * 
 * Converts a number between 10 and 15 to its corresponding lowercase
 * hexadecimal character ('a' to 'f').
 * 
 * @param aux Integer value between 10 and 15.
 * 
 * @return Corresponding lowercase hexadecimal character.
 */
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

/**
 * @brief Converts a number to a hexadecimal string.
 * 
 * Allocates and fills a string with the hexadecimal representation of `nb`,
 * using lowercase letters for values above 9. Negative numbers are handled
 * with a '-' prefix.
 * 
 * @param nb The number to convert.
 * @param n_number The number of digits (including sign if needed).
 * 
 * @return Pointer to the newly allocated hex string, or NULL on failure.
 */
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

/**
 * @brief Counts the number of digits needed for hexadecimal representation.
 * 
 * Computes how many characters are required to represent `nb` in hexadecimal,
 * including space for a minus sign if the number is negative.
 * 
 * @param nb The number to evaluate.
 * 
 * @return Number of characters required for the hex representation.
 */
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

/**
 * @brief Converts a number to a hexadecimal string.
 * 
 * Calculates the number of digits needed and returns a dynamically allocated
 * string containing the hexadecimal representation of `nb`.
 * 
 * @param nb The number to convert.
 * 
 * @return Pointer to a newly allocated hex string, or NULL on failure.
 */
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
