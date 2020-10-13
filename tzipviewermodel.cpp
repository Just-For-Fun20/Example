#include "tzipviewermodel.h"
#include <QFileInfo>
#include <QDebug>
#include <stdint.h>
#include <stdio.h>
#include "mz.h"
#include "mz_zip.h"
#include "mz_strm.h"
#include "mz_zip_rw.h"
//#include "mz_zip_rw.c"


#include <stdio.h>
TZipViewerModel::TZipViewerModel()
{
    _ZipFileName = "";
    _ZipFileSizeBytes = 0;
}


const std::vector< std::pair<QString, QString> >* TZipViewerModel::GetFilesNameAndSize()
{
    return &_InternalEntityNames;
}

unsigned long long TZipViewerModel::getFileSize()
{
    return _ZipFileSizeBytes;
}

void TZipViewerModel::setZipFileName(std::string fileName)
{
    _ZipFileName = fileName;
}

void TZipViewerModel::openZipFile()
{
    int32_t err = MZ_OK;
    void *zip_instance = NULL;
    mz_zip_file *cd_info = NULL;

    if(mz_os_file_exists(_ZipFileName.c_str()) == 0)
    {
        if(mz_zip_reader_create(&zip_instance))
        {
            err = mz_zip_reader_open_file(zip_instance,_ZipFileName.c_str());
            if(err == MZ_OK)
            {
                err = mz_zip_reader_goto_first_entry(zip_instance);
                if(err == MZ_OK)
                {
                    err = mz_zip_reader_entry_get_info(zip_instance,&cd_info);
                    while (err == MZ_OK)
                    {
                        _InternalEntityNames.push_back(std::make_pair(QString(cd_info->filename),QString::number(cd_info->uncompressed_size)));
                        err = mz_zip_reader_goto_next_entry(zip_instance);
                    }
                }
            }
            mz_zip_reader_close(zip_instance);
        }
    }
}
