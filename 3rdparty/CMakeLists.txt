set
(
    DEFAULT_INSTALL_PREFIX "/usr/local" 
)


add_custom_command
(
    OUTPUT ${DEFAULT_INSTALL_PREFIX}/lib/libncurses*.*
    OUTPUT ${DEFAULT_INSTALL_PREFIX}/lib/libcurses.a
    OUTPUT ${DEFAULT_INSTALL_PREFIX}/include/*

    COMMAND "cd" "ncurses"
    COMMAND "./configure"

)