#include <iostream>

template <typename T>
class SimpleVector {
private:
    T* data;           // ������ �迭
    size_t m_capacity; // �迭�� ũ��
    size_t currentSize; // ���� ������ ����

public:
    // �⺻ ������
    SimpleVector() : m_capacity(10), currentSize(0) {
        data = new T[m_capacity];
    }

    // ũ�⸦ �޴� ������
    SimpleVector(size_t size) : m_capacity(size), currentSize(0) {
        data = new T[m_capacity];
    }

    // �Ҹ���
    ~SimpleVector() {
        delete[] data;
    }

    // ���� �߰�
    void push_back(const T& value) {
        if (currentSize < m_capacity) {
            data[currentSize] = value;
            currentSize++;
        }
        // �迭�� �� ���� �ƹ� ���۵� ���� ����
    }

    // ���� ����
    void pop_back() {
        if (currentSize > 0) {
            currentSize--;
        }
        // ������ ���Ұ� ������ �ƹ� ���۵� ���� ����
    }

    // ���� ���� ���� ��ȯ
    size_t size() const {
        return currentSize;
    }

    // ���� �迭�� ũ�� ��ȯ
    size_t capacity() const {
        return m_capacity;
    }
};

// ��� ����
int main() {
    SimpleVector<int> vec; // �⺻ ������ ���
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);

    std::cout << "Size: " << vec.size() << std::endl;       // ���: Size: 3
    std::cout << "Capacity: " << vec.capacity() << std::endl; // ���: Capacity: 10

    vec.pop_back();
    std::cout << "Size after pop: " << vec.size() << std::endl; // ���: Size after pop: 2

    return 0;
}
