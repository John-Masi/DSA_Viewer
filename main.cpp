#include "hash_map.h"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

// g++ main.cpp -o app -lsfml-graphics -lsfml-window -lsfml-system


int main() {
	sf::RenderWindow window(sf::VideoMode(800,600), "Window");
	sf::Event event;

	while(window.isOpen()) {

		while(window.pollEvent(event)) {
			if(event.type == sf::Event::Closed) {
				window.close();
			}
		}

	}

	window.clear(sf::Color::Black);
	window.display();
}