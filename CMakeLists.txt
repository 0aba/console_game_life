cmake_minimum_required(VERSION 3.27)
project(console_game_life)

set(CMAKE_CXX_STANDARD 23)

add_executable(console_game_life
        main.cpp
        game_logic.cpp
        game_logic.hpp
        game_page.cpp
        game_page.hpp
        menu_page.cpp
        menu_page.hpp
        rules_page.cpp
        rules_page.hpp
        settings_page.cpp
        settings_page.hpp
        my_types.hpp
        pages_utils.cpp
        pages_utils.hpp
        settings.cpp
        settings.hpp
)
