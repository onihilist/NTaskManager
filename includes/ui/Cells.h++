//
// Created by otual on 30/07/2025.
//

#ifndef CELLS_H
#define CELLS_H

#include "ftxui/dom/elements.hpp"

using namespace ftxui;

class Cells {
    public:
        static constexpr auto cell_20x1   = [](Element e) { return e | size(WIDTH, EQUAL, 20)  | size(HEIGHT, EQUAL, 1)  | border; };
        static constexpr auto cell_110x1  = [](Element e) { return e | size(WIDTH, EQUAL, 110) | size(HEIGHT, EQUAL, 1)  | border; };
        static constexpr auto cell_40x1   = [](Element e) { return e | size(WIDTH, EQUAL, 40)  | size(HEIGHT, EQUAL, 1)  | border; };
        static constexpr auto cell_30x10  = [](Element e) { return e | size(WIDTH, EQUAL, 30)  | size(HEIGHT, EQUAL, 10) | border; };
        static constexpr auto cell_110x30 = [](Element e) { return e | size(WIDTH, EQUAL, 110) | size(HEIGHT, EQUAL, 30) | border; };
        static constexpr auto cell        = [](Element e) { return e | border; };
};
#endif //CELLS_H
