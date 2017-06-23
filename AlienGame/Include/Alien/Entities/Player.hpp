#pragma once

#include <Alien/Entities/Entity.hpp>

#include <SFML/Graphics/RectangleShape.hpp>


class Player : public Entity
{
public:
  Player();

  void      draw(sf::RenderTarget& target) const final;
  void      update(sf::Time dt)   final;

private:
  sf::RectangleShape      mSprite;
};