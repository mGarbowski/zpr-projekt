set(APP_SOURCES Main.cc
        GuiControls.cc
        GuiControls.h ControlPanel.cpp ControlPanel.h DebugInfoPanel.cpp DebugInfoPanel.h
        Docs.h)
add_executable(app ${APP_SOURCES})
target_link_libraries(app PRIVATE
        sfml-graphics
        ImGui-SFML::ImGui-SFML
        simulation
        road
        visualisation
)