#include "binaryoperation.h"

BinaryOperation::BinaryOperation(Expression* left, char operationType, Expression* right):
    left(left), right(right), operationType(operationType)
{}

double BinaryOperation::Evaluate() const {
    double leftVal = left->Evaluate();
    double rightVal = right->Evaluate();
    switch (operationType) {
        case '+': return leftVal + rightVal;
        case '-': return leftVal - rightVal;
        case '*': return leftVal * rightVal;
        case '/': return leftVal / rightVal;
        default: throw std::runtime_error("Wtf");
    }
}

int BinaryOperation::ExpressionType() const {
    return 1;
};

BinaryOperation::~BinaryOperation() {
    delete left;
    delete right;
}
