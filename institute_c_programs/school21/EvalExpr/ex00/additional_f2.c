/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional_f2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjennine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 18:21:07 by mjennine          #+#    #+#             */
/*   Updated: 2020/10/04 22:12:35 by mjennine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my.h"

t_operand_stack	*operand_create_elem(char data)
{
	t_operand_stack	*temp;

	temp = malloc(sizeof(t_operand_stack));
	temp->data = data;
	temp->next = NULL;
	return (temp);
}

void			operand_push_front(t_operand_stack **begin_list, char data)
{
	t_operand_stack *new_node;

	new_node = operand_create_elem(data);
	new_node->next = *begin_list;
	*begin_list = new_node;
}

t_int_stack		*int_create_elem(int data)
{
	t_int_stack	*temp;

	temp = malloc(sizeof(t_int_stack));
	temp->data = data;
	temp->next = NULL;
	return (temp);
}

int				ft_atoi(char *str)
{
	int	i;
	int	nbr;
	int	negative;

	nbr = 0;
	negative = 0;
	i = 0;
	while ((str[i] == '\n') || (str[i] == '\t') || (str[i] == '\v') ||
			(str[i] == ' ') || (str[i] == '\f') || (str[i] == '\r'))
		i++;
	if (str[i] == '-')
		negative = 1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] && (str[i] >= '0') && (str[i] <= '9'))
	{
		nbr *= 10;
		nbr += (int)str[i] - '0';
		i++;
	}
	if (negative == 1)
		return (-nbr);
	else
		return (nbr);
}

void			ft_putchar(char c)
{
	write(1, &c, 1);
}
