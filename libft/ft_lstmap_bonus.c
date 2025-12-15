/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ando-sou <ando-sou@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 19:50:59 by ando-sou          #+#    #+#             */
/*   Updated: 2025/10/24 19:53:38 by ando-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*nl;
	t_list	*nn;
	void	*nc;

	if (!lst || !f || !del)
		return (NULL);
	nl = NULL;
	while (lst)
	{
		nc = f(lst->content);
		nn = ft_lstnew(nc);
		if (!nn)
		{
			del(nc);
			ft_lstclear(&nl, del);
			return (NULL);
		}
		ft_lstadd_back(&nl, nn);
		lst = lst->next;
	}
	return (nl);
}
