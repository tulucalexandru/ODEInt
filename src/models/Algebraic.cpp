#include <autodiff/forward/real/eigen.hpp>
#include <models/Algebraic.h>

autodiff::VectorXreal CircleCubic(const autodiff::VectorXreal &x) {
  autodiff::VectorXreal y(2);
  y(0) = x(0) * x(0) + x(1) * x(1) - 1.0;
  y(1) = x(0) * x(0) * x(0) - x(1);

  return y;
}
