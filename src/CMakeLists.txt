set(project_SRC
    main.cpp
)

add_executable(dinoCLI ${project_SRC})

target_link_libraries(dinoCLI
  PRIVATE ftxui::screen
  PRIVATE ftxui::dom
  PRIVATE ftxui::component
)

install(TARGETS dinoCLI DESTINATION /usr/bin)