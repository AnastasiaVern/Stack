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
	auto push(T const& value)-> void;
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
auto stack<T>::push(T const& value)->void 
{
	if (allocator<T>::count_ == allocator<T>::size_) 
	{
		try {
			T* new_ptr = static_cast<T*>(operator new[](size_ * sizeof(T) * 2));
			allocator<T> other(size_ * sizeof(T) * 2);
			std::copy(allocator<T>::ptr_, allocator<T>::ptr_ + allocator<T>::count_, new_ptr);
			swap(other);
			allocator<T>::ptr_[allocator<T>::count_] = value;
			allocator<T>::count_++;
		}
		catch (...) 
		{
			std::cerr << "error!";
		}
	}
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
	if (!allocator<T>::count_) { return true; }
	else { return false; }
}
