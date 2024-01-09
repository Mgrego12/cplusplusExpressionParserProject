// Matthew Gregorek Project 2
// Class for Binary operators
// BinaryExpression will take in left,right, and operator, 
// and then evaluate each operator

#include <cmath>
#include <iostream>
#include <algorithm>

/*

class BinaryExpression : public Expression{
    public: 
        BinaryExpression(Expression* left, Expression* right, char binOp){
            this.left -> left;
            this.right -> right;
            this.binOp -> binOp;
    }

    double evaluate(){
        switch(binOp){
            case '-':
                return left->evaluate() - right->evaluate();
            case '+':
                return left->evaluate() + right->evaluate();
            case '/':
                return left->evaluate() / right->evaluate();
            case '*':
                return left->evaluate() * right->evaluate();
            case '<':
                return left->evaluate(), right->evaluate();
            case '/':
                return left->evaluate() / right->evaluate();
            case '/':
                return left->evaluate() / right->evaluate();
        }
    }
    private:
    Expression* left;
    Expression* right;
    char binOp;
};
