#ifndef FORKFLOW_WORLD_GRID_HPP
#define FORKFLOW_WORLD_GRID_HPP

#include <utility>

#include <boost/multi_array.hpp>

#include "metrics.hpp"

namespace forkflow::world {

template<typename Id>
class Grid {
public:
  explicit Grid(Metrics x_len, Metrics y_len, Metrics z_len) noexcept;

public:
  template<typename Self>
  auto operator()(this Self&& self, Metrics x, Metrics y, Metrics z) noexcept ->
    decltype(std::forward<Self>(self).iles_[x][y][z]);

private:
  boost::multi_array<Id, 3> iles_;
}; // class Grid

template<typename Id>
Grid<Id>::Grid(Metrics x_len, Metrics y_len, Metrics z_len) noexcept:
  iles_(boost::extents[x_len][y_len][z_len]) {}

template<typename Id>
template<typename Self>
auto Grid<Id>::operator()(this Self&& self, Metrics x, Metrics y, Metrics z) noexcept ->
    decltype(std::forward<Self>(self).iles_[x][y][z]) {
  return std::forward<Self>(self).iles_[x][y][z];
}

} // namespace forkflow::world

#endif // FORKFLOW_WORLD_GRID_HPP
