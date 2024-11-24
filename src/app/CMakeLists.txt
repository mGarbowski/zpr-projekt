set(APP_SOURCES main.cc
        GuiControls.cc
        GuiControls.h)
add_executable(app ${APP_SOURCES})
target_link_libraries(app PRIVATE
        sfml-graphics
        ImGui-SFML::ImGui-SFML
        simulation
        road
)