#pragma once

/**
 * Based on version written by: Artur Moreira, Henrik Vogelius Hansson, and
 *   Jan Haller for their book "SFML Game Development"
 */


#include <SFML/System/Time.hpp>
#include <SFML/System/NonCopyable.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Text.hpp>


class Application : private sf::NonCopyable
{
public:
  Application();

  void run();

private:
  void processInput();
  void render();
  void update(sf::Time dt);

  void  updateFramerateStatistics(sf::Time dt);

private:
  static const int WindowWidth;
  static const int WindowHeight;

  static const sf::Time TimePerFrame;

private:
  sf::RenderWindow mWindow;

  // For showing frame rate statistics
  sf::Font mStatisticsFont;
  sf::Text				mStatisticsText;
  sf::Time				mStatisticsUpdateTime;
  std::size_t				mStatisticsNumFrames;
}; // class Application
