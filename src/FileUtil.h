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
#ifndef FileUtil_h
#define FileUtil_h

#include "Arduino.h"
#include "SD.h"
/**
 * This class if used for handle all file writer
 * you can define a device name
 */
static const uint8_t TXT_FORMAT =          1; // txt Format
static const uint8_t CSV_FORMAT =          2; // csv Format
static const uint8_t TSV_FORMAT =          3; // tsv Format
static const uint8_t KEY_VALUE_FORMAT =    4; // key value Format
//	Separator
static const char TXT_SEPARATOR =          '|'; // txt separator
static const char CSV_SEPARATOR =          ','; // csv separator
static const char TSV_SEPARATOR =          '\t'; // tsv separator

class FileUtil {
    public:
        FileUtil(String prefixFileName, uint8_t chipSelected, uint8_t fileFormat);
        void open();
        void close();
        boolean write(String valueToWrite);
        boolean newLine();
        String getFileName();
    private:
    	void initValues();
        String _prefixFileName;
        uint8_t _chipSelected;
        uint8_t _fileFormat;
        char _separator;
        String _fileName;
        File _fileToWrite;
};
#endif
