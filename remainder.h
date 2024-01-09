// CMSC 330 Advanced Programming Languages
// Project 2 Skeleton
// UMGC CITE
// Spring 2023 - Matthew Gregorek Project 2
// HEADER FILE for Remainder Symbol  %, or the Modulo 
// This file contains the definition of the Expression class, 
// which is an abstract class that contains one
// abstract (pure virtual) function named evaluate,
// which must be implemented by all its subclasses.

#include <cmath>
#include <iostream>
#include <algorithm>

class Remainder : public SubExpression {
   public:
    Remainder(Expression* left, Expression* right): SubExpression(left, right) {}
    double evaluate() {
        int denominator = (int)right->evaluate();
        if(denominator == 0){
            throw "Cannot divide by Zero!";
        }
        return (int)left->evaluate() % denominator;
    }
}; 
