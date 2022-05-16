//Course: SENG1120
//Coded by: Alex Mendes 

#include "Cities.h"
#include <cstdlib>

// Constructors
Cities::Cities()
{
	name = "";
	population = 0;
}

Cities::Cities(string name_, int population_)
{
	name = name_;
	population = population_;	
}

// empty destructor
Cities::~Cities()
{
	// no object clean up required
}

// Mutator methods (setters)
void Cities::set_name(const string name_) 
{
	name = name_;
}

void Cities::set_population(const int population_)
{ 
	population = population_;
}

// Accessor methods (getters)
string Cities::get_name() const 
{
	return name;
}

int Cities::get_population() const 
{
	return population;
}

// overloaded ostream operator
ostream& operator <<(ostream& out, const Cities& value)
{
    out << "(" << value.get_name() << "," << value.get_population() << ") ";
    return out;
}

// overloaded == operator
bool operator == (const Cities& s1, const Cities& s2)
{
    if (s1.get_name() == s2.get_name())
		return true;
	else
		return false;
}

// overloaded < operator
bool operator < (const Cities& s1, const Cities& s2)
{
    if (s1.get_name() < s2.get_name())
		return true;
	else
		return false;
}

// overloaded > operator
bool operator > (const Cities& s1, const Cities& s2)
{
    if (s1.get_name() > s2.get_name())
		return true;
	else
		return false;
}
