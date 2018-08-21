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
		T 				_value;
		std::string		_str;
		int				_precision;
		eOperandType 	_type;

	public:

		Operand<T>(T value, std::string str, eOperandType type, int precision)
		{
			long double x;

			x = stold(str);
			if (x > std::numeric_limits<T>::max())
				throw OverflowException();
			else if (x < std::numeric_limits<T>::min())
				throw UnderflowException();
			this->_value = value;
			this->_str = str;
			this->_type = type;
			this->_precision = precision;
		}
		
		T & getValue( void ) { return (this->_value); }
		int getPrecision( void ) const { return (this->_precision); }
		eOperandType getType( void ) const { return (this->_type); }

		void	setValue(T value) { this->_value = value; }
		void	setPrecision(int precision) { this->_precision = precision; }
		void	setType(eOperandType type) { this->_type = type; }

		IOperand const * operator+( IOperand const & rhs ) const
		{
			std::string		value;
			eOperandType	type;
			OperandFactory	Factory;

			type = (rhs.getPrecision() > this->_precision) ? rhs.getType() : this->_type;
			value = std::to_string(this->_value + stod(rhs.toString(), 0));
			return (Factory.createOperand(type, value));
		}
		
		IOperand const * operator-( IOperand const & rhs ) const
		{
			std::string		value;
			eOperandType	type;
			OperandFactory	Factory;

			type = (rhs.getPrecision() > this->_precision) ? rhs.getType() : this->_type;
			value = std::to_string(this->_value - stod(rhs.toString(), 0));
			return (Factory.createOperand(type, value));
		}
		
		IOperand const * operator*( IOperand const & rhs ) const
		{
			std::string		value;
			eOperandType	type;
			OperandFactory	Factory;

			type = (rhs.getPrecision() > this->_precision) ? rhs.getType() : this->_type;
			value = std::to_string(this->_value * stod(rhs.toString(), 0));
			return (Factory.createOperand(type, value));
		}
		
		IOperand const * operator/( IOperand const & rhs ) const
		{
			std::string		value;
			eOperandType	type;
			OperandFactory	Factory;

			if (!stod(rhs.toString(), NULL))
				throw ZeroException("Division by 0");
			type = (rhs.getPrecision() > this->_precision) ? rhs.getType() : this->_type;
			value = std::to_string(this->_value / stod(rhs.toString(), 0));
			return (Factory.createOperand(type, value));
		}

		IOperand const * operator%( IOperand const & rhs ) const
		{
			std::string		value;
			eOperandType	type;
			OperandFactory	Factory;

			if (!stod(rhs.toString(), NULL))
				throw ZeroException("Modulo by 0");
			type = (rhs.getPrecision() > this->_precision) ? rhs.getType() : this->_type;
			value = std::to_string(fmod(this->_value , stod(rhs.toString(), 0)));
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