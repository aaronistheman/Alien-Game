#pragma once

/**
 * Based on version written by: Artur Moreira, Henrik Vogelius Hansson, and
 *   Jan Haller for their book "SFML Game Development"
 */


#include <Alien/Utility/ResourceHolder.hpp>
#include <Alien/Utility/ResourceIdentifiers.hpp>
#include <Alien/Entities/Player.hpp>

#include <SFML/System/NonCopyable.hpp>
#include <SFML/Graphics/View.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Time.hpp>

// Forward declaration
namespace sf
{
  class RenderWindow;
}


class World : private sf::NonCopyable
{
public:
  World(sf::RenderWindow& window, FontHolder& fonts);

  void                  draw();
  void                  update(sf::Time dt);
  void                  updateEntities(sf::Time dt);

private: // private methods

  void              calculatePixelsPerWorldUnit(const sf::Vector2u& windowSize);

private:  // private static members

  // Dimensions of the world in "game units" (these units DO NOT change according to
  // the window size).
  static int         Width;
  static int         Height;

private:  // private members
  sf::RenderWindow&       mWindow;
  sf::View                mWorldView;
  TextureHolder           mTextures;
  FontHolder&             mFonts;
  
  // For converting any length/speed/etc in units of window pixels to be in "game units".
  int                     mWidthPixelsPerWorldUnit;
  int                     mHeightPixelsPerWorldUnit;

  Player                  mPlayer;
};