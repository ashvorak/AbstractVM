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

#include "Operand.hpp"

class VM;

class Parser {

	public:

		static IOperand const * value;

		eInstruction parse(std::string instruction);
		
};

#endif