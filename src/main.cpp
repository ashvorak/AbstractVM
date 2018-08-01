/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshvorak <oshvorak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/31 17:52:29 by oshvorak          #+#    #+#             */
/*   Updated: 2018/08/01 18:24:35 by oshvorak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/VM.hpp"

int main(int arc, char **argv)
{
	VM vm;
	Operand<int> a(11);

	std::cout << a.getValue() << std::endl;
	vm.push(5);
	vm.push(6);
	std::cout << vm.print() << std::endl;
	vm.pop();
	std::cout << vm.print() << std::endl;
	vm.pop();
	vm.pop();
	std::cout << vm.print() << std::endl;
	return (0);
}