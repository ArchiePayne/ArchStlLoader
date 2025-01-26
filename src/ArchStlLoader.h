// The following ifdef block is the standard way of creating macros which make exporting
// from a DLL simpler. All files within this DLL are compiled with the ARCHSTLLOADER_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see
// ARCHSTLLOADER_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.

#include <vector>
#include <string>

#ifdef ARCHSTLLOADER_EXPORTS
#define ARCHSTLLOADER_API __declspec(dllexport)
#else
#define ARCHSTLLOADER_API __declspec(dllimport)
#endif

namespace StlLoader
{
    struct Triangle
    {
        float Normal[3];
        float v1[3];
        float v2[3];
        float v3[3];
    };

    struct ImportedStl
    {
        std::vector<Triangle> Triangles;
        std::vector<uint32_t> IndexArray;
    };

    extern "C" ARCHSTLLOADER_API bool LoadSTL(const std::string& filePath, StlLoader::ImportedStl& outStl);
}