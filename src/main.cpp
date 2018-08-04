/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshvorak <oshvorak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/31 17:52:29 by oshvorak          #+#    #+#             */
/*   Updated: 2018/08/04 16:30:19 by oshvorak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/VM.hpp"

int main(int arc, char **argv)
{
	VM vm;

	Operand<double> a(6.2);
	a.setType(_double);

	Operand<float> b(11.7);
	b.setType(_float);

	Operand<double> c(15.1);
	c.setType(_double);

	Operand<int> d(1);
	d.setType(_int);
	
	Operand<int> e(2);
	e.setType(_int);

	vm.pop();
	vm.print();
	vm.push(&b);
	vm.push(&a);
	vm.push(&c);
	vm.push(&e);
	vm.print();

	return (0);
}