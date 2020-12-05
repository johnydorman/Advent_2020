#include <string>
#include <set>

class Passport {
	private:
		std::set<std::string> fields;
		std::vector<std::string> split (std::string s, std::string delimiter);
	public:
		Passport();
		bool isPassportValid(std::set<std::string> validation);
		void addPassportData(std::string data);
};