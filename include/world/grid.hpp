#ifndef FORKFLOW_WORLD_GRID_HPP
#define FORKFLOW_WORLD_GRID_HPP

#include <cstddef>
#include <utility>

#include <boost/multi_array.hpp>

#include "matter_type.hpp"
#include "metrics.hpp"

namespace forkflow::world {

class Grid {
public:
  explicit Grid(Metrics x_len, Metrics y_len, Metrics z_len) noexcept;

public:
  template<typename Self>
  auto operator()(this Self&& self, Metrics x, Metrics y, Metrics z) noexcept ->
    decltype(std::forward<Self>(self).iles_[x][y][z]);

private:
  boost::multi_array<MatterType, 3> iles_;
}; // class Grid

template<typename Self>
auto Grid::operator()(this Self&& self, Metrics x, Metrics y, Metrics z) noexcept ->
    decltype(std::forward<Self>(self).iles_[x][y][z]) {
  return std::forward<Self>(self).iles_[x][y][z];
}

} // namespace forkflow::world

#endif // FORKFLOW_WORLD_GRID_HPP
