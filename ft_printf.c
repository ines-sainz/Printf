/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isainz-r <isainz-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 09:41:36 by isainz-r          #+#    #+#             */
/*   Updated: 2024/02/28 17:53:31 by isainz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_decimal_number_no_sign(int number, int ret)
{
	char	*num;
	int		i;
	long	converted;

	i = 0;
	if (number < 0)
	{
		converted = number + 4294967296;
		num = ft_long(converted);
	}
	else
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

int	ft_hexadecimal_number_lower(size_t number, int ret)
{
	char	*hex;
	int		i;

	i = 0;
	hex = ft_divide_16(number);
	while (hex[i])
	{
		ft_putchar_fd(hex[i], 1);
		i++;
		ret++;
	}
	free(hex);
	return (ret);
}

int	ft_hexadecimal_number_upper(size_t number, int ret)
{
	char	*hex;
	int		i;

	i = 0;
	hex = ft_divide_16(number);
	while (hex[i])
	{
		if (hex[i] >= 'a' && hex[i] <= 'z')
			hex[i] -= 32;
		ft_putchar_fd(hex[i], 1);
		i++;
		ret++;
	}
	free(hex);
	return (ret);
}

int	ft_str_organizer(char *str, va_list args, int ret)
{
	if (*str == '%')
	{
		ft_putchar_fd('%', 1);
		return (ret + 1);
	}
	else if (*str == 'c')
		return (ft_char(va_arg(args, int), ret));
	else if (*str == 's')
		return (ft_string(va_arg(args, char *), ret));
	else if (*str == 'p')
		return (ft_pointer(va_arg(args, size_t), ret));
	else if (*str == 'd')
		return (ft_decimal_number(va_arg(args, int), ret));
	else if (*str == 'i')
		return (ft_enter_number(va_arg(args, int), ret));
	else if (*str == 'u')
		return (ft_decimal_number_no_sign(va_arg(args, int), ret));
	else if (*str == 'x')
		return (ft_hexadecimal_number_lower(va_arg(args, unsigned int), ret));
	else if (*str == 'X')
		return (ft_hexadecimal_number_upper(va_arg(args, unsigned int), ret));
	return (0);
}

int	ft_printf(char const *str, ...)
{
	va_list	args;
	int		ret;

	va_start(args, str);
	ret = 0;
	while (str && *str != '\0')
	{
		if (*str == '%')
		{
			str++;
			ret = ft_str_organizer((char *)str, args, ret);
		}
		else
		{
			ft_putchar_fd(*str, 1);
			ret++;
		}
		if (*str)
			str++;
	}
	va_end(args);
	return (ret);
}
/*
int main(void)
{
    ft_printf("c mios: %c\n", 'r'); //bien
    printf("c suyo: %c\n", 'r');

    ft_printf("s mios: %s\n", "hola"); //bien
    printf("s suyo: %s\n", "hola");

    ft_printf("l mios: %p\n", "last");
    printf("l suyo: %p\n", "last");

    ft_printf("d mios: %d\n", 560789); //bien
    printf("d suyo: %d\n", 560789);

    ft_printf("i mios: %i\n", 120345); //bien
    printf("i suyo: %i\n", 120345);

	ft_printf("u mios: %u\n", -10203);
    printf("u suyo: %u\n", -10203);

	ft_printf("x mios: %x\n", 12);
    printf("x suyo: %x\n", 12);

	ft_printf("X mios: %X\n", 12);
    printf("X suyo: %X\n", 12);

    ft_printf("_  mios: %%\n");
    printf("_ suyo: %%\n");

//  ft_printf("casa %c %i %s\n", 'r', 2, "casa");
//  printf("casa %c %i %s\n", 'r', 2, "casa");
//  ft_printf("hola\n");
//  printf("hola\n");
}
*/
