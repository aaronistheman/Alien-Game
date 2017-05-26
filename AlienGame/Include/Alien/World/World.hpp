#pragma once

/**
 * Based on version written by: Artur Moreira, Henrik Vogelius Hansson, and
 *   Jan Haller for their book "SFML Game Development"
 */


#include <Alien/Utility/ResourceHolder.hpp>
#include <Alien/Utility/ResourceIdentifiers.hpp>

#include <SFML/System/NonCopyable.hpp>
#include <SFML/Graphics/View.hpp>

// Forward declaration
namespace sf
{
  class RenderWindow;
}


class World : private sf::NonCopyable
{
public:
  World(sf::RenderWindow& window, FontHolder& fonts);

private:
  sf::RenderWindow&       mWindow;
  sf::View                mWorldView;
  TextureHolder           mTextures;
  FontHolder&             mFonts;
  

};