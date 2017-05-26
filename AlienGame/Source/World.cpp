#include <Alien/World/World.hpp>

#include <SFML/Graphics/RenderWindow.hpp>


World::World(sf::RenderWindow & window, FontHolder & fonts)
  : mWindow(window)
  , mWorldView(window.getDefaultView())
  , mTextures()
  , mFonts(fonts)
{

}
