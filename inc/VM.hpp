/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   VM.hpp                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshvorak <oshvorak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/01 14:02:12 by oshvorak          #+#    #+#             */
/*   Updated: 2018/08/13 13:42:56 by oshvorak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H

#include <iostream>
#include <string>
#include <vector>

#include "OperandFactory.hpp"

# define OP_NUM 10

enum eInstruction {
	Push,
	Pop,
	Dump,
	Assert,
	Add,
	Sub,
	Mul,
	Div,
	Mod,
	Exit
};

class VM {

	private:
		std::vector <IOperand const *> _stack;
		void (VM:: *operation[OP_NUM])( void );

	public:
		VM();
		~VM();

		void push( IOperand const * value );
		void pop( void );
		void dump( void );
		void assert(std::string const & value, eOperandType type);
		void add( void );
		void sub( void );
		void mul( void );
		void div( void );
		void mod( void );
		void print( void );
		void exit( void );

		void launch();
		void handle(eInstruction instruction);

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