#include <SFML/Graphics.hpp>
#include <SFML/Window/Mouse.hpp>
#include <string>
#include <sstream>
#include <math.h>
#include <vector>

using namespace sf;


class Bullet{
		
		public:
				double XPosition;
				double YPosition;
				double speed;
				double angle;
				
				
				
				
				
				
				
		void setXPosition(double xp){
			XPosition= xp;
			
		}
		
		void setYPosition (double yp){
			YPosition= yp;
			
		}
		
 		void setAngle (double ang){
			angle = ang;
			
		}
 		
		void shoot(){
			
			
		}
			
		
		
	};






class Barrel{
	
	public:
			double XPosition;
			double YPosition;
			double angle;
			Bullet bul;
			
			
			
	void setXPosition(double xp){
		XPosition=xp;
		
	}
	
	void setYPosition(double yp){
		YPosition= yp;
		
	}		
			
	void increaseAngle(){
		angle++;
		
	}
	
	void decreaseAngle(){
		angle--;
		
	}
	
	
	};
	
	
	
	



class Tank{
	
	public:
			double position;
			int numberOfRemainingBullets;
			int numberOfCorrectShoots;
			int numberOfRemainingChances;
	
			Barrel bar;
	
	void moveRight(){
		position+=5;
		
	}
	
	void moveLeft(){
		position-=5;

		
		
	}
	
	void decreaseNumberOfRemainingBullets (){
		
		numberOfRemainingBullets--;
		
		
	}
	
	void increaseNumberOfRemainingBullets(){
		numberOfRemainingBullets++;
		
	}
	
	void decreaseNumberOfRemainingChances (){
		numberOfRemainingChances--;
		
	}
	
	
	};


	
	
	
	
	
	
	
	
	
	
	
	







class EventHandler{
	
public:
		std::vector<String> events;

 

	
	
	
};



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
		
		sf:: Text text;
sf:: Font font;
std:: stringstream ss;



		
		EventHandler eventH;
		Graphic()
{
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

		setUpText(font, "/home/ropa/Desktop/ariblk.ttf", text, 590.0, 15.0, 20,sf::Color::Red);



	} 
	

void createWindow(){

	window.create(sf::VideoMode(backgroundS.getLocalBounds().width+280, backgroundS.getLocalBounds().height), "FuriousAndFastTanks");

//window.create(sf::VideoMode(800, 600), "My window");

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


bool rightClicked(){
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))

		return true;
	else 
		return false;
}

bool leftClicked(){
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))

		return true;
	else 
		return false;
}


bool upClicked(){
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))

		return true;
	else 
		return false;
}


bool downClicked(){
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))

		return true;
	else 
		return false;
}

bool SHFClicked(){
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::RShift) || sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))

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


void drawSprite(sf::Sprite &s){
	window.draw(s);

}



void setUpTexture(sf::Texture &t, const std::string &fileName){

	t.loadFromFile(fileName);
}


void setUpSprite(sf::Sprite &s, sf::Texture &t){

	s.setTexture(t,true);	
}





void setUpText(sf::Font &f, const std::string &fontName, sf::Text &t, float x, float y, int size,const Color &c){
	f.loadFromFile(fontName);
	t.setFont(f);
	t.setPosition(x,y);
	t.setCharacterSize(size);
	t.setColor(c);

}

void setTextString(sf::Text &t, int n){

	std:: stringstream s;
	s.str("");
	s << n;
	t.setString(s.str());
}


void drawText(sf::Text &t){
	window.draw(t);

}









void setOrigin(sf::Sprite &s , double x, double y){
	s.setOrigin(x,y);
}	


double getSpriteHeight(sf::Sprite &s){
	return s.getLocalBounds().height;
}


double getSpriteWidth(sf::Sprite &s){
	return s.getLocalBounds().width;
}

void setSpirtePosition(sf::Sprite &s,double x, double y){
	s.setPosition(x, y);
}

void updateEventVector(){
		
	while(pollEvent()){
			if (exitClicked()){
				 eventH.events.push_back("E1");
				 
			}
			
			if (rightClicked()){
				 eventH.events.push_back("R1");
				 
			}
			
			if (leftClicked()){
				 eventH.events.push_back("L1");
				 
			}
			
			if (upClicked()){
				 eventH.events.push_back("U1");
				 
			}
			
			if (downClicked()){
				 eventH.events.push_back("D1");
				 
			}
			
			if (SHFClicked()){
				 eventH.events.push_back("SH1");
				 
			}
	}
}

void displayBoard(){
	
	createWindow();
		while(isWindowOpen()){
		
		while(pollEvent()){
			if (exitClicked())
				 exit();
		}
		
		setOrigin(firstPlayerBarrelS,getSpriteWidth(firstPlayerBarrelS),getSpriteHeight(firstPlayerBarrelS));
		setOrigin(secondPlayerBarrelS,0,getSpriteHeight(secondPlayerBarrelS));
		
		clearScreen();
		drawSprite(backgroundS);
		drawSprite(firstPlayerTankS);
		drawSprite(secondPlayerTankS);
		drawSprite(firstPlayerBarrelS);
		drawSprite(secondPlayerBarrelS);
	
		display();
			

	}
	
	
	}

};





int main()
{
	Graphic g;
	g.displayBoard();
	/*g.createWindow();
	 //sf::Window window(sf::VideoMode(800, 600), "My window");
		//g.setUpTexture(g.backgroundT, "/home/ropa/Desktop/background.png");
		//g.setUpSprite(g.backgroundS, g.backgroundT);
		//g.setSpirtePosition(g.backgroundS,140, 0);

	//sf::RenderWindow window;
	//window.create(sf::VideoMode(g.backgroundS.getLocalBounds().width+280, g.backgroundS.getLocalBounds().height), "FuriousAndFastTanks");
	while(g.isWindowOpen()){
		
		while(g.pollEvent()){
			if (g.exitClicked())
				 g.exit();
		}
		
		g.setOrigin(g.firstPlayerBarrelS,g.getSpriteWidth(g.firstPlayerBarrelS),g.getSpriteHeight(g.firstPlayerBarrelS));
		g.setOrigin(g.secondPlayerBarrelS,0,g.getSpriteHeight(g.secondPlayerBarrelS));
		
		g.clearScreen();
		g.drawSprite(g.backgroundS);
		g.drawSprite(g.firstPlayerTankS);
		g.drawSprite(g.secondPlayerTankS);
		g.drawSprite(g.firstPlayerBarrelS);
		g.drawSprite(g.secondPlayerBarrelS);
	
		g.display();
			

	}	*/
	
	system("PAUSE");
	return 0;
	
}
