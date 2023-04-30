
#include "../ps_wrs.h"

/* NEEDED FUNCTIONS
LST SIZE
LST START
FT rank ______________
FT PUSH B
FT ROTATE B
FT ROTATE A */

void    ft_willrsq_algorithm(t_ps_wrs **stack_a, t_ps_wrs **stack_b)
{
	int			size;
	int			will;
	int			tenth_of_size;
	t_ps_wrs	*a;
	t_ps_wrs	*b;

	a = *stack_a;
	size = ft_ps_lst_size(stack_a); // prend la nombre de nombres dans la stack
	ft_ps_ranking(stack_a); // trie les nombres de 1 à taille max;
	tenth_of_size = size * 0.1;
	will = tenth_of_size; // parametre de base
	while (a)
	{
		if (a->rank <= will) // si l'elem est un des plus petits elem de la liste
		{
			ft_push_from_a_to_b(stack_a, stack_b); // met l'elem compris entre 0 et will dans B.
			will++;
			b = *stack_b;
			if (b->rank < will - tenth_of_size)
				ft_rotate_b(stack_b);
		}
		else
			ft_rotate_a(stack_a);
		a = *stack_a;
	}
	// mtn, tout a est passé dans b
	ft_willrsq_algorithm_part_2(stack_a, stack_b);
}

void    ft_willrsq_algorithm_part_2(t_ps_wrs **stack_a, t_ps_wrs **stack_b)
{
	/* NEEDED FUNCTIONS
	FT FIND DIRECTION MAX ___________
	FT FIND NEW MAX ____________
	FT ROTATE B
	FT REVERSE ROTATE B
	FT PUSH A*/
	int	pos;
	int max;
	t_ps_wrs *b;

	b = *stack_b;
	while (b)
	{
		pos = ft_find_direction_max(stack_b);
		b = *stack_b;
		max = ft_find_new_max(b);
		while (b->rank < max)
		{
			if (b->rank == max -1)
				ft_push_from_b_to_a(stack_b, stack_a);
			else if (pos == 1)
				ft_rotate_b(stack_b);
			else if (pos == -1)
				ft_reverse_rotate_b(stack_b);
			b = *stack_b;
		}
		ft_push_from_b_to_a(stack_b, stack_a);
		b = *stack_a;
		if (b->next && b->rank > b->next->rank)
			ft_swap_a(stack_a);
		b = *stack_b;
	}
}