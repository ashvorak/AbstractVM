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

void Parser::setInstruction(std::string instruction)
{
	this->_instruction = instruction;
}

eInstruction & Parser::parse(std::string instruction)
{
	if (instruction == "add")
		return (Add);
	else if (instruction == "mul")
		return (Mul);
	else if (instruction == "pop")
		return (Pop);
	else
		throw "Error : Invalid instruction";
}