/*
 *-------------
 * CC-BY-4.0
 * Matej Foltin
 * ------------
 */
#pragma once

//! Class representing token of formula
class Token
{
public:
	//! Type enum
	enum Type
	{
		Number,
		Operator,
		LeftPar
	};

	//! Operation type
	enum Operation
	{
		Add = '+',
		Sub = '-',
		Mul = '*',
		Div = '/',
		Pow = '^'
	};

	//! Float constructor
	/*!
	 * Constructor used for creating token of Type.Number
	 * \param value Float value
	 */
	Token(float value);

	//! Universal constructor
	/*!
	 * Constructor used to create object with given type
	 * \param type Type value
	 */
	Token(Type type);

	//! Operator constructor
	/*!
	 * Constructor used for creating token of Type.Operator
	 * This constructor also assigns weight of the operator
	 * \param operation Operation value
	 */
	Token(Operation operation);

	//! Returns Token Type
	/*!
	 * \return Type of token
	 */
	Type getType();

	//! Returns float value of token
	/*!
	 * \return Value of number as float
	 */
	float getValue();

	//! Returns operation type
	/*!
	 * \return Type of operator
	 */
	Operation getOperation();

	//! Returns operator weight
	/*!
	 * \return Weight of operator
	 */
	int getWeight();


private:
	
	Type type; //!< Token type
	float value; //!< Token value
	Operation operation; //!< Operation type
	int weight = 0; //!< Operator weight

};

