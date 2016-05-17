#ifndef LEVEL2_H
#define LEVEL2_H
#include "game.h"
class Level2 : public Game
{
    std::shared_ptr<Collidable_Model> dead_body;
	std::shared_ptr<Collidable_Model> house;
    std::shared_ptr<Collidable_Model> enemy1;
    std::shared_ptr<Collidable_Model> enemy2;
    std::shared_ptr<Collidable_Model> enemy3;
    std::shared_ptr<Collidable_Model> enemy4;
    std::shared_ptr<Collidable_Model> enemy5;
    std::shared_ptr<Collidable_Model> enemy6;
    std::shared_ptr<Collidable_Model> enemy7;
public:
	

    Level2(Renderer* renderer, Collision_Manager* collision_manager, EulerCamera* camera);
    ~Level2();
	
    virtual void initialize();
    virtual void update(float delta, Actions actions);
private:

};


#endif
