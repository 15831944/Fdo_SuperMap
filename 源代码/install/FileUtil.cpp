#include "StdAfx.h"
#include "FileUtil.h"

FileUtil::FileUtil(void)
{
}

FileUtil::~FileUtil(void)
{
}

BOOL FileUtil::FileExists(CString strFile)
{
	BOOL ret = FALSE;

	WIN32_FIND_DATA findData;
	HANDLE findHandle = ::FindFirstFile (strFile, &findData);
	if (INVALID_HANDLE_VALUE != findHandle)
	{
		::FindClose (findHandle);
		ret = TRUE;
	}
	else
		ret = FALSE;

	return ret;
}

CString FileUtil::GetParentDir(CString strPath)
{
	return strPath.Left(strPath.ReverseFind('\\'));
}

//Ŀ¼�Ƿ����
BOOL FileUtil::FolderExists(CString strPath)
{
	DWORD attr;   
	attr = GetFileAttributes(strPath);  
	return (attr != (DWORD)(-1)) && (attr & FILE_ATTRIBUTE_DIRECTORY);   
}


//����Ŀ¼�����Զ�㴴���������ɹ������Ѵ��ڣ�����true; ���򷵻�false
BOOL FileUtil::SuperMkDir(CString strPath)
{
	int len = strPath.GetLength();
	if ( len < 2 ) return FALSE;  //����ַ�������С��2��������Ч��·����ʽ��

	if ('\\' == strPath[len - 1])
	{
		strPath = strPath.Left(len - 1);
		len = strPath.GetLength();
	}// ɾ��ĩβ��"\"
	if ( len <= 0 ) return FALSE;

	if (len <= 3) //�������<=3����ô�ض��Ǹ�Ŀ¼��ʽ
	{
		if (FolderExists(strPath)) return TRUE;//�����Ŀ¼����,����true;
		else return FALSE;              //��������ڣ���Ŀ¼���޷������ģ�����ʧ�ܣ�
	}

	if (FolderExists(strPath)) return TRUE;//���Ŀ¼����,����true;

	// �ֿ���Ŀ¼�ͱ���Ŀ¼����
	CString Parent;
	Parent = strPath.Left(strPath.ReverseFind('\\'));

	if ( Parent.GetLength() <= 0) return FALSE; //Ŀ¼���ƴ���

	BOOL Ret = SuperMkDir(Parent);  //�ݹ鴴����Ŀ¼

	if (Ret)      // ��Ŀ¼����,ֱ�Ӵ���Ŀ¼
	{
		//SECURITY_ATTRIBUTES sa;
		//sa.nLength = sizeof(SECURITY_ATTRIBUTES);
		//sa.lpSecurityDescriptor = NULL;
		//sa.bInheritHandle = 0;
		Ret = (CreateDirectory(strPath, NULL) == TRUE);
		return Ret;
	}
	else
		return FALSE;
}

CString FileUtil::GetPartContent(CString strPathName, PartType nPartType)
{

	CString strReturn = _T("");

	TCHAR drive[_MAX_DRIVE];
	TCHAR dir[_MAX_DIR];
	TCHAR fname[_MAX_FNAME];
	TCHAR ext[_MAX_EXT];
	_tsplitpath(strPathName, drive, dir, fname, ext); // C4996

	switch (nPartType)
	{
	case DRIVE:
		strReturn = drive;
		break;
	case DIR:
		strReturn = dir;
		break;
	case FNAME:
		strReturn = fname;
		break;
	case EXT:
		strReturn = ext;
		break;
	}

	return strReturn;
}

BOOL FileUtil::Delete (const TCHAR* fileName, bool force)
{
    BOOL ret;
#ifdef _WIN32

    ret = 0 != ::DeleteFile (fileName);

	// Make the file writable if required
	if ( !ret && force ) {
        DWORD accessFlags = GENERIC_READ | GENERIC_WRITE;
        DWORD fileFlags = FILE_ATTRIBUTE_NORMAL | FILE_FLAG_RANDOM_ACCESS;
        DWORD createFlags = OPEN_EXISTING;

		::CreateFile (fileName, accessFlags, FILE_SHARE_READ, NULL, createFlags, fileFlags, NULL);

	    ret = 0 != ::DeleteFile (fileName);
	}

#else // _WIN32
    char* file;
    conv_wide_to_utf8 (file, fileName);
    ret = 0 == unlink (file);

#endif // _WIN32

    return (ret);
}

BOOL FileUtil::Move (const TCHAR* oldFileName, const TCHAR* newFileName)
{
    BOOL ret;

#ifdef _WIN32
    // try using ::MoveFileEx() since it is the safest way to move a file

    DWORD moveFlags = MOVEFILE_REPLACE_EXISTING | MOVEFILE_COPY_ALLOWED;
    ret = 0 != ::MoveFileEx (oldFileName, newFileName, moveFlags);
 
    // if the move failed because the ::MoveFileEx() call is not supported
    // (this is the case under Windows 95), then do a delete-file followed
    // by a move-file

    if (!ret && (ERROR_CALL_NOT_IMPLEMENTED == ::GetLastError ()))
        if (!FileExists (newFileName) || Delete (newFileName))
            ret = 0 != ::MoveFile (oldFileName, newFileName);

#else // _WIN32
    char* oldpath;
    char* newpath;
    conv_wide_to_utf8 (oldpath, oldFileName);
    conv_wide_to_utf8 (newpath, newFileName);
    int rename_result = rename (oldpath, newpath);

    // If we failed to do a simple rename operation (for whatever reasons),
    // attempt to do Copy/Delete operations instead:
    if (-1 == rename_result)
    {
        ret = Copy(oldFileName, newFileName);
        if (ret)
        {
            ret = Delete(oldFileName);
            if (!ret)
            {
                // OK failed to delete original "old" file, revert back to original state of affairs and fail:
                bool bDummy = Delete(newFileName);
                ret = false;
            }
        }
    }
    else
        ret = (0 == rename_result);
#endif // _WIN32

    return (ret);
}



