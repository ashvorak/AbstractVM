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

eOperandType Parser::_type = Int8;
std::string Parser::_value = "42";

std::map<std::string, eInstruction > Parser::_pm = {{"push", Push},
													{"pop", Pop},
													{"dump", Dump},
													{"assert", Assert},
													{"add", Add},
													{"sub", Sub},
													{"mul", Mul},
													{"div", Div},
													{"mod", Mod},
													{"print", Print},
													{"exit", Exit}};

eOperandType Parser::getType( void )
{
	return (_type);
}

std::string Parser::getValue( void )
{
	return (_value);
}

eInstruction  Parser::parse(std::string instr)
{
	std::regex 	rx1("^pop$|^dump$|^add$|^sub$|^mul$|^div$|^mod$|^print$|^exit$");
	std::regex 	rx2("(^[\\s]*?(push|assert)[\\s]+(int8|int16|int32)[\\(][-]?[0-9]+[\\)][\\s]*?$)");
	std::regex 	rx3("(^[\\s]*?(push|assert)[\\s]+(float|double)[\\(][-]?[0-9]+.[0-9]+[\\)][\\s]*?$)");
	std::smatch	match;
	std::string	op;

	if (regex_match(instr.begin(), instr.end(), rx1))
	{
		std::regex_search(instr, match, rx1);
		op = match[0];
	}
	else if (regex_match(instr.begin(), instr.end(), rx2))
	{
		std::regex rx("[-]?[0-9]+");

		std::regex_search(instr, match, rx);
		Parser::_type = Int16;
		Parser::_value = match[0];
	}
	else if (regex_match(instr.begin(), instr.end(), rx3))
	{
		std::regex rx("[-]?[0-9]+.[0-9]+");

		std::regex_search(instr, match, rx);
		Parser::_type = Float;
		Parser::_value = match[0];
	}
	else
		throw ValidException();
	return (_pm[instr]);
}

Parser::ValidException::ValidException() {}
Parser::ValidException::~ValidException() throw() {}

const char* Parser::ValidException::what() const throw()
{
	return ("Invalid instruction");
}
