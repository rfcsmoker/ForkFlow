#include "world/unit.hpp"

namespace forkflow::world {

Unit::Unit(MatterType matter) noexcept:
  matter_(matter) {}

MatterType
Unit::matter() const noexcept {
  return matter_;
}

} // namespace forkflow::world
