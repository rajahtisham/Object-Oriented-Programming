#ifndef TEMPLATEUTILS_H
#define TEMPLATEUTILS_H
#include <vector>

using namespace std;
template <typename T>
void displayAll(const vector<T*>& items) {
    for (const auto& item : items) { item->display(); }
}
#endif
