
#include "includes.h"
#include "singleton.h"
#include "builder.h"
#include "prototype.h"

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


//abstract factory

//class HotDrink
//{
//public:
//    virtual void prepare( const short volume ) = 0;
//};

//class Tea : HotDrink
//{
//    void prepare( const short volume ) override
//    {
//        std::cout << "Take a tea bag, boil water, pour " << volume << " ml, add some limon.\n";
//    }
//};

//class Coffee : HotDrink
//{
//    void prepare( const short volume ) override
//    {
//        std::cout << "Take a coffee dose, boil water, pour " << volume << " ml, add some sugar.\n";
//    }
//};

//class HotDrinkFactory  //abstract factory
//{
//public:
//    virtual std::unique_ptr<HotDrink> make() const = 0;
//};

//class CoffeeFactory : HotDrinkFactory
//{
//    std::unique_ptr<HotDrink> make() const override
//    {
//        return std::make_unique<Coffee>();
//    }
//};

//class TeaFactory : HotDrinkFactory
//{
//    std::unique_ptr<HotDrink> make() const override
//    {
//        return std::make_unique<Tea>();
//    }
//};

//class DrinkFactory
//{
//    std::map< std::string, std::unique_ptr<HotDrinkFactory>> m_hot_factories;

//public:
//    DrinkFactory()
//    {
//        m_hot_factories["coffee"] = std::make_unique<CoffeeFactory>();
//        m_hot_factories["tea"] = std::make_unique<TeaFactory>();
//    }

//    std::unique_ptr<HotDrink> make_drink( const std::string & name)
//    {
//        auto drink = m_hot_factories[name]->make();
//        drink->prepare(200);
//        return drink;
//    }
//};

int main( int charc, char * charv[])
{
    std::unique_ptr uni_point = Point::PointFactory::New_Cartesian_Unique_Pointer( getRandom(RANGE_START,RANGE_END), getRandom(RANGE_START,RANGE_END) );

    Point * classic_point = Point::PointFactory::create_new_cartesian_pointer( getRandom(RANGE_START,RANGE_END), getRandom(RANGE_START,RANGE_END) );

    delete classic_point;

  // Point some_point = PointFactory::NewCartesian(getRandom(RANGE_START,RANGE_END), getRandom(RANGE_START,RANGE_END));

    Singleton::get().some_function();

    //HtmlBuilder builder{"ul"};
    auto builder = HtmlBuilder::HtmlElement::build("ul");
    builder->add_child("1", "hello");
    builder->add_child("2", "world");
    builder->add_child_chained("3","chained").add_child_chained("4","test");
    builder->add_child_chained_arrow_operator("5","arrow")->add_child_chained_arrow_operator("6","opperator");
    std::cout << builder->echo();

    Contact worker{"",new Address{"123 East", "London", 0}}; //a prototype of worker is created
    Contact mr_jhon{worker};  //new worker created by prototype
    mr_jhon.name = "Mr. Jhon";
    mr_jhon.address->suite = 11;

    return 0;
}
































