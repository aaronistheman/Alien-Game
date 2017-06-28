#include <Alien/Entities/OneSpriteEntity.hpp>


OneSpriteEntity::OneSpriteEntity()
{
}

OneSpriteEntity::OneSpriteEntity(const sf::Vector2f & size)
{
  setSize(size);
}

void OneSpriteEntity::centerOrigin()
{
  auto size = mSprite.getSize();

  // Center the origin of the entity (primarily so that it'll rotate about its center).
  setOrigin(std::floor(size.x / 2.f), std::floor(size.y / 2.f));
}

void OneSpriteEntity::setSize(const sf::Vector2f & size)
{
  mSprite.setSize(size);
  centerOrigin();
}
