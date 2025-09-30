#ifndef FORKFLOW_CORE_REGISTRY_HPP
#define FORKFLOW_CORE_REGISTRY_HPP

#include <concepts>
#include <exception>
#include <expected>
#include <format>
#include <functional>
#include <memory>
#include <string>
#include <unordered_map>
#include <utility>

namespace forkflow::core {

template<std::integral Id, typename Object, typename IdManager>
class Registry {
public:
  explicit Registry(IdManager) noexcept;

public:
  std::expected<std::reference_wrapper<const Object>, std::string> operator[](Id) const noexcept;
  std::expected<std::reference_wrapper<Object>, std::string> operator[](Id) noexcept;

public:
  std::expected<Id, std::string> insert(std::unique_ptr<Object>) noexcept;
  void remove(Id) noexcept;

private:
  std::unordered_map<Id, std::unique_ptr<Object>> objects_;
  IdManager idMgr_;
}; // class Registry

template<std::integral Id, typename Object, typename IdManager>
Registry<Id, Object, IdManager>::Registry(IdManager idMgr) noexcept:
  idMgr_(std::move(idMgr)) {}

template<std::integral Id, typename Object, typename IdManager>
std::expected<std::reference_wrapper<const Object>, std::string>
Registry<Id, Object, IdManager>::operator[](Id id) const noexcept {
  auto it = objects_.find(id);
  if (it == objects_.end())
    return std::unexpected(std::format("{} #{} not found", Object::getClassName(), id));
  return std::cref(*(it->second));
}

template<std::integral Id, typename Object, typename IdManager>
std::expected<std::reference_wrapper<Object>, std::string>
Registry<Id, Object, IdManager>::operator[](Id id) noexcept {
  auto it = objects_.find(id);
  if (it == objects_.end())
    return std::unexpected(std::format("{} #{} not found", Object::getClassName(), id));
  return std::ref(*(it->second));
}

template<std::integral Id, typename Object, typename IdManager>
std::expected<Id, std::string>
Registry<Id, Object, IdManager>::insert(std::unique_ptr<Object> obj) noexcept {

  auto id = Id();
  try {
    id = idMgr_++;
  } catch (const std::exception& ex) {
    return std::unexpected(ex.what());
  }

  auto [it, inserted] = objects_.insert({ id, std::move(obj) });
  if (!inserted)
    return std::unexpected(std::format("{} was not inserted", Object::getClassName()));
  return id;
}

template<std::integral Id, typename Object, typename IdManager>
void
Registry<Id, Object, IdManager>::remove(Id id) noexcept {
  objects_.erase(id);
  idMgr_.release(id);
}

} // namespace forkflow::core

#endif // FORKFLOW_CORE_REGISTRY_HPP
