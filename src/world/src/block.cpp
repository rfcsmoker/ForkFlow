#include "world/block.hpp"

namespace forkflow::world {

Block::Block(MatterType matter) noexcept:
  matter_(matter) {}

MatterType
Block::matter() const noexcept {
  return matter_;
}

} // namespace forkflow::world
