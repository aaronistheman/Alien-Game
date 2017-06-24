#include <Alien/Entities/OneSpriteEntity.hpp>

//OneSpriteEntity::OneSpriteEntity()
//{
//}

OneSpriteEntity::OneSpriteEntity(const sf::Vector2f & size)
  : mSprite(size)
{
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
