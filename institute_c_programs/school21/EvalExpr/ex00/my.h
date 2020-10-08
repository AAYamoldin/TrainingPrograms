/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjennine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 16:09:59 by mjennine          #+#    #+#             */
/*   Updated: 2020/10/04 22:09:32 by mjennine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MY_H
# define MY_H

# include <stdlib.h>
# include <unistd.h>

typedef struct				s_int_list
{
	int						data;
	struct s_int_list		*next;
}							t_int_stack;

typedef struct				s_operand_list
{
	char					data;
	struct s_operand_list	*next;
}							t_operand_stack;

int							priority(char c);
int							operations(int a, int b, char c);
int							is_digit(char c);
int							is_operand(char c);
t_operand_stack				*operand_create_elem(char data);
void						operand_push_front(t_operand_stack **begin_list,
		char data);
t_int_stack					*int_create_elem(int data);
int							ft_atoi(char *str);
void						ft_putchar(char c);
void						ft_putnbr(int nb);
int							int_pop(t_int_stack **head);
char						op_pop(t_operand_stack **head);
void						eval_stack(t_int_stack **num_stack,
		t_operand_stack **op_stack, char operand, int *i);
void						int_push_front(t_int_stack **begin_list, int data);
void						into_int_stack(char *str,
		int *pos, t_int_stack **num_stack);
char						*split_whitespaces(char *str);
void						hren(t_int_stack **num_stack,
		t_operand_stack **op_stack);
void						if_operand(char *str, int *i,
		t_operand_stack **op_stack, t_int_stack **num_stack);
void						what_under_while(t_operand_stack **op_stack,
		t_int_stack **num_stack, char *str, int *i);
char						op_pop(t_operand_stack **head);
int							eval_expr(char *str);

#endif
