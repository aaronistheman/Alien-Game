#include <Alien/Application.hpp>

#include <SFML/Window/Event.hpp>


const int Application::WindowWidth = 1200;
const int Application::WindowHeight = 600;
const sf::Time Application::TimePerFrame = sf::seconds(1.f / 60.f);


Application::Application()
  : mWindow(sf::VideoMode(WindowWidth, WindowHeight),
    "Alien Game", sf::Style::Close)
  , mFonts()
  , mStatisticsText()
  , mStatisticsUpdateTime()
  , mStatisticsNumFrames(0)
{
  mWindow.setKeyRepeatEnabled(false);

  mFonts.load(Fonts::Main, "Media/Sansation.ttf");

  mStatisticsText.setFont(mFonts.get(Fonts::Main));
  mStatisticsText.setPosition(5.f, 5.f);
  mStatisticsText.setCharacterSize(10u);
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

    updateFramerateStatistics(dt);
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
  mWindow.draw(mStatisticsText);
  mWindow.display();
} // render()


void Application::update(sf::Time dt)
{
  
} // update()


void Application::updateFramerateStatistics(sf::Time dt)
{
  mStatisticsUpdateTime += dt;
  mStatisticsNumFrames += 1;

  // Only print the number of frames once per second
  if (mStatisticsUpdateTime >= sf::seconds(1.0f))
  {
    mStatisticsText.setString("FPS: " + std::to_string(mStatisticsNumFrames));

    mStatisticsUpdateTime -= sf::seconds(1.0f);
    mStatisticsNumFrames = 0;
  }
} // updateFramerateStatistics()
