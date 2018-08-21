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

eInstruction Parser::parse(std::string line)
{
	OperandFactory F;

	if (line == "add")
		return (Add);
	else if (line == "mul")
		return (Mul);
	else if (line == "pop")
		return (Pop);
	else if (line == "dump")
		return (Dump);
	else if (line == "push")
	{
		Parser::value = F.createOperand(Int8, "65");
		return (Push);
	}
	else
		throw "Invalid line";
}