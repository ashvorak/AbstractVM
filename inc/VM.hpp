/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   VM.hpp                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshvorak <oshvorak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/01 14:02:12 by oshvorak          #+#    #+#             */
/*   Updated: 2018/08/08 18:26:41 by oshvorak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H

#include <iostream>
#include <string>
#include <list>

#include "OperandFactory.hpp"

class VM {

	private:
		std::list <IOperand const *> _stack;

	public:

		void push( IOperand const * value );
		void pop( void );
		void dump( void );
		void assert( IOperand *value );

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