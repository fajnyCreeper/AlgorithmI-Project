#pragma once
#include <queue>
#include <string>

#include "Token.h"

//! Class representing math formula
class MathFormula
{
private:
	
	std::string formula; //!< Math formula as string
	std::queue<Token> tokens; //!< Queue of tokens

	//! Process string
	/*!
	 * Process string by removing all spaces from it
	 */
	void processString();

	//! Process math formula
	/*!
	 * Process math formula using shunting yard algorithm
	 */
	void shuntingYard();
	
public:

	//! Class constructor
	/*!
	 * Construct object by passing math formula
	 * Constructor first calls processString() function and then shuntingYard() function
	 */
	MathFormula(std::string formula);

	//! Calculate the formula
	/*!
	 * Using post fix notation format of math formula calculates the value of the given formula
	 * \return Calculated value of formula as float
	 */
	float calculate();

	//! Parse to string
	/*!
	 * Returns infix math formula without spaces as string
	 * \return String representation of formula
	 */
	std::string toString()
	{
		return this->formula;
	}
};

