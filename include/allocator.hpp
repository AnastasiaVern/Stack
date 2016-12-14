#include <exception>
#include <algorithm>
#include <iostream>


template <typename T>
class allocator
{
public:
	allocator(size_t size = 0);
	auto swap(allocator& other) -> void;
	allocator(allocator const& alloc) noexcept= delete;
	auto operator =(allocator const& )->allocator& = delete;
	~allocator();

	T * ptr_;
	size_t size_;
	size_t count_;
};


template<typename T>
allocator<T>::allocator(size_t size) 
{
	if (size>0)
	{
	ptr_ = static_cast<T*>(::operator new(size * sizeof(T)));
	size_=size;
	count_ = 0;
	}
}

template<typename T>
auto allocator<T>::swap(allocator& other) -> void 
{
	try 
	{
		size_ * 2;
		other.size_;
		while (ptr_!= ptr_ + count_)
		{
			*other.ptr_++ = *ptr_++;
		}
		other.count_ = count_;
		std::swap(ptr_, other.ptr_);
		std::swap(size_, other.size_);
	}
	catch (...) 
	{
		std::cerr << "error!";
	}
	
}

template<typename T>
allocator<T>::~allocator() 
{
	for (size_t i = 0; i < count_; i++)
		ptr_[i].~T();
	::operator delete[](ptr_);
}
