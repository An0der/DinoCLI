#include "Image.h"
#include <string>
#include <iostream>
#include <ifstream>


Image::Image(std::string fileName)
    : mFileName {fileName}
{   
    parseImage();
}

const std::map<std::string, std::vector<std::string> >& 
Image::getImageLines() const
{
    return mImageLines;
}

void Image::checkFile(const std::ifstream& file) const
{
    const std::ifstream& img_file {file};
    if (!img_file.is_open())
    {   
        std::cerr << "Check your file.Maybe it's not created?\n"; 
        throw std::runtime_error("File is not available");
    }
}

void Image::parseImage()
{   
    std::ifstream img_file(mPathToImage + mFileName);
    checkFile(img_file);
    std::string line {};
    while (std::getline(img_file, line))
    {
        if (line == "{")
        {
            std::getline(img_file, line);
            std::string name = line;
            std::getline(img_file, line);
            while (line != "}")
            {
                mImageLines[name].push_back(line);
                std::getline(img_file, line);
            }
        }
    }
    img_file.close();
}