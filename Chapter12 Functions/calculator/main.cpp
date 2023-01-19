#include <functional>
#include <iostream>

using ArithmeticFunction = std::function<int(int, int)>;

int getInteger() {
    std::cout << "Enter an Integer:";
    int number{};
    std::cin >> number;
    return number;
}

char getOperator() {
    char op{};

    do {
       std::cout << "Enter an Operator('+', '-', '*', '/'):";
       std::cin >> op;
   } while (op != '+' && op != '-' && op != '*' && op != '/');

    return op;
}

int add(int x, int y) {
    return x + y;
}

int subtract(int x, int y) {
    return x - y;
}

int multiply(int x, int y) {
    return x * y;
}

int divide(int x, int y) {
    return x / y;
}

ArithmeticFunction getArithmeticFunction(char op) {
    switch(op) {
        case '+':  return &add;
        case '-':  return &subtract;
        case '*':  return &multiply;
        case '/':  return &divide;
        default:   return nullptr;
    }
}

int main() {
    int x{ getInteger() };
    char op{ getOperator() };
    int y{ getInteger() };

    ArithmeticFunction fcn { getArithmeticFunction(op) };
    if (fcn) {
        std::cout << x << ' ' << op << ' ' << y << " = " << fcn(x, y) << '\n';
    }

    return 0;
}