#include "Board.hpp"
#include <iostream>

using namespace std;

Board::Board(const vector<Case> cases) : cases{cases} {}

Board::~Board() {
    cout << "destruction du board" << endl;
}

void Board::getBoard() const {
    for(size_t i=0; i<cases.size(); i++) {
        cases.at(i).getCase();
    }
}