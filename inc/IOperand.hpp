/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IOperand.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshvorak <oshvorak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/31 17:29:21 by oshvorak          #+#    #+#             */
/*   Updated: 2018/08/08 15:21:35 by oshvorak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IOPERAND_HPP
# define IOPERAND_HPP

#include "AbstractVM.hpp"

class IOperand {

	public:
		virtual int getPrecision( void ) const = 0; // Precision of the type of the instance
		virtual eOperandType getType( void ) const = 0; // Type of the instance

		virtual IOperand const * operator+( IOperand const & rhs ) const = 0; // Sum
		virtual IOperand const * operator-( IOperand const & rhs ) const = 0; // Difference
		virtual IOperand const * operator*( IOperand const & rhs ) const = 0; // Product
		virtual IOperand const * operator/( IOperand const & rhs ) const = 0; // Quotient
		virtual IOperand const * operator%( IOperand const & rhs ) const = 0; // Modulo
		virtual IOperand const * operator&( IOperand const & rhs ) const = 0; // And
		virtual IOperand const * operator|( IOperand const & rhs ) const = 0; // Or
		virtual IOperand const * operator^( IOperand const & rhs ) const = 0; // Xor

		virtual std::string const & toString( void ) const = 0; // String representation of the instance
		virtual ~IOperand( void ) {}
};

#endif