#ifndef FORKFLOW_WORLD_UNIT_HPP
#define FORKFLOW_WORLD_UNIT_HPP

#include "matter_type.hpp"

namespace forkflow::world {

class Unit {
public:
  explicit Unit(MatterType) noexcept;

public:
  MatterType matter() const noexcept;

private:
  MatterType matter_;
}; // class Unit

} // namespace forkflow::world

#endif // FORKFLOW_WORLD_UNIT_HPP
