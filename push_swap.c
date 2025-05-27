/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matoledo <matoledo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 19:18:51 by matoledo          #+#    #+#             */
/*   Updated: 2025/05/27 14:10:17 by matoledo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	ft_lstsize(t_list *lst)
{
	t_list	*aux;
	int		size;

	if (!lst)
		return (0);
	aux = lst;
	size = 1;
	while (aux->next)
	{
		size++;
		aux = aux->next;
	}
	return (size);
}


void	push(t_list *s1, t_list *s2)
{
	t_list	*aux;
	
	if (ft_lstsize(s2) <= 0)
		return ;
	aux = s2;
	s2 = s2->next;
	aux->next = s1;
	s1 = aux; 
}

void	*ft_memset(void *dest, int c, size_t n)
{
	char	*pt_dest;

	pt_dest = dest;
	while (n--)
	{
		*pt_dest++ = (char)c;
	}
	return (dest);
}

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, '\0', n);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	total;
	char	*pt_call;

	total = nmemb * size;
	pt_call = malloc(total);
	if (!pt_call)
		return (NULL);
	ft_bzero(pt_call, total);
	return (pt_call);
}


t_list	*ft_lstnew(void *content)
{
	t_list	*node;

	node = (t_list *) ft_calloc(sizeof(t_list), 1);
	if (!node)
		return (0);
	node->content = content;
	node->next = NULL;
	return (node);
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	t_list	*old_node;

	old_node = *lst;
	*lst = new;
	new->next = old_node;
}

int	main(int argc, char **argv)
{
	t_list	**s;
	t_list	**s2;
	t_list	*p;
	int		j = 10;
	int		t = 10;

	s = ft_calloc(sizeof(t_list *), 1);
	s2 = ft_calloc(sizeof(t_list *), 1);

	while (j--)
	{
		p = ft_lstnew(j);
		ft_lstadd_front(s, p);
	}
	while (t--)
	{
		p = ft_lstnew(t);
		ft_lstadd_front(s2, p);
	}

	push((*s), (*s2));
	
	while ((*s2)->next)
	{
		printf("%d\n", (*s2)->content);
		(*s2) = (*s2)->next;
	}
}