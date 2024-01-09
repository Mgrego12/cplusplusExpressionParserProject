// mgrego12 update winter 2023 
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

class Expression {
public: 
    virtual double evaluate() = 0;
};

class Operand: public Expression {
public:
    static Expression* parse(stringstream& in);
};

class SubExpression: public Expression {
public:
    SubExpression(Expression* left, Expression* right);
    static Expression* parse(stringstream& in);
protected: 
    Expression* left;
    Expression* right;
};  

class Literal: public Operand {
public:
    Literal(double value) {
        this->value = value;
    }
    double evaluate() {
        return value;
    }
private:
    double value;
};

class Minus: public SubExpression {
public:
    Minus(Expression* left, Expression* right): SubExpression(left, right) {
    }
    double evaluate() {
       return left->evaluate() - right->evaluate();
    }
};

class Multiply: public SubExpression {
public:
    Multiply(Expression* left, Expression* right): SubExpression(left, right) {
    }
    double evaluate() {
       return left->evaluate() * right->evaluate();
    }
};



string parseName(stringstream& in);

class Plus: public SubExpression {
public:
    Plus(Expression* left, Expression* right): SubExpression(left, right) {
    }
    double evaluate()  {
       return left->evaluate() + right->evaluate();
    }
};

class SymbolTable {
public:
    SymbolTable() {}
    void insert(string variable, double value);
    double lookUp(string variable) const;
private:
    struct Symbol {
        Symbol(string variable, double value) {
            this->variable = variable;
            this->value = value;
        }
        string variable;
        double value;
    };
    vector<Symbol> elements;
};
class Variable: public Operand {
public:
    Variable(string name) {
        this->name = name;
    }
    double evaluate();
private:
    string name;
};

extern SymbolTable symbolTable;

double Variable::evaluate() {
    return symbolTable.lookUp(name);
}

void SymbolTable::insert(string variable, double value) {
    const Symbol& symbol = Symbol(variable, value);
    elements.push_back(symbol);
}

double SymbolTable::lookUp(string variable) const {
    for (int i = 0; i < elements.size(); i++)
        if (elements[i].variable == variable)
             return elements[i].value;
    return -1;
}

SubExpression::SubExpression(Expression* left, Expression* right) {
    this->left = left;
    this->right = right;
}

Expression* SubExpression::parse(stringstream& in) {
    Expression* left;
    Expression* right;
    char operation, paren;
    
    left = Operand::parse(in);
    in >> operation;
    right = Operand::parse(in);
    in >> paren;
    switch (operation) {
        case '+':
            return new Plus(left, right);
        case '-':
            return new Minus(left, right);
        case '*':
            return new Multiply(left, right);
    }
    return 0;
}

string parseName(stringstream& in) {
    char alnum;
    string name = "";

    in >> ws;
    while (isalnum(in.peek())) {
        in >> alnum;
        name += alnum;
    }
    return name;
}
Expression* Operand::parse(stringstream& in) {
    char paren;
    int value;

    in >> ws;
    if (isdigit(in.peek())) {
        in >> value;
        Expression* literal = new Literal(value);
        return literal;
    }
    if (in.peek() == '(') {
        in >> paren;
        return SubExpression::parse(in);
    }
    else
        return new Variable(parseName(in));
    return 0;
}

SymbolTable symbolTable;

void parseAssignments(stringstream& in);

int main() {
	const int SIZE = 256;
	Expression* expression;
    char paren, comma, line[SIZE];
 
	ifstream fin;
	fin = ifstream("input.txt");
	if (!(fin.is_open())) {
		cout << "File did not open" << endl;
		system("pause");
		return 1;
	}
	while (true) {
        fin.getline(line, SIZE);
		if (!fin)
			break;
		stringstream in(line, ios_base::in); 
		in >> paren;
		cout << line << " ";
		try {
			expression = SubExpression::parse(in);
			in >> comma;
			parseAssignments(in);
			double result = expression->evaluate();
			cout << "Value = " << result << endl;
		}
		catch (string message) {
			cout << message << endl;
		}
	}
	system("pause");
	return 0;
}

void parseAssignments(stringstream& in) {
	char assignop, delimiter;
    string variable;
    int value;
    do {
        variable = parseName(in);
        in >> ws >> assignop >> value >> delimiter;
        symbolTable.insert(variable, value);
    }
    while (delimiter == ',');
}

