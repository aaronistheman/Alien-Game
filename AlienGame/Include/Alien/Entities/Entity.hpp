#pragma once

#include <SFML/System/Time.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RenderStates.hpp>


/**
 * A transformable (and thus, positionable),
 * drawable representation of any entity.
 */
class Entity : public sf::Transformable
{
public:
  Entity();

  virtual void    draw(sf::RenderTarget& target) const = 0;
  virtual void    update(sf::Time dt) = 0;

private:
  // position on SFML coordinate system
  int     mPosX;
  int     mPosY;
};