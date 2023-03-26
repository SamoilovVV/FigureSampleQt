#pragma once

#include <string>

//************************************
// Exception for object factory
//************************************
class ObjectFactoryException : public std::exception
{
public:
	ObjectFactoryException(const std::string & message) : m_message(message) {}

	//************************************
	// Method:    what - get error description
	// Returns:   const char * - error description
	//************************************
	virtual const char * what() const override { return m_message.c_str(); }

private:
	// message text
	std::string m_message;
};