/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   VM.cpp                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshvorak <oshvorak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/01 14:39:46 by oshvorak          #+#    #+#             */
/*   Updated: 2018/08/08 18:26:53 by oshvorak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/VM.hpp"

void VM::push(IOperand const * value)
{
	this->_stack.push_front(value);
}

void VM::pop( void )
{
	try
	{
		if (this->_stack.empty())
			throw ErrorException("Error : Pop on empty stack");
		this->_stack.pop_front();
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
}

void	VM::dump( void )
{
	std::list<IOperand const *>::iterator it;
	
	for(it = this->_stack.begin(); it != this->_stack.end(); ++it)
	{
    	std::cout << (*it)->toString() << std::endl;
	}
}

void	VM::assert( IOperand *value )
{
	
}

void	VM::print( void )
{
	
}

VM::ErrorException::ErrorException() {}
VM::ErrorException::~ErrorException() throw() {}

VM::ErrorException::ErrorException(std::string message)
{
	this->_message = message;
}

const char* VM::ErrorException::what() const throw() 
{
	return (this->_message.c_str());
}
