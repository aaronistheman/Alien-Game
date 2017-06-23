#pragma once

#include <SFML/System/Time.hpp>

class Entity
{
public:
  Entity();
  Entity(int posX, int posY);

  virtual void    update(sf::Time dt) = 0;

private:
  // position on SFML coordinate system
  int     mPosX;
  int     mPosY;
};