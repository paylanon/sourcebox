cmake_minimum_required(VERSION 2.6 FATAL_ERROR)

project(TheSourceBox)

find_package(Geant4 REQUIRED ui_all vis_all)

include(${Geant4_USE_FILE})

file(GLOB sources ${PROJECT_SOURCE_DIR}/*.cc)
file(GLOB headers ${PROJECT_SOURCE_DIR}/*.hh)

add_executable(SourceBox SourceBox.cc ${sources} ${headers})

target_link_libraries(SourceBox ${Geant4_LIBRARIES})

add_custom_target(TheSourceBox DEPENDS SourceBox)
