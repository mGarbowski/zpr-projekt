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
        EvolutionManagerFactory.cc
        EvolutionManagerFactory.h
        Window.cc
        Window.h
)

set(APP_LIBRARIES
        sfml-graphics
        ImGui-SFML::ImGui-SFML
        simulation
        road
        visualisation
        evolution
)

add_executable(app ${APP_SOURCES}
        BestCarParamsPanel.cc
        BestCarParamsPanel.h)
target_link_libraries(app PRIVATE ${APP_LIBRARIES})

add_library(app-lib ${APP_SOURCES})
target_link_libraries(app-lib PRIVATE ${APP_LIBRARIES})
target_include_directories(app-lib INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})