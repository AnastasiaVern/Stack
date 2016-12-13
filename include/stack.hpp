#include <iostream>
#include <exception>
template <typename T>
class stack
{
public:
	stack();
	auto count() const-> size_t; 
	auto push(T const& value)-> void; /*strong*/
	auto top() const-> T; /*strong*/
	auto pop() noexcept -> void;
	auto empty() const noexcept-> bool;
	auto print_stack() const noexcept->void;
	~stack();
private:
	T * array_;
	size_t array_size_;
	size_t count_;
};

template <typename T>
stack<T>::stack() : array_(nullptr), array_size_(0), count_(0) {};

template <typename T>
auto stack<T>::count() const ->size_t
{
	return count_;
}

template <typename T> 
auto stack<T>::push(T const& value)->void
{
	if (count_ == array_size_)
	{
			size_t new_size = (array_size_ == 0) + array_size_ * 2;

			auto new_array = new T[new_size];
			try {
				for (auto i = 0; i < count_; ++i)
					new_array[i] = array_[i];
				delete[] array_;
				array_ = new_array;
				array_size_ = new_size;
			}
			catch (...) 
			{
				delete[] new_array;
				throw;
			}
	}
   try {
	array_[count_++] = value;
	}
	catch(...)
	{ }

}
template <typename T>
auto stack<T>::top() const -> T
{
	if (count_ != 0)
	{
		return array_[--count_];
	}
	else
	{ 
		throw std::underflow_error("count_ = 0");
	}
}
template <typename T>
auto stack<T>::pop() noexcept->void
{
	if (count_ != 0) {
		--count_;
	}
}

template <typename T>
stack<T>::~stack()
{
	delete[] array_;
}

template<typename T>
auto stack<T>::print_stack() const noexcept->void 
{
	for (size_t i = 0; i < count_; ++i) 
	{
		std::cout << array_[i] <<" ";
	}
	std::cout << std::endl;
}
template<typename T> 
auto stack<T>::empty() const noexcept->bool
{
	if (!count_) { return true; }
	else { return false; }
}
