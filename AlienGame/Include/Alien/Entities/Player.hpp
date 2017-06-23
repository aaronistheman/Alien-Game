#pragma once

#include <Alien/Entities/Entity.hpp>


class Player : public Entity
{
public:
  Player();

  void      update(sf::Time dt)   final;


};