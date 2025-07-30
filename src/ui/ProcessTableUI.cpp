#include "../../includes/ui/ProcessTableUI.h++"
#include "../../includes/ui/Cells.h++"
#include <ftxui/dom/elements.hpp>
#include <ftxui/component/component.hpp>

using namespace ftxui;

ProcessTableUI::ProcessTableUI() {
    rows = {
        {"PID", "Name", "CPU%", "Memory"},
        {"1234", "chrome.exe", "25", "200 MB"},
        {"5678", "explorer.exe", "2", "50 MB"},
        {"9101", "ntask.exe", "12", "100 MB"},
        {"1121", "spotify.exe", "5", "150 MB"},
        {"1314", "code.exe", "30", "400 MB"},
        {"1516", "discord.exe", "3", "220 MB"},
        {"1718", "steam.exe", "1", "120 MB"},
        {"1819", "terminal.exe", "7", "90 MB"},
        {"1920", "game.exe", "80", "2 GB"},
    };

    // Crée les labels une fois pour toutes
    for (size_t i = 1; i < rows.size(); i++)
        labels.push_back(rows[i][1]);
}

Component ProcessTableUI::getTable() {
    // On crée le menu une fois (sur labels fixes)
    Component table_menu = Menu(&labels, &selected_row);

    // Renderer encapsulé
    return Renderer(table_menu, [&] {
        Elements header_cells;
        if (show_pid)
            header_cells.push_back(text("PID") | bold | size(WIDTH, EQUAL, 8));
        header_cells.push_back(text("Name") | bold | size(WIDTH, EQUAL, 20));
        if (show_cpu)
            header_cells.push_back(text("CPU%") | bold | size(WIDTH, EQUAL, 8));
        if (show_mem)
            header_cells.push_back(text("Memory") | bold | size(WIDTH, EQUAL, 12));

        auto header = hbox(std::move(header_cells)) | border;

        Elements lines;
        for (size_t i = 1; i < rows.size(); i++) {
            bool is_selected = (int)i - 1 == selected_row;

            Elements row_cells;
            if (show_pid)
                row_cells.push_back(text(" " + rows[i][0]) | size(WIDTH, EQUAL, 8));
            row_cells.push_back(text(" " + rows[i][1]) | size(WIDTH, EQUAL, 20));
            if (show_cpu)
                row_cells.push_back(text(" " + rows[i][2]) | size(WIDTH, EQUAL, 8));
            if (show_mem)
                row_cells.push_back(text(" " + rows[i][3]) | size(WIDTH, EQUAL, 12));

            auto row = hbox(std::move(row_cells));
            if (is_selected) row = row | inverted;
            lines.push_back(row);
        }

        return Cells::cell_110x30(
            vbox({
                header,
                vbox(std::move(lines)) | vscroll_indicator | frame | size(HEIGHT, LESS_THAN, 20),
            })
        );
    });
}
