/**
 * Based on version written by: Artur Moreira, Henrik Vogelius Hansson, and
 *   Jan Haller for their book "SFML Game Development"
 */

#include <Alien/Application.hpp>

#include <stdexcept>
#include <iostream>

int main()
{
  try
  {
    Application app;
    app.run();
  }
  catch (std::exception& e)
  {
    std::cerr << "\nEXCEPTION: " << e.what() << std::endl;
  }
}

/*
#include <SFML/Graphics.hpp>

int main()
{
  sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
  sf::CircleShape shape(100.f);
  shape.setFillColor(sf::Color::Green);

  while (window.isOpen())
  {
    sf::Event event;
    while (window.pollEvent(event))
    {
      if (event.type == sf::Event::Closed)
        window.close();
    }

    window.clear();
    window.draw(shape);
    window.display();
  }

  return 0;
}
*/
