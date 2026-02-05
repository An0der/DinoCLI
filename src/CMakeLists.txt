set(project_SRC
    main.cpp
    )

add_executable(dinoCLI ${project_SRC})

target_link_libraries(dinoCLI PRIVATE ncurses_interface)

install(TARGETS dinoCLI DESTINATION /usr/bin)