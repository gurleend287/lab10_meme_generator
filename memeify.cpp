
#include <SFML/Graphics.hpp>
#include "memer.h"
#include <string>
int main(int argc, char** argv)
{
    sf::Image generateImage;
    generateImage.loadFromFile(argv[1]); //load image from file
    memer *newMeme = new memer; //create new class

    switch(argc)
    {
        case 3: //given only top text
        {
            sf::String TopText = argv[2];
            generateImage = newMeme->generateMeme(generateImage, TopText);
            break;
        }
        case 4: //given top text + topX coord
        {
            sf::String TopText = argv[2];
            sf::String BottomText = argv[3];

            generateImage = newMeme->generateMeme(generateImage, TopText, BottomText);
            break;
        }
        case 5: //given top text + topX coord + topY coord
        {
            sf::String TopText = std::string(argv[2]);
            sf::String BottomText = argv[3];

            int topXcoord = std::stoi(argv[4]);
            generateImage = newMeme->generateMeme(generateImage, TopText, BottomText, topXcoord);
            break;
        }

        case 6: //given bottom text
        {
            sf::String TopText = argv[2];
            sf::String BottomText = argv[3];
            int topXcoord = std::stoi(argv[4]);
            int topYcoord = std::stoi(argv[5]);

            generateImage = newMeme->generateMeme(generateImage, TopText, BottomText, topXcoord, topYcoord);
            break;
        }

        case 7: //given bottom text + bottomX coord
        {
            sf::String TopText = argv[2];
            sf::String BottomText = argv[3];
            int topXcoord = std::stoi(argv[4]);
            int topYcoord = std::stoi(argv[5]);
            int bottomXcoord = std::stoi(argv[6]);

            generateImage = newMeme->generateMeme(generateImage, TopText, BottomText, topXcoord, topYcoord, bottomXcoord);
            break;
        }

        case 8: //given bottom text + bottomX + bottomY cord
        {
            sf::String TopText = argv[2];
            sf::String BottomText = argv[3];
            int topXcoord = std::stoi(argv[4]);
            int topYcoord = std::stoi(argv[5]);
            int bottomXcord = std::stoi(argv[6]);
            int bottomYcord = std::stoi((argv[7]));

            generateImage = newMeme
                    ->generateMeme(generateImage, TopText, BottomText, topXcoord, topYcoord, bottomXcord, bottomYcord);
            break;

        }
    }

    generateImage.flipVertically(); //flip image
    sf::Texture texture; //make texture
    texture.loadFromImage(generateImage);
    sf::Vector2<unsigned int> size = generateImage.getSize(); //get size of image
    sf::Sprite sprite(texture);
    sf::RenderWindow window(sf::VideoMode(size.x, size.y), "Meme Generator"); //construct a render window
    while(window.isOpen()){
        sf::Event event; //make an event
        while(window.pollEvent(event)){
            if(event.type == sf::Event::Closed){ //close window if event = close
                window.close();
            }
        }

        window.clear(); //clear window
        window.draw(sprite); //draw sprite and display while window is open
        window.display();
    }
    generateImage.saveToFile("doge-meme.jpg"); //save to file after generating image
    delete newMeme; //delete allocated memory

    return 0;

}