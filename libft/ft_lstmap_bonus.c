/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abosc <abosc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 20:25:57 by abosc             #+#    #+#             */
/*   Updated: 2024/10/25 20:35:37 by abosc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*first_node;
	t_list	*node;

	first_node = NULL;
	while (lst)
	{
		node = ft_lstnew(NULL);
		if (!node)
		{
			ft_lstclear(&first_node, del);
			break ;
		}
		node->content = f(lst->content);
		ft_lstadd_back(&first_node, node);
		lst = lst->next;
	}
	return (first_node);
}
