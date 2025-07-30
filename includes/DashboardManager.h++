//
// Created by onihilist on 24/07/2025.
//

#ifndef DASHBOARD_MANAGER_HPP
#define DASHBOARD_MANAGER_HPP

#include <string>

class DashboardManager {
public:
    DashboardManager();

    int selected_pane = 0;
    void run();

private:
    void renderUI();
    void handleInput();

    std::string title;
};

#endif // DASHBOARD_MANAGER_HPP

