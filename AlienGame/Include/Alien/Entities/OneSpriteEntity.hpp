#pragma once

#include <Alien/Entities/Entity.hpp>

#include <SFML/Graphics/RectangleShape.hpp>

/**
 * An entity extended with the assumption that it will only
 * be represented with one sprite.
 */
class OneSpriteEntity : public Entity
{
public:
  //OneSpriteEntity();
  OneSpriteEntity(const sf::Vector2f& size);

  const sf::Vector2f&     getCenterPosition() const;

  // Because SFML's Transformable::setPosition() sets the position
  // of the top-left coordinate, we have these for setting position
  // of the center (for cases where it's more convenient).
  void setCenterPosition(float x, float y);
  void setCenterPosition(const sf::Vector2f& position);

protected:
  sf::RectangleShape      mSprite;
};