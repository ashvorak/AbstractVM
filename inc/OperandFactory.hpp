/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OperandFactory.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshvorak <oshvorak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 15:20:58 by oshvorak          #+#    #+#             */
/*   Updated: 2018/08/13 14:07:54 by oshvorak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERAND_FACTORY_HPP
# define OPERAND_FACTORY_HPP

#include "IOperand.hpp"

class OperandFactory {

	private:
		static std::map <eOperandType, createValue > _m;

	public:

		OperandFactory();
		OperandFactory(const OperandFactory &copy);
		~OperandFactory();

		OperandFactory &operator=(const OperandFactory &src);

		IOperand const * createInt8( std::string const & value ) const;
		IOperand const * createInt16( std::string const & value ) const;
		IOperand const * createInt32( std::string const & value ) const;
		IOperand const * createFloat( std::string const & value ) const;
		IOperand const * createDouble( std::string const & value ) const;

		IOperand const * createOperand( eOperandType type, std::string const & value ) const;

};

#endif