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
	std::regex 	rx1("(^[\\s]*?(pop|dump|add|sub|mul|div|mod|print|exit)[\\s]*?$)");
	std::regex 	rx2("(^[\\s]*?(push|assert)[\\s]+(int8|int16|int32)[\\(][-]?[0-9]+[\\)][\\s]*?$)");
	std::regex 	rx3("(^[\\s]*?(push|assert)[\\s]+(float|double)[\\(][-]?[0-9]+.[0-9]+[\\)][\\s]*?$)");
	std::cmatch	match;
	std::string	op;

	if (regex_match(instr.begin(), instr.end(), rx1))
	{
		std::regex_search(instr.c_str(), match, rx1);
		op = match[0];
	}
	else if (regex_match(instr.begin(), instr.end(), rx2))
<<<<<<< HEAD
	{
		std::regex rx("int8|int16|int32|[-]?[0-9]+");

		std::regex_search(instr.c_str(), match, rx);
		Parser::_type = Int16;
		Parser::_value = "32";
		std::cout << "match " << match[0] << std::endl;
	}
	else if (regex_match(instr.begin(), instr.end(), rx3))
	{
		std::regex rx("[-]?[0-9]+.[0-9]+");

		std::regex_search(instr.c_str(), match, rx);
		Parser::_type = Float;
		Parser::_value = match[0];
	}
=======
        op = parse_int(instr);
	else if (regex_match(instr.begin(), instr.end(), rx3))
        op = parse_pointed(instr);
>>>>>>> 0297b241b915686efa2e85ed6c1c16598d765c0e
	else
		throw ValidException();
	return (_pm[op]);
}

std::string Parser::parse_int(std::string instr)
{
    std::smatch	match;
    std::regex  rx("(\\w+) (\\w+\\d+)\\((-?\\d+)\\)");

    std::regex_search(instr, match, rx);

    if (match[2] == "int8")
        Parser::_type = Int8;
    else if (match[2] == "int16")
        Parser::_type = Int16;
    else if (match[2] == "int32")
        Parser::_type = Int32;
    Parser::_value = match[3];
    return (match[1]);
}

std::string Parser::parse_pointed(std::string instr)
{
    std::smatch	match;
    std::regex  rx("(\\w+) (\\w+)\\((-?\\d+.\\d+)\\)");

    std::regex_search(instr, match, rx);

    if (match[2] == "float")
        Parser::_type = Float;
    else if (match[2] == "double")
        Parser::_type = Double;
    Parser::_value = match[3];
    return (match[1]);
}

Parser::ValidException::ValidException() {}
Parser::ValidException::~ValidException() throw() {}

const char* Parser::ValidException::what() const throw()
{
	return ("Invalid instruction");
}
