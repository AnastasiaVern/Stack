#include <exception>
#include <algorithm>
#include <iostream>


template <typename T>
class allocator
{
public:
	allocator(size_t size = 0);
	auto swap(allocator& other) -> void;
	auto allocate() -> void;
	auto relocate() -> void;
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
	if (size > 0) {
		ptr_ = static_cast<T*>(::operator new(size * sizeof(T)));
		size_ = size;
		count_ = 0;
	}
}

template<typename T>
auto allocator<T>::swap(allocator& other) -> void 
{
	std::swap(ptr_, other.ptr_);
	std::swap(size_, other.size_);
	std::swap(count_, other.count_);
}
template<typename T>
auto allocator<T>::allocate() -> void 
{
      auto old_size=size_;
      size_ *= 2;
      try {
      relocate();
      }
      catch(...) 
      {
       size_=old_size;
       throw;
      }
      
}
template<typename T>
auto allocator<T>::relocate() -> void
{
   allocator<T> arr(size_);
   std::copy(ptr_, ptr_+ count_,arr.ptr_);
   arr.count_=count_;
   swap(arr);
}

template<typename T>
allocator<T>::~allocator() 
{
	for (size_t i = 0; i < count_; i++)
		ptr_[i].~T();
	::operator delete[](ptr_);
}
