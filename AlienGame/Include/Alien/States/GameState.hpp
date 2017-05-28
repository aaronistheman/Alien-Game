/*
  Authors of original version: Artur Moreira, Henrik Vogelius Hansson, and
    Jan Haller
*/

#ifndef TANKS_GAMESTATE_HPP
#define TANKS_GAMESTATE_HPP

#include <Alien/States/State.hpp>
#include <Alien/Entities/Player.hpp>

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>


class GameState : public State
{
  public:
							GameState(StateStack& stack, Context context);

		virtual void		draw();
		virtual bool		update(sf::Time dt);
		virtual bool		handleEvent(const sf::Event& event);


	private:
    sf::Text      mJunkText;

    Player&				mPlayer;
};

#endif // TANKS_GAMESTATE_HPP