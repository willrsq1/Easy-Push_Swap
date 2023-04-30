#include "../ps_wrs.h"

int	ft_ps_lst_size(t_ps_wrs **stack)
{
	int	i;
	t_ps_wrs	*lst;

	i = 0;
	lst = *stack;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

int	ft_ps_lst_is_sorted(t_ps_wrs *lst)
{
	int		temp;
	t_ps_wrs	*being_checked;

	while (lst)
	{
		being_checked = lst;
		temp = lst->number;
		while (lst->next)
		{
			lst = lst->next;
			if (lst->number < temp)
				return (0);
		}
		lst = being_checked->next;
	}
	return (1);
}

t_ps_wrs *ft_ps_lst_last(t_ps_wrs *lst)
{
	while (lst->next)
		lst = lst->next;
	return (lst);
}