#ifndef FORKFLOW_WORLD_MATERIAL_SOIL_HPP
#define FORKFLOW_WORLD_MATERIAL_SOIL_HPP

#include "world/matter.hpp"

namespace forkflow::world::material {

class Soil: public forkflow::world::Matter {
public:
  explicit Soil() noexcept;
}; // class Soil

} // namespace forkflow::world::material

#endif // FORKFLOW_WORLD_MATERIAL_SOIL_HPP
