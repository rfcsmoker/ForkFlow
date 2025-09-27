#include "world/matter.hpp"

namespace forkflow::world {

Matter::Matter(Properties properties) noexcept:
  properties_(properties) {}

const Matter::Properties&
Matter::properties() const noexcept {
  return properties_;
}

} // namespace forkflow::world
