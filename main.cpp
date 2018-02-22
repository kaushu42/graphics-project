#include "containers.h"
int main(int argc, char const *argv[]) {//
  Matrix44f a(1, 2, 3, 0,
              4, 5, 6, 0,
              7, 8, 9, 0,
              0, 0, 0, 1);
  Vec3f v(1, 2, 3);
  std::cout << a << std::endl;
  std::cout << v << std::endl;
  std::cout << a*v << std::endl;
  return 0;
}
