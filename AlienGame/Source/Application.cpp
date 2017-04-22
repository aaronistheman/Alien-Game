#include <Alien/Application.hpp>

#include <SFML/Window/Event.hpp>


const int Application::WindowWidth = 1200;
const int Application::WindowHeight = 600;
const sf::Time Application::TimePerFrame = sf::seconds(1.f / 60.f);


Application::Application()
  : mWindow(sf::VideoMode(WindowWidth, WindowHeight),
    "Alien Game", sf::Style::Close)
{
  mWindow.setKeyRepeatEnabled(false);
  
} // Application()



void Application::run()
{
  while (mWindow.isOpen())
  {
    sf::Event event;
    while (mWindow.pollEvent(event))
    {
      if (event.type == sf::Event::Closed)
        mWindow.close();
    }
  } // while window is open
} // run()
