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
    std::map<int, std::vector<std::string> > parseImage() const;
    // Ref to ImageLines
    const std::map<int, std::vector<std::string> >& getImageLines() const;     
    // Checks wheather file is opened correctly or not
    void checkFile(const std::ifstream& file) const;
    
    int getState() const;

    void setState(int state);
private:
    std::string mRelPathToDir {};
    std::string mFileName {};
    // could use just int instead of string key.
    std::map<int, std::vector<std::string> > mImageLines; 
    int mState {};
};