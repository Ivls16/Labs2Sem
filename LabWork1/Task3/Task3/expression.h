class Expression
{
public:
    virtual double Evaluate() const = 0;

    virtual ~Expression() = default;
};
