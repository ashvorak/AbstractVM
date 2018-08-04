/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Operand.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshvorak <oshvorak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/31 17:47:16 by oshvorak          #+#    #+#             */
/*   Updated: 2018/08/04 15:48:08 by oshvorak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERAND_VM
# define OPERAND_VM

#include "IOperand.hpp"

template <typename T>
class Operand : public IOperand {

	private:
		T 				_value;
		int				_precision;
		eOperandType 	_type;

	public:

		Operand<T>(T value) {
			this->_value = value;
		}

		T & getValue( void ) { return (this->_value); }
		int getPrecision( void ) const { return (this->_precision); }
		eOperandType getType( void ) const { return (this->_type); }

		void	setValue(T value) { this->_value = value; }
		void	setType(eOperandType type) { this->_type = type; }

		IOperand const * operator+( IOperand const & rhs ) const
		{
			
		}
		
		IOperand const * operator-( IOperand const & rhs ) const
		{
			
		}
		
		IOperand const * operator*( IOperand const & rhs ) const
		{
			
		}
		
		IOperand const * operator/( IOperand const & rhs ) const
		{
			
		}

		IOperand const * operator%( IOperand const & rhs ) const
		{
			
		}

		std::string const & toString( void ) const
		{

		}
		
		~Operand( void ) {}
		
};

#endif