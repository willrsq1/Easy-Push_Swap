#include "../ps_wrs.h"


void		ft_push_from_a_to_b(t_ps_wrs **stack_a, t_ps_wrs **stack_b)
{
	t_ps_wrs	*pushed_list;
	t_ps_wrs	*stack_a_second_list;
	t_ps_wrs	*stack_b_first_list;

	pushed_list = *stack_a;
	if (pushed_list->next)
	{
		stack_a_second_list = pushed_list->next;
		*stack_a = stack_a_second_list;
		stack_a_second_list->previous = NULL;
	}
	else
		*stack_a = NULL;
	stack_b_first_list = *stack_b;
	if (stack_b_first_list)
		stack_b_first_list->previous = pushed_list;
	pushed_list->next = stack_b_first_list;
	*stack_b = pushed_list;
	write(1, "pb\n", 3);
}

void		ft_push_from_b_to_a(t_ps_wrs **stack_b, t_ps_wrs **stack_a)
{
	t_ps_wrs	*pushed_list;
	t_ps_wrs	*stack_b_second_list;
	t_ps_wrs	*stack_a_first_list;

	pushed_list = *stack_b;
	if (pushed_list->next)
	{
		stack_b_second_list = pushed_list->next;
		*stack_b = stack_b_second_list;
		stack_b_second_list->previous = NULL;
	}
	else
		*stack_b = NULL;
	stack_a_first_list = *stack_a;
	if (stack_a_first_list)
		stack_a_first_list->previous = pushed_list;
	pushed_list->next = stack_a_first_list;
	*stack_a = pushed_list;
	write(1, "pa\n", 3);
}

void		ft_swap_a(t_ps_wrs **stack_a)
{
	t_ps_wrs	*first;
	t_ps_wrs *second;

	first = *stack_a;
	if (first->next)
	{
		second = first->next;
		*stack_a = second;
		first->previous = second;
		if (second->next)
		{
			first->next = second->next;
			second->next->previous = first;
		}
		second->next = first;
		second->previous = NULL;
		write(1, "sa\n", 3);
	}
}