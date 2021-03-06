﻿////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////====================================================================================================================================////
/// | \file		CTimer
///	| \author	Daniel Huc
/// | \date		July 2017
/// |----------------------------------------------------------------------------------------------------------------------------------
/// | \brief	TODO
/// | \details	TODO
////====================================================================================================================================////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#pragma once

/* Standard library includes */
#include <chrono>

/* External dependencies */

/* Internal headers includes */
#include "DBasicTypes.h"
#include "DExportDLL.h"

/* Specific defines */

//// ---- Namespaces ---- ////
namespace CommonPhetamine {
	
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	////====================================================================================================================================////
	//// CTimer
	/// \brief		TODO
	/// \details	TODO
	////====================================================================================================================================////
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	class API_DLL CTimer {
	
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//// ---- Members -----																													//// 
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	private:

		std::chrono::time_point<std::chrono::steady_clock> m_startTicks; ///< Initial time
		std::chrono::duration<double> m_elapsedTicks; ///< Cumuled ticks between starts and pauses

		pxBool m_isPaused{ false }; ///< Status in pause

		pxBool m_isHightPerformanceClockIsSteady{ false };	///< Depending on the platform, use highest precision clock if it is consistent or basic consistent clock

		
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//// ---- Methods -----																													////
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	private:
	//// ---- Internal methods ---- ////
		//----------------------------------------------------------------------------------------------------------------------------------------//
		/// Updates the elapsed ticks: adds to the elapsed ticksthe duration between now and previous ticks using the consistent clock. 
		/// And updates the start tick value.
		//----------------------------------------------------------------------------------------------------------------------------------------//
		void _updateElapsedTicks();
		//----------------------------------------------------------------------------------------------------------------------------------------//
		/// Sets start ticks to current tick value using the consistent clock.
		//----------------------------------------------------------------------------------------------------------------------------------------//
		void _updateStartTicks();

	public:
	//// ---- Constructor/Destructor ---- ////
		CTimer() : m_isHightPerformanceClockIsSteady(std::chrono::high_resolution_clock::is_steady) { reset(); }
	
	//// ---- Getter ---- ////
		//----------------------------------------------------------------------------------------------------------------------------------------//
		/// Returns the elapsed time in microseconds since last Timer() OR Timer.reset().
		/// Takes into account Timer.pause() and Timer.resume() -> elapsed time ;)
		/// If the timer is in pause: returns the elapsed time since it was paused!
		//----------------------------------------------------------------------------------------------------------------------------------------//
		pxUInt64 getElapsedMicroseconds();
		//----------------------------------------------------------------------------------------------------------------------------------------//
		/// Returns the elapsed time in nanoseconds since last Timer() OR Timer.reset().
		/// Takes into account Timer.pause() and Timer.resume() -> elapsed time ;)
		/// If the timer is in pause: returns the elapsed time since it was paused!
		//----------------------------------------------------------------------------------------------------------------------------------------//
		pxUInt64 getElapsedNanoseconds();
		//----------------------------------------------------------------------------------------------------------------------------------------//
		/// Returns the elapsed time in milliseconds since last Timer() OR Timer.reset().
		/// Takes into account Timer.pause() and Timer.resume() -> elapsed time ;)
		/// If the timer is in pause: returns the elapsed time since it was paused!
		//----------------------------------------------------------------------------------------------------------------------------------------//
		pxUInt64 getElapsedMiliseconds();
		//----------------------------------------------------------------------------------------------------------------------------------------//
		/// Returns the elapsed time in seconds since last Timer() OR Timer.reset().
		/// Takes into account Timer.pause() and Timer.resume() -> elapsed time ;)
		/// If the timer is in pause: returns the elapsed time since it was paused!
		//----------------------------------------------------------------------------------------------------------------------------------------//
		pxUInt64 getElapsedSeconds();
		//----------------------------------------------------------------------------------------------------------------------------------------//
		/// Returns the elapsed time in minutes since last Timer() OR Timer.reset().
		/// Takes into account Timer.pause() and Timer.resume() -> elapsed time ;)
		/// If the timer is in pause: returns the elapsed time since it was paused!
		//----------------------------------------------------------------------------------------------------------------------------------------//
		pxUInt64 getElapsedMinutes();
		//----------------------------------------------------------------------------------------------------------------------------------------//
		/// Returns the elapsed time in hours since last Timer() OR Timer.reset().
		/// Takes into account Timer.pause() and Timer.resume() -> elapsed time ;)
		/// If the timer is in pause: returns the elapsed time since it was paused!
		//----------------------------------------------------------------------------------------------------------------------------------------//
		pxUInt64 getElapsedHours();

		pxBool isPaused() const { return m_isPaused; }

	//// ---- Core ---- ////
		//----------------------------------------------------------------------------------------------------------------------------------------//
		/// Resets the timer (elapsed time -> near 0) and starts it if it was paused!
		//----------------------------------------------------------------------------------------------------------------------------------------//
		void reset();
		//----------------------------------------------------------------------------------------------------------------------------------------//
		/// Resume the timer if it was paused!
		//----------------------------------------------------------------------------------------------------------------------------------------//
		void resume();
		//----------------------------------------------------------------------------------------------------------------------------------------//
		/// Pauses the timer. This means that the elapsed time will not be updated: to unpause call Timer.resume() or Timer.reset()
		//----------------------------------------------------------------------------------------------------------------------------------------//
		void pause();
	};
}
