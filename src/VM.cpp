/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   VM.cpp                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshvorak <oshvorak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/01 14:39:46 by oshvorak          #+#    #+#             */
/*   Updated: 2018/08/13 13:45:54 by oshvorak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/VM.hpp"

std::map<eInstruction, oper> VM::om = {{Pop, &VM::pop},
									   {Dump, &VM::dump},
									   {Add, &VM::add},
									   {Sub, &VM::sub},
									   {Mul, &VM::mul},
									   {Div, &VM::div},
									   {Mod, &VM::mod},
									   {Print, &VM::mul},
									   {Exit, &VM::exit}};

VM::VM()
{

}

VM::~VM()
{
	for(int i = this->_stack.size() - 1; i >= 0 ; i--)
		delete this->_stack[i];
}

void VM::push(IOperand const * value)
{
	this->_stack.push_back(value);
}

void VM::pop( void )
{
	if (this->_stack.empty())
		throw ErrorException("Error : Pop on empty stack");
	delete this->_stack.back();
	this->_stack.pop_back();
}

void	VM::dump( void )
{
	std::vector<IOperand const *>::iterator it;
	
	for(it = this->_stack.end() - 1; it >= this->_stack.begin(); it--)
	{
    	std::cout << (*it)->toString() << std::endl;
	}
}

void	VM::assert(std::string const & value, eOperandType type)
{
	if (this->_stack.empty())
		throw ErrorException("Error : Assert on empty stack");
	if (this->_stack.back()->getType() != type || stod(this->_stack.back()->toString(), 0) != stod(value, 0))
		throw ErrorException("Error : Assert instruction is not true");
}

void	VM::add()
{
	IOperand const	*value;
	unsigned long	size = this->_stack.size();

	if (this->_stack.size() < 2)
		throw ErrorException("Error : Instruction 'add' when less that two values.");
	value = *(this->_stack[size - 1]) + *(this->_stack[size - 2]);
	delete this->_stack.back();
	this->_stack.pop_back();
	delete this->_stack.back();
	this->_stack.pop_back();
	this->_stack.push_back(value);

}

void	VM::sub()
{
	IOperand const	*value;

	if (this->_stack.size() < 2)
		throw ErrorException("Error : Instruction 'sub' when less that two values.");
	value = *(this->_stack[this->_stack.size() - 1]) - *(this->_stack[this->_stack.size() - 2]);
	delete this->_stack.back();
	this->_stack.pop_back();
	delete this->_stack.back();
	this->_stack.pop_back();
	this->_stack.push_back(value);

}

void	VM::mul()
{
	IOperand const	*value;

	if (this->_stack.size() < 2)
		throw ErrorException("Error : Instruction 'mul' when less that two values.");
	value = *(this->_stack[this->_stack.size() - 1]) * *(this->_stack[this->_stack.size() - 2]);
	delete this->_stack.back();
	this->_stack.pop_back();
	delete this->_stack.back();
	this->_stack.pop_back();
	this->_stack.push_back(value);
}

void	VM::div()
{
	IOperand const	*value;

	if (this->_stack.size() < 2)
		throw ErrorException("Error : Instruction 'div' when less that two values.");
	value = *(this->_stack[this->_stack.size() - 1]) / *(this->_stack[this->_stack.size() - 2]);
	delete this->_stack.back();
	this->_stack.pop_back();
	delete this->_stack.back();
	this->_stack.pop_back();
	this->_stack.push_back(value);
}

void	VM::mod()
{
	IOperand const	*value;

	if (this->_stack.size() < 2)
		throw ErrorException("Error : Instruction 'mod' when less that two values.");
	value = *(this->_stack[this->_stack.size() - 1]) / *(this->_stack[this->_stack.size() - 2]);
	delete this->_stack.back();
	this->_stack.pop_back();
	delete this->_stack.back();
	this->_stack.pop_back();
	this->_stack.push_back(value);
}

void	VM::print( void )
{
	if (this->_stack.empty())
		throw ErrorException("Error : Print on empty stack");
	else if (this->_stack.back()->getType() != Int8)
		throw ErrorException("Error : Can't print (incompetiple type)");
	else
		std::cout << static_cast<char>(stoi(this->_stack.back()->toString())) << std::endl;
}

void	VM::exit( void )
{

}

void	VM::launch( void )
{
	Parser pars("lol");

	handle(Mul);
}

void	VM::handle(eInstruction & instruction)
{
	try
	{
		(this->*om[instruction])();
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
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
