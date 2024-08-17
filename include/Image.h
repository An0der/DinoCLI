#pragma once

#include <map>
#include <string>
#include <vector>
#include <fstream>


class Image
{
public:
    Image(std::string fileName); //fileName in Characters dir.
    ~Image() = default;
    void parseImage(); // constexpr ?
    const std::map<std::string, std::vector<std::string> >& getImageLines() const;     
    void checkFile(const std::ifstream&) const;
    
private:
    std::string mFileName {};
    std::map<std::string, std::vector<std::string> > mImageLines;
    const std::string mPathToImage {"../Characters/"};
};