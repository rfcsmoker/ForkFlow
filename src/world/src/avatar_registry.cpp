#include <format>
#include <stdexcept>

#include "world/avatar.hpp"
#include "world/avatar_registry.hpp"

namespace forkflow::world {

std::expected<std::reference_wrapper<const Avatar>, std::string>
AvatarRegistry::operator[](Id id) const noexcept {
  auto it = avatars_.find(id);
  if (it == avatars_.end())
    return std::unexpected(std::format("avatar #{} not found", id));
  return std::cref(*(it->second));
}

std::expected<std::reference_wrapper<Avatar>, std::string>
AvatarRegistry::operator[](Id id) noexcept {
  auto it = avatars_.find(id);
  if (it == avatars_.end())
    return std::unexpected(std::format("avatar #{} not found", id));
  return std::ref(*(it->second));
}

void
AvatarRegistry::insert(Id id, std::unique_ptr<Avatar> avatar) {
  auto [it, inserted] = avatars_.insert({ id, std::move(avatar) });
  if (!inserted)
    throw std::invalid_argument(std::format("avatar #{} already exist", id));
}

void
AvatarRegistry::remove(Id id) noexcept {
  avatars_.erase(id);
}

} // namespace forkflow::world
