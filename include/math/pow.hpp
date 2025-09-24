#ifndef FORKFLOW_MATH_POW_HPP
#define FORKFLOW_MATH_POW_HPP

#include <concepts>

namespace forkflow::math {

template<std::integral T>
constexpr T pow(T base, T n) noexcept {

  if (n == 0)
    return 1;

  if (n == 1)
    return base;

  auto r = base;
  for (auto i = 1; i < n; ++i)
    r *= base;
  return r;
}

} // namespace forkflow::math

#endif // FORKFLOW_MATH_POW_HPP
