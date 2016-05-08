#ifndef LEVEL2_H
#define LEVEL2_H
#include "game.h"
class Level2 : public Game
{
public:
	

	Level2(Renderer* renderer);
	~Level2();
	
    virtual void initialize();
    virtual void update(float delta, Actions p_actions);
private:

};


#endif
