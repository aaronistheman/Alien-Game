#include <Alien/Entities/Player.hpp>

#include <SFML/Window/Keyboard.hpp>

float Player::RotationSpeed = 90.f;

//Player::Player()
//  //: mSprite(sf::Vector2f(30.f, 30.f))
//  : OneSpriteEntity(sf::Vector2f(30.f, 30.f))
//{
//  setPosition(80.f, 80.f);
//}

Player::Player(const sf::Vector2f & size)
  : OneSpriteEntity(size)
{
}

void Player::draw(sf::RenderTarget & target) const
{
  target.draw(mSprite, getTransform());
}

void Player::update(sf::Time dt)
{
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    rotate(-RotationSpeed * dt.asSeconds());
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    rotate(RotationSpeed * dt.asSeconds());
}
