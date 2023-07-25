#include <SFML/Graphics.hpp>
#include "memer.h"

sf::Image memer::generateMeme(sf::Image base, sf::String topText, sf::String bottomText, int topX, int topY,
                              int bottomX, int bottomY) {
    sf::Vector2<unsigned int> size = base.getSize(); //get size of image
    sf::Texture texture;
    texture.loadFromImage(base); //construct and convert to texture
    sf::Sprite sprite(texture);//construct sprite
    sf::RenderTexture windowTexture;
    windowTexture.create(size.x, size.y);
    windowTexture.draw(sprite); //renderTexture of sprite
    sf::Font font; //construct font
    font.loadFromFile("Cave-story.ttf"); //load font from file
    sf::Text WriteTopText;//construct top text
    WriteTopText.setFont(font);
    WriteTopText.setString(topText);
    WriteTopText.setOrigin(WriteTopText.getLocalBounds().width/2.0f, WriteTopText.getLocalBounds().height/2.0f);
    if(topX == -1 && topY == -1){
        WriteTopText.setPosition(size.x / 2, size.y / 3);
    }
    else if(topX != -1 && topY == -1){
        WriteTopText.setPosition(topX, size.y / 3);
    }
    else if(topX != -1 && topY != -1){
        WriteTopText.setPosition(topX, topY);
    }
    windowTexture.draw(WriteTopText);


    sf::Text WriteBottomText; //construct bottom text
    WriteBottomText.setFont(font);
    WriteBottomText.setString(bottomText);
    WriteBottomText.setOrigin(WriteBottomText.getLocalBounds().width /2, WriteBottomText.getLocalBounds().height/2); //set origin in the middle of the text
    if(bottomText != "" && bottomX == -1 && bottomY == -1){ //if given no bounds

        WriteBottomText.setPosition(size.x / 2, (size.y*2) / 3);
    }
    else if(bottomText != "" && bottomX != -1 && bottomY == -1){ //if given only bottomX bound

        WriteBottomText.setPosition(bottomX, (size.y * 2) / 3);
    }
    else if(bottomText != "" && bottomX != -1 && bottomY != -1){
        WriteBottomText.setPosition(bottomX, bottomY);
    }

    //draw text
    windowTexture.draw(WriteBottomText);

    sf::Image returnImage;
    texture = windowTexture.getTexture();
    returnImage = texture.copyToImage(); //get image from texture and return image
    return returnImage;
}

