/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshvorak <oshvorak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/01 16:03:30 by oshvorak          #+#    #+#             */
/*   Updated: 2018/08/09 10:37:30 by oshvorak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Parser.hpp"
#include "../inc/VM.hpp"

IOperand const * Parser::value = NULL;

eInstruction Parser::parse(std::string instruction)
{
	OperandFactory F;

	if (instruction == "add")
		return (Add);
	else if (instruction == "mul")
		return (Mul);
	else if (instruction == "pop")
		return (Pop);
	else if (instruction == "dump")
		return (Dump);
	else if (instruction == "push")
	{
		Parser::value = F.createOperand(Int8, "42");
		return (Push);
	}
	else
		throw "Invalid instruction";
}