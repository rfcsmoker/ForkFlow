#include "world/unit.hpp"

namespace forkflow::world {

Unit::Unit(MatterId matter) noexcept:
  matter_(matter) {}

MatterId
Unit::matter() const noexcept {
  return matter_;
}

} // namespace forkflow::world
