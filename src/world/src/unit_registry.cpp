#include "world/unit_registry.hpp"

namespace forkflow::world {

void
UnitRegistry::insert(Vector3D at, std::shared_ptr<Unit> unit) noexcept {
  units_.insert({ at, std::move(unit) });
}

void
UnitRegistry::remove(Vector3D at) noexcept {
  units_.erase(at);
}

} // namespace forkflow::world
