/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleonet <mleonet@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 01:24:36 by mleonet           #+#    #+#             */
/*   Updated: 2023/05/08 16:38:34 by mleonet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	int			sign;
	long int	result;
	long int	temp;

	result = 0;
	sign = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		temp = result;
		result = result * 10 + *str - '0';
		str++;
		if (temp > result && sign > 0)
			return (-1);
		else if (temp > result && sign < 0)
			return (0);
	}
	return (result * sign);
}
