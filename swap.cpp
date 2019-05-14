#ifndef SWAP_CPP
#define SWAP_CPP

template <typename T>
void swap_element(T& a, T& b) {
    T c = a;
    a = b;
    b = c;
}

#endif // SWAP_CPP