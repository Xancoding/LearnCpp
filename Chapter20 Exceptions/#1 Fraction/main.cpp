#include <iostream>
#include <stdexcept>

class Fraction
{
private:
    int m_numerator{};
    int m_denominator{};

public:
    Fraction(int numerator, int denominator)
        : m_numerator{ numerator }
        , m_denominator{ denominator }
    {
        if (m_denominator == 0)
            throw std::runtime_error("Invalid denominator");
    }

    friend std::ostream& operator<< (std::ostream& out, const Fraction& f1);
};

std::ostream& operator<< (std::ostream& out, const Fraction& f1)
{
    out << f1.m_numerator << '/' << f1.m_denominator;
    return out;
}

int main()
{

    std::cout << "Enter the numerator:";
    int numerator{};
    std::cin >> numerator;

    std::cout << "Enter the denominator:";
    int denominator{};
    std::cin >> denominator;

    try
    {
        Fraction f{ numerator, denominator };
        std::cout << "Your Fraction is: " << f << '\n';
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

}