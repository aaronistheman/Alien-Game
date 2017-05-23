#pragma once

/**
 * Based on version written by: Artur Moreira, Henrik Vogelius Hansson, and
 *   Jan Haller for their book "SFML Game Development"
 */


#include <SFML/System/Time.hpp>
#include <SFML/System/NonCopyable.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Text.hpp>

#include <Alien/States/StateStack.hpp>
#include <Alien/Utility/ResourceIdentifiers.hpp>
#include <Alien/Utility/ResourceHolder.hpp>


class Application : private sf::NonCopyable
{
public:
  Application();

  void run();

private:
  void          chooseWindowSize();

  void          processInput();
  void          render();
  void          update(sf::Time dt);

  void          updateFramerateStatistics(sf::Time dt);
  void          registerStates();

private:

  static const sf::Time TimePerFrame;

private:
  sf::RenderWindow    mWindow;
  int                 mWindowHeight;
  int                 mWindowWidth;

  TextureHolder			mTextures;
  FontHolder        mFonts;

  StateStack				mStateStack;

  // For showing frame rate statistics
  sf::Text				mStatisticsText;
  sf::Time				mStatisticsUpdateTime;
  std::size_t				mStatisticsNumFrames;
}; // class Application
