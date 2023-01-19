#include <iostream>
#include <string>
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

template<typename S>
class StringValuePair : public Pair<std::string, S>
{
public:
    StringValuePair(const std::string& key, const S& value)
        : Pair<std::string, S>{ key, value }
    {

    }

};

int main()
{
    StringValuePair<int> svp { "Hello", 5 };
    std::cout << "Pair: " << svp.first() << ' ' << svp.second() << '\n';

    return 0;
}