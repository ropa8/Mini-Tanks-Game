#include <SFML/Graphics.hpp>
#include <SFML/Window/Mouse.hpp>
#include <string>
#include <sstream>
#include <math.h>
#include <vector>
#include <iostream>
#define g 9.80665
#define PI 3.14159


using namespace sf;
using namespace std;

class Bullet{
		
		public:
				double XPosition;
				double YPosition;
				double speed;
				//double angle;

				
				
				
				
				
				
		void setXPosition(double xp){
			XPosition= xp;
			
		}
		
		void setYPosition (double yp){
			YPosition= yp;
			
		}
		double getXPosition(){
			return XPosition;
			
		}
		
		double getYPosition (){
			return YPosition;
			
		}
		
		double getSpeed (){
			return speed;
			
		}
		
 		/*void setAngle (double ang){
			angle = ang;
			
		}
 		*/
		
			
		
		
	};






class Barrel{
	
	public:
			double XPosition;
			double YPosition;
			double barrelLength;
			double angle;
			double angleRadian= (double)(angle*PI)/180; 
			Bullet bullet;

			
			
	void setXPosition(double xp){
		XPosition=xp;
		
	}
	
	void setYPosition(double yp){
		YPosition= yp;
		
	}	
	
	double getXPosition(){
		return XPosition;
		
	}
	
	double getYPosition(){
		return YPosition;
		
	}
		
			
	void increaseAngle(){
		angle++;
		
	}
	
	void decreaseAngle(){
		angle--;
		
	}
	void shoot(double t){
			bullet.setXPosition((-(bullet.getSpeed())*cos(angleRadian)* t)*0.01+XPosition-barrelLength*cos(angleRadian));
			bullet.setYPosition(((0.5 * g * t * t) +(-(bullet.getSpeed())*sin(angleRadian)*t))*0.01+YPosition-barrelLength*sin(angleRadian));
			
	}
	
	};
	
	
	
	



class Tank{
	
	public:
			double XPosition;
			double YPosition;
			double maxXPosition;
			double minXPosition;
			int numberOfRemainingBullets;
			int numberOfCorrectShoots;
			int numberOfRemainingChances;
	
			Barrel barrel;
			
			
			
			
	double getXPosition(){
		return XPosition;		
			
	}
	
	double getYPosition(){
		return YPosition;		
			
	}
	
	double getMaxXPosition(){
		return maxXPosition;		
			
	}
	
	double getMinXPosition(){
		return minXPosition;		
			
	}
	void setXPosition(double p){
		if(p < maxXPosition && p > minXPosition)
			XPosition= p;
			
		else if(p > maxXPosition)
			XPosition= maxXPosition;
			
		else 
			XPosition= minXPosition;
		
		
	}
	
	void moveRight(){
		XPosition+=5;
		barrel.setXPosition(barrel.getXPosition()+5);
		
	}
	
	void moveLeft(){
		XPosition-=5;
		barrel.setXPosition(barrel.getXPosition()-5);

		
		
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
	
		//std::vector <std::string> events;
		std::vector <std::string> myEvents;
		std::vector <std::string> enemyEvents;
		int sentEventNumber;
		//Graphic gInstance;
		
		
		
void sendMyEvent(){
	
	
}

std::string recieveEnemyEvent(){
	
}

void push(){
		enemyEvents.push_back(recieveEnemyEvent());
}

	
};

class eventDecoder{
		
