#include <SFML\Graphics.hpp>
#include <iostream>

enum direction{stop, left, right, up, down};

int main() {
	// set RenderWindow
	sf::RenderWindow window(sf::VideoMode(640, 480), "sfml test!!!");
	
	// init. direction
	direction d = stop;

	float horizontal = 320;
	float vertical = 240;

	float hSpeed = 0;
	float vSpeed = 0;
	float fLimit = 0.07;
	float bLimit = -0.07;

	// set circle
	sf::CircleShape circle;
	circle.setRadius(10);
	circle.setFillColor(sf::Color::Red);

	// set circle position on this loop to make it move
	circle.setPosition(horizontal, vertical);


	while (window.isOpen()) {
		
		// some sort of Event Handler?
		sf::Event event;

		while (window.pollEvent(event)) {

			switch (event.type) {
			// close window when click the exit button
				window.close();
				break;
			case sf::Event::KeyPressed :
				switch (event.key.code) {
				case sf::Keyboard::Left:
					d = left;
					break;
				case sf::Keyboard::Right:
					d = right;
					break;
				case sf::Keyboard::Up:
					d = up;
					break;
				case sf::Keyboard::Down :
					d = down;
					break;
				}
				break;
			}
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}

		// move circle
		switch (d) {
		case left:
			if (hSpeed > 0) hSpeed = 0;
			if (hSpeed > bLimit) hSpeed -= 0.0001;

			if (vSpeed > 0) vSpeed -= 0.00005;
			else if (vSpeed < 0) vSpeed += 0.00005;
			break;
		case right:
			if (hSpeed < 0) hSpeed = 0;
			if (hSpeed < fLimit) hSpeed += 0.0001;

			if (vSpeed > 0) vSpeed -= 0.00005;
			else if (vSpeed < 0) vSpeed += 0.00005;
			break;
		case up:
			if (vSpeed > 0) vSpeed = 0;
			if (vSpeed > bLimit) vSpeed -= 0.0001;

			if (hSpeed > 0) hSpeed -= 0.00005;
			else if (hSpeed < 0) hSpeed += 0.00005;
			break;
		case down:
			if (vSpeed < 0) vSpeed = 0;
			if (vSpeed < fLimit) vSpeed += 0.0001;

			if (hSpeed > 0) hSpeed -= 0.00005;
			else if (hSpeed < 0) hSpeed += 0.00005;
			break;
		}
		
		horizontal += hSpeed;
		vertical += vSpeed;
		// set circle position on this loop to make it move
		circle.setPosition(horizontal, vertical);
		// clear on every frame
		window.clear(sf::Color::White);
		// draw the circle on every frame
		window.draw(circle);
		// display what window has done on every frame
		window.display();
	}
}