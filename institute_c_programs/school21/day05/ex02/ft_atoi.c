/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjennine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 13:04:40 by mjennine          #+#    #+#             */
/*   Updated: 2020/03/10 14:02:20 by mjennine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		is_otricatelnoe (int i, char *str);
int		how_many_digids (char *str);
int		probels(char *str);
int		double_min(int i, char *str);

int		ft_atoi(char *str)
{
	int result;
	int digit;
	int stepen;
	int umnoj;
	int i;

	result = 0;
	stepen = how_many_digids(str);
	digit = 0;
	if (double_min(probels(str), str))
		return (0);
	while (stepen--)
	{
		i = 0;
		umnoj = 1;
		while (i < stepen)
		{
			umnoj = umnoj * 10;
			i++;
		}
		result = result + (str[probels(str) + digit++] - '0') * umnoj;
	}
	if (is_otricatelnoe(probels(str), str))
		result = -result;
	return (result);
}

int		probels(char *str)
{
	int i;
	int in_number;
	int probels;

	in_number = 0;
	i = 0;
	probels = 0;
	while (2 + 2 == 4)
	{
		if ((str[i] >= '0' && str[i] <= '9'))
		{
			in_number = 1;
		}
		else if ((str[i] == ' ' || str[i] == '\t'
					|| str[i] == '\n' || str[i] == '-'
					|| str[i] == '\r' || str[i] == '\f'
					|| str[i] == '\v' || str[i] == '+')
				&& in_number == 0)
			probels++;
		else
			break ;
		i++;
	}
	return (probels);
}

int		double_min(int i, char *str)
{
	if ((str[i - 2] == '-' && str[i - 1] == '-')
			|| (str[i - 2] == '+' && str[i - 1] == '+')
			|| (str[i - 2] == '+' && str[i - 1] == '-')
			|| (str[i - 2] == '-' && str[i - 1] == '+'))
		return (1);
	return (0);
}

int		is_otricatelnoe(int i, char *str)
{
	if (str[i - 1] == '-' && ((str[i] >= '0' && str[i] <= '9')))
	{
		return (1);
	}
	return (0);
}

int		how_many_digids(char *str)
{
	int i;
	int in_number;
	int k;

	in_number = 0;
	i = 0;
	k = 0;
	while (2 + 2 == 4)
	{
		if ((str[i] >= '0' && str[i] <= '9'))
		{
			k++;
			i++;
			in_number = 1;
		}
		else if ((str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
				|| str[i] == '-' || str[i] == '\r'
				|| str[i] == '\f' || str[i] == '\v' || str[i] == '+')
				&& in_number == 0)
			i++;
		else
			break ;
	}
	return (k);
}
