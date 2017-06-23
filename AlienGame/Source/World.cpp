#include <Alien/World/World.hpp>

#include <SFML/Graphics/RenderWindow.hpp>


World::World(sf::RenderWindow & window, FontHolder & fonts)
  : mWindow(window)
  , mWorldView(window.getDefaultView())
  , mTextures()
  , mFonts(fonts)
  , mPlayer()
{

}

void World::update(sf::Time dt)
{
  updateEntities(dt);
}

void World::updateEntities(sf::Time dt)
{
  // update enemies

  // update player based on real-time inputs
  mPlayer.update(dt);
}
