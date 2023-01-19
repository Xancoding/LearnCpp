#include <iostream>

class Fruit
{
private:
    std::string m_name{};
    std::string m_color{};

public:
    Fruit(const std::string& name, const std::string& color)
        : m_name{ name }
        , m_color{ color }
    {

    }

    const std::string& getName() const { return m_name; }
    const std::string& getColor() const { return m_color; }
};

class Apple : public Fruit
{
private:
    double m_fiber{};

public:
    Apple(const std::string& name, const std::string& color, double fiber)
        : Fruit{ name, color }
        , m_fiber{ fiber }
    {

    }

    double getFiber() const { return m_fiber; }
};

std::ostream& operator<< (std::ostream& out, const Apple& apple)
{
    out << "Apple(" << apple.getName()
        << ", " << apple.getColor()
        << ", " << apple.getFiber() << ')';

    return out;
}

class Banana : public Fruit
{
public:
    Banana(const std::string& name, const std::string& color)
            : Fruit{ name, color }
    {

    }
};

std::ostream& operator<<(std::ostream& out, const Banana& b)
{
    out << "Banana(" << b.getName() << ", " << b.getColor() << ')';
    return out;
}

int main()
{
    const Apple a{ "Red delicious", "red", 4.2 };
    std::cout << a << '\n';

    const Banana b{ "Cavendish", "yellow" };
    std::cout << b << '\n';

    return 0;
}