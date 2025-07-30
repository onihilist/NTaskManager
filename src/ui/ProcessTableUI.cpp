#include "../../includes/ui/ProcessTableUI.h++"
#include "../../includes/ui/Cells.h++"
#include "../../includes/ProcessInfo.h++"
#include <ftxui/dom/elements.hpp>
#include <ftxui/component/component.hpp>

using namespace ftxui;

ProcessTableUI::ProcessTableUI() {
    static ProcessInfo info = ProcessInfo();
    auto rows = info.GetProcessesTable();

    for (size_t i = 1; i < rows.size(); i++)
        labels.push_back(rows[i][1]);
}

Component ProcessTableUI::getTable() {
    Component table_menu = Menu(&labels, &selected_row);

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
