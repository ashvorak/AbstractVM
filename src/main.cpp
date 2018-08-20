/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshvorak <oshvorak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/31 17:52:29 by oshvorak          #+#    #+#             */
/*   Updated: 2018/08/13 13:58:35 by oshvorak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/VM.hpp"

static void ft_usage( void )
{
	std::cout << "Invalid number of arguments" << std::endl;
	exit(1);
}

int main(int arc, char **argv)
{
	VM vm;

	if (arc <= 2)
	{

	}
	else
		ft_usage();
	return (0);
}