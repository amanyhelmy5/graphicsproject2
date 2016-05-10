#ifndef LEVEL2_H
#define LEVEL2_H
#include "game.h"
class Level2 : public Game
{
    std::shared_ptr<Collidable_Model> dead_body;
public:
	

    Level2(Renderer* renderer, Collision_Manager* collision_manager, EulerCamera* camera);
    ~Level2();
	
    virtual void initialize();
    virtual void update(float delta, Actions actions);
private:

};


#endif
