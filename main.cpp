#include <iostream>
#include <random>
#include <cmath>
#include <memory>
#include <string>
#include <vector>
#include <map>
#include <typeinfo>  //show type of variable  std::cout << typeid(variable).name() << std::endl;

#include "singleton.h"

constexpr unsigned short RANGE_START = 1;
constexpr unsigned short RANGE_END = 100;


int getRandom(int begin, int end) {

    std::random_device seed;        // initial seed
    std::mt19937 engine(seed());    // generator
    std::uniform_int_distribution<> uniformDist(begin, end);

    return uniformDist(engine);
}

/*
//factory methods
class Point
{
private:
    double x,y;

    Point( const double x, const double y ) : x{x}, y{y} {}
public:

    //factory methods
    static Point NewCartesian( const double x, const double y )
    {
        return { x, y };
    }

    static Point NewPolar( const double r, const double theta )
    {
        return { r * cos(theta), r * sin(theta) };
    }

    inline double Get_X() const { return x; }
    inline double Get_Y() const { return y; }
};
*/

/*
//creating Point with a Factory
class Point
{
    friend class PointFactory;
private:
    double x,y;

    Point( const double x, const double y ) : x{x}, y{y} {}
public:

    inline double Get_X() const { return x; }
    inline double Get_Y() const { return y; }
};

class PointFactory
{
private:

    PointFactory();

public:

    static Point NewCartesian( const double x, const double y )
    {
        return { x, y };
    }

    static Point NewPolar( const double r, const double theta )
    {
        return { r * cos(theta), r * sin(theta) };
    }
};
*/

//inner factory pattern
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
            return { x, y };
        }

        static Point NewPolar( const double r, const double theta )
        {
            return { r * cos(theta), r * sin(theta) };
        }


        static std::unique_ptr<Point> New_Cartesian_Unique_Pointer( const double x, const double y )
        {
            return std::unique_ptr<Point>( new Point( x, y ) );
        }

        static std::unique_ptr<Point> New_Polar_Unique_Pointer( const double r, const double theta )
        {
            return std::unique_ptr<Point>( new Point( r * cos(theta), r * sin(theta) ) );
        }

        static Point * create_new_cartesian_pointer( const double x, const double y )
        {
            return new Point{ x, y};
        }

        static Point * create_new_polar_pointer( const double r, const double theta )
        {
            return new Point{ r * cos(theta), r * sin(theta) };
        }

    };

    inline double Get_X() const { return x; }
    inline double Get_Y() const { return y; }

    //an example
    //auto other_experimental = Point::PointFactory::NewPolar(3, M_PI_2);
};
/////////////////// inner factory end /////


int main( int charc, char * charv[])
{
    std::unique_ptr uni_point = Point::PointFactory::New_Cartesian_Unique_Pointer( getRandom(RANGE_START,RANGE_END), getRandom(RANGE_START,RANGE_END) );

    Point * classic_point = Point::PointFactory::create_new_cartesian_pointer( getRandom(RANGE_START,RANGE_END), getRandom(RANGE_START,RANGE_END) );

    delete classic_point;

  // Point some_point = PointFactory::NewCartesian(getRandom(RANGE_START,RANGE_END), getRandom(RANGE_START,RANGE_END));

    Singleton::get().some_function();

    return 0;
}
































