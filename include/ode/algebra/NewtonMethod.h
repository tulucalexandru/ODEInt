#pragma once

#include <Eigen/Core>
#include <Eigen/src/LU/PartialPivLU.h>
#include <autodiff/forward/real/eigen.hpp>
#include <autodiff/forward/real/real.hpp>

namespace ODE {
namespace Algebra {

template <typename Fun>
autodiff::VectorXreal NewtonMethod(autodiff::VectorXreal &x,
                                   const Fun &myFunction) {
  autodiff::VectorXreal x_new;
  autodiff::VectorXreal x_old = x;
  double error = 1;
  double tol = 1e-7;
  int max_iter = 100, iter = 0;

  autodiff::VectorXreal residual;
  autodiff::MatrixXreal J;
  autodiff::VectorXreal dummy_y;

  while (error > tol && iter < max_iter) {
    residual = myFunction(x_old);

    error = residual.norm().val();
    std::cout << "Iteration: " << iter
              << " | Residual F(X): " << residual.norm().val() << std::endl;

    autodiff::jacobian(myFunction, wrt(x_old), at(x_old), dummy_y, J);

    autodiff::VectorXreal delta_x = J.partialPivLu().solve(-residual);
    x_new = x_old + delta_x;

    x_old = x_new;
    iter++;
  }
  return x_new;
}

} // namespace Algebra
} // namespace ODE
