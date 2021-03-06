﻿#include "CInputHandler.h"

namespace PadPhetamine {

	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	////  ================================================================================================================================  ////
	////    ---- Internal methods -----                                                                                                     ////
	////  ================================================================================================================================  ////
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	//----------------------------------------------------------------------------------------------------------------------------------------//
	/// 
	//----------------------------------------------------------------------------------------------------------------------------------------//
	void CInputHandler::_updateInput(SDL_Keycode a_key, pxUInt16 a_value) {
		EInput input = static_cast<EInput>(a_key);
		if (m_inputs.find(input) != m_inputs.end()) {
			m_inputs.at(input) = a_value;
		}
	}

	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	////  ================================================================================================================================  ////
	////    ---- Constructor/Destructor -----                                                                                               ////
	////  ================================================================================================================================  ////
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	
	//----------------------------------------------------------------------------------------------------------------------------------------//
	/// 
	//----------------------------------------------------------------------------------------------------------------------------------------//
	CInputHandler::CInputHandler(SDL_Window* window) {
		m_window = window;
		SDL_GetWindowSize(window, &M_WINDOW_CENTER_X, &M_WINDOW_CENTER_Y);
		M_WINDOW_CENTER_X = M_WINDOW_CENTER_X / 2;
		M_WINDOW_CENTER_Y = M_WINDOW_CENTER_Y / 2;
		SDL_WarpMouseInWindow(m_window, M_WINDOW_CENTER_X, M_WINDOW_CENTER_Y);

		// Input initialisation
		const pxVec<EInput> mappedInputs{
			EInput::UP,
			EInput::DOWN,
			EInput::RIGHT,
			EInput::LEFT,
			EInput::SHOULDER_RIGHT,
			EInput::SHOULDER_LEFT,
			EInput::QUIT
		};
		for (auto const& it_input : mappedInputs) {
			m_inputs[it_input] = 0;
		}
	}

	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	////  ================================================================================================================================  ////
	////    ---- Core -----                                                                                                                 ////
	////  ================================================================================================================================  ////
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	//----------------------------------------------------------------------------------------------------------------------------------------//
	/// 
	//----------------------------------------------------------------------------------------------------------------------------------------//
	void CInputHandler::update() {
		// Incrementing the input duration of pressed keys and mouse_buttons
		for (auto it_input : m_inputs) {
			it_input.second++;
		}
		if (m_mouseButton1)
			m_mouseButton1++;
		if (m_mouseButton2)
			m_mouseButton2++;

		// Process events from the SDL event's qeue
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) {
				m_endEvent = true;
			}
			if (event.type == SDL_KEYDOWN) {
				_updateInput(event.key.keysym.sym, 1);
			}
			if (event.type == SDL_KEYUP) {
				_updateInput(event.key.keysym.sym, 0);
			}
			if (event.type == SDL_MOUSEMOTION) {
				m_mouseMotionX = event.motion.x - M_WINDOW_CENTER_X;
				m_mouseMotionY = event.motion.y - M_WINDOW_CENTER_Y;
			}
			if (event.type == SDL_MOUSEBUTTONDOWN) {
				if (event.button.button == SDL_BUTTON_LEFT) { m_mouseButton1 = 1; }
				if (event.button.button == SDL_BUTTON_RIGHT) { m_mouseButton2 = 1; }
			}
			if (event.type == SDL_MOUSEBUTTONUP) {
				if (event.button.button == SDL_BUTTON_LEFT) { m_mouseButton1 = 0; }
				if (event.button.button == SDL_BUTTON_RIGHT) { m_mouseButton2 = 0; }
			}
			if (event.type == SDL_WINDOWEVENT) {
				if (event.window.event == SDL_WINDOWEVENT_FOCUS_LOST)
					m_pause = true;
				if (event.window.event == SDL_WINDOWEVENT_FOCUS_GAINED)
					m_pause = false;
			}
		}

		// Block the mouse at the center of the window!
		if (m_pause == false) {
			SDL_WarpMouseInWindow(m_window, M_WINDOW_CENTER_X, M_WINDOW_CENTER_Y);
		}
	}
}




