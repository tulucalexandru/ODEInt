#include "autodiff/forward/real/eigen.hpp"
#include "models/Algebraic.h"
#include "ode/algebra/NewtonMethod.h"
#include <iostream>

int main(int argc, char *argv[]) {
  autodiff::VectorXreal x(2);
  x << 1.0, 1.0;
  autodiff::VectorXreal solution = ODE::Algebra::NewtonMethod(x, CircleCubic);
  std::cout << "Solution: " << solution << std::endl;
  return 0;
}
