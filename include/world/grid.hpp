#ifndef FORKFLOW_WORLD_GRID_HPP
#define FORKFLOW_WORLD_GRID_HPP

#include <utility>

#include <boost/multi_array.hpp>

#include "coord.hpp"
#include "metrics.hpp"

namespace forkflow::world {

template<typename Id>
class Grid {
public:
  explicit Grid(Metrics x_len, Metrics y_len, Metrics z_len) noexcept;

public:
  template<typename Self>
  auto operator[](this Self&& self, Coord3D at) noexcept
    -> decltype(std::forward<Self>(self).iles_[at.a[0]][at.a[1]][at.a[2]]);

private:
  boost::multi_array<Id, 3> iles_;
}; // class Grid

template<typename Id>
Grid<Id>::Grid(Metrics x_len, Metrics y_len, Metrics z_len) noexcept:
  iles_(boost::extents[x_len][y_len][z_len]) {}

template<typename Id>
template<typename Self>
auto Grid<Id>::operator[](this Self&& self, Coord3D at) noexcept
    -> decltype(std::forward<Self>(self).iles_[at.a[0]][at.a[1]][at.a[2]]) {
  const auto& [x, y, z] = at.a;
  return std::forward<Self>(self).iles_[x][y][z];
}

} // namespace forkflow::world

#endif // FORKFLOW_WORLD_GRID_HPP
