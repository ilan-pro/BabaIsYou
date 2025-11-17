#include "Case.hpp"

#include <iostream>

using namespace std;

Case::Case(int x, int y) : x{x}, y{y} {}

Case::~Case() {
    cout << "création du point" << endl;
}

void Case::getCase() const {
    cout << "x:" << x << " y:" << y << endl;
}