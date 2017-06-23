#pragma once

#include <SFML/System/Time.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RenderStates.hpp>


class Entity
{
public:
  Entity();
  Entity(int posX, int posY);

  virtual void    draw(sf::RenderTarget& target) const = 0;
  virtual void    update(sf::Time dt) = 0;

private:
  // position on SFML coordinate system
  int     mPosX;
  int     mPosY;
};