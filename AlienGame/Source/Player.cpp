#include <Alien/Entities/Player.hpp>

#include <SFML/Window/Keyboard.hpp>

Player::Player()
  //: mSprite(sf::Vector2f(30.f, 30.f))
  : OneSpriteEntity(sf::Vector2f(30.f, 30.f))
{
  setPosition(80.f, 80.f);
}

void Player::draw(sf::RenderTarget & target) const
{
  target.draw(mSprite, getTransform());
}

void Player::update(sf::Time dt)
{
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    rotate(-1.f);
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    rotate(1.f);
}
