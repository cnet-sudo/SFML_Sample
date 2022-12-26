cmake_minimum_required(VERSION 3.21)
project(SFML_Sample VERSION 0.0.1 LANGUAGES CXX)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.x)
FetchContent_MakeAvailable(SFML)


add_executable(sample main.cpp )

target_link_libraries(sample PRIVATE sfml-graphics sfml-system sfml-window)
target_compile_features(sample PRIVATE cxx_std_14)
if (WIN32 AND BUILD_SHARED_LIBS)
    add_custom_command(TARGET sample POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_RUNTIME_DLLS:sample> $<TARGET_FILE_DIR:sample> COMMAND_EXPAND_LISTS)
endif()

install(TARGETS sample)

# Директория с СMakeLists.txt
# cmake -S . -B build
# cmake --build build --config Release
# Для запуска проекта выбрать активный проект