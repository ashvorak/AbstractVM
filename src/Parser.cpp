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

eOperandType Parser::_type = None;
std::string Parser::_value = "";

std::map<std::string, eInstruction > Parser::_pm = {{"push", Push},
													{"pop", Pop},
													{"dump", Dump},
													{"assert", Assert},
													{"add", Add},
													{"sub", Sub},
													{"mul", Mul},
													{"div", Div},
													{"mod", Mod},
													{"print", Print}};


Parser::Parser()
{

}

Parser::Parser(const Parser &copy)
{
	*this = copy;
}

Parser::~Parser()
{

}

Parser & Parser::operator=(Parser const &src)
{
	if (this == &src)
		return (*this);
	return (*this);
}

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
	std::regex 	rx1("(^[\\s]*?(pop|dump|add|sub|mul|div|mod|print)[\\s]*?(\\;.*?)?$)");
	std::regex 	rx2("(^[\\s]*?(push|assert)[\\s]+(int8|int16|int32)[\\(][-]?[0-9]+[\\)][\\s]*?(\\;.*?)?$)");
	std::regex 	rx3("(^[\\s]*?(push|assert)[\\s]+(float|double)[\\(][-]?[0-9]+.[0-9]+[\\)][\\s]*?(\\;.*?)?$)");
	std::cmatch	match;
	std::string	op;

	if (regex_match(instr.begin(), instr.end(), rx1))
	{
		std::regex  rx("(\\w+)");
		std::regex_search(instr.c_str(), match, rx);
		op = match[0];
	}
	else if (regex_match(instr.begin(), instr.end(), rx2))
        op = parse_int(instr);
	else if (regex_match(instr.begin(), instr.end(), rx3))
        op = parse_pointed(instr);
	else
		throw ValidException();
	return (_pm[op]);
}

std::string Parser::parse_int(std::string instr)
{
    std::smatch	match;
    std::regex  rx("(\\w+)(\\s+)(\\w+\\d+)\\((-?\\d+)\\)");

    std::regex_search(instr, match, rx);
    if (match[3] == "int8")
        Parser::_type = Int8;
    else if (match[3] == "int16")
        Parser::_type = Int16;
    else if (match[3] == "int32")
        Parser::_type = Int32;
    Parser::_value = match[4];
    return (match[1]);
}

std::string Parser::parse_pointed(std::string instr)
{
    std::smatch	match;
    std::regex  rx("(\\w+)(\\s+)(\\w+)\\((-?\\d+.\\d+)\\)");

    std::regex_search(instr, match, rx);

    if (match[3] == "float")
        Parser::_type = Float;
    else if (match[3] == "double")
        Parser::_type = Double;
    Parser::_value = match[4];
    return (match[1]);
}

Parser::ValidException::ValidException() {}
Parser::ValidException::~ValidException() throw() {}

const char* Parser::ValidException::what() const throw()
{
	return ("Invalid instruction");
}
