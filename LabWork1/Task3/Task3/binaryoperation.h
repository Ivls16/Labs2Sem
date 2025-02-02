#include "number.h"
#include <stdexcept>

class BinaryOperation: public Expression
{
private:
    Expression *left, *right;
    char operationType;
public:
    BinaryOperation(Expression*, char, Expression*);

    double Evaluate() const override;

    ~BinaryOperation() override;

    int ExpressionType() const override;
};
