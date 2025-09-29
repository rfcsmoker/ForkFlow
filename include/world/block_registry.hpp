#ifndef FORKFLOW_WORLD_BLOCK_REGISTRY_HPP
#define FORKFLOW_WORLD_BLOCK_REGISTRY_HPP

#include <expected>
#include <memory>
#include <string>
#include <unordered_map>
#include <utility>

#include "block.hpp"
#include "coord.hpp"

namespace forkflow::world {

class BlockRegistry {
public:
  template<typename Self>
  auto operator[](this Self&& self, Coord3D at) noexcept
    -> std::expected<decltype(std::forward<Self>(self).blocks_.find(at)->second), std::string>;

public:
  void insert(Coord3D, std::shared_ptr<Block>) noexcept;
  void remove(Coord3D) noexcept;

private:
  std::unordered_map<Coord3D, std::shared_ptr<Block>> blocks_;
}; // class BlockRegistry

template<typename Self>
auto BlockRegistry::operator[](this Self&& self, Coord3D at) noexcept
    -> std::expected<decltype(std::forward<Self>(self).blocks_.find(at)->second), std::string> {

  auto it = std::forward<Self>(self).blocks_.find(at);
  if (it == std::forward<Self>(self).blocks_.end())
    return std::unexpected("block not found");
  return it->second;
}

} // namespace forkflow::world

#endif // FORKFLOW_WORLD_BLOCK_REGISTRY_HPP
