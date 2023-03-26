#pragma once

#include <memory>

//************************************
// Abstract class for creation objects
// TBase - base class to create
//************************************
template <typename TBase>
class AbstractCreator
{
public:
	AbstractCreator() = default;

	AbstractCreator(const AbstractCreator&) = delete;
	AbstractCreator& operator = (const AbstractCreator&) = delete;

	virtual ~AbstractCreator() = default;

	//************************************
	// Method:    create
	// FullName:  AbstractCreator<TBase>::create - creates pointer to base class
	// Returns:   std::unique_ptr<TBase> - pointer to base class
	//************************************
	virtual std::unique_ptr<TBase> create() const = 0;
};






