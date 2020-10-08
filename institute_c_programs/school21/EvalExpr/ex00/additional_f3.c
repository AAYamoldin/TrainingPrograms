/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional_f3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjennine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 18:22:27 by mjennine          #+#    #+#             */
/*   Updated: 2020/10/04 22:13:15 by mjennine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my.h"

int		priority(char c)
{
	if (c == '-' || c == '+')
		return (1);
	if (c == '*' || c == '/' || c == '%')
		return (2);
	if (c == '(')
		return (0);
	return (0);
}

int		operations(int a, int b, char c)
{
	if (c == '-')
		return (a - b);
	if (c == '+')
		return (a + b);
	if (c == '*')
		return (a * b);
	if (c == '/')
		return (a / b);
	if (c == '%')
		return (a % b);
	return (0);
}

int		is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int		is_operand(char c)
{
	if (c == '-' || c == '+' || c == '*' ||
			c == '/' || c == '%' || c == '(')
		return (1);
	return (0);
}

char	op_pop(t_operand_stack **head)
{
	t_operand_stack	*prev;
	char			val;

	prev = NULL;
	prev = (*head);
	val = prev->data;
	(*head) = (*head)->next;
	free(prev);
	return (val);
}
