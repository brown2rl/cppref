#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <memory>

using namespace std;

struct Renderer
{
  virtual void circle(float x, float y, float radius) = 0;
};

struct VectorRender : Renderer //implementation 1
{
  void circle(float x, float y, float radius) override
  {
    cout << "Drawing vector circle of radius " << radius << endl;
  }
};

struct RasterRender : Renderer //implementation 2
{
  void circle(float x, float y, float radius) override
  {
    cout << "Rasterizing circle of a radius " << endl;
  }
};

struct Shape // bridge between shapes and how rendered
{
  protected:
    Renderer &renderer; // ref to implementation
    Shape(Renderer& renderer) : renderer{renderer} 
    {
    }
  public:
    virtual void draw() = 0;
    virtual void resize(float factor) = 0;
};

struct Circle : Shape // interface
{
  float x, y, radius;

 Circle(Renderer& renderer, const float x, const float y, const float radius) : Shape{renderer}, x{x}, y{y}, radius{radius}
  {
  }

  void draw() override
  {
    renderer.circle(x,y,radius); // access implementation provided by shape base class
  }
  void resize(float factor) override
  {
    radius *= factor;
  }
};

int main()
{
 RasterRender r;
 VectorRender v;

 Circle Rcircle{ r , 10, 10, 5 };
 Rcircle.draw();
 Rcircle.resize(2);
 Rcircle.draw();

 Circle Vcircle { v, 10, 10, 5 };
 Vcircle.draw();
 Vcircle.resize(2);
 Vcircle.draw();

 return 0;
}
