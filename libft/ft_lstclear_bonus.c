/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abosc <abosc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 18:47:29 by abosc             #+#    #+#             */
/*   Updated: 2024/10/25 20:18:06 by abosc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*cpy_next;

	if (!lst)
		return ;
	while (*lst)
	{
		cpy_next = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = cpy_next;
	}
}

// int main()
// {
// 	t_list *truc = ft_lstnew("a");
// 	printf("%p\n", truc);
// 	ft_lstclear(&truc, NULL);
// 	printf("%p\n", truc);
// 	return (0);
// }
