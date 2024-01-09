// CMSC 330 Advanced Programming Languages
// Project 2 Skeleton
// UMGC CITE
// Spring 2023
// Matthew Gregorek - Project 2 , OPERAND header
// This file contains the definition of the Operand class, which is a subclass of Expression. It is an
// abstract class because it does not implement the evaluate function. It contains one static (class)
// function parse that parses an operand as either a literal or variable.

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

class Operand: public Expression {
public:
    static Expression* parse(stringstream& in);
};
