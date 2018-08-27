/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AbstractVM.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshvorak <oshvorak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 11:36:43 by oshvorak          #+#    #+#             */
/*   Updated: 2018/08/20 11:36:45 by oshvorak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ABSTRACTVM_H
#define ABSTRACTVM_H

#include <map>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include <iostream>

class VM;
class IOperand;
class OperandFactory;

enum eOperandType {
	None,
    Int8,
    Int16,
    Int32,
    Float,
    Double
};

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
    Print,
	Exit
};

typedef void 				(VM:: *oper)( void );
typedef IOperand const 		*(OperandFactory:: *createValue)(std::string const & value) const;

#endif
