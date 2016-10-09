#include "NBody.hpp"

int main(int argc, char* argv[]){

    std::string store;//stores the input from the file
    std::string name;//name of planet
    std::vector<Body> objects;//vector of objects to store all objects
    int numberOfPlanets;
    float radius;//radius of window
    float x_p, y_p, x_v, y_v, mass;

    //stores the number of planets
    std::cin >> store;
    std::stringstream(store) >> numberOfPlanets;

    //stores the radius of the window
    std::cin >> store;
    std::stringstream(store) >> radius;

    //loop that stores all relevant data from the file
    for (int x = 0; x < numberOfPlanets; x++){
        
        std::cin >> store;
        std::stringstream(store) >> x_p;
        
        std::cin >> store;
        std::stringstream(store) >> y_p;
        
        std::cin >> store;
        std::stringstream(store) >> x_v;
        
        std::cin >> store;
        std::stringstream(store) >> y_v;
        
        std::cin >> store;
        std::stringstream(store) >> mass;
        
        std::cin >> store;
        name = store;
        //create a temp body to hold values
        Body newBody(x_p,y_p,x_v,y_p,mass,name);

        //push the new body into the array to store it
        objects.push_back(newBody);
    }
    
    //take the data inside the 
    //vector of bodies and print it on the screen using SFML
    
    //need to access the right planet
    for(int i = 0; i < numberOfPlanets; i++){
               
        //load image
        sf::Image image;
        if(!image.loadFromFile(objects[i].getFilename())){
            std::cout << "ERROR: could not load image from file" << std::endl;
            return -1;
        }

        //load image into a texture
        sf::Texture texture;
        texture.loadFromImage(image);
        //create new sprite with the texture
        sf::Sprite sprite;
        sprite.setTexture(texture);
        
        //using the initial x, y position find the
        //corresponding x, y coords in SFML window and then set them as such
        sprite.setPosition(objects[i].getPosition());
        
        //store the sprites into the sprite array
        //sprites.push_back(sprite);
    }
    
    //create the window
    sf::RenderWindow window(sf::VideoMode(radius * 2, radius * 2), "Ps3a Universe");
    //display window
    while(window.isOpen()){
        sf::Event event;
        while(window.pollEvent(event)){
            if(event.type == sf::Event::Closed)    
                window.close();
        }
        window.clear(sf::Color::Black);
        //display all the planets
        for(int i = 0; i < numberOfPlanets; ++i)
            window.draw(sprites[i]);
        window.display();
    }
    
    return 0;
}