		EventHandler eventHandlerInstance;
		Tank myTank; 
		Tank enemyTank; 
		bool myShootFlag=false;
		bool myExitFlag=false;
		bool enemyShootFlag=false;
		bool enemyExitFlag=false;
		
		
void decodeMyEvent(){	
		
		std::string eventString;
		
		if(eventHandlerInstance.myEvents.size()!=0){
			if(eventHandlerInstance.sentEventNumber >= 0)
			{
				eventString = eventHandlerInstance.myEvents.front();
				eventHandlerInstance.myEvents.erase(eventHandlerInstance.myEvents.begin());
				
				if(eventString.compare("U") == 0){
						
					myTank.barrel.increaseAngle();
				}
				
				else if(eventString.compare("D") == 0){
						
					myTank.barrel.decreaseAngle();
				}
				
				else if(eventString.compare("R") == 0){
						
					myTank.moveRight();
				}
				
				else if(eventString.compare("L") == 0){
						
					myTank.moveLeft();
				}
				
				else if(eventString.compare("S") == 0){
					
					myShootFlag=true;
				}
				
				else if(eventString.compare("E") == 0){
					
					myExitFlag=true;
				}
				
			}
		}
}

void decodeEnemyEvent(){	
	
		std::string eventString;	
		
		if(eventHandlerInstance.enemyEvents.size()!=0){
			
				eventString = eventHandlerInstance.enemyEvents.front();
				eventHandlerInstance.enemyEvents.erase(eventHandlerInstance.enemyEvents.begin());
				
				if(eventString.compare("U") == 0){
						
					enemyTank.barrel.increaseAngle();
				}
				
				else if(eventString.compare("D") == 0){
						
					enemyTank.barrel.decreaseAngle();
				}
				
				else if(eventString.compare("R") == 0){
						
					enemyTank.moveRight();
				}
				
				else if(eventString.compare("L") == 0){
						
					enemyTank.moveLeft();
				}
				
				else if(eventString.compare("S") == 0){
					
					enemyShootFlag=true;
				}
				
				else if(eventString.compare("E") == 0){
					
					enemyExitFlag=true;
				}
	}
}	
};

class Graphic{
	public:
		sf::Event event;
		sf::RenderWindow window;
		sf::Texture backgroundT;
		sf::Texture myTankT;
		sf::Texture enemyTankT;
		sf::Texture myBulletT;
		sf::Texture enemyBulletT;
		sf::Texture myBarrelT;
		sf::Texture enemyBarrelT;
		sf::Sprite backgroundS;
		sf::Sprite myTankS;
		sf::Sprite enemyTankS;
		sf::Sprite myBulletS;
		sf::Sprite enemyBulletS;
		sf::Sprite myBarrelS;
		sf::Sprite enemyBarrelS;
		
	/*	double myTankXPosition;
		double myTankYPosition;
		double myBarrelXPosition;
		double myBarrelYPosition;
		double myBulletXPosition;
		double myBulletYPosition;
		
		double enemyTankXPosition;
		double enemyTankYPosition;
		double enemyBarrelXPosition;
		double enemyBarrelYPosition;
		double enemyBulletXPosition;
		double enemyBulletYPosition;
	*/	
		
		
		sf:: Text text;
		sf:: Font font;
		std::stringstream ss;


		int leftEdgeX;
		int rightEdgeX;
		int groundX;
		int wallMinX;
		int wallMaxX;
		
		int angle;
		
