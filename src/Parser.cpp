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

std::map<std::string, eInstruction > Parser::_pm = {{"add", Add},
													{"sub", Sub},
													{"mul", Mul},
													{"div", Div},
													{"dump", Dump}};

eInstruction  Parser::parse(std::string line)
{
	OperandFactory F;

	lexicalAnalysis(line);
	return _pm[line];
}

std::string		Parser::lexicalAnalysis(std::string instr)
{
	std::regex rx("^add$|^sub$|^mul$|^div$|^dump$");
	if (!regex_match(instr.begin(), instr.end(), rx))
		throw ValidException();
	return (instr);
}

Parser::ValidException::ValidException() {}
Parser::ValidException::~ValidException() throw() {}

const char* Parser::ValidException::what() const throw()
{
	return ("Invalid instruction");
}