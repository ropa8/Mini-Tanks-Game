#include <SFML/Graphics.hpp>
#include <SFML/Window/Mouse.hpp>
#include <SFML/Audio.hpp>
int main(){

sf::Texture loole;
loole.loadFromFile("loole.PNG");
sf::Sprite looleS(loole);
looleS.setPosition(300,300);
	sf::Event event;
	sf::RenderWindow window(sf::VideoMode(1200, 1000), "Tank");
	while(window.isOpen()){
		//looleS.setRotation(45);
		
		looleS.setOrigin(looleS.getLocalBounds().width,looleS.getLocalBounds().height);
		while(window.pollEvent(event)){
		if (event.type == sf::Event::Closed)
			window.close();

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{

		looleS.rotate(1);
		
		}


		window.clear();
		window.draw(looleS);
		window.display();
	}
	}
	
	system("pause");
	
	return 0;
}
