#ifndef FORKFLOW_MATH_VECTOR_HPP
#define FORKFLOW_MATH_VECTOR_HPP

#include <cstddef>

#include <boost/container_hash/hash.hpp>
#include <boost/qvm/vec.hpp>
#include <boost/qvm/vec_operations.hpp>

namespace forkflow::math {

template <typename T>
using Vector3D = boost::qvm::vec<T, 3>;

} // namespace forkflow::math

namespace std {

template<typename T>
struct hash<forkflow::math::Vector3D<T>> {
  std::size_t operator()(const forkflow::math::Vector3D<T>& vec) const {
    auto seed = std::size_t(0);
    for (auto i = 0; i < 3; ++i)
      boost::hash_combine(seed, vec.a[i]);
    return seed;
  }
}; // struct hash<forkflow::math::Vector3D<T>>

} // namespace std

#endif // FORKFLOW_MATH_VECTOR_HPP
