#ifndef FORKFLOW_WORLD_UNIT_HPP
#define FORKFLOW_WORLD_UNIT_HPP

#include "matter_id.hpp"

namespace forkflow::world {

class Unit {
public:
  explicit Unit(MatterId) noexcept;

public:
  MatterId matter() const noexcept;

private:
  MatterId matter_;
}; // class Unit

} // namespace forkflow::world

#endif // FORKFLOW_WORLD_UNIT_HPP
