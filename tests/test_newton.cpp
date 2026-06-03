#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_floating_point.hpp>
#include <models/Algebraic.h>
#include <ode/algebra/NewtonMethod.h>

TEST_CASE("Newton's method", "[newton]") {
  SECTION("Circle cubic") {
    autodiff::VectorXreal x(2);
    x << 1.0, 1.0;
    autodiff::VectorXreal solution = ODE::Algebra::NewtonMethod(x, CircleCubic);

    using Catch::Matchers::WithinAbs;
    constexpr double tol = 1e-6;

    // Tesing solution within tolerance
    REQUIRE_THAT(solution(0).val(), WithinAbs(0.826031, tol));
    REQUIRE_THAT(solution(1).val(), WithinAbs(0.563624, tol));
  }
}
