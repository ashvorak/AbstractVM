/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   VM.hpp                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshvorak <oshvorak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/01 14:02:12 by oshvorak          #+#    #+#             */
/*   Updated: 2018/08/01 18:49:45 by oshvorak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H

#include <iostream>
#include <string>
#include <stack>

#include "Operand.hpp"

class VM {

	private:
		std::stack <IOperand *> _stack;

	public:

		void pop( void );
		void push(IOperand * value);
		void print( void );

	class ErrorException : public std::exception {
		
			std::string _message;
			
		public:
			ErrorException();
			ErrorException(std::string message);
			~ErrorException() throw();
			
			virtual const char *what() const throw();

	};
	
};

#endif