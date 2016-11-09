#include <SFML\Graphics.hpp>
#include <iostream>

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

			switch (event.type) {
			// close window when click the exit button
			case sf::Event::Closed :
				window.close();
				break;
			case sf::Event::KeyPressed :
				std::cout << "key pressed" << event.key.code << std::endl;
				switch (event.key.code) {
				case sf::Keyboard::Left:
					std::cout << "going left" << std::endl;
					horizontal--;
					break;
				case sf::Keyboard::Right:
					std::cout << "going right" << std::endl;
					horizontal++;
					break;
				case sf::Keyboard::Up:
					std::cout << "going up" << std::endl;
					vertical--;
					break;
				case sf::Keyboard::Down :
					std::cout << "going down" << std::endl;
					vertical++;
					break;
				}
				break;
			}
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