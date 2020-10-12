#include "tzipviewermodel.h"
#include <QFileInfo>
#include <stdint.h>
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

void TZipViewerModel::setZipFileName(QString fileName)
{
    _ZipFileName = fileName;
}

void TZipViewerModel::openZipFile()
{

    int32_t err = MZ_OK;
    void *read_mem_stream = NULL;
    void *zip_instance = NULL;
    mz_zip_file *cd_info = NULL;
    //mz_zip_reader reader;
    if(mz_os_file_exists(_ZipFileName.toStdString().c_str()) == 0)
    {
        mz_zip_reader_create(&zip_instance);

        err = mz_zip_reader_open_file(zip_instance,_ZipFileName.toStdString().c_str());

        if(err == MZ_OK)
        {
            err = mz_zip_reader_goto_first_entry(&zip_instance);
            if(err == MZ_OK)
            {
                err = mz_zip_reader_entry_get_info(&zip_instance,&cd_info);
                if (err == MZ_OK)
                {
                    _InternalEntityNames.push_back(std::make_pair(QString(cd_info->filename),QString::number(cd_info->uncompressed_size)));
                }
            }
        }
    }
}
