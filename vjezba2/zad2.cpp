#include <iostream>

struct Vector {
    int* data;      // pokazivac na niz elemenata
    int size;       // logicka velicina
    int capacity;   // fizicka velicina
};

void vector_new(Vector& v, int init_capacity) {
    v.data = new int[init_capacity];
    v.size = 0;
    v.capacity = init_capacity;
}

void vector_delete(Vector& v) {
    delete[] v.data;
    v.data = nullptr;
    v.size = 0;
    v.capacity = 0;
}

void vector_push_back(Vector& v, int value) {
    if (v.size == v.capacity) {
        int new_capacity = v.capacity * 2;
        int* new_data = new int[new_capacity];
        for (int i = 0; i < v.size; ++i)
            new_data[i] = v.data[i];
        delete[] v.data;
        v.data = new_data;
        v.capacity = new_capacity;
    }
    v.data[v.size++] = value;
}

void vector_pop_back(Vector& v) {
    if (v.size > 0)
        v.size--;
}

int vector_front(const Vector& v) {
    return v.data[0];
}

int vector_back(const Vector& v) {
    return v.data[v.size - 1];
}

int vector_size(const Vector& v) {
    return v.size;
}

// ======= Test programa =======
int main() {
    Vector v;
    vector_new(v, 2);

    vector_push_back(v, 10);
    vector_push_back(v, 20);
    vector_push_back(v, 30);

    std::cout << "Vektor ima " << vector_size(v) << " elemenata.\n";
    std::cout << "Prvi: " << vector_front(v)
        << ", Zadnji: " << vector_back(v) << "\n";

    vector_pop_back(v);
    std::cout << "Nakon pop_back, velicina = " << vector_size(v) << "\n";

    vector_delete(v);
    return 0;
}


