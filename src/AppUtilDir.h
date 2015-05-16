//
//  AppUtilDir.h
//  AppUtilDir_example
//
//  Created by erik on 16/5/15.
//
//

#ifndef __AppUtilDir_example__AppUtilDir__
#define __AppUtilDir_example__AppUtilDir__

#include "ofMain.h"

class AppUtilDir
{
    
public:
    vector<string> getFilesFrom(string _path);
    vector<string> getFilesFrom(string _path, string _ext);
    vector<string> getFilesFrom(string _path, vector<string> _ext);
};


#endif /* defined(__AppUtilDir_example__AppUtilDir__) */
