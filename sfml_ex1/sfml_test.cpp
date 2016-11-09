#include <SFML\Graphics.hpp>

int main() {
	// set RenderWindow
	sf::RenderWindow window(sf::VideoMode(640, 480), "sfml test!!!");
	
	float horizontal = 320;
	float vertical = 240;
	// set circle
	sf::CircleShape circle;
	circle.setRadius(70);
	circle.setFillColor(sf::Color::Red);

	while (window.isOpen()) {

		// set circle position on this loop to make it move
		circle.setPosition(horizontal, vertical);
		
		// some sort of Event Handler?
		sf::Event event;

		while (window.pollEvent(event)) {

			horizontal--;
			
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}

		// clear on every frame
		window.clear(sf::Color::White);
		// draw the circle on every frame
		window.draw(circle);
		// display what window has done on every frame
		window.display();
	}
}