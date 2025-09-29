#include "world/grid.hpp"

namespace forkflow::world {

Grid::Grid(Metrics x_len, Metrics y_len, Metrics z_len) noexcept:
  iles_(boost::extents[x_len][y_len][z_len]) {}

} // namespace forkflow::world
