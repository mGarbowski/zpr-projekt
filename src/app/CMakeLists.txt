set(APP_SOURCES main.cc
        GuiControls.cc
        GuiControls.h ControlPanel.cpp ControlPanel.h DebugInfoPanel.cpp DebugInfoPanel.h)
add_executable(app ${APP_SOURCES})
target_link_libraries(app PRIVATE
        sfml-graphics
        ImGui-SFML::ImGui-SFML
        simulation
        road
        visualisation
)