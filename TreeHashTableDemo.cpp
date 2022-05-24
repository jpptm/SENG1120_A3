//TreeHashTableDemo - Main Program
/******************************/
//Author: Alex Mendes
//Course: SENG1120
//Program Description: This program demonstrates the basic functionality of binary seach trees and hash tables. 

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <time.h>
#include <sstream> 
#include "BSTree.h"
//#include "HTable.h"
#include "Cities.h"

using namespace std;

int main()
{
	clock_t t;

	// you are using class templates
	BSTree<Cities> treeValues;
	//HTable<Cities> tableValues;
    	
    Cities city;

	// Reads data from input file and populates tree
	string line;

    ifstream myfileA ("Worldcities.txt");
    if (myfileA.is_open())
    {
		while ( getline (myfileA,line) )
		{
			stringstream tempSS, tempSS2;
			double tempDouble;
			tempSS << line;
			string token;
			getline(tempSS, token, ' '); // get name
			city.set_name(token);
			getline(tempSS, token, ' '); // get population
			tempSS2 << token;  
			tempSS2 >> tempDouble;
			city.set_population(tempDouble);
			treeValues.add(city); // adds element to the tree
			//tableValues.add(city); // adds element to the table
			
		}
	}

	string vectorNames[] = {"Manila", "Kolkata", "BuenosAires", "Lagos", "Kinshasa", "Tehran", "London", "Nagoya", "Lima", "Ganzhou", "Hanoi", "Bogota", "HongKong", "Nanning", "Hangzhou", "Miami", "Madrid", "Philadelphia", "Atlanta", "Singapore", "Xianyang", "Sydney", "Harbin", "Johannesburg", "Fuzhou", "Seattle", "Berlin", "Changzhi", "SanDiego", "Jinzhou", "AddisAbaba"};
	int vectorPop[] = {23971000, 18698000, 16216000, 15487000, 15056000, 13819000, 11120000, 9522000, 8992000, 8677600, 8246600, 7743955, 7398000, 7254100, 6713000, 6445545, 6006000, 5649300, 5449398, 5271000, 5096001, 4840600, 4583000, 4434827, 4047200, 3789215, 3664088, 3334565, 3220118, 3126463, 3041002};
			
	cout << "==================" << endl << "BINARY SEARCH TREE" << endl << "==================" << endl << endl;
	
	t = clock(); // gets current time
	
	cout << "Initial tree: " << treeValues << endl; // prints the contents of the tree.

	cout << endl << "Adding and removing..." << endl;
	
	for (int j=0; j<10000; j++)
	{
		for (int i=0; i<31; i++)
		{ // removes the 31 elements in the list. The first one is not present.
			city.set_name(vectorNames[i]); city.set_population(vectorPop[i]);
			treeValues.remove(city);
		}

		for (int i=1; i<31; i++)
		{ // adds all elements removed back into the data structure.
			city.set_name(vectorNames[i]); city.set_population(vectorPop[i]);
			treeValues.add(city);
		}
	} 
	cout << endl << endl;
	
	cout << "Final tree  : " << treeValues << endl << endl; // prints the contents of the tree.
	cout << "Time elapsed: " << (clock() - t)/1000.0 << " seconds" << endl; // prints elapsed time.
	cout << "Time per ins/del operation: " << 1000.0*(double)(clock() - t)/(double)(10000*31) << " milliseconds." << endl;
	cout << "There are " << treeValues.calculateTotalPop() << " people living in those cities and " << treeValues.calculatePopGreaterThan(10000000) << " people living in cities with more than 10 million inhabitants." << endl;
    /*
	cout << "==================" << endl << "HASH TABLE" << endl << "==================" << endl << endl;
	t = clock(); // gets current time
    cout << "Initial hash table: " << tableValues << endl; // prints the contents of the hash table.

	cout << endl << "Adding and removing..." << endl;
	for (int j=0; j<10000; j++)
	{
		for (int i=0; i<31; i++)
		{ // removes the 31 elements in the list. The first one is not present.
			city.set_name(vectorNames[i]); city.set_population(vectorPop[i]);
			tableValues.remove(city);
		}

		for (int i=1; i<31; i++)
		{ // adds all elements removed back into the data structure.
			city.set_name(vectorNames[i]); city.set_population(vectorPop[i]);
			tableValues.add(city);
		}
	}

	cout << endl << endl;
	
	//cout << "Final hash table  : " << tableValues << endl << endl; // prints the contents of the hash table.
    cout << "Time elapsed: " << (clock() - t)/1000.0 << " seconds" << endl; // prints elapsed time.
	cout << "Time per ins/del operation: " << 1000.0*(double)(clock() - t)/(double)(10000*31) << " milliseconds." << endl << endl;
	cout << "There are " << tableValues.calculateTotalPop() << " people living in those cities and " << tableValues.calculatePopGreaterThan(10000000) << " people living in cities with more than 10 million inhabitants." << endl;
	cout << "The program has finished." << endl;*/
	
	return 0;
}
