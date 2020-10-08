/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional_f.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjennine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 18:05:45 by mjennine          #+#    #+#             */
/*   Updated: 2020/10/04 22:11:21 by mjennine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my.h"

void	ft_putnbr(int nb)
{
	unsigned int number;

	if (nb == -2147483648)
	{
		nb = -214748364;
		ft_putnbr(nb);
		ft_putchar('8');
		return ;
	}
	if (nb < 0)
	{
		ft_putchar('-');
		number = -nb;
		ft_putnbr(number);
	}
	else
	{
		if (nb < 10)
			return (ft_putchar(nb + '0'));
		ft_putnbr(nb / 10);
		ft_putchar((nb % 10) + '0');
	}
}

int		int_pop(t_int_stack **head)
{
	t_int_stack	*prev;
	int			val;

	prev = NULL;
	prev = (*head);
	val = prev->data;
	(*head) = (*head)->next;
	free(prev);
	return (val);
}

void	eval_stack(t_int_stack **num_stack,
		t_operand_stack **op_stack, char operand, int *i)
{
	int		result;
	int		b;
	int		a;
	char	op;

	result = 0;
	a = 0;
	b = 0;
	if (*op_stack == NULL || operand == '(' ||
			priority(operand) > priority((*op_stack)->data))
	{
		operand_push_front(op_stack, operand);
		*i = *i + 1;
		return ;
	}
	else
	{
		b = int_pop(num_stack);
		a = int_pop(num_stack);
		op = op_pop(op_stack);
		int_push_front(num_stack, operations(a, b, op));
	}
}

void	int_push_front(t_int_stack **begin_list, int data)
{
	t_int_stack	*new_node;

	new_node = int_create_elem(data);
	new_node->next = *begin_list;
	*begin_list = new_node;
}

void	into_int_stack(char *str, int *pos, t_int_stack **num_stack)
{
	int		is_num;
	char	*number;
	int		i;

	is_num = 0;
	number = (char *)malloc(sizeof(char));
	i = 0;
	if (is_num == 0)
	{
		is_num = 1;
		number[i] = str[*pos];
	}
	while (str[*pos] != '\0')
	{
		if (!is_digit(str[*pos + 1]))
		{
			int_push_front(num_stack, ft_atoi(number));
			return ;
		}
		number[++i] = str[++(*pos)];
	}
}
