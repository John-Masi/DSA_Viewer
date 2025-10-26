#include "mainView.h"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

// g++ main.cpp -o app -lsfml-graphics -lsfml-window -lsfml-system


int main() {
	HashMap<int, int> h_map(9); 
	//h_map.insert(1,9);
	HashView h_view{h_map};

	MainView* m_view{ &h_view };

	sf::RenderWindow window(sf::VideoMode(1280,1080), "Window");
	sf::Event event;

	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)){
			h_view.remove();
	}


	while(window.isOpen()) {

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