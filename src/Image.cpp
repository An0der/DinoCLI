#include <iostream>
#include <algorithm> // std::max()
#include <fstream>


#include "Image.h"


Image::Image(std::string_view relPathToDir, std::string_view fileName)
    :mRelPathToDir { relPathToDir }, mFileName { fileName },
     mImageLines { parseImage() }
{   
    
}


const std::map<int, std::vector<std::string> >&
Image::getImageLines() const
{   
    return mImageLines;
}

void Image::checkFile(const std::ifstream& file) const
{
    
    if (!file.is_open())
    {   
        std::cerr << "Check your file.Maybe it's not created?\n"; 
        throw std::runtime_error("File is not available");
    }
}

std::map<int, std::vector<std::string> > Image::parseImage() const
{   
    std::ifstream img_file(mRelPathToDir + mFileName);
    std::map<int, std::vector<std::string> > imageLines;
    checkFile(img_file);
    std::string line {};
    // TODO Refactor this
    while (std::getline(img_file, line))
    {
        if (line == "{")
        {   
            int name {};
            img_file >> name;
            std::string end;
            std::getline(img_file, end);
            std::getline(img_file, line);
            while (line != "}")
            {
                imageLines[name].push_back(line);
                std::getline(img_file, line);
            }
        }
    }
    img_file.close();
    return imageLines;
}

int Image::getState() const { return mState; }

void Image::setState(int state) { mState = state; }


int main()
{
    Image img {"../Characters/", "Dino"};
   
}