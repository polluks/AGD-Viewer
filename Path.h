//---------------------------------------------------------------------------
#ifndef PathH
#define PathH
//---------------------------------------------------------------------------
#include <vcl.h>
//---------------------------------------------------------------------------
namespace System
{
//---------------------------------------------------------------------------
class Path
{
public:
            enum                        Location { lpApplication, lpCommon, lpDocuments, lpProjects };

private:
    static String                       m_Application;
    static String                       m_Common;
    static String                       m_Documents;
    static String                       m_Projects;
    static String                       m_ProjectName;
    static String                       m_Separator;

public:
                            __fastcall  Path();

    static  void            __fastcall  Init();

    static  TStringDynArray __fastcall  GetFiles(const String& folder, const String& filter);
    static  TStringDynArray __fastcall  GetFiles(Location location, const String& filter, const String& subFolder = "");
    static  TStringDynArray __fastcall  GetFolders(Location location, const String& subFolder = "");
    static  String          __fastcall  GetFolder(const Location location, const String& subFolder = "");
    static  String          __fastcall  GetFolderRelativeTo(const Location location, const String& path);
    static  String          __fastcall  GetActiveProjectFolder();
    static  String          __fastcall  Create(Location location, const String& subFolder);
    static  bool            __fastcall  Exists(Location location, const String& subFolder = "");
    static  void            __fastcall  Delete(Location location, const String& subFolder);
    static  void            __fastcall  Rename(Location location, const String& fromSubFolder, const String& toSubFolder);

                                        // application specific files, configs etc (per installation)
    static  __property  String          Application = { read = m_Application };
                                        // common game asset files, common application files (shared)
    static  __property  String          Common = { read = m_Common };
                                        // OS documents folder. The base for all projects
    static  __property  String          Documents = { read = m_Documents };
                                        // game projects folder (shared)
    static  __property  String          Projects = { read = m_Projects };
                                        // active project folder
    static  __property  String          Project = { read = GetActiveProjectFolder };
                                        // the active project name
    static  __property  String          ProjectName = { read = m_ProjectName, write = m_ProjectName };
                                        // The OS file system path separator
    static  __property  String          Separator = { read = m_Separator };
};
extern PACKAGE Path Path;
//---------------------------------------------------------------------------
} // file namespace
//---------------------------------------------------------------------------
#endif