//#include "CInputHandler.h"
//
//CInputHandler::CInputHandler(SDL_Window* window) {
//	m_window = window;
//	SDL_GetWindowSize(window, &WINDOW_CENTER_X, &WINDOW_CENTER_Y);
//	WINDOW_CENTER_X = WINDOW_CENTER_X / 2;
//	WINDOW_CENTER_Y = WINDOW_CENTER_Y / 2;
//	m_mouseMotionX = 0;
//	m_mouseMotionY = 0;
//	SDL_WarpMouseInWindow(m_window, WINDOW_CENTER_X, WINDOW_CENTER_Y);
//}
//
//void CInputHandler::update() {
//	this->incInputTime(); // On incrémente la durée de l'appui sur les boutons enclenchés
//	while (SDL_PollEvent(&event)) {
//		if (event.type == SDL_QUIT) {
//			m_endEvent = 1;
//		}
//		if (event.type == SDL_KEYDOWN) {
//			keyPressed(&event.key);
//		}
//		if (event.type == SDL_KEYUP) {
//			keyReleased(&event.key);
//		}
//		if (event.type == SDL_MOUSEMOTION) {
//			mouseMoved(&event.motion);
//		}
//		if (event.type == SDL_MOUSEBUTTONDOWN) {
//			mousePressed(&event.button);
//		}
//		if (event.type == SDL_MOUSEBUTTONUP) {
//			mouseReleased(&event.button);
//		}
//		if (event.type == SDL_WINDOWEVENT) {
//			if (event.window.event == SDL_WINDOWEVENT_FOCUS_LOST) {
//				m_pause++;
//			}
//			if (event.window.event == SDL_WINDOWEVENT_FOCUS_GAINED) {
//				m_pause = 0;
//			}
//		}
//	}
//
//	if (m_pause == 0) {
//		SDL_WarpMouseInWindow(m_window, WINDOW_CENTER_X, WINDOW_CENTER_Y);
//	}
//}
//
//void CInputHandler::incInputTime() {
//	if (m_moveForward) { m_moveForward++; }
//	if (m_moveBackward) { m_moveBackward++; }
//	if (m_moveLeft) { m_moveLeft++; }
//	if (m_moveRight) { m_moveRight++; }
//	if (m_moveUp) { m_moveUp++; }
//	if (m_moveDown) { m_moveDown++; }
//	if (m_shoot) { m_shoot++; }
//	if (m_endEvent) { m_endEvent++; }
//}
//
//
//void CInputHandler::keyPressed(SDL_KeyboardEvent* key) {
//	switch (key->keysym.sym) {
//		case SDLK_z:
//			if (m_moveForward == 0) { m_moveForward++; }
//			break;
//		case SDLK_s:
//			if (m_moveBackward == 0) { m_moveBackward++; }
//			break;
//		case SDLK_q:
//			if (m_moveLeft == 0) { m_moveLeft++; }
//			break;
//		case SDLK_d:
//			if (m_moveRight == 0) { m_moveRight++; }
//			break;
//		case SDLK_e:
//			if (m_moveUp == 0) { m_moveUp++; }
//			break;
//		case SDLK_a:
//			if (m_moveDown == 0) { m_moveDown++; }
//			break;
//		case SDLK_ESCAPE:
//			if (m_endEvent == 0) { m_endEvent++; }
//			break;
//	}
//}
//
//
//void CInputHandler::keyReleased(SDL_KeyboardEvent* key) {
//	switch (key->keysym.sym) {
//	case SDLK_z:
//		m_moveForward = 0;
//		break;
//	case SDLK_s:
//		m_moveBackward = 0;
//		break;
//	case SDLK_q:
//		m_moveLeft = 0;
//		break;
//	case SDLK_d:
//		m_moveRight = 0;
//		break;
//	case SDLK_e:
//		m_moveUp = 0;
//		break;
//	case SDLK_a:
//		m_moveDown = 0;
//		break;
//	}
//}
//
//
//void CInputHandler::mouseMoved(SDL_MouseMotionEvent* mouse) {
//	m_mouseMotionX = mouse->x - WINDOW_CENTER_X;
//	m_mouseMotionY = mouse->y - WINDOW_CENTER_Y;
//}
//
//
//void CInputHandler::mousePressed(SDL_MouseButtonEvent* mouse) {
//	if (mouse->button == SDL_BUTTON_LEFT)	{ m_shoot = 1; }
//	if (mouse->button == SDL_BUTTON_RIGHT)	{ m_bulletTime = 1; }
//}
//
//
//void CInputHandler::mouseReleased(SDL_MouseButtonEvent* mouse) {
//	if (mouse->button == SDL_BUTTON_LEFT)	{ m_shoot = 0; }
//	if (mouse->button == SDL_BUTTON_RIGHT)	{ m_bulletTime = 0; }
//}