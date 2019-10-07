#include "stdafx.h"
#include "main.h"

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow* window);

// settings
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

const char* vertexShaderSource = "#version 330 core\n"
"layout (location = 0) in vec3 aPos;\n"
"void main()\n"
"{\n"
"   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
"}\0";
const char* fragmentShaderSource = "#version 330 core\n"
"out vec4 FragColor;\n"
"void main()\n"
"{\n"
"   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
"}\n\0";




float vertices[] = {
		-0.5f, -0.5f, 0.0f, // left  
		 0.5f, -0.5f, 0.0f, // right 
		 0.0f,  0.5f, 0.0f  // top   
};

int main()
{

	PIXELFORMATDESCRIPTOR pfd =
	{
		sizeof(PIXELFORMATDESCRIPTOR),
			1,
			PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER,    // Flags
			PFD_TYPE_RGBA,        // The kind of framebuffer. RGBA or palette.
			32,                   // Colordepth of the framebuffer.
			0, 0, 0, 0, 0, 0,
			0,
			0,
			0,
			0, 0, 0, 0,
			24,                   // Number of bits for the depthbuffer
			8,                    // Number of bits for the stencilbuffer
			0,                    // Number of Aux buffers in the framebuffer.
			PFD_MAIN_PLANE,
			0,
			0, 0, 0
	};



	// glfw: initialize and configure
	// ------------------------------
	glfwInit();
	//glfwWindowHint(GLFW_NO_API, GLFW_TRUE);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 4);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // uncomment this statement to fix compilation on OS X
#endif

	// glfw window creation
	// --------------------
	GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "Open Cascade GLFW", NULL, NULL);
	

	//glfwSetWindowUserPointer(window, this);
	
	if (window == NULL)
	{
		OutputDebugString("Failed to create GLFW window\n");
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	HWND winHandle = glfwGetWin32Window(window);
	void* mGlContext = ::wglGetCurrentContext();
	
	/*GLenum err = glewInit();
	if (GLEW_OK != err)
	{
		/* Problem: glewInit failed, something is seriously wrong. 
		//fprintf(stderr, "Error: %s\n", glewGetErrorString(err));
		//...
		OutputDebugString("Error introduced here");
		//return -1;
	}*/
	fprintf(stdout, "Status: Using GLEW %s\n", glewGetString(GLEW_VERSION));
	OutputDebugString("Got GLEW and the OpenGl to work together\n");

	



	//NOT USING GLAD
	/*// glad: load all OpenGL function pointers
	// ---------------------------------------
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}*/

	// render loop
	// -----------
	Aspect_DisplayConnection* myDisplayConnection = new Aspect_DisplayConnection();

	//Handle_Graphic3d_GraphicDriver myDriver = new OpenGl_GraphicDriver(myDisplayConnection, false);
	Handle(OpenGl_GraphicDriver) myDriver = new OpenGl_GraphicDriver(myDisplayConnection, false);
	myDriver->SetBuffersNoSwap(true);
	
	V3d_Viewer* myViewer = new V3d_Viewer(myDriver);
	myViewer->SetDefaultViewSize(1000.);
	myViewer->SetDefaultViewProj(V3d_XposYnegZpos);
	myViewer->SetDefaultBackgroundColor(Quantity_NOC_ALICEBLUE);
	myViewer->SetDefaultVisualization(V3d_ZBUFFER);
	myViewer->SetDefaultShadingModel(V3d_GOURAUD);
	myViewer->SetDefaultLights();
	myViewer->SetLightOn();


	Handle_Aspect_Window myAspect = new Aspect_NeutralWindow();
	//Aspect_RenderingContext asp;// = new Aspect_RenderingContext();
	Handle_OpenGl_Context myGLContext = new OpenGl_Context();

	int iPixelFormat = ChoosePixelFormat(wglGetCurrentDC(), &pfd);
	SetPixelFormat(wglGetCurrentDC(), iPixelFormat, &pfd);


	//myGLContext->Init(winHandle, wglGetCurrentDC(), asp, Standard_False);
	myGLContext->Init(winHandle, ::GetDC(winHandle), &pfd);
	
	//myGLContext->SetColor4fv(OpenGl_Vec4(1.0f,1.0f,1.0f,1.0f));
	
	//glfwMakeContextCurrent(window);
	//OutputDebugStringA(glfwGetCurrentContext());

	Handle_V3d_View myView = myViewer->CreateView();

	
	
	if (myGLContext->IsCurrent())
	{
		OutputDebugString("The custom GL is the current context\n");
	}

	//int iPixelFormat = ChoosePixelFormat(wglGetCurrentDC(), &pfd);
	//SetPixelFormat(wglGetCurrentDC(), iPixelFormat, &pfd);
	HGLRC winGL = wglCreateContext(wglGetCurrentDC());
	//(OpenGl_Context)winGL->Init(winHandle, ::GetDC(winHandle), mGlContext);

	

	myAspect->DoResize();
	//myAspect->Map();
	myView->SetWindow(myAspect, mGlContext);
	myAspect->DoResize();
	char buffer[100];
	Standard_Integer width, height;
	myAspect->Size(width, height);
	myAspect->DoResize();
	sprintf_s(buffer, "The aspect ratio is %.2f\n width = %d, height = %d", myAspect->Ratio(), width, height);
	OutputDebugString(buffer);
	myView->SetSize(800);

	if (!myAspect->IsMapped())
	{
		myAspect->Map();
	}

	//Handle_AIS_InteractiveContext myInteractiveContext = new AIS_InteractiveContext(myViewer);
	//myInteractiveContext->

	while (!glfwWindowShouldClose(window))
	{
		// input
		// -----
		//processInput(window);

		//unsigned int VAO;
		//glGenVertexArrays(1, &VAO);
		// render
		// ------
		//myGLContext->
		//glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		//glClear(GL_COLOR_BUFFER_BIT);

		// glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
		// -------------------------------------------------------------------------------
		//glfwSwapBuffers(window);
		glfwPollEvents();
	}

	// glfw: terminate, clearing all previously allocated GLFW resources.
	// ------------------------------------------------------------------
	glfwTerminate();
	return 0;
}

// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
// ---------------------------------------------------------------------------------------------------------
void processInput(GLFWwindow* window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);
}

// glfw: whenever the window size changed (by OS or user resize) this callback function executes
// ---------------------------------------------------------------------------------------------
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	// make sure the viewport matches the new window dimensions; note that width and 
	// height will be significantly larger than specified on retina displays.
	//glViewport(0, 0, width, height);
}