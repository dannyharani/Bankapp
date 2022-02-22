#pragma once
#include <string>

class User {

	std::string m_name;
	std::string m_phone;
	
	short m_birth_year;
	short m_birth_month;
	short m_birth_day;


public:

	// For date comparissons, user input begins at 1
	enum MONTHS { JANUARY = 1, FEBRUARY, MARCH, APRIL, MAY, JUNE, JULY, AUGUST, SEPTEMBER, OCTOBER, NOVEMBER, DECEMBER };

	User() = default;

	User(std::string name, std::string phone, short birth_day, short birth_month, short birth_year);
	
	bool operator==(User other);

	std::string getName() { return m_name; };

	std::string getPhone() { return m_phone; };

	std::string getInfo();

};
