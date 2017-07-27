﻿////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////====================================================================================================================================////
/// | \file		CInputHandler.h
///	| \author	Daniel Huc
/// | \date		February 2017
/// |----------------------------------------------------------------------------------------------------------------------------------
/// | \brief	Based on SDL2
/// | \details	Blabla
////====================================================================================================================================////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#pragma once

/* Standard library includes */
#include <iostream>

/* External dependencies */
#include <SDL2/SDL.h>

/* Modules include */
#include "CommonPhetamine/code/headers/DBasicTypes.h"

/* Internal headers includes */

#if defined(PADPHETAMINE_EXPORT) // inside DLL
#   define PADPHETAMINE_DLL   __declspec(dllexport)
#else // outside DLL
#   define PADPHETAMINE_DLL   __declspec(dllimport)
#endif

//// ---- Namespaces ---- ////
namespace PadPhetamine {

	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	////====================================================================================================================================////
	//// CInputHandler
	/// \brief		Blabla
	/// \details	Blabla
	////====================================================================================================================================////
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	class PADPHETAMINE_DLL CInputHandler {

	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//// ---- Enumerations -----                                                                                                            ////
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	public:
		enum class EInput {
			UP = SDLK_z,
			DOWN = SDLK_s,
			RIGHT = SDLK_d,
			LEFT = SDLK_q,
			SHOULDER_RIGHT = SDLK_e,
			SHOULDER_LEFT = SDLK_a,
			QUIT = SDLK_ESCAPE
		};

	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//// ---- Members -----																													//// 
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	private:
		SDL_Event event;
		pxMap<EInput, pxUInt16> m_inputs;
		pxInt m_mouseMotionX{ 0 };
		pxInt m_mouseMotionY{ 0 };
		pxUInt16 m_mouseButton1{ 0 };
		pxUInt16 m_mouseButton2{ 0 };
		pxBool m_endEvent{ false };
		pxBool m_pause{ false };

		SDL_Window* m_window;
		pxInt M_WINDOW_CENTER_X;
		pxInt M_WINDOW_CENTER_Y;

	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//// ---- Methods -----																													////
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	private:
	//// ---- Internal methods ---- ////
		void _updateInput(SDL_Keycode key, pxUInt16 value);

	public:
	//// ---- Constructor/Destructor ---- ////
		CInputHandler(SDL_Window* window);

	//// ---- Getter ---- ////
		pxUInt getKey(EInput const& requiredInput) const { return m_inputs.at(requiredInput); }
		pxInt getMouseMotionX() const { return m_mouseMotionX; }
		pxInt getMouseMotionY() const { return m_mouseMotionY; }
		pxBool isQuit() const { return (m_endEvent || getKey(EInput::QUIT)); }

	//// ---- Core ---- ////
		void update();
	};
}