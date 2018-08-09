/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshvorak <oshvorak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/31 17:52:29 by oshvorak          #+#    #+#             */
/*   Updated: 2018/08/08 19:05:55 by oshvorak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/VM.hpp"

int main(int arc, char **argv)
{
	VM vm;

	OperandFactory Factory;

	IOperand const *a = Factory.createOperand(Int8, "42");
	IOperand const *b = Factory.createOperand(Float, "42.42");
	IOperand const *c = Factory.createOperand(Double, "142.142");
	IOperand const *d = Factory.createOperand(Double, "41.142");
	IOperand const *x = Factory.createOperand(Int8, "42");
	IOperand const *y = Factory.createOperand(Int8, "42");

	vm.push(b);
	vm.push(a);
	vm.push(c);
	vm.push(d);
	vm.push(x);
	vm.push(y);

	vm.dump();

	std::cout << "-------" << std::endl;

	vm.print();

	vm.assert("42", Int8);

	vm.mul();

	vm.dump();

	return (0);
}