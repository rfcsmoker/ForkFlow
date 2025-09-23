#include "world/space3d.hpp"

namespace forkflow::world {

Space3D::Space3D(std::size_t x_len, std::size_t y_len, std::size_t z_len) noexcept:
  iles_(boost::extents[x_len][y_len][z_len]) {}

} // namespace forkflow::world
