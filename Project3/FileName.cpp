#include <iostream>

template <typename T>
class SimpleVector {
private:
    T* data;           // 데이터 배열
    size_t m_capacity; // 배열의 크기
    size_t currentSize; // 현재 원소의 개수

public:
    // 기본 생성자
    SimpleVector() : m_capacity(10), currentSize(0) {
        data = new T[m_capacity];
    }

    // 크기를 받는 생성자
    SimpleVector(size_t size) : m_capacity(size), currentSize(0) {
        data = new T[m_capacity];
    }

    // 소멸자
    ~SimpleVector() {
        delete[] data;
    }

    // 원소 추가
    void push_back(const T& value) {
        if (currentSize < m_capacity) {
            data[currentSize] = value;
            currentSize++;
        }
        // 배열이 꽉 차면 아무 동작도 하지 않음
    }

    // 원소 제거
    void pop_back() {
        if (currentSize > 0) {
            currentSize--;
        }
        // 제거할 원소가 없으면 아무 동작도 하지 않음
    }

    // 현재 원소 개수 반환
    size_t size() const {
        return currentSize;
    }

    // 현재 배열의 크기 반환
    size_t capacity() const {
        return m_capacity;
    }
};

// 사용 예시
int main() {
    SimpleVector<int> vec; // 기본 생성자 사용
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);

    std::cout << "Size: " << vec.size() << std::endl;       // 출력: Size: 3
    std::cout << "Capacity: " << vec.capacity() << std::endl; // 출력: Capacity: 10

    vec.pop_back();
    std::cout << "Size after pop: " << vec.size() << std::endl; // 출력: Size after pop: 2

    return 0;
}
