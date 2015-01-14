#ifndef UTILS_H
#define UTILS_H

#include "preinfra.h"

// IN - full path to file with filename
// OUT - only path to file
std::string GetFilePath(const char *filename)
{
    std::string path(filename);

    unsigned int position = path.size();
    for (std::string::iterator itr = path.end(); itr != path.begin(); --itr)
    {
        if ('/' != *itr && '\\' != *itr)
        {
            --position;
        }
        else
        {
            break;
        }
    }
    ++position;

    path.erase(position, path.size());

    return path;
}

#endif // UTILS_H
