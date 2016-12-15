#include "allocator.hpp"
#include <iostream>
#include <exception>
#include <algorithm>
template <typename T>
class stack : public allocator<T>
{
public:
	stack() : allocator<T>(5) {};
	auto count() const noexcept->size_t;
	auto push(T const& value)-> void; /*strong*/
	auto top() const->T; 
	auto pop() noexcept -> void;
	auto empty() const noexcept-> bool;
};

template <typename T>
auto stack<T>::count() const noexcept -> size_t
{
	return allocator<T>::count_;
}

template <typename T>
auto stack<T>::push(T const& value)->void /*strong*/
{
	    bool any_change = false;
        if (allocator<T>::count_ == allocator<T>::size_)
        {
	try {
            allocator<T>::allocate();
            any_change = true;
	    }
        catch (...)
            {
        throw;
            }

    try
    {
        allocator<T>::ptr_[allocator<T>::count_] = value;
    }
    catch (...)
    {
        if (any_change)
        {
            allocator<T>::size_ /= 2;
            allocator<T>::relocate();
        }
        throw;
    }
	}
    ++allocator<T>::count_;
    return;
}
template <typename T>
auto stack<T>::top() const -> T
{
	    if (allocator<T>::count_ != 0)
    {
        return allocator<T>::ptr_[allocator<T>::count_ - 1];
    }
    throw std::underflow_error("Stack is empty!");
}
template <typename T>
auto stack<T>::pop() noexcept->void
{
	if (allocator<T>::count_)
		--allocator<T>::count_;
}

template<typename T>
auto stack<T>::empty() const noexcept->bool
{
	if (!allocator<T>::count_) { return true; }
	else { return false; }
}
