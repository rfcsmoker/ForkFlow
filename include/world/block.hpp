#ifndef FORKFLOW_WORLD_BLOCK_HPP
#define FORKFLOW_WORLD_BLOCK_HPP

#include "matter_type.hpp"

namespace forkflow::world {

class Block {
public:
  explicit Block(MatterType) noexcept;

public:
  MatterType matter() const noexcept;

private:
  MatterType matter_;
}; // class Block

} // namespace forkflow::world

#endif // FORKFLOW_WORLD_BLOCK_HPP
