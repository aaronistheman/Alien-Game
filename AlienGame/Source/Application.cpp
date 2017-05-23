#include <Alien/Application.hpp>
#include <Alien/States/GameState.hpp>

#include <SFML/Window/Event.hpp>


//const int Application::WindowWidth = 1200;
//const int Application::WindowHeight = 600;
const sf::Time Application::TimePerFrame = sf::seconds(1.f / 60.f);


Application::Application()
  : mWindow()
  , mTextures()
  , mFonts()
  , mStateStack(State::Context(mWindow, mTextures, mFonts))
  , mStatisticsText()
  , mStatisticsUpdateTime()
  , mStatisticsNumFrames(0)
{
  chooseWindowSize();
  mWindow.create(sf::VideoMode(mWindowWidth, mWindowHeight), "Alien Game", sf::Style::Close);

  mWindow.setKeyRepeatEnabled(false);

  mFonts.load(Fonts::Main, "Media/Sansation.ttf");

  mStatisticsText.setFont(mFonts.get(Fonts::Main));
  mStatisticsText.setPosition(5.f, 5.f);
  mStatisticsText.setCharacterSize(10u);

  registerStates();
  mStateStack.pushState(States::Game);
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

      // Check inside this loop, because stack might be empty before update() call
      if (mStateStack.isEmpty())
        mWindow.close();
    }

    updateFramerateStatistics(dt);
    render();
  } // while window is open
} // run()


void Application::chooseWindowSize()
{
  mWindowWidth = 1200;
  mWindowHeight = 600;

  // Check the resolution of the user's computer, and with this information,
  // decide the window width/height

} // chooseWindowSize()



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

  mStateStack.draw();

  mWindow.draw(mStatisticsText);

  mWindow.display();
} // render()


void Application::update(sf::Time dt)
{
  mStateStack.update(dt);
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


void Application::registerStates()
{
  mStateStack.registerState<GameState>(States::Game);
} // registerStates()
