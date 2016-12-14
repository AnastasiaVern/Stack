#include "stdafx.h"
#include "Allocator.hpp"
#include <iostream>
#include <exception>
#include <algorithm>
template <typename T>
class stack : public allocator<T>
{
public:
	stack() : allocator<T>(5) {};
	auto count() const noexcept->size_t;
	auto push(allocator<T> &obj,T const& value)-> void;
	auto top() const->T; 
	auto pop() noexcept -> void;
	auto empty() const noexcept-> bool;

/*private:
	T * array_;
	size_t array_size_;
	size_t count_;*/
};

template <typename T>
auto stack<T>::count() const noexcept -> size_t
{
	return allocator<T>::count_;
}

template <typename T>
auto stack<T>::push(allocator<T> &obj,T const& value)->void 
{
	 allocator<T>::swap(obj);
     allocator<T>::ptr_[allocator<T>::count_] = value;
	 allocator<T>::count_++;
}
template <typename T>
auto stack<T>::top() const -> T
{
	if (allocator<T>::count_)
	{
		return allocator<T>::ptr_[allocator<T>::count_ - 1];
	}
	else
	{
		throw std::underflow_error("count_ = 0");
	}
}
template <typename T>
auto stack<T>::pop() noexcept->void
{
	if (allocator<T>::count_)
		allocator<T>::count_--;
}

template<typename T>
auto stack<T>::empty() const noexcept->bool
{
	if (!allocator<T>::count_;) { return true; }
	else { return false; }
}
