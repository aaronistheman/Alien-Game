#pragma once

/**
 * Based on version written by: Artur Moreira, Henrik Vogelius Hansson, and
 *   Jan Haller for their book "SFML Game Development"
 */


#include <SFML/System/Time.hpp>
#include <SFML/System/NonCopyable.hpp>
#include <SFML/Graphics/RenderWindow.hpp>


class Application : private sf::NonCopyable
{
public:
  Application();

  void run();

private:
  static const int WindowWidth;
  static const int WindowHeight;

  static const sf::Time TimePerFrame;

private:
  sf::RenderWindow mWindow;

}; // class Application
