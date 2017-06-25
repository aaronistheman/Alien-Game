#include <Alien/Entities/OneSpriteEntity.hpp>

//OneSpriteEntity::OneSpriteEntity()
//{
//}

OneSpriteEntity::OneSpriteEntity(const sf::Vector2f & size)
  : mSprite(size)
{
  // Center the origin of the entity (primarily so that it'll rotate about its center).
  setOrigin(std::floor(size.x / 2.f), std::floor(size.y / 2.f));
}

const sf::Vector2f & OneSpriteEntity::getCenterPosition() const
{
  auto pos = getPosition();
  auto size = mSprite.getSize();
  return sf::Vector2f(pos.x + size.x / 2.f, pos.y + size.y / 2.f);
}

void OneSpriteEntity::setCenterPosition(float x, float y)
{
  auto size = mSprite.getSize();
  setPosition(x - size.x / 2.f, y - size.y / 2.f);
}

void OneSpriteEntity::setCenterPosition(const sf::Vector2f & position)
{
  setCenterPosition(position.x, position.y);
}
