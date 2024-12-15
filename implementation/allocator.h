#ifndef MYSTUFF_ALLOCATOR_H
#define MYSTUFF_ALLOCATOR_H

#include <cstddef>
#include <utility>

namespace mystuff {

    template<class T>
    class MyAllocator {
    private:
//        typedef T value_type;
//        typedef size_t size_type;
    public:
        MyAllocator() = default;
        ~MyAllocator() = default;

        static T* allocate();
        static void deallocate(T* ptr);

        static void construct(T* ptr);
        static void construct(T* ptr, const T& value);
        static void construct(T* ptr, T&& value);

        static void destroy(T* ptr);
    };

    template<class T>
    T* MyAllocator<T>::allocate() {
        return static_cast<T*>(::operator new(sizeof(T)));
    }

    template<class T>
    void MyAllocator<T>::deallocate(T* ptr) {
        if (ptr == nullptr)
            return;
        ::operator delete(ptr);
    }

    template<class T>
    void MyAllocator<T>::construct(T* ptr) {
        ::new((void*)ptr) T();
    }

    template<class T>
    void MyAllocator<T>::construct(T* ptr, const T& value) {
        ::new((void*)ptr) T(value);
    }

    template<class T>
    void MyAllocator<T>::construct(T* ptr, T&& value) {
        ::new((void*)ptr) T(std::move(value));
    }

    template<class T>
    void MyAllocator<T>::destroy(T* ptr) {
        if (ptr != nullptr)
            ptr->~T();
    }

}

#endif //MYSTUFF_ALLOCATOR_H
