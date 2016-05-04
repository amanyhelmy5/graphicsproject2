#ifndef Collision_Manager_h__
#define Collision_Manager_h__

#include <vector>
#include "Collidable_Model.h"

class Collision_Manager
{
	std::vector<Collidable_Model*> collidableModels;
public:
	Collision_Manager(void);
	~Collision_Manager(void);

	void SetCollidableModels(std::vector<Collidable_Model*> fCollid_Models);
	void AddCollidableModel(Collidable_Model* model);
	void UpdateCollisions();
	void RemoveCollidableModel(int model_Index);
	void RemoveCollidableModel(Collidable_Model* model);
	
};

#endif // Collision_Manager_h__
