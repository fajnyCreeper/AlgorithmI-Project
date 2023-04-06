#include <iostream>
#include <string>
#include <vector>

#include "MathFormula.h"

using namespace std;

int main()
{
	//Results in comments after formulas were calculated using WolframAlpha
	vector<string> formulas;
	formulas.push_back("3 + 4 * 2 / ( 1 - 5 ) ^ 2 ^ 3"); // ~3.00
	formulas.push_back("60-100"); // -40
	formulas.push_back("100^2-(20*7)/(30^2)-5"); // ~9994.84
	formulas.push_back("12^2-11^2*3/(12*9)+18*5"); // ~230.639

	formulas.push_back("9^2048");
	formulas.push_back("3^3^3+20");

	for (auto formulaString : formulas)
	{
		MathFormula formula = MathFormula(formulaString);
		cout << "Formula: " << formula.toString() <<  endl << "Result: " << formula.calculate() << endl << endl;
	}

	return 0;
}