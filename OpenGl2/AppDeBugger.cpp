#include "AppDeBugger.h"

AppDebugger* AppDebugger::appDebuger = new AppDebugger();

/*
	获得AppDebugger的单例
	@return appDebugger
*/
AppDebugger * AppDebugger::getInstance()
{
	if (appDebuger == nullptr)
		appDebuger = new AppDebugger();
	return appDebuger;
}

AppDebugger::AppDebugger()
{
	width = -1;
	height = -1;
}
/*
* 窗口的回调函数
* Param window :  窗口
* Param hWndList : 宽
* Param height: 高
* @Return void
*/
void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
	glViewport(0, 0, width, height);
}

/*
	键盘和鼠标等事件的监听
	@Param windows窗口
*/
void AppDebugger::processInput(GLFWwindow * window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);
}
/*
	初始化窗口
*/
int AppDebugger::init()
{
	if (width<=0 || height <=0) {
		std::cout << "Width or Height is NULL" << std::endl;
	}

	// glfw: initialize and configure
	// ------------------------------
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // uncomment this statement to fix compilation on OS X
#endif

														 // glfw window creation
														 // --------------------
	GLFWwindow* window = glfwCreateWindow(width, height, "LearnOpenGL", NULL, NULL);
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	// glad: load all OpenGL function pointers
	// ---------------------------------------
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}

	// render loop
	// -----------
	Update(window);

	// glfw: terminate, clearing all previously allocated GLFW resources.
	// ------------------------------------------------------------------
	glfwTerminate();
	return 0;
}

/*
	更新和重新渲染
	@Param window windows窗口
*/
void AppDebugger::Update(GLFWwindow * window)
{
	
	RectangleRender *rectangleRender = new RectangleRender();
	rectangleRender->CompileShader("./Shader/HelloShader3/HelloShaderObject.vs", "./Shader/HelloShader3/HelloShaderObject.fs");
	rectangleRender->InitVAOAndVBO();

	Light *light = new Light();
	light->CompileShader("./Shader/HelloShader3/HelloShaderLight.vs", "./Shader/HelloShader3/HelloShaderLight.fs");
	light->InitVAOAndVBO();
	glEnable(GL_DEPTH_TEST);
	while (!glfwWindowShouldClose(window))
	{
		// input
		// -----
		processInput(window);
		//
		glClearColor(0,0,0, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT); 
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		rectangleRender->render();
		light->render();

		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	delete(light);
	delete(rectangleRender);
}

/*
*设置窗口的大小
*@Param SCR_WIDTH 屏幕的宽
*@Param SCR_HEIGHT 屏幕的高
*
*/
void AppDebugger::SetWindows(int SCR_WIDTH, int SCR_HEIGHT)
{
	if (SCR_WIDTH <= 0 || SCR_HEIGHT <= 0) {
		std::cout << "Width or Height is NULL" << std::endl;
	}
	this->width = SCR_WIDTH;
	this->height = SCR_HEIGHT;
}
/*
	显示窗口
*/
void AppDebugger::ShowWindows()
{
	init();
}

AppDebugger::~AppDebugger()
{
	
}
