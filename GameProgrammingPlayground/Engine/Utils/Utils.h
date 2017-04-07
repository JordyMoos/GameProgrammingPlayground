#pragma once

#include <memory>


template <class Type>
std::shared_ptr<Type> MakeStrongPtr(std::weak_ptr<Type> weakPtr)
{
	if (weakPtr.expired())
	{
		return std::shared_ptr<Type>();
	}

	return std::shared_ptr<Type>(weakPtr);
}
