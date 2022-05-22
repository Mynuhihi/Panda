#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <math.h>
#include <stdlib.h>
#include <cstdlib>
#include <sstream>
#include <Menu.h>

int main(){

    int length, height;
    length = 1000;
    height = 500;
    float pi = 3.14;
    float ballRadius = 12;
    float lengthRtl = 120.f, widthRlt = 20.f;

    //music
    sf::Music music;
    music.openFromFile("music.wav");
    if(!music.openFromFile("music.wav")) return -1;

    //Sound
    sf::SoundBuffer ballSFX;
    ballSFX.loadFromFile("mixkit-game-ball-tap-2073.wav");
    sf::Sound sfx;
    sfx.setBuffer(ballSFX);
    //SoundMenu
    sf::SoundBuffer MenuSFX;
    MenuSFX.loadFromFile("Menu.wav");
    sf::Sound mnsfx;
    mnsfx.setBuffer(MenuSFX);
    //SoundGameOver
    sf::SoundBuffer GVSFX;
    GVSFX.loadFromFile("game over.wav");
    sf::Sound gameoversfx;
    gameoversfx.setBuffer(GVSFX);


    sf::RenderWindow window(sf::VideoMode(length, height), "PANDA");
    Menu menu (window.getSize().x, window.getSize().y);

       // load background
   sf::Texture Atexture;
   Atexture.loadFromFile("BackgrMenu.jpg");

   sf::Sprite Abackground;
   Abackground.setTexture(Atexture);

    //load font
   sf::Font font;
   font.loadFromFile("Playtoon-PersonalUse.otf");

   sf::Font font2;
   font2.loadFromFile("pricedown bl.otf");

   //Score

   int score1 = 0, score2 = 0;
   sf::Text Score;
   Score.setFont(font2);
   Score.setCharacterSize(50);
   Score.setFillColor(sf::Color::Red);
   Score.setPosition(length/2 - 50, height/2 + 150);


    sf::Text title;
    title.setFont(font);
    title.setPosition(length/2 - 170  , height/2 - 220);
    title.setFillColor(sf::Color::Black);
    title.setCharacterSize(90);
    title.setString("PANDA");

    while (window.isOpen())
    {
        sf:: Event event;
        window.draw(title);

        while (window.pollEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::KeyReleased:
                switch (event.key.code)
                {
                case sf::Keyboard::Up:
                    menu.MoveUp();
                    mnsfx.play();
                    break;

                case sf::Keyboard::Down:
                    menu.MoveDown();
                    mnsfx.play();
                    break;
                case sf::Keyboard::Return:
                    sf::RenderWindow Play(sf::VideoMode(length, height), "1:1");
                    sf::RenderWindow WithBot(sf::VideoMode(length, height), "Play against Bot");
                    sf::RenderWindow Instructions (sf::VideoMode(length, height), "Instructionss");

                      switch (menu.GetPressedItem())
                    {
                        case 0:
                          {

                           WithBot.close();
                           Instructions.close();
                        //sf::RenderWindow Play(sf::VideoMode(length, height), "Panda", sf::Style::Default );

                            //create the ball
                            sf::CircleShape ball(ballRadius);
                            ball.setFillColor(sf::Color::White);
                            ball.setOutlineThickness(6);
                            ball.setOutlineColor(sf::Color::Black);
                            ball.setPointCount(1000);
                            ball.setPosition(length/2-ball.getRadius(), height/2-ball.getRadius());

                            //create the paddle
                            sf::RectangleShape rectangle1(sf::Vector2f(widthRlt, lengthRtl));
                            rectangle1.setFillColor(sf::Color(25, 176, 60));
                            rectangle1.setOutlineThickness(6);
                            rectangle1.setOutlineColor(sf::Color(13, 77, 28));
                            rectangle1.setPosition(0, height/2 - lengthRtl/2);



                            sf::RectangleShape rectangle2(sf::Vector2f(widthRlt, lengthRtl));
                            rectangle2.setFillColor(sf::Color(25, 176, 60));
                            rectangle2.setOutlineThickness(6);
                            rectangle2.setOutlineColor(sf::Color(13, 77, 28));
                            rectangle2.setPosition(length-widthRlt, height/2- lengthRtl/2);


                           // load background
                           sf::Texture texture;
                           texture.loadFromFile("backgr.jpg");

                           sf::Sprite background;
                           background.setTexture(texture);

                            // load background2
                           sf::Texture texture3;
                           texture3.loadFromFile("Backgr 11 - With Bot.jpg");

                           sf::Sprite background3;
                           background3.setTexture(texture3);

                            //
                            sf::Text pauseMessenger;
                            pauseMessenger.setFont(font);
                            pauseMessenger.setPosition(length/2-200, height/2-50);
                            pauseMessenger.setFillColor(sf::Color::Black);
                            pauseMessenger.setCharacterSize(120);
                            pauseMessenger.setString("Panda");

                            sf::Text pauseMessenger2;
                            pauseMessenger2.setFont(font2);
                            pauseMessenger2.setPosition(length/2-150, height/2 + 110);
                            pauseMessenger2.setFillColor(sf::Color::Black);
                            pauseMessenger2.setCharacterSize(30);
                            pauseMessenger2.setString("Press space to play");

                            //define paddle properties
                            const float paddleSpeed = 300.f;

                            //define the paddle properties
                            const float ballSpeed = 400.f;
                            float angleBall = 90.f;



                            sf::Clock clock;
                            float deltatime=0.f;

                            //Game State
                            bool isPlaying = false;


                            //Game loop

                            while (Play.isOpen()){

                                    sf::Event event;
                                    deltatime = clock.restart().asSeconds();

                                    while (Play.pollEvent(event)){

                                          switch (event.type){

                                                 case sf::Event::Closed:
                                                  Play.close();
                                                  break;

                                          }
                                    }
                                    if(isPlaying == false && sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
                                        ball.setPosition(length/2-ball.getRadius(), height/2-ball.getRadius());
                                        rectangle1.setPosition(0, height/2 - lengthRtl/2);
                                        rectangle2.setPosition(length-widthRlt, height/2- lengthRtl/2);
                                        score1 = score2 = 0;

                                        isPlaying = true;
                                    }
                                    if( isPlaying ){
                                           //the leftPaddle Moving
                                        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)){

                                           sf::Vector2f pos1 = rectangle1.getPosition();
                                           if (pos1.y + lengthRtl + paddleSpeed*deltatime > height) rectangle1.setPosition(0, height - lengthRtl) ;
                                           else rectangle1.move(0, paddleSpeed*deltatime);

                                    }

                                        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)){

                                           sf::Vector2f pos1 = rectangle1.getPosition();

                                           if (pos1.y  - paddleSpeed*deltatime  <0) rectangle1.setPosition(0, 0) ;
                                           else rectangle1.move(0, -paddleSpeed*deltatime);

                                    };

                                    //the rightPaddle Movings
                                       if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){

                                       sf::Vector2f pos2 = rectangle2.getPosition();
                                       if (pos2.y + lengthRtl + paddleSpeed*deltatime > height) rectangle2.setPosition(length-widthRlt, height- lengthRtl) ;
                                       else rectangle2.move(0, paddleSpeed*deltatime);

                                    }

                                       else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){

                                       sf::Vector2f pos2 = rectangle2.getPosition();

                                       if (pos2.y  - paddleSpeed*deltatime  <0) rectangle2.setPosition(length-widthRlt, 0) ;
                                       else rectangle2.move(0, -paddleSpeed*deltatime);

                                    };

                                    // the ball moving
                                       float deltaS = ballSpeed*deltatime;
                                       ball.move(sin(angleBall*pi/180)*deltaS, cos(angleBall*pi/180)*deltaS);

                                    //check collision Top_Down Wall
                                       if (ball.getPosition().y <= 0 || ball.getPosition().y + 30>= height){
                                        angleBall = 180.f - angleBall;
                                        sfx.play();

                                    }

                                    //check collision with the paddle

                                    //leftPaddle

                                       if (ball.getPosition().x  <= rectangle1.getPosition().x + widthRlt
                                        && ball.getPosition().y + ballRadius >= rectangle1.getPosition().y
                                        && ball.getPosition().y + ballRadius <= rectangle1.getPosition().y + lengthRtl
                                        && ball.getPosition().x + ballRadius > rectangle1.getPosition().x + widthRlt/2)
                                      {
                                           if ( ball.getPosition().y + ballRadius > rectangle1.getPosition().y + lengthRtl/2){
                                            angleBall = 360.f - angleBall - rand() % 10;

                                         }
                                         else angleBall = 360.f - angleBall + rand() % 10;
                                         sfx.play();
                                      }

                                     //rightPaddle

                                       if (ball.getPosition().x + 2 * ballRadius >= rectangle2.getPosition().x
                                        && ball.getPosition().y + ballRadius    >= rectangle2.getPosition().y
                                        && ball.getPosition().y + ballRadius    < rectangle2.getPosition().y +lengthRtl
                                        && ball.getPosition().x + ballRadius < rectangle2.getPosition().x + widthRlt/2)
                                        {
                                         if ( ball.getPosition().y + ballRadius > rectangle2.getPosition().y + lengthRtl/2){
                                            angleBall = 360.f - angleBall - rand() % 10;

                                         }
                                         else angleBall = 360.f - angleBall + rand() % 10;
                                         sfx.play();
                                        }
                                        if ( ball.getPosition().x + ballRadius <= 0){
                                            pauseMessenger.setFont(font2);
                                            pauseMessenger.setPosition(length/2 - 160, height/2 +10 );
                                            pauseMessenger.setCharacterSize(50);
                                            pauseMessenger.setString("Choi ngu qua");

                                            score2++;
                                            if (score2 == 5) isPlaying = false;

                                            ball.setPosition(length/2-ball.getRadius(), height/2-ball.getRadius());

                                            angleBall = rand() % 360;
                                        }
                                        if ( ball.getPosition().x + ballRadius >= length){
                                            pauseMessenger.setFont(font2);
                                            pauseMessenger.setPosition(length/2 - 160, height/2 +10);
                                            pauseMessenger.setCharacterSize(50);
                                            pauseMessenger.setString(" ahihi do ngoc");

                                            score1++;
                                            if (score1 == 5) isPlaying = false;
                                            ball.setPosition(length/2-ball.getRadius(), height/2-ball.getRadius());

                                            angleBall = rand() % 360;
                                        }



                            }

                                   Play.clear(sf::Color::White);

                                    if(isPlaying){
                                          std::stringstream ss;
                                          ss << score1 << "  |  " << score2;
                                          Score.setString(ss.str());

                                        Play.draw(background3);
                                        Play.draw(Score);
                                        Play.draw(ball);
                                        Play.draw(rectangle1);
                                        Play.draw(rectangle2);

                                    }
                                    else {
                                        Play.draw(background);
                                        Play.draw(pauseMessenger);
                                        Play.draw(pauseMessenger2);
                                    }

                                    Play.display();

                        }

                                                break;}
                        case 1:
                            {

                           Play.close();
                           Instructions.close();
                        //sf::RenderWindow WithBot(sf::VideoMode(length, height), "Panda", sf::Style::Default );

                            //create the ball
                            sf::CircleShape ball(ballRadius);
                            ball.setFillColor(sf::Color::White);
                            ball.setOutlineThickness(6);
                            ball.setOutlineColor(sf::Color::Black);
                            ball.setPointCount(1000);
                            ball.setPosition(length/2-ball.getRadius(), height/2-ball.getRadius());

                            //create the paddle
                            sf::RectangleShape rectangle1(sf::Vector2f(widthRlt, lengthRtl));
                            rectangle1.setFillColor(sf::Color(25, 176, 60));
                            rectangle1.setOutlineThickness(6);
                            rectangle1.setOutlineColor(sf::Color(13, 77, 28));
                            rectangle1.setPosition(0, height/2 - lengthRtl/2);



                            sf::RectangleShape rectangle2(sf::Vector2f(widthRlt, lengthRtl));
                            rectangle2.setFillColor(sf::Color(25, 176, 60));
                            rectangle2.setOutlineThickness(6);
                            rectangle2.setOutlineColor(sf::Color(13, 77, 28));
                            rectangle2.setPosition(length-widthRlt, height/2- lengthRtl/2);


                           // load background
                           sf::Texture texture;
                           texture.loadFromFile("backgr.jpg");

                           sf::Sprite background;
                           background.setTexture(texture);

                            // load background2
                           sf::Texture texture3;
                           texture3.loadFromFile("Backgr 11 - With Bot.jpg");

                           sf::Sprite background3;
                           background3.setTexture(texture3);

                            //
                            sf::Text pauseMessenger;
                            pauseMessenger.setFont(font);
                            pauseMessenger.setPosition(length/2-200, height/2-50);
                            pauseMessenger.setFillColor(sf::Color::Black);
                            pauseMessenger.setCharacterSize(120);
                            pauseMessenger.setString("Panda");

                            sf::Text pauseMessenger2;
                            pauseMessenger2.setFont(font2);
                            pauseMessenger2.setPosition(length/2-150, height/2 + 110);
                            pauseMessenger2.setFillColor(sf::Color::Black);
                            pauseMessenger2.setCharacterSize(30);
                            pauseMessenger2.setString("Press space to WithBot");

                            //define paddle properties
                            const float paddleSpeed = 450.f;

                            //define the paddle properties
                            const float ballSpeed = 400.f; //van toc bong
                            float angleBall = 90.f; //huong cua bong, chon truc thang dung huong len tren



                            sf::Clock clock;
                            float deltatime=0.f;

                            //Bot properties
                            int botTarget = height/2;
                            float botPeriod = 0.2f;
                            float botTimer = 0.f;


                            //Game State
                            bool isPlaying = false;


                            //Game loop

                            while (WithBot.isOpen()){

                                    sf::Event event;
                                    deltatime = clock.restart().asSeconds();

                                    while (WithBot.pollEvent(event)){

                                          switch (event.type){

                                                 case sf::Event::Closed:
                                                  WithBot.close();
                                                  break;

                                          }
                                    }
                                    if(isPlaying == false && sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
                                        ball.setPosition(length/2-ball.getRadius(), height/2-ball.getRadius());
                                        rectangle1.setPosition(0, height/2 - lengthRtl/2);
                                        rectangle2.setPosition(length-widthRlt, height/2- lengthRtl/2);
                                        score1 = score2 = 0;

                                        isPlaying = true;
                                    }
                                    if( isPlaying ){
                                           //the leftPaddle Moving
                                        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)){

                                           sf::Vector2f pos1 = rectangle1.getPosition();
                                           if (pos1.y + lengthRtl + paddleSpeed*deltatime > height) rectangle1.setPosition(0, height - lengthRtl) ;
                                           else rectangle1.move(0, paddleSpeed*deltatime);

                                    }

                                        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)){

                                           sf::Vector2f pos1 = rectangle1.getPosition();

                                           if (pos1.y  - paddleSpeed*deltatime  <0) rectangle1.setPosition(0, 0) ;
                                           else rectangle1.move(0, -paddleSpeed*deltatime);

                                    };

                                    //the rightPaddle Movings

                                          //Update target of bot
                                    botTimer += deltatime;
                                    if (botTimer >= botPeriod)
                                    {
                                        if ( sin(angleBall*pi/180) > 0.f)
                                        {
                                            botTarget = ball.getPosition().y - ballRadius;
                                            botTimer =0.f;
                                        }
                                    }
                                    if (rectangle2.getPosition().y + lengthRtl/2 + lengthRtl/4 < botTarget)
                                    {
                                        sf::Vector2f pos = rectangle2.getPosition();
                                        if (pos.y + paddleSpeed*deltatime >= height) rectangle2.setPosition(pos.x, height - lengthRtl) ;
                                           else rectangle2.move(0,  paddleSpeed*deltatime);

                                    }
                                    else if (rectangle2.getPosition().y +lengthRtl/2 - lengthRtl/4 > botTarget)
                                    {
                                        sf::Vector2f pos = rectangle2.getPosition();
                                        if (pos.y  - paddleSpeed*deltatime  <0 ) rectangle2.setPosition(pos.x, 0) ;
                                           else rectangle2.move(0, - paddleSpeed*deltatime);

                                    }




                                    // the ball moving
                                       float deltaS = ballSpeed*deltatime;
                                       ball.move(sin(angleBall*pi/180)*deltaS, cos(angleBall*pi/180)*deltaS);

                                    //check collision Top_Down Wall
                                       if (ball.getPosition().y <= 0 || ball.getPosition().y + 30>= height){
                                        angleBall = 180.f - angleBall;
                                        sfx.play();


                                    }

                                    //check collision with the paddle

                                    //leftPaddle

                                       if (ball.getPosition().x  <= rectangle1.getPosition().x + widthRlt
                                        && ball.getPosition().y + ballRadius >= rectangle1.getPosition().y
                                        && ball.getPosition().y + ballRadius <= rectangle1.getPosition().y + lengthRtl
                                        && ball.getPosition().x + ballRadius > rectangle1.getPosition().x + widthRlt/2)
                                      {
                                           if ( ball.getPosition().y + ballRadius > rectangle1.getPosition().y + lengthRtl/2){
                                            angleBall = 360.f - angleBall - rand() % 10;

                                         }
                                         else angleBall = 360.f - angleBall + rand() % 10;
                                         sfx.play();
                                      }

                                     //rightPaddle

                                       if (ball.getPosition().x + 2 * ballRadius >= rectangle2.getPosition().x
                                        && ball.getPosition().y + ballRadius    >= rectangle2.getPosition().y
                                        && ball.getPosition().y + ballRadius    < rectangle2.getPosition().y +lengthRtl
                                        && ball.getPosition().x + ballRadius < rectangle2.getPosition().x + widthRlt/2)
                                        {
                                         if ( ball.getPosition().y + ballRadius > rectangle2.getPosition().y + lengthRtl/2){
                                            angleBall = 360.f - angleBall - rand() % 10;

                                         }
                                         else angleBall = 360.f - angleBall + rand() % 10;
                                         sfx.play();
                                        }
                                        if ( ball.getPosition().x + ballRadius <= 0){
                                            pauseMessenger.setFont(font2);
                                            pauseMessenger.setPosition(length/2 - 160, height/2 +10 );
                                            pauseMessenger.setCharacterSize(50);
                                            pauseMessenger.setString("Game Over! :) ");

                                            score2++;
                                            if (score2 == 5) isPlaying = false;

                                            ball.setPosition(length/2-ball.getRadius(), height/2-ball.getRadius());

                                            angleBall = rand() % 360;
                                        }
                                        if ( ball.getPosition().x + ballRadius >= length){
                                            pauseMessenger.setFont(font2);
                                            pauseMessenger.setPosition(length/2 - 160, height/2 +10);
                                            pauseMessenger.setCharacterSize(50);
                                            pauseMessenger.setString("Game Over! :) ");

                                            score1++;
                                            if (score1 == 5) isPlaying = false;
                                            ball.setPosition(length/2-ball.getRadius(), height/2-ball.getRadius());

                                            angleBall = rand() % 360;
                                        }



                            }

                                   WithBot.clear(sf::Color::White);

                                    if(isPlaying){
                                          std::stringstream ss;
                                          ss << score1 << "  |  " << score2;
                                          Score.setString(ss.str());

                                        WithBot.draw(background3);
                                        WithBot.draw(Score);
                                        WithBot.draw(ball);
                                        WithBot.draw(rectangle1);
                                        WithBot.draw(rectangle2);

                                    }
                                    else {
                                        WithBot.draw(background);
                                        WithBot.draw(pauseMessenger);
                                        WithBot.draw(pauseMessenger2);
                                    }

                                    WithBot.display();


                        }

                                                break;}
                        case 2:{
                           WithBot.close();
                           Play.close();
                           //load font

                           sf::Font font2;
                           font2.loadFromFile("pricedown bl.otf");


                            sf::Text pauseMessenger3;
                            pauseMessenger3.setFont(font2);
                            pauseMessenger3.setPosition(140, height/2 - 180 );
                            pauseMessenger3.setFillColor(sf::Color::White);
                            pauseMessenger3.setCharacterSize(20);
                            pauseMessenger3.setString(" 1:1:\n "
                                                      " \t    Player 1 uses the W key to move up and the S key to move down.\n "
                                                      " \t    Player 2 uses the Up key to move up and the Down key to move down.\n"
                                                      " \t    If one player misses the ball, the other player gets 1 point.\n"
                                                      " \t    Whoever reaches 5 points first would be the winner, and the game is over.\n \n"

                                                      " Playing against Bot: \n"
                                                      " \t    The player uses the W key to move up and the S key to move down. \n"
                                                      " \t    The player misses the ball, the bot gets 1 point and vice versa. \n"
                                                      " \t    Whoever reaches 5 points first would be the winner, and the game is over."
                                                      " \n \n \n \t \t \t \t \t \t \t \t \t \t           Press Escape to exit Instructions ");

                            while (Instructions.isOpen()){

                                    sf::Event event;

                                    while (Instructions.pollEvent(event)){

                                    if (event.type == sf::Event::Closed)
                                    {
                                        Instructions.close();
                                    }
                                    if (event.type == sf::Event::KeyPressed)
                                    {

                                        if (event.key.code == sf::Keyboard::Escape) {
                                            Instructions.close();
                                        }
                                    }



                                                   }
                                                   Instructions.clear();

                                                   Instructions.draw(pauseMessenger3);

                                                   Instructions.display();
                                                }
                                                break;
                                                }
                            case 3:
                                window.close();
                                break;
                        }

                    }
                    break;


                case sf::Event::Closed:
                    window.close();
                    break;
                }
            }
            window.clear();
            window.draw(Abackground);
            menu.draw(window);
            window.draw(title);
            music.play();
            window.display();
        }


    }


