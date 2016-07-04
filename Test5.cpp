#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
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


class Board{
	
	public:
//double rightEdge;
//double leftEdge;
//double ground;
double width;
double height;
double wallX;
double wallHeight;
double margin;


//Board(){}

Board(double width, double height, double wallX, double wallHeight, double margin){
	this-> width = width;
	this-> height = height;
	this-> wallX = wallX;
	this-> wallHeight = wallHeight;
	this-> margin = margin;
	
}

void setWidth(double w){
	width= w;
}
void setHeight(double h){
	height= h;
}
void setWallX(double x){
	wallX= x;
}
void setWallHeight(double y){
	wallHeight= y;
}
void setMargin(double m){
	margin= m;
}


double getWidth(){
	return width;
}
double getHeight(){
	return height;
}
double getWallX(){
	return wallX;
}
double getWallHeight(){
	return wallHeight;
}
double getMargin(){
	return margin;
}
	
	
};
class Bullet{
		
		public:
				double XPosition;
				double YPosition;
				double height;
				double width;
				double speed;
				//double angle;

				
				
Bullet(double bulletXPosition, double bulletYPosition, double bulletHeight, double bulletWidth, double speed){
	XPosition = bulletXPosition;
	YPosition = bulletYPosition;
	height = bulletHeight;
	width = bulletWidth;
	this-> speed = speed;
	
}
		
				
				
				
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
		
		double getWidth(){
			return width;
			
		}
		
		double getHeight(){
			return height;
			
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
			double angleRadian; 
			Bullet bullet;

Barrel(double barrelXPosition, double barrelYPosition, double barrelLength, double angle,double bulletXPosition,
			double bulletYPosition, double bulletHeight, double bulletWidth, double speed):bullet(Bullet(bulletXPosition,
			 bulletYPosition, bulletHeight, bulletWidth, speed)){
	this-> XPosition = barrelXPosition;
	this-> YPosition = barrelYPosition;
	this-> barrelLength = barrelLength;
	this-> angle = angle;
	angleRadian= (double)(angle*PI)/180; 
	
}
			
			
	void setXPosition(double xp){
		XPosition=xp;
		
	}
	
	void setYPosition(double yp){
		YPosition= yp;
		
	}	
	void setAngle(int d){
		angle=d;
		
	}
	
	void setAngleRadian(double r){
		angleRadian=r;
		
	}
	
	
	double getXPosition(){
		return XPosition;
		
	}
	
	double getYPosition(){
		return YPosition;
		
	}
		
	int getAngle(){
		return angle;
		
	}
	
	double getAngleRadian(){
		return (double)((getAngle()*PI)/180);
		
	}
			
	void increaseAngle(){
		angle++;
		
	}
	
	void decreaseAngle(){
		angle--;
		
	}
	void shoot(double t){
				//angleRadian= (double)(angle*PI)/180; 
				//angleRadian= getAngleRadian(); 

			bullet.setXPosition((-(bullet.getSpeed())*cos(getAngleRadian())* t)*0.01+getXPosition()-barrelLength*cos(getAngleRadian()));
			bullet.setYPosition(((0.5 * g * t * t) +(-(bullet.getSpeed())*sin(getAngleRadian())*t))*0.01+YPosition-barrelLength*sin(getAngleRadian()));
			
	}
	
	};
	
	
	
	



class Tank{
	
	public:
			double XPosition;
			double YPosition;
			double height;
			double width;
			//double maxXPosition;
			//double minXPosition;
			int numberOfRemainingBullets;
			int numberOfCorrectShoots;
			int numberOfRemainingChances;
	
