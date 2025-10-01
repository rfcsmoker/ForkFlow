#ifndef FORKFLOW_WORLD_SPARSE_GRID_HPP
#define FORKFLOW_WORLD_SPARSE_GRID_HPP

#include <concepts>      // integral
#include <format>
#include <ranges>        // subrange
#include <stdexcept>     // invalid_argument
#include <unordered_map>

#include "coord.hpp"

namespace forkflow::world {

namespace rng = std::ranges;

template<std::integral Id>
class SparseGrid {
public:
  auto operator[](Coord3D) const noexcept;

public:
  void insert(Coord3D, Id);
  void remove(Id) noexcept;

private:
  std::unordered_multimap<Coord3D, Id> iles_;
  std::unordered_map<Id, Coord3D> index_;
}; // class SparseGrid

template<std::integral Id>
auto
SparseGrid<Id>::operator[](Coord3D at) const noexcept {
  auto [begin, end] = iles_.equal_range(at);
  return rng::subrange(begin, end);
}

template<std::integral Id>
void
SparseGrid<Id>::insert(Coord3D at, Id id) {

  if (index_.contains(id))
    throw std::invalid_argument(std::format("#{} already contains", id));

  iles_.insert({ at, id });
  index_.insert({ id, at });
}

template<std::integral Id>
void
SparseGrid<Id>::remove(Id id) noexcept {
  
  auto coordNode = index_.extract(id);
  if (coordNode.empty())
    return;

  const auto& coord = coordNode.mapped();
  auto [begin, end] = iles_.equal_range(coord);
  for (; begin != end; ++begin) {
    auto storedId = begin->second;
    if (storedId == id) {
      iles_.erase(begin);
      return;
    }
  }
}

} // namespace::world

#endif // FORKFLOW_WORLD_SPARSE_GRID_HPP
