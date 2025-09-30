#ifndef FORKFLOW_CORE_ID_MANAGER_HPP
#define FORKFLOW_CORE_ID_MANAGER_HPP

#include <algorithm>    // min
#include <concepts>     // integral
#include <cstddef>
#include <set>
#include <stdexcept>    // overflow_error

#include "math/pow.hpp" // pow

namespace forkflow::core {

template<std::integral Id>
class IdManager {
public:
  static constexpr std::size_t MAX_ID = forkflow::math::pow(2, sizeof(Id)*8);

public:
  IdManager(Id) noexcept;

public:
  operator Id() const noexcept;

  IdManager operator++();
  IdManager operator++(int);

public:
  void release(Id) noexcept;

private:
  Id curId_;
  std::set<Id> releasedTree_;
}; // class IdManager

template<std::integral Id>
IdManager<Id>::IdManager(Id id) noexcept:
  curId_(id)
, releasedTree_() {}

template<std::integral Id>
IdManager<Id>::operator Id() const noexcept {
  return curId_;
}

template<std::integral Id>
IdManager<Id>
IdManager<Id>::operator++() {

  if (!releasedTree_.empty())
    return releasedTree_.extract(releasedTree_.begin()).value();

  if (curId_ == MAX_ID)
    throw std::overflow_error("identifiers range exhausted");

  ++curId_;
  return curId_;
}

template<std::integral Id>
IdManager<Id>
IdManager<Id>::operator++(int) {
  auto curId = curId_;
  auto nextId = static_cast<Id>(++(*this));
  return std::min(curId, nextId); // Released IDs always lower
}

template<std::integral Id>
void
IdManager<Id>::release(Id id) noexcept {
  releasedTree_.insert(id);
}

} // namespace forkflow::core

#endif // FORKFLOW_CORE_ID_MANAGER_HPP
