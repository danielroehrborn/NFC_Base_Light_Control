#include <Windows.h>
#include "UIForm.h"

using namespace UIProject;

void main() {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	MyForm mainWindow;
	mainWindow.Show();
	Application::Run();
}