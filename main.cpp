#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
using namespace std;

class Canvas {
private:
	vector <sf::Vector2i> a;  // vector with all pixels of canvas
	sf::RenderWindow window;  // our canvas - холст
	sf::CircleShape circle;
public:
	sf::Vector2f current_position;
	sf::Vector2i mouse_position;

	void initialization()
	{
		window.create(sf::VideoMode(900, 600), "My window");

		current_position.x = 0;
		current_position.y = 0;

		circle.setFillColor(sf::Color(200, 213, 32));
		circle.setRadius(50.f);
	}
	void render()
	{
		while (window.isOpen())
		{
			sf::Event event;
			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)  // if window is closed
				{
					window.close();
				}

				if (event.type == sf::Mouse::isButtonPressed(sf::Mouse::Left))  // if we press the mouse...
				{
					mouse_position = sf::Mouse::getPosition(window);
					current_position = sf::Vector2f(mouse_position);

					circle.setPosition(20,40);
				}
			}

			display();
		}
	}
	void display()
	{
		window.clear(sf::Color(255,255,255));
		window.draw(circle);
		window.display();
	}
	void run()
	{
		render();
	}
	~Canvas()
	{

	}
};

int main()
{
	Canvas canvas;
	canvas.initialization();
	canvas.run();
	printf("Hello!");
}