#ifndef PS_WRS_H
# define PS_WRS_H
# include <stdlib.h> /* for malloc */
# include <unistd.h> /* for write */
# include <stdio.h>

typedef struct s_ps_wrs
{
	int					number;
	int					rank;
	struct s_ps_wrs	*next;
	struct s_ps_wrs	*previous;
	
}	t_ps_wrs;

/*		Main.c			*/

int			main(int argc, char **argv);
t_ps_wrs	*ft_ps_stack_creation(int argc, char **argv);
void		ft_ps_free_and_exit(t_ps_wrs **stack_a, t_ps_wrs **stack_b);
int			ft_ps_atoi(t_ps_wrs **stack_a, char *str);
void		ft_ps_arguments_check(t_ps_wrs **stack_a);

/*		Algorithm.c		*/

void    	ft_willrsq_algorithm(t_ps_wrs **stack_a, t_ps_wrs **stack_b);
void    	ft_willrsq_algorithm_part_2(t_ps_wrs **stack_a, t_ps_wrs **stack_b);

/*		Lst_utils.c		*/

int			ft_ps_lst_size(t_ps_wrs **stack);
int			ft_ps_lst_is_sorted(t_ps_wrs *lst);
t_ps_wrs *ft_ps_lst_last(t_ps_wrs *lst);

/*		Push_ans_swap_functs.c	*/

void		ft_push_from_a_to_b(t_ps_wrs **stack_a, t_ps_wrs **stack_b);
void		ft_push_from_b_to_a(t_ps_wrs **stack_b, t_ps_wrs **stack_a);
void		ft_swap_a(t_ps_wrs **stack_a);

/*		Rotate_functs.c	*/

void		ft_rotate_a(t_ps_wrs **stack_a);
void		ft_rotate_b(t_ps_wrs **stack_b);
void		ft_reverse_rotate_a(t_ps_wrs **stack_a);
void		ft_reverse_rotate_b(t_ps_wrs **stack_b);

/*		Utils_algorithm.c	*/

void		ft_ps_ranking(t_ps_wrs **stack_a);
int			ft_find_direction_max(t_ps_wrs **stack_b);
int			ft_find_new_max(t_ps_wrs *lst);


/* Gotta handle free + exit / add the small stacks fct */
#endif