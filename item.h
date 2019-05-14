#ifndef ITEM_H
#define ITEM_H

using namespace std;

struct item {
    double val;
    int id;
};


bool comp(item i1, item i2) {
    return i1.val > i2.val;
}

#endif // ITEM_H