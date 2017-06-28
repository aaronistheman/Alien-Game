#include <Alien/World/World.hpp>

#include <SFML/Graphics/RenderWindow.hpp>

#include <iostream>


int World::Width = 30;
int World::Height = World::Width / 2;


World::World(sf::RenderWindow & window, FontHolder & fonts)
  : mWindow(window)
  , mWorldView(window.getDefaultView())
  , mTextures()
  , mFonts(fonts)
  , mPlayer()
  , mEntityDimensionsInGameUnits()
{
  calculatePixelsPerWorldUnit(window.getSize());
  // std::cout << "width pixels per world unit: " << mWidthPixelsPerWorldUnit << '\n';
  // std::cout << "height ...: " << mHeightPixelsPerWorldUnit << '\n';

  fillEntityDimensions();

  // mPlayer.setSize(sf::Vector2f(50.f, 50.f));
  auto sizeInGameUnits = mEntityDimensionsInGameUnits[mPlayer.getType()];
  sizeInGameUnits.x *= mWidthPixelsPerWorldUnit;
  sizeInGameUnits.y *= mHeightPixelsPerWorldUnit;
  mPlayer.setSize(sizeInGameUnits);

  // Put player at center of the window
  auto windowPos = window.getSize();
  mPlayer.setPosition(windowPos.x / 2, windowPos.y / 2);
}

void World::draw()
{
  mPlayer.draw(mWindow);
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

void World::calculatePixelsPerWorldUnit(const sf::Vector2u & windowSize)
{
  mWidthPixelsPerWorldUnit = windowSize.x / Width;
  mHeightPixelsPerWorldUnit = windowSize.y / Height;
}

// For deciding how to insert into the map:
// https://stackoverflow.com/questions/4286670/preferred-idiomatic-way-to-insert-into-a-map
void World::fillEntityDimensions()
{
  mEntityDimensionsInGameUnits.insert(
    EntityDimensionsMap::value_type(Entity::Type::Player, sf::Vector2f(7.5f, 7.5f)));
}
