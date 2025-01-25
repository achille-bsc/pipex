/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abosc <abosc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 20:25:33 by abosc             #+#    #+#             */
/*   Updated: 2024/11/03 08:25:19 by abosc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_numlen(long num)
{
	int	i;

	i = 0;
	if (num < 0)
		i += 1;
	if (!num)
		return (1);
	while (num != 0)
	{
		num /= 10;
		i++;
	}
	return (i);
}

int	ft_print_nbr(long num)
{
	ft_putnbr_fd(num, 1);
	return (ft_numlen(num));
}
