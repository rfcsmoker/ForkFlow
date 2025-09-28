#include "world/block_registry.hpp"

namespace forkflow::world {

void
BlockRegistry::insert(Vector3D at, std::shared_ptr<Block> block) noexcept {
  blocks_.insert({ at, std::move(block) });
}

void
BlockRegistry::remove(Vector3D at) noexcept {
  blocks_.erase(at);
}

} // namespace forkflow::world
