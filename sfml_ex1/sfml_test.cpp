#include <SFML\Graphics.hpp>

int main() {
	// set RenderWindow
	sf::RenderWindow window(sf::VideoMode(640, 480), "sfml test!!!");
	
	// set circle
	sf::CircleShape circle;
	circle.setRadius(40.f);
	circle.setPosition(100.f, 100.f);
	circle.setFillColor(sf::Color::Blue);

	while (window.isOpen()) {

		// some sort of Event Handler?
		sf::Event event;

		while (window.pollEvent(event)) {
			
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}

		window.clear(sf::Color::White);
		window.draw(circle);
		window.display();
	}
}