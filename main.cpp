#include <iostream>
#include <random>
#include <cmath>



int getRandom(int begin, int end) {

    std::random_device seed;        // initial seed
    std::mt19937 engine(seed());    // generator
    std::uniform_int_distribution<> uniformDist(begin, end);

    return uniformDist(engine);
}

//inner factory pattern
//can be a shape with various forms.. perhaps
class Point
{
private:
    Point( const double x, const double y ) : x{x}, y{y} {}

    double x,y;

public:
    class PointFactory //inner factory class, it can access the outer class's private members and vice versa
    {
    private:
        PointFactory();

    public:

        static Point NewCartesian( const double x, const double y )
        {
            return { x,y };
        }

        static Point NewPolar( const double r, const double theta )
        {
            return { r * cos(theta), r * sin(theta) };
        }
    };

    inline double Get_X() const { return x; }
    inline double Get_Y() const { return y; }

    //an example
    //auto other_experimental = Point::PointFactory::NewPolar(3, M_PI_2);
};

int main( int charc, char * charv[])
{


	return 0;
}
