		EventHandler eventH;
		Graphic()
	{
		setUpTexture(backgroundT, "/home/ropa/Desktop/background.png");
	    setUpTexture(myTankT, "/home/ropa/Desktop/firstPlayerTank.png");
	    setUpTexture(enemyTankT, "/home/ropa/Desktop/secondPlayerTank.png");
	    //setUpTexture(myBulletT, "/home/ropa/Desktop/car1.png");
	    //setUpTexture(enemyBulletT, "/home/ropa/Desktop/car2.png");
	    setUpTexture(myBarrelT, "/home/ropa/Desktop/firstPlayerBarrel.png");
	    setUpTexture(enemyBarrelT, "/home/ropa/Desktop/secondPlayerBarrel.png");


		setUpSprite(backgroundS, backgroundT);
		setUpSprite(myTankS, myTankT);
		setUpSprite(enemyTankS, enemyTankT);
		//setUpSprite(myBulletS, myBulletT);
		//setUpSprite(enemyBulletS, enemyBulletT);
		setUpSprite(myBarrelS, myBarrelT);
		setUpSprite(enemyBarrelS, enemyBarrelT);
		
		setSpirtePosition(backgroundS,140, 0);
		setSpirtePosition(myTankS,1000,500-myTankS.getLocalBounds().height);
		setSpirtePosition(enemyTankS,200,500-enemyTankS.getLocalBounds().height);
		setSpirtePosition(myBarrelS,1000-myTankS.getLocalBounds().width+53+myBarrelS.getLocalBounds().width,500-myTankS.getLocalBounds().height-4+myBarrelS.getLocalBounds().height);
		setSpirtePosition(enemyBarrelS,200+enemyTankS.getLocalBounds().width-34,500-enemyTankS.getLocalBounds().height-20+enemyBarrelS.getLocalBounds().height);

		setUpText(font, "/home/ropa/Desktop/ariblk.ttf", text, 590.0, 15.0, 20,sf::Color::Red);



	} 
	
	
	/*	void  setMyTankXPosition(double x){
			
				myTankXPosition= x;
		
		}
		void setMyTankYPosition(double y){
			
			myTankYPosition= y;
			
		}
		void setMyBarrelXPosition(double x){
			
			myBarrelXPosition= x;
			
		}
		
		void setMyBarrelYPosition(double y){
			
			myBarrelYPosition= y;
			
		}
		
		void setMyBulletXPosition(double x){
			
			myBulletXPosition= x;
			
		}
		void setMyBulletYPosition(double y){
			myBulletYPosition= y;
			
		}	
		
		void setEnemyTankXPosition(double x){
			
			enemyTankXPosition= x;
			
		}	
		void setEnemyTankYPosition(double y){
			
			enemyTankYPosition= y;
			
		}
		void setEnemyBarrelXPosition(double x){
			
			enemyBarrelXPosition= x;
			
		}
		void setEnemyBarrelYPosition(double y){
			
			enemyBarrelYPosition= y;
			
			
		}
		void setEnemyBulletXPosition(double x){
			
			enemyBulletXPosition= x;
			
		}
		void setEnemyBulletYPosition(double y){
			
			enemyBulletYPosition= y;
		}
	*/
		void setAngle(int ang){
			
				angle=ang;
		}
	
	
	
	
	
	
	
	
	

void createWindow(){

	window.create(sf::VideoMode(backgroundS.getLocalBounds().width+280,
					backgroundS.getLocalBounds().height), "FAST AND FURIOUS TANKS");

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
	
	if(pollEvent()){
	
		if (event.type == sf::Event::Closed)

			return true;
		else 
			return false;
	}
}


bool rightClicked(){
	
	if(pollEvent()){

	
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))

			return true;
		else 
			return false;
	}
}


bool leftClicked(){
	
	if(pollEvent()){

	
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))

			return true;
		else 
			return false;
	}
}


bool upClicked(){
	
	if(pollEvent()){

	
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))

			return true;
		else 
			return false;
	}
}


bool downClicked(){
	
	if(pollEvent()){
		
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))

			return true;
		else 
			return false;
	}
}


bool SHFClicked(){
	
	if(pollEvent()){

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::RShift) || sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))

			return true;
		else 
			return false;
	}
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


void setTextString(sf::Text &t, char n){
	
	std::stringstream s;
	s.str("");
	s << n;
	t.setString(s.str());
}


void drawText(sf::Text &t){
	window.draw(t);

}


/*void printVector(){
	
	//setTextString(text, eventH.events[0]);
	
	//for(int i=0; i< eventH.events.size(); i++){
		//std:: stringstream s;
		//s.str("");
		//s << eventH.events.size();
		//s << eventH.events.pop_back();
		//text.setString(s.str());
		
	//}	
	while(eventH.enemyEvents.size()!=0){
		//s.str("");
		ss << eventH.enemyEvents.front();
		text.setString(ss.str());
		eventH.enemyEvents.erase(eventH.enemyEvents.begin());
	}
			
}
*/

void setOrigin(sf::Sprite &s , double x, double y){
	
	s.setOrigin(x,y);
}	



