#include "world/matter_registry.hpp"

namespace forkflow::world {

votype
MatterRegistry::insert(MatterType type, std::shared_ptr<Matter> matter) noexcept {
  materials_[static_cast<int>(type)] = std::move(matter);
}

votype
MatterRegistry::remove(MatterType type) noexcept {
  materials_[static_cast<int>(type)].reset();
}

} // namespace forkflow::world
