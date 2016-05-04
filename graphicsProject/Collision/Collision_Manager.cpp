#include "Collision_Manager.h"


Collision_Manager::Collision_Manager(void)
{
}


Collision_Manager::~Collision_Manager(void)
{
}

void Collision_Manager::UpdateCollisions()
{
	for (int i = 0; i < collidableModels.size(); i++)
	{
		for (int j = i + 1; j < collidableModels.size(); j++)
		{
			if (collidableModels[i]->Get_BoundingBox().IsIntersecting(collidableModels[j]->Get_BoundingBox()))
			{
				collidableModels[i]->Collided();
				collidableModels[j]->Collided();
			}
		}
	}
}

void Collision_Manager::SetCollidableModels(std::vector<Collidable_Model*> fCollid_Models)
{
	collidableModels = fCollid_Models;
}

void Collision_Manager::AddCollidableModel(Collidable_Model* model)
{
	collidableModels.push_back(model);
}

void Collision_Manager::RemoveCollidableModel(int model_Index)
{
	collidableModels.erase(collidableModels.begin() + model_Index);
}

void Collision_Manager::RemoveCollidableModel(Collidable_Model* model)
{
	for (int i = 0; i < collidableModels.size(); i++)
	{
		//comparing the addresses.
		if (model == collidableModels[i])
		{
			RemoveCollidableModel(i);
			return;
		}
	}
}

