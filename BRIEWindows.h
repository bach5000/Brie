/*

BeOS Rapid Integrated Environment (BRIE)

BRIEWindows Header by Sikosis

Released under the MIT license.

(C) 2002-2003 http://brie.sf.net/

*/

#ifndef __BRIEWINDOWS_H__
#define __BRIEWINDOWS_H__

//#include "brie.h"
#include "BRIEViews.h"
#include "URLView.h"
//#include "brieconstants.h"

class BPictureButton;
class FileWindowView; 
class ProjectWindowView;
class PropertiesWindowView;
class ToolboxWindowView;
class NewProjectWindowView;
class AboutWindowView;
class BRIEIconView;
class HelpTipView;
class InputBoxView;


class ProjectWindow : public BWindow
{
	public:
    	ProjectWindow(BRect frame);
	    ~ProjectWindow();
    	virtual bool QuitRequested();
	    virtual void MessageReceived(BMessage *message);
	    void AddProjectFile(BString tmp);
	    
	    BStringView         *stvProjectName;
	    BListView       	*lsvProjectFiles;
	private:
		void InitWindow(void);
		void ShowProjectFiles(BMessage *msg);
	    ProjectWindowView*  ptrProjectWindowView;
	    
	    //BListView       	*lsvProjectFiles;
	    BPictureButton      *btnAddFileToProjectList;
	    BPictureButton      *btnRemoveFileFromProjectList;
};


class AboutWindow : public BWindow
{
	public:
		AboutWindow(BRect frame);
		~AboutWindow();
		virtual void MessageReceived(BMessage *message);
	private:
		void InitWindow(void);
	    AboutWindowView*   ptrAboutWindowView;
	    BRIEIconView*      ptrBRIEIconView;
	    
	    BButton            *btnOkay;
	    //URLView			   *urlWebSite;
	    //URLView			   *urlEmail;
	    //URLView			   *urlVersion;
	    //URLView            *urlMDR;
	    
	    BStringView        *stvMDR;
	    BStringView        *stvWebSiteAddress;
	    BStringView        *stvEmailAddress;
	    BStringView        *stvVersionNumber;
	    BStringView        *stvVersion;
	    BStringView        *stvEmail;
	    BStringView        *stvEmail2;
	    BStringView        *stvAppName;
	    BStringView	       *stvDescription;
	    BStringView	       *stvDescription2;
	    BStringView	       *stvDescription3;
	    BStringView	       *stvDescription4;	    
	    BStringView	       *stvDescription5;	
	    BStringView		   *stvDescription6;
};


class FileWindow : public BWindow
{
	public:
    	FileWindow(BRect frame);
	    ~FileWindow();
    	virtual bool QuitRequested();
	    virtual void MessageReceived(BMessage *message);
	    void SaveProject(void);
	    void GetCurrentPath(void);
	private:
		void InitWindow(void);
	    void CompileGCC(void);
	    void CreateMakeFile(void);
	    void CreateJamFile(void);
	    void SetProject(const char *prjname);
	    FileWindowView* 	ptrFileWindowView;
	    FileWindow*			ptrFileWindow;
	    ProjectWindow*		ptrProjectWindow;
	    
	    BMenuBar  			*menubar;
	    BMenuItem			*menusaveproject;
	    BMenuItem			*menusaveasproject;
	    BMenuItem           *menuwinproj;
	    BMenuItem			*menucreatemakefile;
	    BMenuItem			*menucreatejamfile;
	    BMenuItem			*menucompilegcc;
	    BMenuItem			*menucreatedox;
	    AboutWindow         *aboutWindow;
	    BPictureButton      *btnNewProject;
	    BPictureButton      *btnLoadProject;
	    BPictureButton      *btnSaveProject;
	    BPictureButton      *btnSaveAsProject;
	    BPictureButton      *btnPrintProject;
	    BPictureButton      *btnCreateMake;
	    BPictureButton      *btnCreateJam;
	    BPictureButton      *btnCompile;
	    BPictureButton      *btnOptions;
	    BPictureButton      *btnHelp;
	    BFilePanel			*BrowsePanel;
};


class NewProjectWindow : public BWindow
{
	public:
    	NewProjectWindow(BRect frame);
	    ~NewProjectWindow();
	    virtual void MessageReceived(BMessage *message);
	    void ShowTracker(char apath[256],char AppName[256]);
	private:
		void InitWindow(void);
		void CreateNewProject(void);
		void CreateExistingProject(void);
	    NewProjectWindowView*		ptrNewProjectWindowView;
	    	    
	    BButton         		    *btnAdd;  // alias Create
	    BButton         		    *btnCancel;
	    BTextControl                *txtNewProject;
	    BTextControl                *txtAuthor;
	    BMessage					*msg;
	    BCheckBox					*chkLoadSavePrefs;
	    BCheckBox					*chkMenuBar;
};


class PropertiesWindow : public BWindow
{
	public:
    	PropertiesWindow(BRect frame);
	    ~PropertiesWindow();
    	virtual bool QuitRequested();
	    virtual void MessageReceived(BMessage *message);
	    void ShowProperties(BString currentobject, BString objectname);
	private:
		void InitWindow(void);
		void AddPropertyItem(BString propname, BString propvalue);
	    PropertiesWindowView* ptrPropertiesWindowView;
	    
	    BListView	*lsvProperties;
};


class ToolboxWindow : public BWindow
{
	public:
    	ToolboxWindow(BRect frame);
	    ~ToolboxWindow();
    	virtual bool QuitRequested();
	    virtual void MessageReceived(BMessage *message);
	private:
		void InitWindow(void);
	    ToolboxWindowView* ptrToolboxWindowView;
	    
	    BPictureButton		*btnBrieStringViewControl; // aka Label
	    BPictureButton      *btnBrieTextControl;   
	    BPictureButton      *btnBrieButtonControl;
	    BPictureButton      *btnBriePictureControl; // aka Image 
};


class HelpTipWindow : public BWindow
{
	public:
		HelpTipWindow(BRect frame);
		~HelpTipWindow();
		virtual bool QuitRequested();
		virtual void MessageReceived(BMessage *message);
	private:
		void SaveTipSettings(void);
		void InitWindow(void);
		HelpTipView*	ptrHelpTipView;
		
		BButton			*btnOkay;
	    BStringView		*stvTipTitle;
	    BStringView     *stvTipText;
	    BStringView     *stvTipText2;
	    BStringView     *stvTipText3;
	    BCheckBox		*chkDontShowAgain;
};

class InputBoxWindow : public BWindow
{
	public:
		InputBoxWindow(BRect frame);
		~InputBoxWindow();
		virtual bool QuitRequested();
		virtual void MessageReceived(BMessage *message);
	private:
		void InitWindow(void);
		InputBoxView*	ptrInputBoxView;
		
		BButton			*btnOkay;
	    BTextControl    *txtQuestion;
};

#endif
