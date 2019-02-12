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
	sf::Image img;
	sf::RectangleShape rect;

	void initialization()
	{
		window.create(sf::VideoMode(900, 600), "My window");
		img.create(window.getSize().x,window.getSize().y, sf::Color(255,255,255));
		rect.setSize(sf::Vector2f(window.getSize().x,window.getSize().y));
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
			}

			display();
		}
	}
	void display()
	{
		window.clear(sf::Color(255,255,255));
		mouse_position = sf::Mouse::getPosition(window);
		img.setPixel(mouse_position.x, mouse_position.y, sf::Color(rand()));
		sf::Sprite s;
		sf::Texture* t = new sf::Texture();
		t->loadFromImage(img, sf::IntRect(0,0,img.getSize().x,img.getSize().y));
		rect.setTexture(t);
		window.draw(rect);
		delete t;
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
