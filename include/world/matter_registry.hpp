#ifndef FORKFLOW_WORLD_MATTER_REGISTRY_HPP
#define FORKFLOW_WORLD_MATTER_REGISTRY_HPP

#include <array>
#include <memory>
#include <utility>

#include "matter.hpp"
#include "matter_type.hpp"

#include "math/pow.hpp"

namespace forkflow::world {

class MatterRegistry {
public:
  template<typename Self>
  auto&& operator[](this Self&& self, MatterType) noexcept;

public:
  void insert(MatterType, std::shared_ptr<Matter>) noexcept;
  void remove(MatterType) noexcept;

private:
  std::array<std::shared_ptr<Matter>, forkflow::math::pow(2, static_cast<int>(sizeof(MatterType)*8))> materials_;
}; // class MatterRegistry

template<typename Self>
auto&& MatterRegistry::operator[](this Self&& self, MatterType type) noexcept {
  return std::forward<Self>(self).materials_[static_cast<int>(type)];
}

} // namespace forkflow::world

#endif // FORKFLOW_WORLD_MATTER_REGISTRY_HPP
