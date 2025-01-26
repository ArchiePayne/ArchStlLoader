// ArchStlLoader.cpp : Defines the exported functions for the DLL.
//

#include "pch.h"
#include "framework.h"
#include "ArchStlLoader.h"

#include <iostream>
#include <fstream>


extern "C" ARCHSTLLOADER_API bool LoadSTL(const std::string& filePath, StlLoader::ImportedStl& outStl)
{
    std::ifstream infile;
    infile.open(filePath, std::ios::binary | std::ios::in);

    if (!infile) 
    {
        std::cerr << "Failed to open file." << std::endl;
        return false; // Exit if file opening failed
    }

    infile.ignore(80);

    uint32_t numTris = 0;
    char numTrisBuf[4];

    // Read the next 4 bytes into the buffer
    infile.read(numTrisBuf, 4);
    uint32_t num;
    memcpy(&num, numTrisBuf, 4);

    std::vector<StlLoader::Triangle> tris{};
    for (uint32_t i = 0; i < num; i++)
    {
        StlLoader::Triangle tri{};

        infile.read(reinterpret_cast<char*>(tri.Normal), 12);
        infile.read(reinterpret_cast<char*>(tri.v1), 12);
        infile.read(reinterpret_cast<char*>(tri.v2), 12);
        infile.read(reinterpret_cast<char*>(tri.v3), 12);

        tris.push_back(tri);

        infile.ignore(2);
    }

    outStl.Triangles = tris;

    for (uint32_t i = 0; i < tris.size(); ++i) 
    {
        outStl.IndexArray.push_back(i * 3);
        outStl.IndexArray.push_back(i * 3 + 1);
        outStl.IndexArray.push_back(i * 3 + 2);
    }

    return true;
}