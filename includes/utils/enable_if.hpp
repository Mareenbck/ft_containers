/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enable_if.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbascuna <mbascuna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 13:53:24 by mbascuna          #+#    #+#             */
/*   Updated: 2022/10/15 16:27:09 by mbascuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENABLE_IF_HPP
# define ENABLE_IF_HPP

namespace ft {

	template<bool Condition, typename T = void>
	struct enable_if
	{
	};

	template<typename T>
	struct enable_if<true, T>
	{
		typedef T type;
	};
}



#endif
