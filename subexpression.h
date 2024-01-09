#include "minus.h"
#include "plus.h"
#include "remainder.h"
#include "multiply.h"

class SubExpression: public Expression {
public:
    SubExpression(Expression* left, Expression* right);
    static Expression* parse(stringstream& in);
protected: 
    Expression* left;
    Expression* right;
};    
