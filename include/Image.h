#pragma once

#include <map>
#include <string>
#include <vector> 
#include <fstream> // std::ifstream
#include <string_view> 


/*
Class represents ASCII Image of all characters used in game.
mRelpathToDir - relative path to dir which contains ascii images
mFileName - file name which contains image
mImageLines - hash table which contains ascii image of certain character:
 key - state of character e.g Dino.mImageLines[1] - image of Dino when makes
 left step.
*/
class Image
{
public:
    
    Image(std::string_view relPathToDir, std::string_view fileName); 
    // why virtual and not abstract class ?
    virtual ~Image() = default;

    // To gather info from textfiles located in relPathToDir
    std::map<int, std::vector<std::string> > parseImage() const;
    // Ref to ImageLines
    const std::map<int, std::vector<std::string> >& getImageLines() const;     
    // Checks wheather file is opened correctly or not
    void checkFile(const std::ifstream& file) const;
    
    // get state of image e.g 1(Dino - left step), 2(Dino - right step)
    int getState() const;

    void setState(int state);
private:
    // Relative path to dir with ASCII images
    std::string mRelPathToDir {};
    std::string mFileName {};
    int mState {};
protected:
    // Made this protected cause i often read this var and not change it.
    std::map<int, std::vector<std::string> > mImageLines; 
};