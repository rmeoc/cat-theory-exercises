
#include <iostream>
#include <memory>
#include <math.h>

int challenge2()
{
  class Shape
  {
    public:
      virtual ~Shape() {};
      virtual double area() = 0;
  };

  class Circle : public Shape
  {
      double _r;
    public:
      Circle(double r) : _r(r) {}
      virtual double area() { return M_PI * _r * _r; }
  };

  class Rect : public Shape
  {
      double _d, _h;
    public:
      Rect(double d, double h) : _d(d), _h(h) {}
      virtual double area() { return _d * _h; }
  };

  std::unique_ptr<Shape> circle(new Circle(11.0));
  std::unique_ptr<Shape> rect(new Rect(7.0, 4.0));

  std::cout << "Circle area: " << circle->area() << std::endl;
  std::cout << "Rectangle area: " << rect->area() << std::endl;
  return 0;
}

void challenge3()
{
  class Shape
  {
    public:
      virtual ~Shape() {};
      virtual double area() = 0;
      virtual double circ() = 0; /*TOUCHED*/
  };

  class Circle : public Shape
  {
      double _r;
    public:
      Circle(double r) : _r(r) {}
      virtual double area() { return M_PI * _r * _r; }
      virtual double circ() { return 2.0 * M_PI * _r; }; /*TOUCHED*/
  };

  class Rect : public Shape
  {
      double _d, _h;
    public:
      Rect(double d, double h) : _d(d), _h(h) {}
      virtual double area() { return _d * _h; }
      virtual double circ() { return 2 * (_d + _h); }; /*TOUCHED*/
  };

  std::unique_ptr<Shape> circle(new Circle(11.0));
  std::unique_ptr<Shape> rect(new Rect(7.0, 4.0));

  std::cout << "Circle area: " << circle->area() << std::endl;
  std::cout << "Rectangle area: " << rect->area() << std::endl;
  std::cout << "Circle circumference: " << circle->circ() << std::endl;  /*TOUCHED*/
  std::cout << "Rectangle circumference: " << rect->circ() << std::endl;  /*TOUCHED*/
}

void challenge4()
{
  class Shape
  {
    public:
      virtual ~Shape() {};
      virtual double area() = 0;
      virtual double circ() = 0;
  };

  class Circle : public Shape
  {
      double _r;
    public:
      Circle(double r) : _r(r) {}
      virtual double area() { return M_PI * _r * _r; }
      virtual double circ() { return 2.0 * M_PI * _r; };
  };

  class Rect : public Shape
  {
      double _d, _h;
    public:
      Rect(double d, double h) : _d(d), _h(h) {}
      virtual double area() { return _d * _h; }
      virtual double circ() { return 2 * (_d + _h); };
  };

  class Square : public Shape                   /* Touched */
  {                                             /* Touched */
      double _d;                                /* Touched */
    public:                                     /* Touched */
      Square(double d) : _d(d) {}               /* Touched */
      virtual double area() { return _d * _d; } /* Touched */
      virtual double circ() { return 4 * _d; }; /* Touched */
  };                                            /* Touched */

  std::unique_ptr<Shape> circle(new Circle(11.0));
  std::unique_ptr<Shape> rect(new Rect(7.0, 4.0));
  std::unique_ptr<Shape> square(new Square(5.0)); /* Touched */

  std::cout << "Circle area: " << circle->area() << std::endl;
  std::cout << "Rectangle area: " << rect->area() << std::endl;
  std::cout << "Square area: " << square->area() << std::endl; /* Touched */
  std::cout << "Circle circumference: " << circle->circ() << std::endl;
  std::cout << "Rectangle circumference: " << rect->circ() << std::endl;
  std::cout << "Square circumference: " << square->circ() << std::endl; /* Touched */
}

int main()
{
  std::cout << "--- Challenge 2 ---" << std::endl;
  challenge2();
  std::cout << "--- Challenge 3 ---" << std::endl;
  challenge3();
  std::cout << "--- Challenge 4 ---" << std::endl;
  challenge4();
  return 0;
}

