#include <iostream>
#include <exception>
template <typename T>
class stack
{
public:
	stack();
	auto count() const noexcept -> size_t; 
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
auto stack<T>::count() const noexcept -> size_t
{
	return count_;
}

template <typename T> 
auto stack<T>::push(T const& value)->void /*strong*/
{
    bool any_change= false;
    auto old_array = array_;
    auto new_array = nullptr;

    if (count_ == array_size_)
    {
        array_size_ *= 2;

        try
        {
            new_array = new T[array_size_];
		for(size_t i=0; i<(array_+count_); ++i)
		 new_array[i]=array_[i]; 
        }
        catch (...)
        {
            delete[] new_array;
            array_size_ /= 2;
            throw;
        }
        array_ = new_array;
        any_change = true;
    }

    try
    {
        array_[count_] = value;
    }
    catch (...)
    {
        if (any_change)
        {
            delete[] array_;
            array_ = old_array;
            array_size_ /= 2;
        }
        throw;
    }
	
    ++count_;
    if (any_change) delete[] old_array;
    return;

}
template <typename T>
auto stack<T>::top() const -> T
{
	if (count_ != 0)
	{
	      return array_[count_-1];
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