			Barrel barrel;
			
			
			
			
Tank(double tankXPosition, double tankYPosition, double tankHeight, double tankWidth, int numberOfRemainingBullets,
		int numberOfCorrectShoots, int numberOfRemainingChances,double barrelXPosition, double barrelYPosition, double barrelLength,
		 double angle,double bulletXPosition, double bulletYPosition, double bulletHeight, double bulletWidth, double speed):barrel(Barrel(barrelXPosition,
		  barrelYPosition, barrelLength, angle, bulletXPosition, bulletYPosition, bulletHeight, bulletWidth,  speed)){
	this-> XPosition = tankXPosition;
	this-> YPosition = tankYPosition;
	this-> height = tankHeight;
	this-> width = tankWidth;
	this-> numberOfRemainingBullets = numberOfRemainingBullets;
	this-> numberOfCorrectShoots = numberOfCorrectShoots;
	this-> numberOfRemainingChances = numberOfRemainingChances;	
}			
			

	double getXPosition(){
		return XPosition;		
			
	}
	
	double getYPosition(){
		return YPosition;		
			
	}
	
/*	double getMaxXPosition(){
		return maxXPosition;		
			
	}
	
	double getMinXPosition(){
		return minXPosition;		
			
	}
*/	
	double getWidth(){
		return width;
			
	}
		
	double getHeight(){
		return height;
			
	}
		
	void setXPosition(double p){
		XPosition= p;
/*		if(p < maxXPosition && p > minXPosition)
			XPosition= p;
			
		else if(p > maxXPosition)
			XPosition= maxXPosition;
			
		else 
			XPosition= minXPosition;
*/		
		
	}
	
	void moveRight(){
		setXPosition(getXPosition()+ 5);
		barrel.setXPosition(barrel.getXPosition()+5);
		
	}
	
	void moveLeft(){
		setXPosition(getXPosition()- 5);
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
	
	void increaseNumberOfCorrectShoots (){
		numberOfCorrectShoots++;
		
	}
	
	int getRemainingBullets(){
		return numberOfRemainingBullets;
		
	}
	
	int getRemainingChances (){
		return numberOfRemainingChances;
		
	}
	
	int getCorrectShoots (){
		return numberOfCorrectShoots;
		
	} 
	
	};
	
	
	




class EventHandler{
	
	public:
	
		//std::vector <std::string> events;
		std::vector <std::string> myEvents;
		std::vector <std::string> enemyEvents;
		int sentEventNumber;
		//Graphic gInstance;
EventHandler(){
	sentEventNumber=-1;
	
}		
		
		
void sendMyEvent(){
	
	
}

std::string recieveEnemyEvent(){
	
}

void push(){
		//enemyEvents.push_back(recieveEnemyEvent());
}

	
};




/*class EventDecoder{
	public:
		EventHandler &eventHandlerInstance;
		//Tank myTank; 
		//Tank enemyTank; 
		bool myShootFlag;
		bool myExitFlag;
		bool enemyShootFlag;
		bool enemyExitFlag;


EventDecoder( ){
		myShootFlag=false;
		myExitFlag=false;
		enemyShootFlag=false;
		enemyExitFlag=false;
		//myTank=myT;
		//enemyTank=enemyT;
		//eventHandlerInstance=eh;
}

		
		
		void setMyShootFlag(bool flag){
				myShootFlag= flag;
		}
		
		void setMyExitFlag(bool flag){
				myExitFlag= flag;
		}
		
		
		bool getMyShootFlag(){
				return myShootFlag;
		}
		
		bool getMyExitFlag(){
				return myExitFlag;
		}
		
		
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


*/

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
		sf::Texture explosionT;

		sf::Sprite backgroundS;
		sf::Sprite myTankS;
		sf::Sprite enemyTankS;
		sf::Sprite myBulletS;
		sf::Sprite enemyBulletS;
		sf::Sprite myBarrelS;
		sf::Sprite enemyBarrelS;
		sf::Sprite myExplosionS;
		sf::Sprite enemyExplosionS;
		
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
		sf:: SoundBuffer buffer;
		sf:: Sound explosionSound;
		
		sf:: SoundBuffer shootBuffer;
		sf:: Sound shootSound;
		
