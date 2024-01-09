#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

class Multiply: public SubExpression {
public:
    Multiply(Expression* left, Expression* right): SubExpression(left, right) {
    }
    double evaluate() {
       return left->evaluate() * right->evaluate();
    }
};
