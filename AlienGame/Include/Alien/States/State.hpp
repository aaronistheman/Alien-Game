/*
  Authors of original version: Artur Moreira, Henrik Vogelius Hansson, and
    Jan Haller
*/

#pragma once

#include <Alien/States/StateIdentifiers.hpp>
#include <Alien/Utility/ResourceIdentifiers.hpp>
#include <Alien/Entities/Player.hpp>

#include <SFML/System/Time.hpp>
#include <SFML/Window/Event.hpp>

#include <memory>


namespace sf
{
	class RenderWindow;
}

class StateStack;
//class Player;

class State
{
	public:
		typedef std::unique_ptr<State> Ptr;

		struct Context
		{
								Context(sf::RenderWindow& window, TextureHolder& textures,
                  FontHolder& fonts, Player& player);

			sf::RenderWindow*	window;
			TextureHolder*		textures;
			FontHolder*			fonts;
      Player*				player;
		};


	public:
							State(StateStack& stack, Context context);
		virtual				~State();

		virtual void		draw() = 0;
		virtual bool		update(sf::Time dt) = 0;
		virtual bool		handleEvent(const sf::Event& event) = 0;


	protected:
		void				requestStackPush(States::ID stateID);
		void				requestStackPop();
		void				requestStateClear();

		Context				getContext() const;


	private:
		StateStack*			mStack;
		Context				mContext;
};
