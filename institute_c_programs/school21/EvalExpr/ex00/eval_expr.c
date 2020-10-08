/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_expr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjennine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 17:35:22 by mjennine          #+#    #+#             */
/*   Updated: 2020/10/04 22:15:26 by mjennine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my.h"

char	*split_whitespaces(char *str)
{
	char	*c;
	int		i;
	int		j;

	i = 0;
	j = 0;
	c = (char *)malloc(100 * sizeof(char));
	while (str[i] != '\0')
	{
		if (str[i] == ' ')
			i++;
		else
		{
			c[j] = str[i];
			j++;
			i++;
		}
	}
	c[j] = '\0';
	return (c);
}

void	hren(t_int_stack **num_stack, t_operand_stack **op_stack)
{
	int		a;
	int		b;
	char	op;

	b = int_pop(num_stack);
	a = int_pop(num_stack);
	op = op_pop(op_stack);
	int_push_front(num_stack, operations(a, b, op));
}

void	if_operand(char *str, int *i,
		t_operand_stack **op_stack, t_int_stack **num_stack)
{
	if ((str[*i] == '-' || str[*i] == '+') && (*i == 0 ||
				str[*i - 1] == '('))
		int_push_front(num_stack, 0);
	eval_stack(num_stack, op_stack, str[*i], i);
}

void	what_under_while(t_operand_stack **op_stack,
		t_int_stack **num_stack, char *str, int *i)
{
	if (is_digit(str[*i]))
	{
		into_int_stack(str, i, num_stack);
		*i = *i + 1;
	}
	if (is_operand(str[*i]))
		if_operand(str, i, op_stack, num_stack);
	if (str[*i] == ')')
	{
		while ((*op_stack)->data != '(')
		{
			hren(num_stack, op_stack);
		}
		op_pop(op_stack);
		*i = *i + 1;
	}
}

int		eval_expr(char *str)
{
	t_operand_stack	*op_stack;
	t_int_stack		*num_stack;
	int				i;

	op_stack = (t_operand_stack *)malloc(sizeof(t_operand_stack));
	num_stack = (t_int_stack *)malloc(sizeof(t_int_stack ));
	op_stack = NULL;
	num_stack = NULL;
	i = 0;
	str = split_whitespaces(str);
	while (str[i] != '\0')
	{
		what_under_while(&op_stack, &num_stack, str, &i);
	}
	while (op_stack != NULL)
	{
		hren(&num_stack, &op_stack);
	}
	return (num_stack->data);
}
