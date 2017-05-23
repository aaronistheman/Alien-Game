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
