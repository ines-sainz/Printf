/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isainz-r <isainz-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 16:13:28 by isainz-r          #+#    #+#             */
/*   Updated: 2024/10/18 12:38:16 by isainz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <limits.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include <stdint.h>
# include <stddef.h>

int		ft_printf(char const *str, ...);
void	ft_putchar_fd(char c, int fd);
int		ft_negative(int n);
int		ft_count_numbers(int n);
void	*ft_calloc(size_t count, size_t size);
char	*ft_itoa(int n);
void	ft_percent(int i);
int		ft_char(char c, int ret);
int		ft_string(char *str, int ret);
int		ft_pointer(size_t pointer, int ret);
int		ft_decimal_number(int number, int ret);
int		ft_enter_number(int number, int ret);
int		ft_decimal_number_no_sign(int number, int ret);
int		ft_hexadecimal_number_lower(size_t number, int ret);
int		ft_hexadecimal_number_upper(size_t number, int ret);
int		ft_str_organizer(char *str, va_list args, int ret);
int		ft_negative_16(size_t nb, char *number);
char	ft_up_10(int aux);
char	*ft_fill_16(size_t nb, int n_number);
int		ft_count_numbers_16(size_t nb);
char	*ft_divide_16(size_t nb);
int		ft_count_numbers_long(long n);
char	*ft_long(long n);

#endif
