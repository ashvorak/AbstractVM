/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshvorak <oshvorak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/01 15:53:29 by oshvorak          #+#    #+#             */
/*   Updated: 2018/08/08 15:20:55 by oshvorak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

#include <string>
#include <Operand.hpp>

class Parser {

	private:
		std::string _instruction;

	public:
		Parser(std::string instruct);

		void setInstruction(std::string const instruction);
		
};

#endif