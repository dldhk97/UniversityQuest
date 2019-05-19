#include "User.h"

//Getter
std::string User::getId()
{
	return this->id;
}
int User::getUserState()
{
	return this->userState;
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