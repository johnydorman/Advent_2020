#include <string>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <set>
#include <iterator>

#include "Passport.h"

Passport::Passport() {	}

void Passport::addPassportData(std::string line){
	
	std::vector<std::string> fieldEntries = split(line, " ");
	
	for(auto fieldEntry : fieldEntries){
		std::vector<std::string> splitData = split(fieldEntry, ":");

		int valid = 0;
		
		if (splitData[0].compare("byr") == 0){
			valid = 1;
			//valid = validateBirthYear(fieldEntry[1]);
		}
		else if ((splitData[0].compare("iyr")) == 0){
			valid = 1;
		}
        else if ((splitData[0].compare("eyr")) == 0){
			valid = 1;
		}
		else if ((splitData[0].compare("hgt")) == 0){
			valid = 1;
		}
		else if ((splitData[0].compare("hcl")) == 0){
			valid = 1;
		}
		else if ((splitData[0].compare("ecl")) == 0){
			valid = 1;
		}
		else if ((splitData[0].compare("pid")) == 0){
			valid = 1;
		} 
		else {
			valid = 1;
		}
		
//		std::cout << splitData[0] << "\n";
		
		if(valid == 1){
			fields.insert(splitData[0]);
		} else {
			return;
		}
	}
}

bool Passport::isPassportValid(std::set<std::string> validation){
	std::set<std::string> result;
	
	std::set_difference(validation.begin(), validation.end(), fields.begin(), fields.end(), std::inserter(result, result.end()));
	
	for (auto res: result)
    {
        std::cout << res << ' ';
    }
	
	if(result.size() == 0){
		std::cout << "Pass \n";
		return true;
	}
	
	std::cout << "Fail \n";
	return false;
}

std::vector<std::string> Passport::split (std::string s, std::string delimiter) {
    size_t pos_start = 0, pos_end, delim_len = delimiter.length();
    std::string token;
    std::vector<std::string> res;

    while ((pos_end = s.find (delimiter, pos_start)) != std::string::npos) {
        token = s.substr (pos_start, pos_end - pos_start);
        pos_start = pos_end + delim_len;
        res.push_back (token);
    }

    res.push_back (s.substr (pos_start));
    return res;
}
