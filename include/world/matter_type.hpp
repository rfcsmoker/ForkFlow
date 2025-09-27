#ifndef FORKFLOW_WORLD_MATTER_TYPE_HPP
#define FORKFLOW_WORLD_MATTER_TYPE_HPP

#include <cstdint>

namespace forkflow::world {

enum class MatterType: std::uint8_t {
  NONE = 0,
  SOIL = 1,
  UNIQUE = 255
}; // enum class MatterType

} // namespace forkflow::world

#endif // FORKFLOW_WORLD_MATTER_TYPE_HPP
