//
// Created by onihilist on 24/07/2025.
//

#include "../includes/DashboardManager.h++"
#include <iostream>

#include <ftxui/component/component.hpp>
#include <ftxui/component/event.hpp>
#include <ftxui/component/screen_interactive.hpp>
#include <ftxui/dom/elements.hpp>

using namespace ftxui;

DashboardManager::DashboardManager()
    : title("NTaskManager") {}

void DashboardManager::run() {
    // cell builders
    auto cell_20x1 = [](Element e) { return e | size(WIDTH, EQUAL, 20) | size(HEIGHT, EQUAL, 1) | border; };
    auto cell_110x1 = [](Element e) { return e | size(WIDTH, EQUAL, 110) | size(HEIGHT, EQUAL, 1) | border; };
    auto cell_40x1 = [](Element e) { return e | size(WIDTH, EQUAL, 40) | size(HEIGHT, EQUAL, 1) | border; };
    auto cell_30x10 = [](Element e) { return e | size(WIDTH, EQUAL, 30) | size(HEIGHT, EQUAL, 10) | border; };
    auto cell_110x30 = [](Element e) { return e | size(WIDTH, EQUAL, 110) | size(HEIGHT, EQUAL, 30) | border; };
    auto cell = [](Element e) { return e | border; };

    CheckboxOption opt1{.label = "Show PID", .checked = true};
    CheckboxOption opt2{.label = "Show memory usage", .checked = false};
    CheckboxOption opt3{.label = "Show CPU usage", .checked = false};

    Component task_list = Container::Vertical({
        Checkbox(opt1),
        Checkbox(opt2),
        Checkbox(opt3),
    });

    Component layout = Renderer(task_list, [&] {
        return gridbox({
            {
                cell_20x1(text("NTaskManager") | color(Color::Cyan) | center),
                cell_110x1(text("")),
                cell_40x1(text("[CPU 56%] [GPU 2%] [MEM 68%]") | color(Color::Grey53) | center),
            },
            {
                cell_30x10(
                    vbox({
                        text("Options") | center,
                        separator(),
                        task_list->Render()
                    })
                ),
                gridbox({
                    {
                        cell_110x30(text("center"))
                    }
                }),
                cell_30x10(text("center-east")),
            },
            {
                cell(text("south-west")),
                cell(text("south")),
                cell(text("Press 'q' to quit") | color(Color::Yellow) | center),
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
