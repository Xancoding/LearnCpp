#include <iostream>

template<typename T1, typename T2>
class Pair
{
private:
    T1 m_first{};
    T2 m_second{};

public:
    Pair(const T1& first, const T2& second)
        : m_first{ first }
        , m_second{ second }
    {

    }

    T1& first() { return  m_first; }
    T2& second() { return m_second; }
    const T1& first() const { return  m_first; }
    const T2& second() const { return m_second; }
};



int main()
{
    Pair<int, double> p1 { 5, 6.7 };
    std::cout << "Pair: " << p1.first() << ' ' << p1.second() << '\n';

    const Pair<double, int> p2 { 2.3, 4 };
    std::cout << "Pair: " << p2.first() << ' ' << p2.second() << '\n';

    return 0;
}