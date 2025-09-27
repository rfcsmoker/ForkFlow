#ifndef FORKFLOW_WORLD_MATTER_HPP
#define FORKFLOW_WORLD_MATTER_HPP

namespace forkflow::world {

class Matter {
public:
  struct Properties {
    bool solid: 1;    // solid/transparent
    bool physical: 1; // physical/static
  }; // struct Properties

public:
  explicit Matter(Properties) noexcept;

public:
  const Properties& properties() const noexcept;

private:
  Properties properties_;
}; // class Matter

} // namespace forkflow::world

#endif // FORKFLOW_WORLD_MATTER_HPP
