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
#include "regex"

class VM;

class Parser {

	private:
		static std::map<std::string, eInstruction > _pm;

	public:

		static IOperand const * value;

		eInstruction 	parse(std::string instruction);
		std::string		lexicalAnalysis(std::string instruction);

		class ValidException : public std::exception {

		public:
			ValidException();
			~ValidException() throw();

			virtual const char *what() const throw();

		};

};

#endif