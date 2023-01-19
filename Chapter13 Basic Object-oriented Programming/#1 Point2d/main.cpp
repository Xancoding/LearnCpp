#include <iostream>
#include <cmath>

class Point2d {
private:
    double m_x{};
    double m_y{};

public:
    Point2d(double x=0.0, double y=0.0)
        :m_x{ x }, m_y{ y }
    {
    }

    void print() const {
        std::cout << "Point2d(" << m_x << ", " << m_y << ")\n";
    }

    friend double distanceFrom(const Point2d& first, const Point2d& second);
};


double distanceFrom(const Point2d& first, const Point2d& second) {
    double dx = first.m_x - second.m_x;
    double dy = first.m_y - second.m_y;

    return std::sqrt(dx * dx + dy * dy);
}

int main()
{
    Point2d first{};
    Point2d second{ 3.0, 4.0 };
    first.print();
    second.print();
    std::cout << "Distance between two points: " << distanceFrom(first, second) << '\n';

    return 0;
}