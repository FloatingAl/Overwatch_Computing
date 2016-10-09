#include "NBody.hpp"


void virtual draw(sf::RenderTarget &target, sf::RenderStates states) const{
  target.draw(_filename,states);
}

Body::Body(float xCoord, float yCoord, float xVelocity, float yVelocity, float mass, std::string fileName){
  //setting vars to specifications
  _position.x = xCoord;
  _position.y = yCoord;
  _velocity.x = xVelocity;
  _velocity.y = yVelocity;
  _mass = mass;
  _filename = fileName;
  
}

 sf::Vector2f Body::getPosition(){
  return _position;
 }
 
 sf::Vector2f Body::getVel(){
  return _velocity;
 }
 
 float Body::getMass(){
  return _mass;
 }
 
 std::string Body::getFilename(){
  return _filename;
 }

 Body::~Body(){

 }


 /*friend istream &operator>>( istream &input, const Body &B){

      input >> B.
 }*/





//in main, before we make a new Body, we read in the file name that has the proper characteristics, save them into multiple vars or strings, then feed them into the Body constructor
