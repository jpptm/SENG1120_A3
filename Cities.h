//Course: SENG1120
//Coded by: Alex Mendes 

#ifndef CITIES_H
#define CITIES_H
#include <string>
#include <cstdlib>
#include <iostream>
using namespace std;

class Cities
{
public:
	
	// Constructors
	Cities();
	Cities(const string, const int);

	// Destructor
    ~Cities();

	// Setters
    void set_name(const string);
	void set_population(const int);

	// Getters
	string get_name() const;
	int get_population() const;

//Private member variables
private:
	string name; // city name
	int population; // city population
};
ostream& operator <<(ostream&, const Cities&);

bool operator == (const Cities& s1, const Cities& s2);
bool operator < (const Cities& s1, const Cities& s2);
bool operator > (const Cities& s1, const Cities& s2);

#endif