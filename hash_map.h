#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

// Closed address hash map (Does collision giving extra buckets)
template<typename K, typename T> 
class HashMap{
	public:

		HashMap() = default;

		HashMap(size_t s) : size(s) , table(s) {

		}

		// Base size 
		size_t size = 8;
		// std::list giving extra buckets 
		std::vector<std::list<std::pair<K, T>>> table;
		int elements = 0;


		// Hash our key 
		size_t hash(const K& key) {
			return std::hash<K>{}(key) % size;
		}

		size_t getSize() {
			return size;
		}

		//double load_factor = static_cast<double>(elements) / table.size();
		// When our load factor is greater then 0.70 we create a new table that is double the size of the previous and compute hashes for the indexs again 
		void rehash(size_t new_size) {
			std::vector<std::list<std::pair<K, T>>> table_2(new_size);

			for(auto& bucket: table){
				for(auto& b: bucket) {
					size_t index = std::hash<K>{}(b.first) % new_size;
					table_2[index].push_back(b);
				}
			}

			table.swap(table_2);
		}

		void insert(const K& key,const T& value){
			size_t index = hash(key) % size;
			// Looking through the std::list<std::pair<K, T>> which is our buckets 
			for(auto& b: table[index]){
				if(b.first == key) {
					b.second = value;
					return;
				}
			}

			// Storing all collisions 
			table[index].push_back({key,value});
			elements++;
		}

		T* find(const K& key) {
			size_t index = hash(key);
			for(auto& b: table[index]){
				if(b.first == key) {
					std::cout << b.second << '\n';
					return &b.second;
				}
			}

			std::cout << "Could not find pair" << '\n';
			return nullptr; 
		}

		void erase(const K& key,const T& value) {
			size_t index = hash(key);
			for(auto& b: table[index]){
				if(b.first == key) {
					table[index].erase(b);
					return; 
				}
			}
			elements--;
		}
};

// HashMap view for the gui
class HashView{
	public:
		HashMap<int,int> h_map;
		std::vector<sf::Sprite> sprites;

		void draw(sf::RenderWindow& w) { 
			for(int i = 0; i < sprites.size(); i++) {
				sprites[i].setPosition(100*i,100 * i);
				sprites[i].setScale(0.5f,0.5f);
				w.draw(sprites[i]);
			}
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
