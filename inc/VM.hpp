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

#include "Parser.hpp"
#include "OperandFactory.hpp"

class VM {

	private:
		std::vector <IOperand const *> 		_stack;
		static std::map<eInstruction, oper> _om;
		std::stringstream					_ss;
		unsigned long						_count_line;

	public:
		VM();
		VM(const VM & copy);
		~VM();

		VM &operator=(VM const &src);

		void push( void );
		void pop( void );
		void dump( void );
		void assert( void );
		void add( void );
		void sub( void );
		void mul( void );
		void div( void );
		void mod( void );
		void print( void );

		void and_b();
		void or_b();
		void xor_b();

		void handleSI( void );
		void handleFile(const char *file_name);

		void handleInstruction(std::string & line);
		void execute(eInstruction instruction);

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