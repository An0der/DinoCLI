set(project_SRC
    main.cpp
    )

add_executable(dinoCLI ${project_SRC})

set(CURSES_NEED_NCURSES TRUE)
find_package(Curses)

if(Curses_FOUND AND NOT TARGET Curses::Curses)
  add_library(Curses::Curses INTERFACE IMPORTED)
  set_target_properties(
    Curses::Curses
    PROPERTIES
      INTERFACE_LINK_LIBRARIES "${CURSES_LIBRARIES}"
      INTERFACE_INCLUDE_DIRECTORIES "${CURSES_INCLUDE_DIRS}"
  )
endif()

target_link_libraries(dinoCLI PRIVATE Curses::Curses)