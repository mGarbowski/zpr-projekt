set(APP_SOURCES
        Docs.h
        Main.cc
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
        ConfigurationPanel.cc
        ConfigurationPanel.h
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