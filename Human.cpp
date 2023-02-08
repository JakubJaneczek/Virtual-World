#include "Human.h"

Human::Human()
{
}

Human::Human(World* mWorld, const COORDINATES mPosition)
	:Animal(mWorld, mPosition)
{
	this->power = HUMAN_POWER;
	this->initiative = HUMAN_INITIATIVE;
	this->age = 1;
	this->sign = HUMAN;
}

Human::Human(World* mWorld, const COORDINATES mPosition, const int mAge, const int mInitiative, const int mPower, const int turnsLeft, const int turnsCooldown)
	: Animal(mWorld, mPosition, mAge, mInitiative, mPower)
{
	this->turnsLeft = turnsLeft;
	this->turnsCooldown = turnsCooldown;
	this->sign = HUMAN;
}

const void Human::Print()
{
	std::cout << HUMAN;
}

void Human::SetCooldown()
{
	turnsCooldown = 10;
}

void Human::DecreaseCooldown()
{
	if(turnsCooldown > 0)
	turnsCooldown--;
}

void Human::SetTurnsLeft()
{
	turnsLeft = 5;
}

void Human::DecreaseTurnsLeft()
{
	if (turnsLeft > 0)
		turnsLeft--;
	else if (turnsLeft == 0)
		DisableAbility();
}

int Human::GetCooldown()
{
	return turnsCooldown;
}

int Human::GetTurnsLeft()
{
	return turnsLeft;
}

void Human::Action()
{
	if (this->GetAlive() == 1)
	{
		DecreaseCooldown();
		DecreaseTurnsLeft();

		char choice;
		do
		{
			std::cout << "Choose what you want to do: \n 1 -> Special ability \n 2 -> Move \n 3 -> End of move \n";
			std::cin >> choice;
			switch (choice)
			{
			case '1':
				if (GetCooldown() == 0)
				{
					UseAbility();
					SetTurnsLeft();
					SetCooldown();
					std::cout << "Special ability (Alzur's Shield) activated! \n";
				}
				else
				{
					std::cout << "Ability on cooldown! \n";
				}
				break;
			case '2':
				char mDir;
				std::cin >> mDir;
				switch (mDir)
				{
				case 'w': // UP
					DirectionOfMove(UP);
					break;
				case 's': // DOWN
					DirectionOfMove(DOWN);
					break;
				case 'a': // LEFT
					DirectionOfMove(LEFT);
					break;
				case 'd': // RIGHT
					DirectionOfMove(RIGHT);
					break;
				}
				break;
			case '3':
				break;
			}
		} while (choice != '2' && choice != '3');
	}
}

void Human::DirectionOfMove(DIRECTION mDir)
{
	if (NextPositon(mDir, 1) == nullptr)
	{
		Move(mDir);
	}
	else
	{
		NextPositon(mDir, 1)->Collision(this);
		if (NextPositon(mDir, 1) == nullptr)
		{
			Move(mDir);
		}
	}
}

void Human::UseAbility()
{
	AlzurShield = true;
}

void Human::DisableAbility()
{
	AlzurShield = false;
}

void Human::Collision(Organism* organismToCollide)
{
	if (AlzurShield == true)
	{
		std::string log = "";
		log += organismToCollide->GetSign();
		log += " from field (";
		log += std::to_string(organismToCollide->GetPosition().x);
		log += ", ";
		log += std::to_string(organismToCollide->GetPosition().y);
		log += ") was stopped by ";
		log += this->GetSign();
		log += " ,and his Alzur's Shield, from field (";
		log += std::to_string(this->GetPosition().x);
		log += ", ";
		log += std::to_string(this->GetPosition().y);
		log += ").";
		worldReference->Info(log);
	}
	else
	{
		if (organismToCollide->GetPower() < this->GetPower())
		{
		std::string log = "";
		log += organismToCollide->GetSign();
		log += " from field (";
		log += std::to_string(organismToCollide->GetPosition().x);
		log += ", ";
		log += std::to_string(organismToCollide->GetPosition().y);
		log += ") attacks stronger ";
		log += this->GetSign();
		log += " from field (";
		log += std::to_string(this->GetPosition().x);
		log += ", ";
		log += std::to_string(this->GetPosition().y);
		log += ") and dies.";
		worldReference->Info(log);
		worldReference->world[organismToCollide->GetPosition().y][organismToCollide->GetPosition().x] = nullptr;
		organismToCollide->SetAlive();
		}
		else
		{
		std::string log = "";
		log += organismToCollide->GetSign();
		log += " from field (";
		log += std::to_string(organismToCollide->GetPosition().x);
		log += ", ";
		log += std::to_string(organismToCollide->GetPosition().y);
		log += ") attacks weaker ";
		log += this->GetSign();
		log += " from field (";
		log += std::to_string(this->GetPosition().x);
		log += ", ";
		log += std::to_string(this->GetPosition().y);
		log += ") and kills his opponent.";
		worldReference->Info(log);
		worldReference->world[this->position.y][this->position.x] = nullptr;
		this->SetAlive();
		}
	}
}
