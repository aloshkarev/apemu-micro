function(deploy_binary_after_build BINARY DEPLOY_DIR)
    add_custom_command(TARGET ${BINARY} POST_BUILD
            COMMAND mkdir -p "${DEPLOY_DIR}/bin"
            COMMAND mkdir -p "${DEPLOY_DIR}/lib"
            COMMAND mkdir -p "${DEPLOY_DIR}/etc"
            COMMAND mkdir -p "${DEPLOY_DIR}/modules"
            COMMAND cp -u "${CMAKE_CURRENT_BINARY_DIR}/${BINARY}" "${DEPLOY_DIR}/bin/${BINARY}"

#            COMMAND cp -u "${CMAKE_CURRENT_BINARY_DIR}/${BINARY}" "${DEPLOY_DIR}/bin/${BINARY}.bin"
#            COMMAND cp -u "${CMAKE_SOURCE_DIR}/scripts/wrapper.sh" "${DEPLOY_DIR}/bin/.${BINARY}_wrapper.sh"
#            COMMAND rm -f "${DEPLOY_DIR}/${BINARY}"
#            COMMAND chmod a+x ${DEPLOY_DIR}/bin/.${BINARY}_wrapper.sh
#            COMMAND cd "${DEPLOY_DIR}/bin" && ln -s -f .${BINARY}_wrapper.sh ${BINARY}
            )

    add_custom_command(TARGET ${BINARY} POST_BUILD
            COMMAND sh "${CMAKE_SOURCE_DIR}/scripts/copy_libs.sh"
            "${DEPLOY_DIR}/bin/${BINARY}"
            "${DEPLOY_DIR}/lib"
            )
endfunction()