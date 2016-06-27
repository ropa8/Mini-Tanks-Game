#include <SFML/Graphics.hpp>
#include <SFML/Window/Mouse.hpp>

class Graphic{
	public:
		sf::Event event;
		sf::RenderWindow window;
		sf::Texture backgroundT;
		sf::Texture firstPlayerTankT;
		sf::Texture secondPlayerTankT;
		sf::Texture firstPlayerBulletT;
		sf::Texture secondPlayerBulletT;
		sf::Texture firstPlayerBarrelT;
		sf::Texture secondPlayerBarrelT;
		sf::Sprite backgroundS;
		sf::Sprite firstPlayerTankS;
		sf::Sprite secondPlayerTankS;
		sf::Sprite firstPlayerBulletS;
		sf::Sprite secondPlayerBulletS;
		sf::Sprite firstPlayerBarrelS;
		sf::Sprite secondPlayerBarrelS;
		
		Graphic(){
		//window.create(sf::VideoMode(backgroundS.getLocalBounds().width+280, backgroundS.getLocalBounds().height), "FuriousAndFastTanks");
		setUpTexture(backgroundT, "/home/ropa/Desktop/background.png");
	    setUpTexture(firstPlayerTankT, "/home/ropa/Desktop/firstPlayerTank.png");
	    setUpTexture(secondPlayerTankT, "/home/ropa/Desktop/secondPlayerTank.png");
	    //setUpTexture(firstPlayerBulletT, "/home/ropa/Desktop/car1.png");
	    //setUpTexture(secondPlayerBulletT, "/home/ropa/Desktop/car2.png");
	    setUpTexture(firstPlayerBarrelT, "/home/ropa/Desktop/firstPlayerBarrel.png");
	    setUpTexture(secondPlayerBarrelT, "/home/ropa/Desktop/secondPlayerBarrel.png");


		setUpSprite(backgroundS, backgroundT);
		setUpSprite(firstPlayerTankS, firstPlayerTankT);
		setUpSprite(secondPlayerTankS, secondPlayerTankT);
		//setUpSprite(firstPlayerBulletS, firstPlayerBulletT);
		//setUpSprite(secondPlayerBulletS, secondPlayerBulletT);
		setUpSprite(firstPlayerBarrelS, firstPlayerBarrelT);
		setUpSprite(secondPlayerBarrelS, secondPlayerBarrelT);
		
		setSpirtePosition(backgroundS,140, 0);
		setSpirtePosition(firstPlayerTankS,1000,500-firstPlayerTankS.getLocalBounds().height);
		setSpirtePosition(secondPlayerTankS,200,500-secondPlayerTankS.getLocalBounds().height);
		setSpirtePosition(firstPlayerBarrelS,1000-firstPlayerTankS.getLocalBounds().width+53+firstPlayerBarrelS.getLocalBounds().width,500-firstPlayerTankS.getLocalBounds().height-4+firstPlayerBarrelS.getLocalBounds().height);
		setSpirtePosition(secondPlayerBarrelS,200+secondPlayerTankS.getLocalBounds().width-34,500-secondPlayerTankS.getLocalBounds().height-20+secondPlayerBarrelS.getLocalBounds().height);


	} 
	
	
		bool pollEvent(){
	return window.pollEvent(event);
}


bool isWindowOpen(){
	return window.isOpen();

}



void exit(){
	window.close();

}

bool exitClicked(){
	if (event.type == sf::Event::Closed)

		return true;
	else 
		return false;
}


void clearScreen(){
	window.clear();

}


void display(){
	window.display();

}


void drawSprite(sf::Sprite s){
	window.draw(s);

}



void setUpTexture(sf::Texture t, const std::string &fileName){

	t.loadFromFile(fileName);
}


void setUpSprite(sf::Sprite s, sf::Texture t){

	s.setTexture(t,true);	
}

void setOrigin(sf::Sprite s , double x, double y){
	s.setOrigin(x,y);
}	


double getSpriteHeight(sf::Sprite s){
	return s.getLocalBounds().height;
}


double getSpriteWidth(sf::Sprite s){
	return s.getLocalBounds().width;
}

void setSpirtePosition(sf::Sprite s,double x, double y){
	s.setPosition(x, y);
}

};





int main()
{
	Graphic g;
	sf::RenderWindow window(sf::VideoMode(2000,2000), "Tank");

	//sf::RenderWindow window;
	//window.create(sf::VideoMode(g.backgroundS.getLocalBounds().width+280, g.backgroundS.getLocalBounds().height), "FuriousAndFastTanks");

	while(g.isWindowOpen()){
		
		while(g.pollEvent()){
			if (g.exitClicked())
				 g.exit();
		}
		
		//g.setOrigin(g.firstPlayerTankS,(g.firstPlayerTankS).(g.getSpriteWidth),(g.firstPlayerTankS).(g.getSpriteHeight));
		//g.setOrigin(0,(g.secondPlayerTankS).(g.getSpriteHeight));
		
		g.clearScreen();
		g.drawSprite(g.backgroundS);
		g.drawSprite(g.firstPlayerTankS);
		g.drawSprite(g.secondPlayerTankS);
		g.drawSprite(g.firstPlayerBarrelS);
		g.drawSprite(g.secondPlayerBarrelS);
		
		g.display();
			

	}	
	
	system("pause");
	return 0;
	
}
