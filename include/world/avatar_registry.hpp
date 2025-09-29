#ifndef FORKFLOW_WORLD_AVATAR_REGISTRY_HPP
#define FORKFLOW_WORLD_AVATAR_REGISTRY_HPP

#include <expected>
#include <functional>
#include <memory>
#include <string>
#include <unordered_map>

#include "id.hpp"

namespace forkflow::world {

class Avatar;

class AvatarRegistry {
public:
  std::expected<std::reference_wrapper<const Avatar>, std::string> operator[](Id) const noexcept;
  std::expected<std::reference_wrapper<Avatar>, std::string> operator[](Id) noexcept;

public:
  void insert(Id, std::unique_ptr<Avatar>);
  void remove(Id) noexcept;

private:
  std::unordered_map<Id, std::unique_ptr<Avatar>> avatars_;
}; // class AvatarRegistry

} // namespace forkflow::world

#endif // FORKFLOW_WORLD_AVATAR_REGISTRY_HPP
