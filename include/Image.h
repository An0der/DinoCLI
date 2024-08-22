#pragma once

#include <map>
#include <string>
#include <vector> 
#include <fstream> // std::ifstream
#include <string_view> 


/*
Class represents ASCII Image of all 
characters used in game.
*/
class Image
{
public:
    Image(std::string_view relPathToDir, std::string_view fileName); //fileName in Characters dir.
    virtual ~Image() = default;

    // To gather info from textfiles located in relPathToDir
    std::map<std::string, std::vector<std::string> > parseImage() const;
    // Ref to ImageLines
    const std::map<std::string, std::vector<std::string> >& getImageLines() const;     
    // Checks wheather file is opened correctly or not
    void checkFile(const std::ifstream& file) const;

    // inits mHeight with maximum gotten image's line width to use in Rect.
    // int initHeight() const;

    // // inits mwidth
    // int initWidth() const;
    
private:
    std::string mRelPathToDir {};
    std::string mFileName {};
    std::map<std::string, std::vector<std::string> > mImageLines;
};