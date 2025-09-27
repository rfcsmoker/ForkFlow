#include "world/grid.hpp"

namespace forkflow::world {

Grid::Grid(std::size_t x_len, std::size_t y_len, std::size_t z_len) noexcept:
  iles_(boost::extents[x_len][y_len][z_len]) {}

} // namespace forkflow::world
