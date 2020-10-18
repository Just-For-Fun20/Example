#ifndef TZIPVIEWERMODEL_H
#define TZIPVIEWERMODEL_H

#include <QString>
#include <vector>
#include <utility>
#include <string>

//------------------include C library--------------------//

#include "mz_crypt.h"
#include "mz_os.h"
#include "mz_strm_mem.h"
#include "mz_strm_buf.h"
#include "mz_strm_os.h"



class TZipViewerModel
{

private:
    std::vector< std::pair<QString, QString> > _InternalEntityNames;
    std::string _ZipFileName;
    unsigned long long  _ZipFileSizeBytes;

public:
    TZipViewerModel();
    unsigned long long getFileSize();
    void setZipFileName(std::string fileName);
    const std::vector< std::pair<QString, QString> > GetFilesNameAndSize();
    void openZipFile();
};

#endif // TZIPVIEWERMODEL_H
