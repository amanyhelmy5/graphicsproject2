#ifndef LEVEL1_H
#define LEVEL1_H
#include "game.h"
class Level1: public Game
{

    std::shared_ptr<Collidable_Model> spider2;
    std::shared_ptr<Collidable_Model> spider;

public:
	
    ~Level1 ();
    Level1(Renderer* renderer, Collision_Manager* collision_manager, EulerCamera* camera);



    virtual void initialize();
    virtual void update(float delta, Actions actions);
private:
	 
};


#endif
