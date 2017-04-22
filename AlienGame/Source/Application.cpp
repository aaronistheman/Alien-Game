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
  sf::Clock clock;
  sf::Time timeSinceLastUpdate = sf::Time::Zero;

  while (mWindow.isOpen())
  {
    sf::Time dt = clock.restart();
    timeSinceLastUpdate += dt;

    // Fixed time step
    while (timeSinceLastUpdate > TimePerFrame)
    {
      timeSinceLastUpdate -= TimePerFrame;

      processInput();
      update(TimePerFrame);
    }
    
    render();
  } // while window is open
} // run()


void Application::processInput()
{
  sf::Event event;
  while (mWindow.pollEvent(event))
  {
    if (event.type == sf::Event::Closed)
      mWindow.close();
  }
} // processInput()



void Application::render()
{
  mWindow.clear();
  mWindow.display();
} // render()


void Application::update(sf::Time dt)
{
  
} // update()
