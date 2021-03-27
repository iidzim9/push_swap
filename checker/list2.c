/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iidzim <iidzim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 18:49:05 by iidzim            #+#    #+#             */
/*   Updated: 2021/03/27 18:49:22 by iidzim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int list_size(t_list *l)
{
    int i;

    i = 0;
    while(l != NULL)
    {
        l = l->next++;
        i++;
    }
    return (i);
}

void ft_freelst(t_list *inst)
{
	t_list *temp;

	while(inst != NULL)
	{
		temp = inst;
		inst = inst->next;
		free(temp);
	}
	print_err();
}

void fill_list(int n, int *dup, t_all *x)
{
	int index;

	index = n - 1;
	while(index >= 0)
	{
		if (!x->a)
			x->a = ft_lstnew(dup[index]);
		else
			ft_lstadd_front(&x->a, ft_lstnew(dup[index]));
		index--;
	}
}

void print_list(t_list *l)
{
	t_list *temp;

	temp = l;
	while(temp)
	{
		printf("%d - ", temp->value);
		temp = temp->next;
	}
	printf("\n");
}
