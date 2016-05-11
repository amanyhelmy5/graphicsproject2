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

void Collision_Manager::SetCollidableModels(std::vector<Collidable*> fCollid_Models)
{
	collidableModels = fCollid_Models;
}

void Collision_Manager::AddCollidableModel(Collidable* model)
{
	collidableModels.push_back(model);
}

void Collision_Manager::RemoveCollidableModel(int model_Index)
{
	collidableModels.erase(collidableModels.begin() + model_Index);
}

void Collision_Manager::RemoveCollidableModel(Collidable* model)
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

void Collision_Manager::empty_collidable_models()
{
	if (collidableModels.size() > 0)
		collidableModels.clear();
}

