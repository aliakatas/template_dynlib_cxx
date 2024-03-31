#ifndef EXAMPLE_C_INTERFACE_H 
#define EXAMPLE_C_INTERFACE_H  

#ifdef _WIN32
#define DLL_EXPORT __declspec(dllexport)
#else
#define DLL_EXPORT __attribute__((visibility("default")))
#endif

extern "C"
{

    /**
     * @brief Initialise the library to work correctly for
     * subsequent calls.
    */
    DLL_EXPORT void init_library();

    /**
     * @brief Get information regarding build toolchain.
     * 
     * @param [out] buffer The output buffer containing the string with the information. Can be NULL to force the return of the number of chars needed.
     * @param [inout] nchars The number of characters in the buffer. If buffer is NULL, it returns the number of characters needed.
    */
    DLL_EXPORT void get_lib_build_information(char* buffer, int* nchars);

    /**
     * @brief Get information regarding the version of the library.
     * 
     * @param [out] buffer The output buffer containing the string with the version. Can be NULL to force the return of the number of chars needed.
     * @param [inout] nchars The number of characters in the buffer. If buffer is NULL, it returns the number of characters needed.
    */
    DLL_EXPORT void get_lib_version(char* buffer, int* nchars);

    /**
     * @brief Get error status from the library.
     * Resets the error code to "success".
     * 
     * @param [out] err_stat The error code from the last operation.
    */
    DLL_EXPORT void get_lib_error_status(int* err_stat);

    /**
     * @brief Get the translation to the error status from the library.
     * Resets the error code to "success".
     * 
     * @param [in] err_stat The error code from the last operation.
     * @param [out] buffer The output buffer containing the string with the error translation. Can be NULL to force the return of the number of chars needed.
     * @param [inout] nchars The number of characters in the buffer. If buffer is NULL, it returns the number of characters needed.
    */
    DLL_EXPORT void translate_lib_error_status(const int err_stat, char* buffer, int* nchars);

}

#endif // EXAMPLE_C_INTERFACE_H