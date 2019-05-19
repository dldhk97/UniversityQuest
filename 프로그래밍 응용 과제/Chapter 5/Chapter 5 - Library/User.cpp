#include "User.h"
#include "Professor.h"

//Getter
std::string User::getId()
{
	return this->id;
}
int User::getUserState()
{
	return this->userState;
}
std::string User::getName()
{
	return this->name;
}
//Setter
void User::setId(std::string id)
{
	this->id = id;
}
void User::setUserState(int userState)
{
	this->userState = userState;
}
//Display
void User::display()
{

}
//Compare
int User::getPriority(User* user)
{
	if (typeid(*user).name() == typeid(Professor).name())
		return PROFESSOR;
	else
		return STUDENT;
}
bool User::compare(User* user)
{
	int thisPriority = getPriority(this);
	int targetPriority = getPriority(user);

	if (thisPriority > targetPriority)
		return true;
	else if (thisPriority == targetPriority)
		if (this->getName() > user->getName())
			return true;
	return false;
}