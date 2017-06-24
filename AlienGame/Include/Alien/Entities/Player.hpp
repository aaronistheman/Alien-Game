#pragma once

#include <Alien/Entities/Entity.hpp>
#include <Alien/Entities/OneSpriteEntity.hpp>


class Player : public OneSpriteEntity
{
public:
  Player();

  void      draw(sf::RenderTarget& target) const final;
  void      update(sf::Time dt)   final;

private:
  // nothing yet, please check again later
};