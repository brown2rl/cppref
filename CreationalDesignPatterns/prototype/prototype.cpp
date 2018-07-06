#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <memory>

using namespace std;

//class HtmlBuilder;

class Point
{
  Point(const float x, const float y): x{x}, y{y}
   {
   }
  class PointFactory
  {
    public:
      static Point NewCart(const float x, const float y)
      {
         return { x, y};
      }

      static Point NewPolar(const float r, const float theta)
      {
         return { r*cos(theta), r*sin(theta) };
      }
  };
  public:
    float x,y;

    friend ostream& operator<<(ostream& os, const Point& obj)
    {
      return os << "x: " << obj.x << "  y: " << obj.y << endl;
    }

    static PointFactory Factory;
};

int main()
{
auto c = Point::Factory.NewCart(1,2);
cout << c << endl;
auto b = Point::Factory.NewPolar(90, 135);
cout << b << endl;
 //getchar()
 return 0;
}
