//
//  AppUtilDir.cpp
//  AppUtilDir_example
//
//  Created by erik on 16/5/15.
//
//

#include "AppUtilDir.h"

//--------------------------------------------------------------
vector<string> AppUtilDir::getFilesFrom(string _path)
{
    return getFilesFrom(_path, "");
}

//--------------------------------------------------------------
vector<string> AppUtilDir::getFilesFrom(string _path, string _ext)
{
    vector<string> _rgExt;
    if(_ext != "")
        _rgExt.push_back(_ext);
    return getFilesFrom(_path, _rgExt);
}

//--------------------------------------------------------------
vector<string> AppUtilDir::getFilesFrom(string _path, vector<string> _ext)
{
    ofDirectory _dir;
    for (string& _e : _ext) {
        _dir.allowExt(_e);
    }
    _dir.listDir(_path);

    vector<string> _files;
    for (int i=0; i<_dir.size(); i++) {
        _files.push_back(_dir[i].getFileName());
    }
    return _files;
}
