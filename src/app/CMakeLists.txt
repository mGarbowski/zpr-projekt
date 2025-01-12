set(APP_SOURCES
        Docs.h
        Main.cc
        GuiControls.cc
        GuiControls.h
        ControlPanel.cpp
        ControlPanel.h
        DebugInfoPanel.cpp
        DebugInfoPanel.h
        SimulationsManager.cc
        SimulationsManager.h
        FitnessFunction.cc
        FitnessFunction.h
        EvolutionManager.cc
        EvolutionManager.h
)

add_executable(app ${APP_SOURCES})
target_link_libraries(app PRIVATE
        sfml-graphics
        ImGui-SFML::ImGui-SFML
        simulation
        road
        visualisation
        evolution
)