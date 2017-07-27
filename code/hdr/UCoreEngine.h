/// \file		UCoreEngine.h
/// \author		Daniel Huc, Henry Lefèvre
/// \date		April 2016
#pragma once

/* Standard library includes */
#include <stdio.h>
#include <stdlib.h>
#include <map>
#include <string>

/* External dependencies */
#include <GL/glew.h>
#include <SDL2/SDL.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

/* Modules include */
#include "CommonPhetamine/code/headers/DBasicTypes.h"

/* Internal headers includes */
#include "HConstants.h"
#include "CStaticMesh.h"
#include "CShader.h"
#include "PadPhetamine/code/headers/CInputHandler.h"
#include "CCamera.h"
#include "CTimer.h"
#include "LowLevelRenderingWrapper.h"
#include "UErrorHandler.h"
#include "FDisplay.h"
#include "CFrameBuffer.h"
#include "CPostProcessPass.h"
#include "CSkybox.h"

/* Singleton */
class UCoreEngine {
/* Members */
private:
	static UCoreEngine* game;

	pxBool m_isRunning;

	pxInt m_frame{ 0 };
	pxUInt64 m_elapsedTime{ 0 };
	CTimer m_secondTimer; // Timer reset on each second for FPS computation
	char m_windowCaption[64]; // Window caption (updated on each frame to show FPS)

	SDL_Window* m_SDLWindow; // Our window handle
	SDL_GLContext m_GLContext; // Our opengl context handle

	PadPhetamine::CInputHandler* m_InputHandler; // Retrieve the inputs of player one
	PixPhetamine2D::CCamera* m_Camera; // Camera for the player one

	std::vector<std::string> m_ShaderNames;
	std::vector<std::string> m_MeshNames;

	std::map<std::string, PixPhetamine2D::LowLevelWrapper::CShader*> m_ShaderList; // List of the shaders used in the game
	std::map<std::string, PixPhetamine2D::CStaticMesh*> m_MeshList;

	pxMat4f m_ModelMatrix;
	pxMat4f m_ViewProjectionMatrix;
	pxMat4f m_ModelViewProjectionMatrix;

	PixPhetamine2D::PostProcess::CFrameBuffer* m_GBufferMS;
	PixPhetamine2D::PostProcess::CFrameBuffer* m_GBufferAA;
	PixPhetamine2D::PostProcess::CFrameBuffer* m_DownSampled;
	PixPhetamine2D::PostProcess::CFrameBuffer* m_RGBSplitted;
	PixPhetamine2D::PostProcess::CFrameBuffer* m_BufferBlurPartial;
	PixPhetamine2D::PostProcess::CFrameBuffer* m_BufferBlur;

	PixPhetamine2D::PostProcess::CPostProcessPass* m_DownSamplingPass;
	PixPhetamine2D::PostProcess::CPostProcessPass* m_BlurPassPartI;
	PixPhetamine2D::PostProcess::CPostProcessPass* m_BlurPassPartII;
	PixPhetamine2D::PostProcess::CPostProcessPass* m_RGBSplitPass;
	PixPhetamine2D::PostProcess::CPostProcessPass* m_DeferredShadingPass;

	PixPhetamine2D::SceneRendering::CSkybox* m_skyBox;

/* Methods */
private:
	UCoreEngine();
	~UCoreEngine();
	void loadShaders();
	void reloadShaders();
	void loadMeshes();

public:
	static UCoreEngine& getInstance();
	static void destroyInstance();
	void runGameLoop();
};
