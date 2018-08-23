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
	std::cout << "USAGE :";
	std::cout << " ./avm" << std::endl;
	std::cout << "        ./avm <filename>" << std::endl;
	exit(1);
}

int main(int argc, char **argv)
{
	VM 			vm;
	OperandFactory f;

	if (argc <= 2)
	{
		if (argc == 1)
			vm.handleSI();
		else
			vm.handleFile(argv[1]);
	}
	else
		ft_usage();
	return (0);
}
