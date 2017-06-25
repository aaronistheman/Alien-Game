#include <Alien/States/GameState.hpp>
#include <Alien/Utility/ResourceHolder.hpp>

#include <SFML/Graphics/RenderWindow.hpp>


GameState::GameState(StateStack& stack, Context context)
: State(stack, context)
, mWorld(*context.window, *context.fonts)
{
  // mJunkText.setFont(context.fonts->get(Fonts::Main));
  // mJunkText.setString("Hey");
}

void GameState::draw()
{
  mWorld.draw();
}

bool GameState::update(sf::Time dt)
{
  mWorld.update(dt);

  //mPlayer.handleRealTimeInput(dt);

	return true;
}

bool GameState::handleEvent(const sf::Event& event)
{
	return true;
}