#ifndef FORKFLOW_WORLD_SPACE3D_HPP
#define FORKFLOW_WORLD_SPACE3D_HPP

#include <cstddef>
#include <utility>

#include <boost/multi_array.hpp>

#include "matter_id.hpp"

namespace forkflow::world {

class Space3D {
public:
  explicit Space3D(std::size_t x_len, std::size_t y_len, std::size_t z_len) noexcept;

public:
  template<typename Self>
  auto operator()(this Self&& self, std::size_t x, std::size_t y, std::size_t z) noexcept ->
    decltype(std::forward<Self>(self).iles_[x][y][z]);

private:
  boost::multi_array<MatterId, 3> iles_;
}; // class Space3D

template<typename Self>
auto Space3D::operator()(this Self&& self, std::size_t x, std::size_t y, std::size_t z) noexcept ->
    decltype(std::forward<Self>(self).iles_[x][y][z]) {
  return std::forward<Self>(self).iles_[x][y][z];
}

} // namespace forkflow::world

#endif // FORKFLOW_WORLD_SPACE3D_HPP
