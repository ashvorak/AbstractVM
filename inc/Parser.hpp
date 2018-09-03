/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshvorak <oshvorak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/01 15:53:29 by oshvorak          #+#    #+#             */
/*   Updated: 2018/08/09 10:37:09 by oshvorak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_HPP
# define PARSER_HPP

#include "AbstractVM.hpp"
#include "Operand.hpp"
#include <regex>

class VM;

class Parser {

	private:
		static std::map<std::string, eInstruction > _pm;
		static eOperandType _type;
		static std::string	_value;

	public:

		Parser();
		Parser(const Parser &copy);
		~Parser();

		Parser &operator=(const Parser &src);

		static eOperandType getType( void );
		static std::string getValue( void );

		eInstruction 	parse(std::string instr);
        std::string     parse_int(std::string instr);
        std::string     parse_pointed(std::string instr);

		class ValidException : public std::exception {

		public:
			ValidException();
			~ValidException() throw();

			virtual const char *what() const throw();

		};

};

#endif