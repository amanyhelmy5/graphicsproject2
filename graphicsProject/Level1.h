#ifndef LEVEL1_H
#define LEVEL1_H
#include "game.h"
class Level1: public Game
{
public:
	
	~Level1 ();
	Level1(Renderer* renderer);

    virtual void initialize();
    virtual void update(float delta, Actions p_actions);
private:
	 
};


#endif