void rotate(sf::Sprite &s){
	
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


void pushMyEventVector(){
		
	//while(pollEvent()){
		
			if (exitClicked()){
				eventH.myEvents.push_back("E");
					//exit();
				
			}
			
			if (rightClicked()){
				eventH.myEvents.push_back("R");
				 
			}
			
			if (leftClicked()){
				eventH.myEvents.push_back("L");
				 
			}
			
			if (upClicked()){
				 eventH.myEvents.push_back("U");
				 
			}
			
			if (downClicked()){
				eventH.myEvents.push_back("D");
				 
			}
			
			if (SHFClicked()){
				 eventH.myEvents.push_back("S");
				 
			}
//	}
}


/*void detectEvent(){
	
	if(pollEvent()){
			if (exitClicked()){
					exit();
					
			}
			
			if (rightClicked()){
				//eventH.events.push_back('R');
				firstPlayerTankS.move(5,0);
				firstPlayerBarrelS.move(5,0);
				 
			}
			
			if (leftClicked()){
				//eventH.events.push_back('L');
				firstPlayerTankS.move(-5,0);
				firstPlayerBarrelS.move(-5,0);
			}
			
			if (upClicked()){
				 //eventH.events.push_back('U');
				firstPlayerBarrelS.rotate(1);
				//secondPlayerBarrelS.rotate(-1);
			}
			
			if (downClicked()){
				//eventH.events.push_back('D');
				firstPlayerBarrelS.rotate(-1);
				//secondPlayerBarrelS.rotate(+1); 
			}
			
			if (SHFClicked()){
				 //eventH.events.push_back('S');
				 
			}
		
	}
	
}

*/
/*void handleEnemyEvents(){
	
	if(eventH.events.size()!=0){
		
		switch(eventH.events.front()){
			case 'U':
				secondPlayerBarrelS.rotate(1);

				
				
			case 'D':
				secondPlayerBarrelS.rotate(-1);

				
				
			case 'R':
				secondPlayerTankS.move(5,0);
				secondPlayerBarrelS.move(5,0);				
				
			case 'L':
				
				secondPlayerTankS.move(-5,0);
				secondPlayerBarrelS.move(-5,0);
			
			
		}

		eventH.events.erase(eventH.events.begin());
	}
	
	
}

*/



void updateValues(double myTankX,double myTankY, double myBarrelX, double myBarrelY, double myBulletX, double myBulletY, double enemyTankX,
					double enemyTankY, double enemyBarrelX, double enemyBarrelY, double enemyBulletX, double enemyBulletY, int ang){
	/*setMyTankXPosition(myTankX);
	setMyBarrelXPosition(myBarrelX);
	setMyBarrelYPosition(myBarrelY);
	setMyBulletXPosition(myBulletX);
	setMyBulletYPosition(myBulletY);
	setEnemyTankXPosition(enemyTankX);
	setEnemyBarrelXPosition(enemyBarrelX);
	setEnemyBarrelYPosition(enemyBarrelY);
	setEnemyBulletXPosition(enemyBulletX);
	setEnemyBulletYPosition(enemyBulletY);
	*/
	setSpirtePosition(myTankS, myTankX, myTankY);
	setSpirtePosition(myBarrelS, myBarrelX, myBarrelY);
	setSpirtePosition(myBulletS, myBulletX, myBulletY);
	setSpirtePosition(enemyTankS, enemyTankX, enemyTankY);
	setSpirtePosition(enemyBarrelS, enemyBarrelX, enemyBarrelY);
	setSpirtePosition(enemyBulletS, enemyBulletX, enemyBulletY);
	setAngle(ang);
	
}

void displayBoard(){
	
	createWindow();
	
	//for(int i=0; i<30; i++){
	//eventH.events.push_back("L1");
	//}

	while(isWindowOpen()){
		
		setOrigin(myBarrelS,getSpriteWidth(myBarrelS),getSpriteHeight(myBarrelS));
		setOrigin(enemyBarrelS,0,getSpriteHeight(enemyBarrelS));
		
		
		//detectEvent();
		//handleEnemyEvents();
		//updateEventVector();
		
		//eventH.events.push_back('S');
		//setTextString(text, eventH.events.back());
			//setTextString(text, eventH.events.back());

		//printVector();
		
		
		clearScreen();
		drawSprite(backgroundS);
		drawSprite(myTankS);
		drawSprite(enemyTankS);
		drawSprite(myBarrelS);
		drawSprite(enemyBarrelS);
		drawText(text);
		display();
		sf::sleep(sf::milliseconds(50));

			
	}
}

};



class Game{
	
	EventHandler eventHandlerInstance;
	Graphic graphicInstance;
	
	
	void run(){
			
		
		
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
};

int main()
{
	Graphic gr;
	gr.displayBoard();
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
