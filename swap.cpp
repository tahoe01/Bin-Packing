#ifndef SWAP_CPP
#define SWAP_CPP

void swap_element(int& a, int& b) {
    int c = a;
    a = b;
    b = c;
}

#endif // SWAP_CPP