#include <SFML/Graphics.hpp>
#include <SFML/Window/Mouse.hpp>
#include <SFML/Audio.hpp>
int main(){

sf::Texture boll;
boll.loadFromFile("bullet.png");
sf::Sprite bollS(boll);
//bollS.setPosition(0,2000);

double x=0;
double y=0;
//double t=0;
	sf::Event event;
	sf::RenderWindow window(sf::VideoMode(1000,1000), "Tank");
	while(window.isOpen()){
		//looleS.setRotation(45);
		

		while(window.pollEvent(event)){
		if (event.type == sf::Event::Closed)
			window.close();
	
		}
	
	for(double t=0;t<=2000*0.642/9.8;t+=0.1){
		x = (-1000*0.766* t)*0.01+500;
		y = ((0.5 * 9.8 * t * t) +(-1000*0.642*t))*0.01+500;
		//t=t+0.1;
		//x++;
		//y++;
		window.clear();
		bollS.setPosition(x,y);
		window.draw(bollS);
		window.display();
	}
	
		
	}

	
	system("pause");
	
	return 0;
}
