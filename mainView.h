#include "hash_map.h"
#include <vector>
#include <string>
#include <string_view>


class MainView {
	public:
		std::string_view currentView{"hash_map"};
	protected:
		std::vector<sf::Sprite> sprites;

};

class HashView: MainView {
	public:
		HashMap<int,int> h_map;

		void draw(sf::RenderWindow& w) { 
			for(int i = 0; i < sprites.size(); i++) {
				sprites[i].setPosition(i*150,100);
				sprites[i].setScale(0.2f,0.2f);
				w.draw(sprites[i]);
			}
		}

		void remove() {
			sprites.pop_back();
		}

		HashView() = default;
		HashView(HashMap<int,int> hm) : h_map{hm} {
			sf::Texture img;
			img.loadFromFile("bucket.png");

			for(int i = 0; i < static_cast<int>(h_map.getSize()); i++) {
				sprites.emplace_back(img);
			}
		}
		~HashView() {
			// Destroy all sprites
		} 
};
