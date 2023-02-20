/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mincshin <mincshin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 13:51:11 by mincshin          #+#    #+#             */
/*   Updated: 2022/11/09 20:42:30 by mincshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>

int		ft_putchar(char c);
int		ft_putstr(char *str);
int		printelse(char c);
int		printvar(char c, va_list *args);
int		ft_printf(const char *str, ...);

int		ft_itoa(int n);
int		ft_uitoa(int n);

int		charcount(unsigned long long nb);
void	putnbr_base(unsigned long long nb, char *base);
int		ft_puthex(int i, char x);
int		ft_putpointer(unsigned long long l);

#endif