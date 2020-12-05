#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <set>

#include "Passport.h"

using namespace std;

int main()
{
	ifstream infile("input.txt");
	
	std:vector<Passport*> passports;
	
	Passport* passport = new Passport();
	string line;
	while (getline(infile, line))
	{	
		//new passport
		if (line.length() == 0){
			passports.push_back(passport);
			passport = new Passport();
		}
		
		passport->addPassportData(line);
	}
	passports.push_back(passport);
	
	
	std::set<std::string> validation =  {"byr", "iyr", "eyr", "hgt", "hcl", "ecl", "pid"};
	// validation.insert("byr");
	// validation.insert("iyr");
	// validation.insert("eyr");
	// validation.insert("hgt");
	// validation.insert("hcl");
	// validation.insert("ecl");
	// validation.insert("pid");
	
	int counter = 0;
	//validate passports
	for(Passport* passport: passports){
		
		if(passport->isPassportValid(validation)){
			++counter;
		}
	}
	
	cout << "\n Ouput \n";
	std::cout << "Passports Total: " << passports.size() << '\n';
	std::cout << "Part 1. : "<< counter;

	cin.get();
    return 0;
}