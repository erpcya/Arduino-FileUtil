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
#ifndef FileUtil_h
#define FileUtil_h

#include "Arduino.h"
#include "SD.h"
/**
 * This class if used for handle all file writer
 * you can define a device name
 */
class FileUtil {
    public:
        FileUtil(String prefixFileName, int chipSelected, short fileFormat);
        void openFile();
        void closeFile();
        boolean write(String valueToWrite);
        boolean writeln(String valueToWrite);
    private:
        String _prefixFileName;
        int _chipSelected;
        short _fileFormat;
        File _fileToWrite;
}
#endif
