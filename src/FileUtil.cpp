/*************************************************************************************
 * Product: Device-Suite (Device Control Suite)                                      *
 * This program is free software; you can redistribute it and/or modify it           *
 * under the terms version 2 or later of the GNU General Public License as published *
 * by the Free Software Foundation. This program is distributed in the hope          *
 * that it will be useful, but WITHOUT ANY WARRANTY; without even the implied        *
 * warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.                  *
 * See the GNU General Public License for more details.                              *
 * You should have received a copy of the GNU General Public License along           *
 * with this program; if not, write to the Free Software Foundation, Inc.,           *
 * 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA.                            *
 * For the text or an alternative of this public license, you may reach us           *
 * Copyright (C) 2012-2018 E.R.P. Consultores y Asociados, S.A. All Rights Reserved. *
 * Contributor(s): Yamel Senih www.erpya.com                                         *
 *************************************************************************************/
#include "FileUtil.h"
#include "SD.h"
"
/**
 * Implement library FileUtil.h
 */

/**
 * Constructor, get prefix for file, chip selected for out and file format
 */
FileUtil::FileUtil(String prefixFileName, int chipSelected, short fileFormat) {
    _prefixFileName = prefixFileName;
    _chipSelected = chipSelected;
    _fileFormat = fileFormat;
    //  Initialize SD
    if (!SD.begin(_chipSelected)) {
        // don't do anything more:
        while (1);
    }
}

/**
 * Open file
 */
void FileUtil::openFile() {
    if(!_fileToWrite) {
        String format = "txt";
        String fileName = _prefixFileName + "." + format;
        _fileToWrite = SD.open(fileName, FILE_WRITE);
    }
}

/**
 * Close file
 */
void FileUtil::closeFile() {
    if(_fileToWrite) {
        _fileToWrite.close();
    }
}

/**
 * Write file from String, return false if exist a error
 */
boolean FileUtil::write(String valueToWrite) {
    boolean isOk = false;
    if(_fileToWrite) {
        _fileToWrite.print(valueToWrite);
        isOk = true;
    }
    return isOk;
}

/**
 * Write file from String and add a new line after write, return false if exist a error
 */
boolean FileUtil::writeln(String valueToWrite) {
    boolean isOk = false;
    if(_fileToWrite) {
        _fileToWrite.println(valueToWrite);
        isOk = true;
    }
    return isOk;   
}
