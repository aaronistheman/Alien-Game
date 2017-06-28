#pragma once

#include <Alien/Entities/Entity.hpp>
#include <Alien/Entities/OneSpriteEntity.hpp>


/**
 * Representation of a main player entity that is limited in how it can be subclassed.
 */
class Player : public OneSpriteEntity
{
public:
  Player();
  Player(const sf::Vector2f& size);

  void      draw(sf::RenderTarget& target) const final;
  void      update(sf::Time dt)   final;

  Type      getType() final;

private:
  static  float   RotationSpeed; // degrees per second
};