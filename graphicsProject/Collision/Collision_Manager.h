#ifndef Collision_Manager_h__
#define Collision_Manager_h__

#include <vector>
#include "Collidable.h"

class Collision_Manager
{
	std::vector<Collidable*> collidableModels;
public:
	Collision_Manager(void);
	~Collision_Manager(void);

	void SetCollidableModels(std::vector<Collidable*> fCollid_Models);
	void AddCollidableModel(Collidable* model);
	void UpdateCollisions();
	void RemoveCollidableModel(int model_Index);
	void RemoveCollidableModel(Collidable* model);
	
};

#endif // Collision_Manager_h__
