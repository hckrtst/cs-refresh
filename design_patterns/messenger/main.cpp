#include <iostream>

using namespace std;

class Point {
public:
   float x, y ,z;
   Point(float x, float y, float z):x(x), y(y), z(z) {}
   Point(const Point& p):x(p.x), y(p.y), z(p.z) {}
   // only constructors can take base initializers
   Point& operator=(const Point& p) {
      x = p.x;
      y = p.y;
      z = p.z;
      return *this;
   }
   friend ostream&
   operator<<(ostream& os, const Point& p) {
      return os << "x = " << p.x << ", y = " <<
         p.y << ", z = " << p.z;
   }
};

class Vector {
public:
   int magnitude, direction;
   Vector(int m, int d):magnitude(m), direction(d) {}
};

class Space {
public:
   static Point translate(Point p, Vector v) {
      p.x += (float) (v.magnitude + v.direction);
      p.y += v.magnitude + v.direction;
      p.z += v.magnitude + v.direction;
      return p;
   }
};

int main() {
   Point p1(1, 2.5, 9.34);
   Point p2 = Space::translate(p1, Vector(19, -3));
   cout << "P1 = " << p1 << endl;
   cout << "P2 = " << p2 << endl;
   return 0;
}