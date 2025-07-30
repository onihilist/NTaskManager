//
// Created by otual on 30/07/2025.
//

#ifndef PROCESSTABLEUI_H
#define PROCESSTABLEUI_H

#include <ftxui/component/component.hpp>

using namespace ftxui;

class ProcessTableUI {

    public:
        ProcessTableUI();
        Component getTable();

        int selected_row = 0;
        bool show_pid = true;
        bool show_mem = false;
        bool show_cpu = false;

        std::string title;
        std::vector<std::string> labels;

    private:
        std::vector<std::vector<std::string>> rows;

};

#endif //PROCESSTABLEUI_H
