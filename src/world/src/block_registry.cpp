#include "world/block_registry.hpp"

namespace forkflow::world {

void
BlockRegistry::insert(Coord3D at, std::shared_ptr<Block> block) noexcept {
  blocks_.insert({ at, std::move(block) });
}

void
BlockRegistry::remove(Coord3D at) noexcept {
  blocks_.erase(at);
}

} // namespace forkflow::world
