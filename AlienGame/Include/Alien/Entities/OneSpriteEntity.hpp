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
  OneSpriteEntity();
  OneSpriteEntity(const sf::Vector2f& size);

  void      setSize(const sf::Vector2f& size);

protected:
  sf::RectangleShape      mSprite;

  void    centerOrigin();
};