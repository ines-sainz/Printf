/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_organizer.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isainz-r <isainz-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 18:06:11 by isainz-r          #+#    #+#             */
/*   Updated: 2024/02/29 09:30:55 by isainz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * @brief Prints a single character to stdout.
 * 
 * Writes the character `c` to file descriptor 1 and increments the count
 * of printed characters.
 * 
 * @param c Character to print.
 * @param ret Current count of printed characters.
 * 
 * @return Updated count of printed characters.
 */
int	ft_char(char c, int ret)
{
	ft_putchar_fd(c, 1);
	return (ret + 1);
}

/**
 * @brief Prints a string to stdout.
 * 
 * Writes the string `str` to file descriptor 1 character by character.
 * If `str` is NULL, prints "(null)" instead. Updates and returns the
 * total number of printed characters.
 * 
 * @param str String to print.
 * @param ret Current count of printed characters.
 * 
 * @return Updated count of printed characters.
 */
int	ft_string(char *str, int ret)
{
	int	i;

	i = 0;
	if (!str)
	{
		write(1, "(null)", 6);
		return (ret + 6);
	}
	while (str[i])
	{
		ft_putchar_fd(str[i], 1);
		i++;
		ret++;
	}
	return (ret);
}

/**
 * @brief Prints a pointer address in hexadecimal format.
 * 
 * Prints the prefix "0x" followed by the hexadecimal representation of
 * `pointer`. Uses lowercase letters for hex digits. Returns updated count.
 * 
 * @param pointer Pointer value to print.
 * @param ret Current count of printed characters.
 * 
 * @return Updated count of printed characters.
 */
int	ft_pointer(size_t pointer, int ret)
{
	char	*direction;
	int		i;

	i = 0;
	ft_putchar_fd('0', 1);
	ft_putchar_fd('x', 1);
	direction = ft_divide_16(pointer);
	while (direction[i])
	{
		ft_putchar_fd(direction[i], 1);
		i++;
		ret++;
	}
	free(direction);
	return (ret + 2);
}

/**
 * @brief Prints a signed decimal integer.
 * 
 * Converts `number` to a string and prints it character by character to
 * stdout. Updates and returns the total printed character count.
 * 
 * @param number Integer to print.
 * @param ret Current count of printed characters.
 * 
 * @return Updated count of printed characters.
 */
int	ft_decimal_number(int number, int ret)
{
	char	*num;
	int		i;

	i = 0;
	num = ft_itoa(number);
	while (num[i])
	{
		ft_putchar_fd(num[i], 1);
		i++;
		ret++;
	}
	free(num);
	return (ret);
}

/**
 * @brief Prints a signed decimal integer (alias).
 * 
 * Identical behavior to ft_decimal_number; prints `number` and updates
 * printed character count.
 * 
 * @param number Integer to print.
 * @param ret Current count of printed characters.
 * 
 * @return Updated count of printed characters.
 */
int	ft_enter_number(int number, int ret)
{
	char	*num;
	int		i;

	i = 0;
	num = ft_itoa(number);
	while (num[i])
	{
		ft_putchar_fd(num[i], 1);
		i++;
		ret++;
	}
	free(num);
	return (ret);
}
