#include <Alien/Entities/Player.hpp>

#include <SFML/Window/Keyboard.hpp>

#include <iostream>

Player::Player()
{
}

void Player::update(sf::Time dt)
{
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    std::cout << "You're sweet\n";
}
