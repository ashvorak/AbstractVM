/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Operand.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshvorak <oshvorak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/31 17:47:16 by oshvorak          #+#    #+#             */
/*   Updated: 2018/08/09 11:13:29 by oshvorak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERAND_HPP
# define OPERAND_HPP

#include <cmath>
#include "IOperand.hpp"
#include "OperandFactory.hpp"

template <typename T>
class Operand : public IOperand {

	private:
		std::string		_str;
		int				_precision;
		eOperandType 	_type;

	public:

		Operand<T>(std::string str, eOperandType type, int precision)
		{
			long double x;

			x = stold(str);
			if (x > std::numeric_limits<T>::max())
				throw OverflowException();
			else if (x < std::numeric_limits<T>::lowest())
				throw UnderflowException();
			this->_str = (type < Float) ? str.substr(0, str.find('.')) :  str;
			this->_type = type;
			this->_precision = precision;
		}

		int getPrecision( void ) const { return (this->_precision); }
		eOperandType getType( void ) const { return (this->_type); }

		IOperand const * operator+( IOperand const & rhs ) const
		{
			std::string		value;
			eOperandType	type;
			OperandFactory	Factory;

			type = (rhs.getType() > this->_type) ? rhs.getType() : this->_type;
			value = std::to_string(stod(this->_str, 0) + stod(rhs.toString(), 0));
			return (Factory.createOperand(type, value));
		}
		
		IOperand const * operator-( IOperand const & rhs ) const
		{
			std::string		value;
			eOperandType	type;
			OperandFactory	Factory;

			type = (rhs.getType() > this->_type) ? rhs.getType() : this->_type;
			value = std::to_string(stod(this->_str, 0) - stod(rhs.toString(), 0));
			return (Factory.createOperand(type, value));
		}
		
		IOperand const * operator*( IOperand const & rhs ) const
		{
			std::string		value;
			eOperandType	type;
			OperandFactory	Factory;

			type = (rhs.getType() > this->_type) ? rhs.getType() : this->_type;
			value = std::to_string(stod(this->_str, 0) * stod(rhs.toString(), 0));
			return (Factory.createOperand(type, value));
		}
		
		IOperand const * operator/( IOperand const & rhs ) const
		{
			std::string		value;
			eOperandType	type;
			OperandFactory	Factory;

			if (!stod(rhs.toString(), NULL))
				throw ZeroException("Division by 0");
			type = (rhs.getType() > this->_type) ? rhs.getType() : this->_type;
			value = std::to_string(stod(this->_str, 0) / stod(rhs.toString(), 0));
			return (Factory.createOperand(type, value));
		}

		IOperand const * operator%( IOperand const & rhs ) const
		{
			std::string		value;
			eOperandType	type;
			OperandFactory	Factory;

			if (!stod(rhs.toString(), NULL))
				throw ZeroException("Modulo by 0");
			type = (rhs.getType() > this->_type) ? rhs.getType() : this->_type;
			value = std::to_string(fmod(stod(this->_str, 0) , stod(rhs.toString(), 0)));
			return (Factory.createOperand(type, value));
		}

		std::string const & toString( void ) const
		{
			return (this->_str);
		}

		class OverflowException : public std::exception
		{

			public:
				OverflowException() {}
				~OverflowException() throw() {}

				virtual const char *what() const throw()
				{
					return ("Overflow value");
				}

		};

		class UnderflowException : public std::exception
		{

			public:
				UnderflowException() {}
				~UnderflowException() throw() {}

				virtual const char *what() const throw()
				{
					return ("Underflow value");
				}
		};

		class ZeroException : public std::exception
		{

			private:
				std::string _message;

			public:
				ZeroException() {}
				ZeroException(std::string message) { this->_message = message; }
				~ZeroException() throw() {}

				virtual const char *what() const throw()
				{
					return (this->_message.c_str());
				}
			};

		~Operand( void ) {}
		
};

#endif