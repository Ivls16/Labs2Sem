#include "expression.h"

class Number: public Expression
{
private:
    double value;
public:
    Number(double val);

    double Evaluate() const override;

    ~Number() override = default;

    int ExpressionType() const override;
};
