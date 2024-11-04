#include "type.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <iostream>

Base* generate(void) {
  std::srand(static_cast<unsigned int>((std::chrono::steady_clock::now().time_since_epoch().count())));
  int randomValue = std::rand() % 3;
  switch (randomValue) {
  case 0: 
    std::cout << "A instance created" << std::endl;
    return new A();
  case 1: 
    std::cout << "B instance created" << std::endl;
    return new B();
  case 2:
    std::cout << "C instance created" << std::endl;
    return new C();
  default:
    std::cout << "Error: randomValue is " << randomValue << std::endl;
    return nullptr;
  }
}

void identify(Base* p) {
  if (dynamic_cast<A*>(p))
    std::cout << "instance of type A" << std::endl;
  else if (dynamic_cast<B*>(p))
    std::cout << "instance of type B" << std::endl;
  else if (dynamic_cast<C*>(p))
    std::cout << "instance of type C" << std::endl;
  else
    std::cout << "unknown type" << std::endl;
}

void identify(Base& p) {
  try {
    (void)dynamic_cast<A&>(p);
    std::cout << "instance of type A" << std::endl;
  } catch (const std::bad_cast&) {
    try {
      (void)dynamic_cast<B&>(p);
      std::cout << "instance of type B" << std::endl;
    } catch (const std::bad_cast&) {
      try {
        (void)dynamic_cast<C&>(p);
        std::cout << "instance of type C" << std::endl;
      } catch (const std::bad_cast&) {
        std::cout << "unknown type" << std::endl;
      }
    }
  }

}