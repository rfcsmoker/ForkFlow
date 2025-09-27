#ifndef FORKFLOW_WORLD_MATTER_ID_HPP
#define FORKFLOW_WORLD_MATTER_ID_HPP

#include <cstdint>

namespace forkflow::world {

enum class MatterId: std::uint8_t {
  NONE = 0,
  SOIL = 1,
  UNIQUE = 255
}; // enum class MatterId

} // namespace forkflow::world

#endif // FORKFLOW_WORLD_MATTER_ID_HPP
