#pragma once

#include <memory>
#include "ShapeFactory.h"

//************************************
// Add shape class to factory
//************************************
template <typename T>
class RegisterShape
{
public:

	//************************************
	// Method:    RegisterShape - constructor
	// Parameter: const QString & id - shape identifier
	//************************************
	RegisterShape(const QString & id)
	{
		if (m_class_registered++ == 0) // Schwarz counter
			ShapeFactory::add<T>(id);
	}

private:

	static int m_class_registered;
};

template<typename T> int RegisterShape<T>::m_class_registered = 0;//initialize counter
