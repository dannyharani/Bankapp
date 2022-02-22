#include "User.h"

	std::string m_name;
	std::string m_phone;
	short m_birth_day;
	short m_birth_month;
	short m_birth_year;

	User::User(std::string name = "NO USER", std::string phone = "NO USER", short birth_day = 00, short birth_month = 00, short birth_year = 0000)
	{
		this->m_name = name;
		this->m_phone = phone;
		this->m_birth_day = birth_day;
		this->m_birth_month = birth_month;
		this->m_birth_year = birth_year;
	}

	bool User::operator==(User other)
	{
		return this->getInfo() == other.getInfo();
	}


	std::string User::getInfo()
	{
		return "Name: " + m_name + ", Phone: " + m_phone + " DoB (mm/dd/yyyy): " + std::to_string(m_birth_month) + "/" + std::to_string(m_birth_day) + "/" + std::to_string(m_birth_year);
	}
