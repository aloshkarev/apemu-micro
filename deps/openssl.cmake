file(COPY ${CMAKE_SOURCE_DIR}/openssl/ DESTINATION ${CMAKE_BINARY_DIR}/openssl)
add_custom_target(openssl ALL
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/openssl
        COMMAND ./Configure linux-x86 shared
        COMMAND make -j4
        COMMAND mkdir -p ${CMAKE_BINARY_DIR}/ap-emu-build/lib
        COMMAND cp -fP *.so* ${CMAKE_BINARY_DIR}/ap-emu-build/lib
        COMMAND mkdir -p ${CMAKE_BINARY_DIR}/ap-emu-build/bin
        COMMAND cp -fP apps/openssl ${CMAKE_BINARY_DIR}/ap-emu-build/bin
        COMMAND mkdir -p ${CMAKE_BINARY_DIR}/ap-emu-build/ssl
        COMMAND cp -fP apps/openssl.cnf ${CMAKE_BINARY_DIR}/ap-emu-build/ssl
        )