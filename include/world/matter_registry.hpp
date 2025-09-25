#ifndef FORKFLOW_WORLD_MATTER_REGISTRY_HPP
#define FORKFLOW_WORLD_MATTER_REGISTRY_HPP

#include <array>
#include <memory>
#include <utility>

#include "matter.hpp"
#include "matter_id.hpp"

#include "math/pow.hpp"

namespace forkflow::world {

class MatterRegistry {
public:
  template<typename Self>
  auto&& operator[](this Self&& self, MatterId) noexcept;

public:
  void insert(MatterId, std::shared_ptr<Matter>) noexcept;
  void remove(MatterId) noexcept;

private:
  std::array<std::shared_ptr<Matter>, forkflow::math::pow(2, static_cast<int>(sizeof(MatterId)*8))> materials_;
}; // class MatterRegistry

template<typename Self>
auto&& MatterRegistry::operator[](this Self&& self, MatterId id) noexcept {
  return std::forward<Self>(self).materials_[static_cast<int>(id)];
}

} // namespace forkflow::world

#endif // FORKFLOW_WORLD_MATTER_REGISTRY_HPP
