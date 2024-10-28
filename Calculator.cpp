// this is a caculator
// it has the following functions which involve float type numbers
// addition, deduction, division, multiplication

#include <iostream>
#include <algorithm>
class Calculator
{
private:
    float v1 = 0.0, v2 = 0.0;

public:
    Calculator(float v1 = 0.0, float v2 = 0.0) : v1(v1), v2(v2) {}
    void setValues(float newV1, float newV2)
    {
        v1 = newV1;
        v2 = newV2;
    }
    float add();
    float deduct();
    float divide();
    float multiply();
};

float Calculator::add()
{
    return this->v1 + this->v2;
}

float Calculator::divide()
{
    float ret = 0;
    if (this->v2 != 0)
    {
        ret = this->v1 / this->v2;
    }
    else
    {
        throw std::invalid_argument("Division by zero is not allowed");
    }
    return ret;
}

float Calculator::deduct()
{
    return this->v1 - this->v2;
}

float Calculator::multiply()
{
    return this->v1 * this->v2;
}

int main()
{
    std::cout << "give the first number:\n";
    float v1;
    std::cin >> v1;
    std::cout << "give the second number:\n";
    float v2;
    std::cin >> v2;
    Calculator cal = Calculator(5.5, 2.3);
    cal.setValues(v1, v2);

    char op;
    std::cout << "Choose one opeartion: +, -, *, /" << std::endl;
    std::cin >> op;
    switch (op)
    {
    case '+':
        std::cout << "v1 + v2 = " << cal.add() << std::endl;
        break;
    case '-':
        std::cout << "v1 + v2 = " << cal.deduct() << std::endl;
        break;
    case '*':
        std::cout << "v1 + v2 = " << cal.multiply() << std::endl;
        break;
    case '/':
        try
        {
            std::cout << "v1 / v2 = " << cal.divide() << std::endl;
        }
        catch (const std::invalid_argument &e)
        {
            std::cerr << e.what() << std::endl;
        }
        break;
    default:
        std::cerr << "wrong input" << std::endl;
        break;
    }
    return 0;
}