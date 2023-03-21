if (NOT TARGET moving_average)
    add_library(moving_average INTERFACE)

    target_sources(moving_average INTERFACE
            ${CMAKE_CURRENT_LIST_DIR}/moving_average.c
    )

    target_include_directories(moving_average INTERFACE
            ${CMAKE_CURRENT_LIST_DIR}
    )

    target_link_libraries(moving_average INTERFACE
        pico_stdlib
    )
endif()