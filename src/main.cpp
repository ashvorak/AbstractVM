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

int main(int arc, char **argv)
{
	VM vm;

	arc = 1;
	*argv = NULL;
	OperandFactory Factory;

	IOperand const *a = Factory.createOperand(Int8, "42");
	IOperand const *b = Factory.createOperand(Float, "42.42");
	IOperand const *c = Factory.createOperand(Double, "142.142");
	IOperand const *d = Factory.createOperand(Double, "41.142");
	IOperand const *x = Factory.createOperand(Int8, "42");
	IOperand const *y = Factory.createOperand(Int8, "42");

	vm.push(a);
	vm.push(b);
	vm.push(c);
	vm.push(d);
	vm.push(x);
	vm.push(y);

	vm.dump();

	vm.launch();

	vm.dump();

	return (0);
}