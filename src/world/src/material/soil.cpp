#include "world/material/soil.hpp"

namespace forkflow::world::material {

Soil::Soil() noexcept:
  forkflow::world::Matter({
    .solid=true
  , .physical=false
  }) {}

} // forkflow::world::material
