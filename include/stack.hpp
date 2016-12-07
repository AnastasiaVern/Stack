#include "stdafx.h"
#include <iostream>
template <typename T>
class stack
{
public:
	stack();
	auto count() const -> size_t;
	auto push(T const& value)-> void;
	auto pop()-> T;
	~stack();
private:
	T * array_;
	size_t array_size_;
	size_t count_;
};

template <typename T>
stack<T>::stack() : array_(nullptr), array_size_(0), count_(0) {};

template <typename T>
auto stack<T>::count() const->size_t
{
	return count_;
}

template <typename T> 
auto stack<T>::push(T const& value)->void
{
	if (count_ == array_size_) 
	{
	//	std::cout << "Stack is full" << std::endl;
	 	T* new_array = new T[array_size_];

		for (size_t i = 0; i < count_; i++)
		{
			new_array[i] = array_[i];
		}
		delete[] array_;
		
		array_ = new T[array_size_];
		for (size_t i = 0; i < count_; i++) 
		{
			array_[i] = new_array[i];
		}
		delete[] new_array;

	}
		count_++;
		array_[count_] == value;
}

template <typename T>
auto stack<T>::pop()->T
{
	if (count_ != 0) 
	{
		return array_[--count_];
	}
	else throw std::logic_error( "Stack underflow!");
}

template <typename T>
stack<T>::~stack()
{
	delete[] array_;
}
