#include <iostream>
#include <arithmetic.h>

bool check_equals(Expression const* left, Expression const* right) {
    return left->ExpressionType() == right->ExpressionType();
}

int main() {
    Expression* sube = new BinaryOperation(new Number(4.5), '*', new Number(5));
    Expression* expr = new BinaryOperation(new Number(3), '+', sube);
    std::cout << expr->Evaluate() << std::endl;

    Expression* a = new Number(4);
    Expression* b = new Number(5);
    Expression* c = new BinaryOperation(a, '*', b);
    std::cout << check_equals(a, b) << ' ' << check_equals(a, c) << '\n';
}
