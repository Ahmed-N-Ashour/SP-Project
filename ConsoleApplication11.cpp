// ConsoleApplication11.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include <cmath>
using namespace std;

struct times
{
	int hours[3], mins[3];
};
struct theatre
{
	int capacity[2], reserved[2];
	string theatreId[2];
};

struct movie
{
	string name, director, actor[2], rate, genre;
	times t;
	theatre masra7;

}; 

void store(movie x[5]);
void showDesc(int choice, movie x[5]);
void menu(movie x[5]);
void time(movie x[5], string n);

int main()
{

	movie x[5];
	store(x);
	int choice;
	cin >> choice;
	showDesc(choice, x);

	return 0;
}

void store(movie x[5]) {
	string s;
	ifstream cin("mac.txt");
	for (int i = 0; i<5; i++) {
		getline(cin, x[i].name);
		getline(cin, x[i].director);
		getline(cin, x[i].actor[0]);
		getline(cin, x[i].actor[1]);
		getline(cin, x[i].rate);
		getline(cin, x[i].genre);
		getline(cin, x[i].masra7.theatreId[0]);
		getline(cin, x[i].masra7.theatreId[1]);
		getline(cin, s);
		x[i].masra7.capacity[0] = stoi(s);
		getline(cin, s);
		x[i].masra7.capacity[1] = stoi(s);
		getline(cin, s);
		x[i].masra7.reserved[0] = stoi(s);
		getline(cin, s);
		x[i].masra7.reserved[1] = stoi(s);
		getline(cin, s);
		x[i].t.hours[0] = stoi(s);
		getline(cin, s);
		x[i].t.hours[1] = stoi(s);
		getline(cin, s);
		x[i].t.hours[2] = stoi(s);
		getline(cin, s);
		x[i].t.mins[0] = stoi(s);
		getline(cin, s);
		x[i].t.mins[1] = stoi(s);
		getline(cin, s);
		x[i].t.mins[2] = stoi(s);
	}
}

void showDesc(int choice , movie x[5])
{
	while (choice > 5 || choice < 1){
		if (choice > 5 || choice < 1) {
			cout << "INVALID OPTION! PLEASE CHOOSE A NUMBER FROM THE MOVIES LIST *from 1 to 5*" << endl;
			cin >> choice;
		}
		else {
			showDesc(choice, x);
		}
	} while (choice > 5);
	cout << "Movie Name: " << x[choice - 1].name << endl;
	cout << "Genre: " << x[choice - 1].genre << endl;
	cout << "Director: " << x[choice - 1].director << endl;
	cout << "Stars: " << x[choice - 1].actor[0] << " , " << x[choice - 1].actor[1] << endl;
	cout << "Theaters: " << x[choice - 1].masra7.theatreId[0] << " , " << x[choice - 1].masra7.theatreId[1] << endl;
	cout << "Screening times: " << x[choice - 1].t.hours[0] << ":" << x[choice - 1].t.mins[0] << " , " << x[choice - 1].t.hours[1] << ":" << x[choice - 1].t.mins[1] << " , " << x[choice - 1].t.hours[2] << ":" << x[choice - 1].t.mins[2] << endl;
	cout << "------------------------" << endl;
	cout << "To book movie tickets PRESS 1" << endl;
	cout << "To return to the main menu PRESS 0" << endl;
}



