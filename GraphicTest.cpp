#include <SFML/Graphics.hpp>
#include <SFML/Window/Mouse.hpp>
#include <string>
#include <sstream>
#include <math.h>
#define PI 3.14159
int main(){


sf:: Text text;
sf:: Font font;
std:: stringstream ss;
if(!font.loadFromFile("/home/ropa/Desktop/ariblk.ttf")){
}
text.setFont(font);
text.setPosition(20,20);
text.setCharacterSize(30);
text.setColor(sf::Color::Red);






sf::Texture boll;
boll.loadFromFile("background.png");
sf::Sprite bolls(boll);
bolls.setPosition(140,0);
sf::Texture t1;
t1.loadFromFile("secondPlayerTank.png");
sf::Sprite t1S(t1);
t1S.setPosition(200,500-t1S.getLocalBounds().height);
sf::Texture t2;
t2.loadFromFile("firstPlayerTank.png");
sf::Sprite t2S(t2);
t2S.setPosition(1000,500-t2S.getLocalBounds().height);

sf::Texture l1;
l1.loadFromFile("firstPlayerBarrel.png");
sf::Sprite l1S(l1);
l1S.setPosition(1000-t2S.getLocalBounds().width+53+l1S.getLocalBounds().width,500-t2S.getLocalBounds().height-4+l1S.getLocalBounds().height);
sf::Texture l2;
l2.loadFromFile("secondPlayerBarrel.png");
sf::Sprite l2S(l2);
l2S.setPosition(200+t1S.getLocalBounds().width-34,500-t1S.getLocalBounds().height-20+l2S.getLocalBounds().height);

sf::Texture bullet;
bullet.loadFromFile("bullet.png");
sf::Sprite bulletS(bullet);
//bulletS.setPosition(1000-t2S.getLocalBounds().width+53,500-t2S.getLocalBounds().height-4);
//bulletS.setPosition(l1S.getPosition().x-l1S.getLocalBounds().width,l1S.getPosition().y-l1S.getLocalBounds().height);

sf::Texture leftBullet;
leftBullet.loadFromFile("bullet.png");
sf::Sprite leftBulletS(leftBullet);
leftBulletS.setPosition(l2S.getPosition().x+l2S.getLocalBounds().width,l2S.getPosition().y-l2S.getLocalBounds().height);


sf::RenderWindow window;
sf::Event event;
//sf::RenderWindow window(sf::VideoMode(1200,700), "SFML works!");

double x;
double y;


double d= sqrt(pow(l1S.getLocalBounds().width,2)+pow(l1S.getLocalBounds().height,2));
//double alpha=12;
double z;
double alpha=atan((double)(l1S.getLocalBounds().height/l1S.getLocalBounds().width));
int alphaD=(alpha*180/PI)-4;
window.create(sf::VideoMode(bolls.getLocalBounds().width+280, bolls.getLocalBounds().height), "SFML works!");
		l1S.setOrigin(l1S.getLocalBounds().width,l1S.getLocalBounds().height);
		l2S.setOrigin(0,l2S.getLocalBounds().height);

	while(window.isOpen()){
		//looleS.setRotation(45);
		
		while(window.pollEvent(event)){
			if (event.type == sf::Event::Closed)
				window.close();
				
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
				{
//z=(double)(fmod((l1S.getRotation()+alpha),360)*PI/180);
					z=(double)((l1S.getRotation())*PI/180)+alpha;
//z=(double)((l1S.getRotation()+alpha)*PI/180);
				l1S.rotate(1);
				l2S.rotate(-1);

//bulletS.setPosition(l1S.getPosition().x-l1S.getLocalBounds().width,l1S.getPosition().y-l1S.getLocalBounds().height);
				
				}






if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
				{
//z=(double)(fmod((l1S.getRotation()+alpha),360)*PI/180);
					z=(double)((l1S.getRotation())*PI/180)+alpha;
//z=(double)((l1S.getRotation()+alpha)*PI/180);
				l1S.rotate(-1);
				l2S.rotate(+1);

//bulletS.setPosition(l1S.getPosition().x-l1S.getLocalBounds().width,l1S.getPosition().y-l1S.getLocalBounds().height);
				
				}


if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
				{
			
				t2S.move(5,0);
				l1S.move(5,0);
				}



if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
				{
				t2S.move(-5,0);
				l1S.move(-5,0);
				
				}



			if (sf::Keyboard::isKeyPressed(sf::Keyboard::RShift))
			{
		
				for(double t=0;t<=2000/9.8;t+=0.1){
					//x = (-1000*cos(l1S.getRotation())* t)*0.01+l1S.getPosition().x-l1S.getLocalBounds().width;
					//y = ((0.5 * 9.8 * t * t) +(-1000*0.642*t))*0.01+l1S.getPosition().y-l1S.getLocalBounds().height;


					 z=(double)(fmod((l1S.getRotation()+alphaD),360)*PI/180); 
					//z=(double)((l1S.getRotation())*PI/180)+alpha;
					x = (-1000*cos(z)* t)*0.01+l1S.getPosition().x-d*cos(z);
					y = ((0.5 * 9.8 * t * t) +(-1000*sin(z)*t))*0.01+l1S.getPosition().y-d*sin(z);






		ss.str("");
		ss << fmod(l1S.getRotation()+alphaD,360);
		//ss << fmod((z*180/PI),360);
		text.setString(ss.str());



					//t=t+0.1;
					//x++;
					//y++;
					window.clear();
					bulletS.setPosition(x,y);
					window.draw(bolls);
					window.draw(t1S);
					window.draw(t2S);
					window.draw(l1S);
					window.draw(l2S);
					window.draw(bulletS);
					window.draw(leftBulletS);
					window.draw(text);

					window.display();
	
				}
		
			}

		
		}


		ss.str("");
		ss << fmod(l1S.getRotation()+alphaD,360);
	//	ss << fmod((l1S.getRotation()+alpha),360);
		//ss << fmod((z*180/PI),360);
		text.setString(ss.str());

		


		window.clear();
		bulletS.setPosition(x,y);
		window.draw(bolls);
		window.draw(t1S);
		window.draw(t2S);
		window.draw(l1S);
		window.draw(l2S);
		window.draw(bulletS);
		window.draw(leftBulletS);
		window.draw(text);
		window.display();
		/*window.clear();
		window.draw(bolls);
		window.draw(t1S);
		window.draw(t2S);
		window.draw(l1S);
		window.draw(l2S);
		window.draw(bulletS);

		window.display();
		*/

	}
	
	system("pause");
	
	return 0;
}
