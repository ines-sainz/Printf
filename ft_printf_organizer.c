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

int	ft_char(char c, int ret)
{
	ft_putchar_fd(c, 1);
	return (ret + 1);
}

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
