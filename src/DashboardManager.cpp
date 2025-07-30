//
// Created by onihilist on 24/07/2025.
//
#include "../includes/DashboardManager.h++"

#include <ftxui/component/component.hpp>
#include <ftxui/component/event.hpp>
#include <ftxui/component/screen_interactive.hpp>
#include <ftxui/dom/elements.hpp>

#include "../includes/ui/Cells.h++"
#include "../includes/ui/ProcessTableUI.h++"

using namespace ftxui;

DashboardManager::DashboardManager()
    : title("NTaskManager") {}

void DashboardManager::run() {

    const auto processTableUI = new ProcessTableUI();

    Component task_list = Container::Vertical({
        Checkbox("Show PID", &processTableUI->show_pid),
        Checkbox("Show CPU usage", &processTableUI->show_cpu),
        Checkbox("Show memory usage", &processTableUI->show_mem),
    });

    Component table_menu = Menu(&processTableUI->labels, &processTableUI->selected_row);

    Component panes = Container::Tab({
        task_list,
        table_menu,
    }, &selected_pane);

    panes = CatchEvent(panes, [&](Event e) {
        if (e == Event::ArrowRight) { selected_pane = 1; return true; }
        if (e == Event::ArrowLeft)  { selected_pane = 0; return true; }
        return false;
    });

    Component layout = Renderer(panes, [&] {
        return gridbox({
            {
                Cells::cell_20x1(text("NTaskManager") | color(Color::SandyBrown) | center),
                Cells::cell_110x1(text("NTaskManager") | color(Color::SandyBrown) | center),
                Cells::cell_40x1(text("[CPU 56%] [GPU 2%] [MEM 68%]") | color(Color::SandyBrown) | center),
            },
            {
                Cells::cell_30x10(
                    vbox({
                        text("Options") | center,
                        separator(),
                        task_list->Render(),
                    })
                ),
                processTableUI->getTable()->Render(),
                Cells::cell_30x10(text("center-east")),
            },
            {
                Cells::cell(text("south-west")),
                Cells::cell(text("Press ← → to switch focus")),
                Cells::cell(text("Press 'q/Q' to quit") | color(Color::Red1) | center),
            },
        });
    });

    auto screen = ScreenInteractive::FitComponent();
    auto app = CatchEvent(layout, [&](Event event) {
        if (event == Event::Character('q') || event == Event::Character('Q')) {
            screen.Exit();
            return true;
        }
        return false;
    });

    screen.Loop(app);
}
