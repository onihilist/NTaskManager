cmake_minimum_required(VERSION 3.30)
project(NTaskManager)

set(CMAKE_CXX_STANDARD 20)

include(FetchContent)

FetchContent_Declare(
        ftxui
        GIT_REPOSITORY https://github.com/ArthurSonzogni/FTXUI
        GIT_TAG v6.1.9
)

FetchContent_MakeAvailable(ftxui)

add_executable(NTaskManager main.cpp
        includes/Task.h++
        src/Task.cpp
        src/LegacyTask.cpp
        includes/LegacyTask.h++
        includes/Utils.h++
        src/DashboardManager.cpp
        includes/DashboardManager.h++
        src/ui/ProcessTableUI.cpp
        includes/ui/ProcessTableUI.h++
        includes/ui/Cells.h++
)

target_link_libraries(NTaskManager PRIVATE ftxui::screen ftxui::dom ftxui::component)