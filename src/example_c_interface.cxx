#include "example_c_interface.h"
#include "dynlibconfig.h"
#include "build_version_utils.h"

#include <iostream>
#include <cstring>
#include <map>

extern std::map<int, std::string> dliberrcodes;
namespace dynlibglobs
{
    int glob_error_code;
}

extern "C"
{
    //============================================================
    DLL_EXPORT void init_library()
    {
        std::cout << "Initialising library..." << std::endl;

        std::cout << "OK" << std::endl;

        dynlibglobs::glob_error_code = 0;
    }

    //============================================================
    DLL_EXPORT void get_lib_build_information(char* buffer, int* nchars)
    {
        std::string s = std::string("Compiler: ") + build_info::get_compiler_info();
        s += std::string("\n");

        s += std::string("Build date: ") + build_info::get_build_date_time();
        s += std::string("\n");

        s += std::string("CUDA support: ") + build_info::get_nvidia_cuda_version();

        dynlibglobs::glob_error_code = 0;
    }

    //============================================================
    DLL_EXPORT void get_lib_version(char* buffer, int* nchars)
    {
        std::string s = std::to_string(DYNLIB_VERSION_MAJOR) + 
            std::string(".") + std::to_string(DYNLIB_VERSION_MINOR) + 
            std::string(".") + std::to_string(DYNLIB_VERSION_PATCH);
        
        if (buffer)
        {   
            strcpy(buffer, s.c_str());
            dynlibglobs::glob_error_code = 0;
            return;
        }
        else 
        {
            *nchars = s.length();
            dynlibglobs::glob_error_code = 0;
            return;
        }
    }

    //============================================================
    DLL_EXPORT void get_lib_error_status(int* err_stat)
    {
        *err_stat = dynlibglobs::glob_error_code;

        // reset error code
        dynlibglobs::glob_error_code = 0;
    }

    //============================================================
    DLL_EXPORT void translate_lib_error_status(const int err_stat, char* buffer, int* nchars)
    {
        std::string s;
        auto pos = dliberrcodes.find(err_stat);
        if (pos == dliberrcodes.end()) 
        {
            //handle the error
            s = std::string("Unkown error code");
        } 
        else 
        {
            s = pos->second;
        }

        if (buffer)
        {   
            strcpy(buffer, s.c_str());
        }
        else 
        {
            *nchars = s.length();
        }

        // reset error code
        dynlibglobs::glob_error_code = 0;
    }


}