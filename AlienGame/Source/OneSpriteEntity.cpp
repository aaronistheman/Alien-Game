#include <Alien/Entities/OneSpriteEntity.hpp>

//OneSpriteEntity::OneSpriteEntity()
//{
//}

OneSpriteEntity::OneSpriteEntity(const sf::Vector2f & size)
  : mSprite(size)
{
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
