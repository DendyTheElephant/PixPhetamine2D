/// \file		CSkybox.h
///	\author		Daniel Huc
/// \date		January 2017
#pragma once

/* Standard library includes */

/* External dependencies */
#include <GL/glew.h>

/* Modules include */
#include "CommonPhetamine/code/headers/DBasicTypes.h"

/* Internal headers includes */
#include "HConstants.h"
#include "UErrorHandler.h"
#include "FBasicMeshes.h"
#include "CSkyboxTexture.h"
#include "CShader.h"

namespace PixPhetamine2D {

	namespace SceneRendering {

		class CSkybox {
		/* Members */
		private:
			LowLevelWrapper::CBasicMeshCube		m_cube;
			LowLevelWrapper::CSkyboxTexture*	m_texture{ nullptr };
		public:
			LowLevelWrapper::CShader*			m_shader{ nullptr };

		/* Methods */
		public:
			CSkybox(std::string skyboxTexturePathName);
			~CSkybox();

			void draw(pxMat4f modelViewMatrix, pxVec3f cameraPosition);
		};
	}
}