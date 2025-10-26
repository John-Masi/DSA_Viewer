#include "mainView.h"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <memory>

// g++ main.cpp -o app -lsfml-graphics -lsfml-window -lsfml-system


int main() {
	HashMap<int, int> h_map(9); 

	std::unique_ptr<MainView> m_view = std::make_unique<HashView>(h_map);

	sf::RenderWindow window(sf::VideoMode(1280,1080), "Window");
	sf::Event event;

	while(window.isOpen()) {

		// Switch views here 
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)){
			
		}

		while(window.pollEvent(event)) {
			if(event.type == sf::Event::Closed) {
				window.close();
			}
		}

		window.clear(sf::Color::Black);
		m_view->draw(window);
		window.display();

	}
}