		sf:: Text myAngleText;
		sf:: Text myRemainingBulletsText;
		sf:: Text myCorrectShootsText;
		sf:: Text myRemainingChancesText;
		sf:: Text enemyAngleText;
		sf:: Text enemyRemainingBulletsText;
		sf:: Text enemyCorrectShootsText;
		sf:: Text enemyRemainingChancesText;
		sf:: Font font;
		std::stringstream ss;
		


		
		

/*
		int leftEdgeX;
		int rightEdgeX;
		int groundX;
		int wallMinX;
		int wallMaxX;
	*/	
		int angle;
		
		EventHandler eventH;
		Graphic()
	{
		angle=0;
		setUpTexture(backgroundT, "/home/ropa/Desktop/background.png");
		setUpTexture(backgroundT, "/home/ropa/Desktop/background.png");
	    setUpTexture(myTankT, "/home/ropa/Desktop/firstPlayerTank.png");
	    setUpTexture(enemyTankT, "/home/ropa/Desktop/secondPlayerTank.png");
	    setUpTexture(myBulletT, "/home/ropa/Desktop/bullet.png");
	    //setUpTexture(enemyBulletT, "/home/ropa/Desktop/bullet.png");
	    setUpTexture(myBarrelT, "/home/ropa/Desktop/firstPlayerBarrel.png");
	    setUpTexture(enemyBarrelT, "/home/ropa/Desktop/secondPlayerBarrel.png");
		setUpTexture(explosionT, "/home/ropa/Desktop/explosion.png");

		setUpSprite(backgroundS, backgroundT);
		setUpSprite(myExplosionS, explosionT);
		setUpSprite(enemyExplosionS, explosionT);
		setUpSprite(myTankS, myTankT);
		setUpSprite(enemyTankS, enemyTankT);
		setUpSprite(myBulletS, myBulletT);
		setUpSprite(enemyBulletS, enemyBulletT);
		setUpSprite(myBarrelS, myBarrelT);
		setUpSprite(enemyBarrelS, enemyBarrelT);
		
		setSpirtePosition(backgroundS,140, 0);
/*		setSpirtePosition(myTankS,1000,500-myTankS.getLocalBounds().height);
		setSpirtePosition(enemyTankS,200,500-enemyTankS.getLocalBounds().height);
		setSpirtePosition(myBarrelS,1000-myTankS.getLocalBounds().width+53+myBarrelS.getLocalBounds().width,500-myTankS.getLocalBounds().height-4+myBarrelS.getLocalBounds().height);
		setSpirtePosition(enemyBarrelS,200+enemyTankS.getLocalBounds().width-34,500-enemyTankS.getLocalBounds().height-20+enemyBarrelS.getLocalBounds().height);
*/
		setUpText(font, "/home/ropa/Desktop/ariblk.ttf", myAngleText,1120 , 15, 10,sf::Color::Red);
		setUpText(font, "/home/ropa/Desktop/ariblk.ttf", myRemainingBulletsText, 1120, 55, 10,sf::Color::Red);
		setUpText(font, "/home/ropa/Desktop/ariblk.ttf", myCorrectShootsText, 1120, 95.0, 10,sf::Color::Red);
		setUpText(font, "/home/ropa/Desktop/ariblk.ttf", myRemainingChancesText, 1120, 135, 10,sf::Color::Red);
		setUpText(font, "/home/ropa/Desktop/ariblk.ttf", enemyAngleText, 5, 15, 10,sf::Color::Red);
		setUpText(font, "/home/ropa/Desktop/ariblk.ttf", enemyRemainingBulletsText, 5, 55, 10,sf::Color::Red);
		setUpText(font, "/home/ropa/Desktop/ariblk.ttf", enemyCorrectShootsText, 5, 95, 10,sf::Color::Red);
		setUpText(font, "/home/ropa/Desktop/ariblk.ttf", enemyRemainingChancesText, 5, 135, 10,sf::Color::Red);
		setUpSound(buffer,"/home/ropa/Desktop/Explosion.wav", explosionSound);
		setUpSound(shootBuffer,"/home/ropa/Desktop/shoot.wav", shootSound);
		createWindow(1254,549);

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
	
	
	
	
	
	
	
	
	

void createWindow(double w,double h){

	//window.create(sf::VideoMode(backgroundS.getLocalBounds().width+280,
					//backgroundS.getLocalBounds().height), "MINI TANKS");
window.create(sf::VideoMode(w,h), "MINI TANKS");

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


void setTextString(sf::Text &t,std::string s, int n){
	
	std::stringstream st;
	st.str("");
	st << n;
	
	
	t.setString(s+st.str());
}


void drawText(sf::Text &t){
	window.draw(t);

}


void setUpSound(sf::SoundBuffer &buffer,const std::string &fileName, sf::Sound &s){

	buffer.loadFromFile(fileName);
	s.setBuffer(buffer);
}


void playSound(sf::Sound &s){

	s.play();

}
void playShoot(){

	shootSound.play();

}

void printVector(){
	
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
		myAngleText.setString(ss.str());
		//setTextString(myAngleText, myAngle);

		eventH.enemyEvents.erase(eventH.enemyEvents.begin());
	}
			
}


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

double getSpriteX(sf::Sprite &s){
	
	return s.getPosition().x;
}


double getSpriteY(sf::Sprite &s){
	
	return s.getPosition().y;
}


void setSpriteSize(sf::Sprite &s, double width, double height){
	s.setScale((double)(width / getSpriteWidth(s)), (double)(height / getSpriteHeight(s)));
	
}

void setSpirtePosition(sf::Sprite &s,double x, double y){
	
	s.setPosition(x, y);
}


void pushMyEventVector(){
		
	if(pollEvent()){
		
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
	}
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



void updatePositions(double myTankX,double myTankY, double myBarrelX, double myBarrelY, double myBulletX, double myBulletY, double enemyTankX,
					double enemyTankY, double enemyBarrelX, double enemyBarrelY, double enemyBulletX, double enemyBulletY){
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
	//setAngle(ang);
	
}

void updateValues(int myAngle,int myRemainingBullets,int myCorrectShoots,int myRemainingChances,int enemyAngle,int enemyRemainingBullets,
					int enemyCorrectShoots,int enemyRemainingChances){
						
		myBarrelS.setRotation(myAngle-11);
		setTextString(myAngleText,"angle : ", myAngle);
		setTextString(myRemainingBulletsText,"Remaining Bullets : ", myRemainingBullets);
		setTextString(myCorrectShootsText,"Correct Shoots : ", myCorrectShoots);
		setTextString(myRemainingChancesText,"Remaining Chances : ", myRemainingChances);
		setTextString(enemyAngleText,"angle : ", enemyAngle);
		setTextString(enemyRemainingBulletsText,"Remaining Bullets : ", enemyRemainingBullets);
		setTextString(enemyCorrectShootsText,"Correct Shoots : ", enemyCorrectShoots);
		setTextString(enemyRemainingChancesText,"Remaining Chances : ", enemyRemainingChances);
		
}


void displayBoard(bool displayBullet, bool displayExplosion){
	
	//createWindow(1000,1000);
	printVector();
	if(isWindowOpen()){
		
		setOrigin(myBarrelS,getSpriteWidth(myBarrelS),getSpriteHeight(myBarrelS));
		setOrigin(enemyBarrelS,0,getSpriteHeight(enemyBarrelS));
	
		clearScreen();
		drawSprite(backgroundS);
		drawSprite(myTankS);
		drawSprite(enemyTankS);
		drawSprite(myBarrelS);
		drawSprite(enemyBarrelS);
		
		drawText(myAngleText);
		drawText(myRemainingBulletsText);
		drawText(myCorrectShootsText);
		drawText(myRemainingChancesText);
		drawText(enemyAngleText);
		drawText(enemyRemainingBulletsText);
		drawText(enemyCorrectShootsText);
		drawText(enemyRemainingChancesText);
		if(displayBullet){
		
			drawSprite(myBulletS);
		}
		if(displayExplosion){
			setSpirtePosition(myExplosionS, getSpriteX(myBulletS), getSpriteY(myBulletS)-getSpriteHeight(myExplosionS)/2);
			drawSprite(myExplosionS);
			playSound(explosionSound);
			
		}
		display();
		//sf::sleep(sf::milliseconds(50));

			
	}
}

void displayBoard_Bullet(){
	drawSprite(myBulletS);
	//createWindow();
	
	/*if(isWindowOpen()){
		
		setOrigin(myBarrelS,getSpriteWidth(myBarrelS),getSpriteHeight(myBarrelS));
		setOrigin(enemyBarrelS,0,getSpriteHeight(enemyBarrelS));
	
		clearScreen();
		drawSprite(backgroundS);
		drawSprite(myTankS);
		drawSprite(enemyTankS);
		drawSprite(myBarrelS);
		drawSprite(enemyBarrelS);
		drawSprite(myBulletS);
		drawSprite(enemyBulletS);
				
		drawText(myAngleText);
		drawText(myRemainingBulletsText);
		drawText(myCorrectShootsText);
		drawText(myRemainingChancesText);
		drawText(enemyAngleText);
		drawText(enemyRemainingBulletsText);
		drawText(enemyCorrectShootsText);
		drawText(enemyRemainingChancesText);
	

		display();
		//sf::sleep(sf::milliseconds(50));

			
	}*/
}


void displayBoard_Explosion(){
	
	//createWindow();
	
	/*if(isWindowOpen()){
		
		setOrigin(myBarrelS,getSpriteWidth(myBarrelS),getSpriteHeight(myBarrelS));
		setOrigin(enemyBarrelS,0,getSpriteHeight(enemyBarrelS));
	*/	
		setSpirtePosition(myExplosionS, getSpriteX(myBulletS), getSpriteY(myBulletS)-getSpriteHeight(myExplosionS));
		drawSprite(myExplosionS);
		//setSpirtePosition(enemyExplosionS, getSpriteX(enemyBulletS), getSpriteY(enemyBulletS)-getSpriteHeight(myExplosionS));
		playSound(explosionSound);
		/*clearScreen();
		drawSprite(backgroundS);
		drawSprite(myTankS);
		drawSprite(enemyTankS);
		drawSprite(myBarrelS);
		drawSprite(enemyBarrelS);
		drawSprite(myExplosionS);
		drawSprite(enemyExplosionS);
				
		drawText(myAngleText);
		drawText(myRemainingBulletsText);
		drawText(myCorrectShootsText);
		drawText(myRemainingChancesText);
		drawText(enemyAngleText);
		drawText(enemyRemainingBulletsText);
		drawText(enemyCorrectShootsText);
		drawText(enemyRemainingChancesText);
	

		display();
		//sf::sleep(sf::milliseconds(50));

		*/	
	//}
}


};



class Game{
	
	public:
	
	Graphic graphicInstance;
	Board myBoard;
	bool gameFinished;
	Tank myTank;
	Tank enemyTank;
	
	//EventHandler eventHandlerInstance;
	
	bool myShootFlag;
	bool myExitFlag;
	bool enemyShootFlag;
	bool enemyExitFlag;
		
	//EventDecoder eventDecoderInstance;
	
	Game(double mytankXPosition, double mytankYPosition, double mytankHeight, double mytankWidth, int mynumberOfRemainingBullets,
		int mynumberOfCorrectShoots, int mynumberOfRemainingChances,double mybarrelXPosition, double mybarrelYPosition, double mybarrelLength,
		 double myangle,double mybulletXPosition, double mybulletYPosition, double mybulletHeight, double mybulletWidth, double myspeed,double enemytankXPosition, double enemytankYPosition, double enemytankHeight, double enemytankWidth, int enemynumberOfRemainingBullets,
		int enemynumberOfCorrectShoots, int enemynumberOfRemainingChances,double enemybarrelXPosition, double enemybarrelYPosition, double enemybarrelLength,
		 double enemyangle,double enemybulletXPosition, double enemybulletYPosition, double enemybulletHeight, double enemybulletWidth, double enemyspeed , double width, double height, double wallX, double wallHeight, double margin):myTank(Tank(mytankXPosition, mytankYPosition, mytankHeight, mytankWidth, mynumberOfRemainingBullets,
		mynumberOfCorrectShoots, mynumberOfRemainingChances,mybarrelXPosition, mybarrelYPosition, mybarrelLength,
		 myangle,mybulletXPosition, mybulletYPosition, mybulletHeight, mybulletWidth, myspeed)),enemyTank(Tank(enemytankXPosition, enemytankYPosition, enemytankHeight, enemytankWidth, enemynumberOfRemainingBullets,
		 enemynumberOfCorrectShoots, enemynumberOfRemainingChances,enemybarrelXPosition, enemybarrelYPosition, enemybarrelLength,
		 enemyangle,enemybulletXPosition, enemybulletYPosition, enemybulletHeight, enemybulletWidth, enemyspeed)),myBoard(Board(width, height, wallX, wallHeight, margin)){
			 
			 	myShootFlag=false;
			 	myExitFlag=false;
			 	enemyShootFlag=false;
			 	enemyExitFlag=false;
			 
			 //EventDecoder eventDecoderInstance( this->myTank,this->enemyTank, this->eventHandlerInstance);
		 }
	
 



/*EventDecoder( ){
		myShootFlag=false;
		myExitFlag=false;
		enemyShootFlag=false;
		enemyExitFlag=false;
		//myTank=myT;
		//enemyTank=enemyT;
		//eventHandlerInstance=eh;
}
*/
		
		
		void setMyShootFlag(bool flag){
				myShootFlag= flag;
		}
		
		void setMyExitFlag(bool flag){
				myExitFlag= flag;
		}
		
		
		bool getMyShootFlag(){
				return myShootFlag;
		}
		
		bool getMyExitFlag(){
				return myExitFlag;
		}
		
		
void decodeMyEvent(){	
		
		std::string eventString;
		
		if(graphicInstance.eventH.myEvents.size()>0){
			//if(eventHandlerInstance.sentEventNumber >= 0)
			//{
				eventString = graphicInstance.eventH.myEvents.front();
				graphicInstance.eventH.myEvents.erase(graphicInstance.eventH.myEvents.begin());
				
				if(eventString.compare("U") == 0){
						
					myTank.barrel.increaseAngle();
				}
				
				else if(eventString.compare("D") == 0){
						
					myTank.barrel.decreaseAngle();
				}
				
				else if(eventString.compare("R") == 0){
						if(myTank.getXPosition()+myTank.getWidth()< myBoard.getWidth()-myBoard.getMargin())
							myTank.moveRight();
				}
				
				else if(eventString.compare("L") == 0){
						if(myTank.getXPosition() > myBoard.getWallX())
							myTank.moveLeft();
				}
				
				else if(eventString.compare("S") == 0){
					
					//myShootFlag=true;
					setMyShootFlag(true);
				}
				
				else if(eventString.compare("E") == 0){
					
					//myExitFlag=true;
					setMyExitFlag(true);
					
				}
				
			//}
		}
}

void decodeEnemyEvent(){	
	
		std::string eventString;	
		
		if(graphicInstance.eventH.enemyEvents.size()!=0){
			
				eventString = graphicInstance.eventH.enemyEvents.front();
				graphicInstance.eventH.enemyEvents.erase(graphicInstance.eventH.enemyEvents.begin());
				
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
	
	
	
	
	
	

	bool myShotHit(){
			if((myTank.barrel.bullet.getXPosition()+myTank.barrel.bullet.getWidth()> enemyTank.getXPosition() && myTank.barrel.bullet.getXPosition()< enemyTank.getXPosition()+ enemyTank.getWidth()) &&
					(myTank.barrel.bullet.getYPosition()+myTank.barrel.bullet.getHeight()> enemyTank.getYPosition() && myTank.barrel.bullet.getYPosition()< enemyTank.getYPosition()+ enemyTank.getHeight()))
				return true;
				
			else
				return false;
	}
	
	bool myShotHitTheWall(){
			if( (myTank.barrel.bullet.getXPosition() <= myBoard.getWallX()) &&(myTank.barrel.bullet.getXPosition() > myBoard.getWallX()-10) &&
					(myTank.barrel.bullet.getYPosition()+myTank.barrel.bullet.getHeight()> myBoard.getHeight()-myBoard.getWallHeight()))
				return true;
				
			else
				return false;
	}
	
	
	bool myShotIsOUt(){
			if(myTank.barrel.bullet.getXPosition()< myBoard.getMargin() ||
					myTank.barrel.bullet.getYPosition()> myBoard.getHeight() )
				return true;
				
			else
				return false;
	}
	
	
	
	
	bool enemyShotHit(){
			if((enemyTank.barrel.bullet.getXPosition()+enemyTank.barrel.bullet.getWidth()> enemyTank.getXPosition() && enemyTank.barrel.bullet.getXPosition()< enemyTank.getXPosition()+ enemyTank.getWidth()) &&
					(enemyTank.barrel.bullet.getYPosition()+enemyTank.barrel.bullet.getHeight()> enemyTank.getYPosition() && enemyTank.barrel.bullet.getYPosition()< enemyTank.getYPosition()+ enemyTank.getHeight()))
				return true;
				
			else
				return false;
	}
	
	bool enemyShotHitTheWall(){
			if( (enemyTank.barrel.bullet.getXPosition() == myBoard.getWallX()) &&
					(enemyTank.barrel.bullet.getYPosition()+enemyTank.barrel.bullet.getHeight()> myBoard.getHeight()-myBoard.getWallHeight()))
				return true;
				
			else
				return false;
	}
	
	
	bool enemyShotIsOUt(){
			if(enemyTank.barrel.bullet.getXPosition()> (myBoard.getWidth()+ 2* myBoard.getMargin()) ||
					enemyTank.barrel.bullet.getYPosition()> myBoard.getHeight() )
				return true;
				
			else
				return false;
	}
	
bool isGameFinished(){
		if(myTank.getRemainingChances() ==0 || enemyTank.getRemainingChances() ==0 ||
		 (myTank.getRemainingBullets() ==0 && enemyTank.getRemainingBullets() ==0 ))
			return true;
		else
			return false;
}

String whoIsTheWinner(){
	
		if(myTank.getCorrectShoots() > enemyTank.getCorrectShoots())
			return "Congratulations,you won the game:)";
		else if(enemyTank.getCorrectShoots() > myTank.getCorrectShoots())
			return "Oh,you lost the game:(";
		else
			return "No winner:|";
}

	
	
	void run(){
		
		//graphicInstance.createWindow(myBoard.getWidth(),myBoard.getHeight());
		double t;
			while(!isGameFinished()){
				graphicInstance.pushMyEventVector();
				decodeMyEvent();
				if(getMyExitFlag()){
					graphicInstance.exit();
					//break;
				}
				if(getMyShootFlag()){
					myTank.decreaseNumberOfRemainingBullets();
					t=0;
					graphicInstance.playShoot();
					do{
						
						(myTank.barrel).shoot(t);	
						//myTank.decreaseNumberOfRemainingBullets();
						t+=0.2;
						
					graphicInstance.updatePositions(myTank.getXPosition(),myTank.getYPosition(),(myTank.barrel).getXPosition(),(myTank.barrel).getYPosition(),
														((myTank.barrel).bullet).getXPosition(),((myTank.barrel).bullet).getYPosition(),enemyTank.getXPosition(),
														enemyTank.getYPosition(),(enemyTank.barrel).getXPosition(),(enemyTank.barrel).getYPosition(),
														((enemyTank.barrel).bullet).getXPosition(),((enemyTank.barrel).bullet).getYPosition());
					graphicInstance.updateValues((myTank.barrel).getAngle(),myTank.getRemainingBullets(),myTank.getCorrectShoots(),myTank.getRemainingChances(),
					(enemyTank.barrel).getAngle(),enemyTank.getRemainingBullets(),enemyTank.getCorrectShoots(),enemyTank.getRemainingChances());
					
				
						//graphicInstance.clearScreen();
						//graphicInstance.displayBoard();
						//graphicInstance.displayBoard_Bullet();
						
							
						
						graphicInstance.displayBoard(true,false);
					}while(!myShotHit() && !myShotHitTheWall() && !myShotIsOUt());
						//}while(t<10);
					

					if(myShotHit()){
						
						enemyTank.decreaseNumberOfRemainingChances();
						myTank.increaseNumberOfCorrectShoots();
						
						graphicInstance.updatePositions(myTank.getXPosition(),myTank.getYPosition(),(myTank.barrel).getXPosition(),(myTank.barrel).getYPosition(),
														((myTank.barrel).bullet).getXPosition(),((myTank.barrel).bullet).getYPosition(),enemyTank.getXPosition(),
														enemyTank.getYPosition(),(enemyTank.barrel).getXPosition(),(enemyTank.barrel).getYPosition(),
														((enemyTank.barrel).bullet).getXPosition(),((enemyTank.barrel).bullet).getYPosition());
					graphicInstance.updateValues((myTank.barrel).getAngle(),myTank.getRemainingBullets(),myTank.getCorrectShoots(),myTank.getRemainingChances(),
					(enemyTank.barrel).getAngle(),enemyTank.getRemainingBullets(),enemyTank.getCorrectShoots(),enemyTank.getRemainingChances());
					
						//graphicInstance.clearScreen();
						//graphicInstance.displayBoard();
						//graphicInstance.displayBoard_Explosion();
						graphicInstance.displayBoard(false,true);
						sf::sleep(sf::milliseconds(1000));
					}
					setMyShootFlag(false);
				}
				
				
				// setMyShootFlag(false);
				//eventDecoderInstance.decodeEnemyEvent();
				graphicInstance.updatePositions(myTank.getXPosition(),myTank.getYPosition(),(myTank.barrel).getXPosition(),(myTank.barrel).getYPosition(),
														((myTank.barrel).bullet).getXPosition(),((myTank.barrel).bullet).getYPosition(),enemyTank.getXPosition(),
														enemyTank.getYPosition(),(enemyTank.barrel).getXPosition(),(enemyTank.barrel).getYPosition(),
														((enemyTank.barrel).bullet).getXPosition(),((enemyTank.barrel).bullet).getYPosition());
				graphicInstance.updateValues((myTank.barrel).getAngle(),myTank.getRemainingBullets(),myTank.getCorrectShoots(),myTank.getRemainingChances(),
				(enemyTank.barrel).getAngle(),enemyTank.getRemainingBullets(),enemyTank.getCorrectShoots(),enemyTank.getRemainingChances());
				
				//if(!getMyShootFlag()){
			//	graphicInstance.clearScreen();
				//graphicInstance.displayBoard();
				graphicInstance.displayBoard(false,false);
			//}
			}
		
		if(isGameFinished()){
			string s=whoIsTheWinner();
				cout<< s;
		}
	
	}
	
};

int main()
{
	Game myGame(1000, 480, 60, 108, 10,0, 5,1029, 500,87.3613,11,943.2438, 483.331, 22, 20,
		  1000,200, 480, 50, 105, 10,0, 5, 271, 503, 74.6860,20, 338, 536, 20,22,1000,1254,549,627,270,140);
		  
	myGame.run();

	system("PAUSE");
	return 0;
}
