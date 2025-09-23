#ifndef FORKFLOW_MATH_VECTOR_HPP
#define FORKFLOW_MATH_VECTOR_HPP

#include <boost/qvm/vec.hpp>

namespace forkflow::math {

template <typename T>
using Vector3D = boost::qvm::vec<T, 3>;

} // namespace forkflow::math

#endif // FORKFLOW_MATH_VECTOR_HPP
