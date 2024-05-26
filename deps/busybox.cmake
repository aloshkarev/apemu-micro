file(COPY ${CMAKE_SOURCE_DIR}/busybox/ DESTINATION ${CMAKE_BINARY_DIR}/busybox)
add_custom_target(busybox ALL
        COMMAND mkdir -p ${CMAKE_BINARY_DIR}/ap-emu-build/bin
        DEPENDS execcmd
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/busybox
        COMMAND mkdir -p build
        COMMAND cp ${CMAKE_SOURCE_DIR}/scripts/.config build/
        COMMAND make -C . O=build
        COMMAND make -C build -j4
        COMMAND cp -fP build/busybox ${CMAKE_BINARY_DIR}/ap-emu-build/bin
        )


