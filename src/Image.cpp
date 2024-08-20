#include <iostream>
#include <algorithm> // std::max()
#include <fstream>


#include "Image.h"

std::pair<int, int> getMaxLegthHeight(const Image& image)
{
    
}

Image::Image(std::string_view relPathToDir, std::string_view fileName)
    :mRelPathToDir {relPathToDir}, mFileName {fileName}
{   
    parseImage();
    setMaxLengthHeight();
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
    std::ifstream img_file(mRelPathToDir + mFileName);
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

int Image::getHeight() const { return mHeight; }


int Image::getLength() const { return mLength; }


void Image::setLength(int length) { mLength = length; }


void Image::setHeight(int height) { mHeight = height; }


void Image::setMaxLengthHeight()
{
    int maxLineLength = 0;
    int height = 0;
    for (auto& line : mImageLines)
    {
        maxLineLength = std::max(static_cast<int>(mImageLines[line.first].size()), maxLineLength);
        ++height;
    }
    setHeight(height);
    setLength(maxLineLength);
}

