#ifndef REALEXECUTIONMAIN_CPP_H__
#define REALEXECUTIONMAIN_CPP_H__

#include "../../../BaseProgramFile.h"

const char* REALEXECUTIONMAIN_CPP_FILE_NAME=R"(RealExecutionMain.cpp)";
const char* REALEXECUTIONMAIN_CPP_PATH=R"(\\Source\\Private)";

const char* REALEXECUTIONMAIN_CPP_H=R"(
#include "RealExecutionMain.h"

IMPLEMENT_APPLICATION(ProgramTemplate, "ProgramTemplate");

int RealExecutionMain(const TCHAR* pCmdLine)
{
	ON_SCOPE_EXIT
	{
		RequestEngineExit(TEXT("Exiting"));
		FEngineLoop::AppPreExit();
		FModuleManager::Get().UnloadModulesAtShutdown();
		FEngineLoop::AppExit();
	};

    std::cout << "Hello UE4!" << std::endl;

	// init Engine
	GEngineLoop.PreInit(GetCommandLineW());
	FSlateApplication::InitializeAsStandaloneApplication(GetStandardStandaloneRenderer());

	FSlateApplication::InitHighDPI(true);

	// create a test window
	FGlobalTabmanager::Get()->SetApplicationTitle(LOCTEXT("AppTitle", "ProgramTemplate"));
	TSharedPtr<SWindow> MainWindow = SNew(SWindow)
		.Title(LOCTEXT("MainWindow_Title", "Hello UE4!"))
		.ScreenPosition(FVector2D(800, 600))
		.ClientSize(FVector2D(900, 600))
		.AutoCenter(EAutoCenter::None);
		
	FSlateApplication::Get().AddWindow(MainWindow.ToSharedRef());

	while (!IsEngineExitRequested())
	{
		BeginExitIfRequested();
	
		FTSTicker::GetCoreTicker().Tick(FApp::GetDeltaTime());
		FSlateApplication::Get().Tick();
		FSlateApplication::Get().PumpMessages();
	}

	MainWindow->HideWindow();

	FCoreDelegates::OnExit.Broadcast();
	FSlateApplication::Shutdown();

	return 0;
}

)";


class FileRealExecutionMain_cpp:public BaseProgramFile
{
public:
	virtual void Init(const std::string& pProgramName)override
	{
		BaseProgramFile::Init(pProgramName);
		
		file_name=REALEXECUTIONMAIN_CPP_FILE_NAME;
		file_path=ProgramName+REALEXECUTIONMAIN_CPP_PATH;
		file_content=REALEXECUTIONMAIN_CPP_H;
	}
};

FileRealExecutionMain_cpp RealExecutionMain_cpp=FileRealExecutionMain_cpp();

#endif