# Math Formula Processor

The MathFormula class uses *Shunting Yard* algorithm to create post fix notation format.
Then by utilizing algorithm for solving post fix notation, it calculates the result of the formula.

## Notes
* The program was made to work with following operators (separated by spaced): `+ - * / ( ) ^`  
* This solution expects only valid formulas using numbers and the operators listed above.
* The main function contains pre-defined set of example formulas. When executing, the program will calculate the formulas and print them to console including the results.