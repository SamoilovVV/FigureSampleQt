#pragma once

#include <typeinfo>

#include "ObjectFactoryException.h"

//************************************
// Error policies for error handling strategy
//************************************
struct ObjectFactoryErrorPolicy
{
	//************************************
	// Ignore factory errors
	// TBase - base class
	// Type - identifier type
	//************************************
	template <typename TBase, typename Type>
	class Ignore
	{
	public:

		//************************************
		// Method:    createFailed - class registration failed
		// Returns:   std::unique_ptr<TBase> - pointer to base class
		// Parameter: const Type & type - Type of identifier
		//************************************
		std::unique_ptr<TBase> createFailed(const Type & type) const
		{
			return nullptr;
		}

		//************************************
		// Method:    removeFailed - class removing failed
		// Parameter: const Type & type - Type of identifier
		//************************************
		void removeFailed(const Type & type)
		{
		}

		//************************************
		// Method:    duplicateRegister - attempt to register class twice
		// Returns:   false
		// Parameter: const Type & type - Type of identifier
		//************************************
		bool duplicateRegister(const Type & type)
		{
			return false;
		}
	};

	//************************************
	// Throw exception on error
	// TBase - base class
	// Type - identifier type
	//************************************
	template <typename TBase, typename Type>
	class ThrowException
	{
	public:


		//************************************
		// Method:    generateMessage - generate error message
		// Returns:   std::string - error message
		// Parameter: const char * msg - message text
		// Parameter: const Type & type - identifier type
		//************************************
		static std::string generateMessage(const char * msg, const Type & type)
		{
			std::string retStr = msg + std::string(", requested type id : ") + typeid(Type).name();

			return retStr;
		}

		//************************************
		// Method:    createFailed - class registration failed
		// Returns:   nothing - throw exception
		// Parameter: const Type & type - Type of identifier
		//************************************
		std::unique_ptr<TBase> createFailed(const Type & type) const
		{
			throw ObjectFactoryException(generateMessage("ObjectFactory - can't create object (not registered)", type));
		}

		//************************************
		// Method:    removeFailed - class removing failed
		// Parameter: const Type & type - Type of identifier
		//************************************
		void removeFailed(const Type & type)
		{
			throw ObjectFactoryException(generateMessage("ObjectFactory - can't remove class (not registered)", type));
		}

		//************************************
		// Method:    duplicateRegister - attempt to register class twice
		// Returns:   nothing - throw exception
		// Parameter: const Type & type - Type of identifier
		//************************************
		bool duplicateRegister(const Type & type)
		{
			throw ObjectFactoryException(generateMessage("ObjectFactory - class already registered", type));
		}
	};
};