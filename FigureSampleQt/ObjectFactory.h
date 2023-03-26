#pragma once

#include <map>
#include <memory>

#include "Creator.h"
#include "ObjectFactoryErrorPolicy.h"

//************************************
// Templated object factory
// TBase - base class
// IdType - identifier type
// ErrorPolicyType - error handling policy
//************************************
template <typename TBase, typename IdType = int, template <typename, typename> class ErrorPolicyType = ObjectFactoryErrorPolicy::ThrowException >
class ObjectFactory
{
protected:
	using AbstractFactory = AbstractCreator<TBase>;
	using AbstractFactoryPtr = std::unique_ptr<AbstractFactory>;

	using FactoryMap = std::map<IdType, AbstractFactoryPtr>;
	using ErrorPolicyHandler = ErrorPolicyType<TBase, IdType>;

public:
	ObjectFactory() = default;

	ObjectFactory(const ObjectFactory &) = delete;
	ObjectFactory& operator = (const ObjectFactory &) = delete;

	virtual ~ObjectFactory() = default;

	//************************************
	// Method:    create - create object of TBase class
	// Returns:   std::unique_ptr<TBase> - pointer to object
	// Parameter: const IdType & id - identifier
	//************************************
	std::unique_ptr<TBase> create(const IdType & id) const
	{
		auto it = m_map.find(id);
		if (it != m_map.end()) {
			return it->second->create();
		}
			
		return m_errorHandler.createFailed(id);
	}

	//************************************
	// Method:    add - add object class to factory
	// Returns:   bool - true if successfully registered
	// Parameter: const IdType & id - identifier
	//************************************
	template <typename Class>
	bool add(const IdType & id)
	{
		return registerClass(id, std::make_unique<Creator<Class, TBase>>());
	}

	//************************************
	// Method:    remove - removes class from factory
	// Parameter: const IdType & id - identifier
	//************************************
	void remove(const IdType & id)
	{
		auto it = m_map.find(id);
		if (it != m_map.end()) {
			m_map.erase(it);
		}
		else {
			m_errorHandler.removeFailed(id);
		}
			
	}

	//************************************
	// Method:    isRegistered - check if class is registered
	// Returns:   bool - true, if class is registered
	// Parameter: const IdType & id - identifier
	//************************************
	bool isRegistered(const IdType & id) const
	{
		return m_map.find(id) != m_map.end();
	}

	//************************************
	// Method:    registredTypes - get list of registered classes
	// Returns:   std::vector<IdType> - vector of registred classes identifiers
	//************************************
	std::vector<IdType> registredTypes() const
	{
		std::vector<IdType> retVector;
		for (auto &it : m_map) {
			retVector.push_back(it.first);
		}

		return retVector;
	}

	//************************************
	// Method:    size - get count of registered classes 
	// Returns:   size_t - registered classes count
	//************************************
	size_t size() const
	{
		return m_map.size();
	}


protected:
	//************************************
	// Method:    registerClass - class registration
	// Returns:   bool - true if class is successfully registered
	// Parameter: const IdType & id - identifier
	// Parameter: AbstractFactoryPtr && abstractFactory - pointer to creator
	//************************************
	bool registerClass(const IdType & id, AbstractFactoryPtr && abstractFactory)
	{
		typename FactoryMap::iterator it = m_map.find(id);
		if (it == m_map.end()) {
			m_map[id] = std::move(abstractFactory);
			return true;
		}
		return m_errorHandler.duplicateRegister(id);
	}

private:
	FactoryMap          m_map;
	ErrorPolicyHandler  m_errorHandler;
};

//************************************
// Static wrapper for object factory (singleton-like factory)
// initializer - factory initializer
// TBase - base class
// IdType - identifier type
// ErrorPolicyType - error handling policy
//************************************
template <typename initializer, typename TBase, typename IdType = int, template <typename, typename> class ErrorPolicy = ObjectFactoryErrorPolicy::Ignore >
class StaticObjectFactory
{
public:
	using Factory = ObjectFactory<TBase, IdType, ErrorPolicy>;

	//************************************
	// Method:    create - create object of TBase class
	// Returns:   std::unique_ptr<TBase> - pointer to object
	// Parameter: const IdType & id - identifier
	//************************************
	static std::unique_ptr<TBase> create(const IdType & id)
	{
		return instance().create(id);
	}

	//************************************
	// Method:    add - add object class to factory
	// Returns:   bool - true if successfully registered
	// Parameter: const IdType & id - identifier
	//************************************
	template <typename Class>
	static bool add(const IdType & id)
	{
		return instance().add<Class>(id);
	}

	//************************************
	// Method:    remove - removes class from factory
	// Parameter: const IdType & id - identifier
	//************************************
	static void remove(const IdType & id)
	{
		instance().remove(id);
	}

	//************************************
	// Method:    isRegistered - check if class is registered
	// Returns:   bool - true, if class is registered
	// Parameter: const IdType & id - identifier
	//************************************
	static bool isRegistered(const IdType & id)
	{
		return instance().isRegistered(id);
	}

	//************************************
	// Method:    registredTypes - get list of registered classes
	// Returns:   std::vector<IdType> - vector of registred classes identifiers
	//************************************
	static std::vector<IdType> registredTypes()
	{
		return instance().registredTypes();
	}

	//************************************
	// Method:    size - get count of registered classes 
	// Returns:   size_t - registered classes count
	//************************************
	static size_t size()
	{
		return instance().size();
	}

	//************************************
	// Method:    init - factory initialization
	// Parameter: Factory & factory - factory to initialize
	//************************************
	static void init(Factory & factory)
	{
		// Empty initialiation
	}

protected:
	StaticObjectFactory() {}
	StaticObjectFactory(const StaticObjectFactory &) = delete;
	StaticObjectFactory & operator = (const StaticObjectFactory &) = delete;

private:
	//************************************
	// Helper struct for factory initialization
	//************************************
	struct StaticStorage
	{
		Factory factory_;
		StaticStorage()
		{
			initializer().init(factory_);
		}
	};

	//************************************
	// Method:    instance - instantiate factory
	// Returns:   Factory & - initialized factory reference
	//************************************
	static Factory & instance()
	{
		static StaticStorage storage;
		return storage.factory_;
	}
};