#include "world/matter_registry.hpp"

namespace forkflow::world {

void
MatterRegistry::insert(MatterId id, std::shared_ptr<Matter> matter) noexcept {
  materials_[static_cast<int>(id)] = std::move(matter);
}

void
MatterRegistry::remove(MatterId id) noexcept {
  materials_[static_cast<int>(id)].reset();
}

} // namespace forkflow::world
