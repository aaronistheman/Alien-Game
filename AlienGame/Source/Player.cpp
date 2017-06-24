#include <Alien/Entities/Player.hpp>

#include <SFML/Window/Keyboard.hpp>

#include <iostream>

Player::Player()
  : mSprite(sf::Vector2f(30.f, 30.f))
{
  setPosition(80.f, 80.f);
}

void Player::draw(sf::RenderTarget & target) const
{
  target.draw(mSprite, getTransform());
}

void Player::update(sf::Time dt)
{
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    std::cout << "You're sweet\n";
}
