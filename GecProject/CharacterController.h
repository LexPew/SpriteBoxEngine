#pragma once
#include "Component.h"
#include "GameObject.h"
#include "SFML/Graphics.hpp"
#include "Rigidbody.h"
class CharacterController : public Component
{
	float baseMovementSpeed = 10.0f;
	Rigidbody* physics{ nullptr };
	void Start() override
	{
		physics = Owner->GetComponent<Rigidbody>();
	}
	void Update(const float p_deltaTime) override
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) 
		{
			physics->SetVelocity({ physics->GetVelocity().X - (baseMovementSpeed * p_deltaTime), physics->GetVelocity().Y });
		}
		else 		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			physics->SetVelocity({ physics->GetVelocity().X + (baseMovementSpeed * p_deltaTime), physics->GetVelocity().Y });
		}
	}
};
