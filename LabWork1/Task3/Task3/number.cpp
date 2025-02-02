#include "number.h"

Number::Number(double value): value(value) {}

double Number::Evaluate() const {
    return value;
}

int Number::ExpressionType() const {
    return 0;
};
