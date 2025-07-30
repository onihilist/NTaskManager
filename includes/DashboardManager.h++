//
// Created by onihilist on 24/07/2025.
//

#ifndef DASHBOARD_MANAGER_HPP
#define DASHBOARD_MANAGER_HPP

#include <string>

class DashboardManager {
public:
    DashboardManager();

    void run();

private:
    void renderUI();
    void handleInput();

    std::string title;
};

#endif // DASHBOARD_MANAGER_HPP

