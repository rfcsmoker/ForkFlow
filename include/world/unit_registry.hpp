#ifndef FORKFLOW_WORLD_UNIT_REGISTRY_HPP
#define FORKFLOW_WORLD_UNIT_REGISTRY_HPP

#include <expected>
#include <memory>
#include <string>
#include <unordered_map>
#include <utility>

#include "unit.hpp"
#include "vector.hpp"

namespace forkflow::world {

class UnitRegistry {
public:
  template<typename Self>
  auto operator[](this Self&& self, Vector3D at) noexcept
    -> std::expected<decltype(*(std::forward<Self>(self).units_.find(at))->second), std::string>;

public:
  void insert(Vector3D, std::shared_ptr<Unit>) noexcept;
  void remove(Vector3D) noexcept;

private:
  std::unordered_map<Vector3D, std::shared_ptr<Unit>> units_;
}; // class UnitRegistry

template<typename Self>
auto UnitRegistry::operator[](this Self&& self, Vector3D at) noexcept
    -> std::expected<decltype(*(std::forward<Self>(self).units_.find(at))->second), std::string> {

  auto it = std::forward<Self>(self).units_.find(at);
  if (it == std::forward<Self>(self).units_.end())
    return std::unexpected("unit not found");
  return *it;
}

} // namespace forkflow::world

#endif // FORKFLOW_WORLD_UNIT_REGISTRY_HPP
