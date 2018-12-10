/*************************************************************************************
 * Product: Device-Suite (Device Control Suite)                                      *
 * This program is free software; you can redistribute it and/or modify it           *
 * under the terms version 3 of the GNU General Public License as published          *
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

/**
 * Implement library FileUtil.h
 */

/**
 * Constructor, get prefix for file, chip selected for out and file format
 */
FileUtil::FileUtil(String prefixFileName, uint8_t chipSelected, uint8_t fileFormat) {
    _prefixFileName = prefixFileName;
    _chipSelected = chipSelected;
    _fileFormat = fileFormat;
    //  Initialize SD
    if (!SD.begin(_chipSelected)) {
        // don't do anything more:
        while (1);
    }
    //	Init values
    initValues();
}

/**
 * Init default values
 */
void FileUtil::initValues() {
	String format;
	switch (_fileFormat) {
	case CSV_FORMAT:
		format = "csv";
		_separator = CSV_SEPARATOR;
		break;
	case TSV_FORMAT:
		format = "tsv";
		_separator = TSV_SEPARATOR;
		break;
	case KEY_VALUE_FORMAT:
		format = "kvf";
		_separator = TXT_SEPARATOR;
		break;
	default:
		format = "txt";
		_separator = TXT_SEPARATOR;
		break;
	}
	//	Set file name
	_fileName = _prefixFileName + "." + format;
}

/**
 * Open file
 */
void FileUtil::open() {
    if(!_fileToWrite) {
        _fileToWrite = SD.open(_fileName, FILE_WRITE);
    }
}

/**
 * Close file
 */
void FileUtil::close() {
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
        _fileToWrite.print(valueToWrite + _separator);
        isOk = true;
    }
    return isOk;
}

/**
 * Write a new line
 */
boolean FileUtil::newLine() {
    boolean isOk = false;
    if(_fileToWrite) {
        _fileToWrite.print("\n");
        isOk = true;
    }
    return isOk;   
}

/**
 * Get file name from format and prefix
 */
String FileUtil::getFileName() {
	return _fileName;
}
