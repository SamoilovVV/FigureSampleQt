#pragma once

#include "AbstractCreator.h"

//************************************
// Template class for creating concrete objects
// T - class to create
// TBase - base class of T
//************************************
template <typename T, class TBase>
class Creator : public AbstractCreator<TBase>
{
public:
	Creator() = default;

	virtual ~Creator() = default;

	//************************************
	// Method:    create
	// FullName:  AbstractCreator<TBase>::create - creates pointer to base class
	// Returns:   std::unique_ptr<TBase> - pointer to base class
	//************************************
	std::unique_ptr<TBase> create() const override
	{
		return std::make_unique<T>();
	}
};