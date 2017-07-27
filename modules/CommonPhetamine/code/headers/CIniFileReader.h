////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////====================================================================================================================================////
/// | \file		CIniFileReader
///	| \author	Daniel Huc
/// | \date		July 2017
/// |----------------------------------------------------------------------------------------------------------------------------------
/// | \brief	.ini files parser
/// | \details	Create by passing ini_path or juste use with parse(ini_path) ans then check for (section,key) with isKeyFound()
/// |			then get the required typed value with a get(). Readable values are of types: [STRING, BOOL, INT or FLOAT]
////====================================================================================================================================////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#pragma once

/* Standard library includes */
#include <fstream>
#include <string>

/* External dependencies */

/* Internal headers includes */
#include "DBasicTypes.h"

/* Specific defines */

//// ---- Namespaces ---- ////
namespace CommonPhetamine {
	namespace IO {

		////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		////====================================================================================================================================////
		//// CIniFileReader
		/// \brief		Blabla
		/// \details	Blabla
		////====================================================================================================================================////
		////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		class CIniFileReader {

		////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		//// ---- Members -----																													//// 
		////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		private:
			///< This is the description
			pxMap<pxPair<pxString>, pxString>	m_stringEntriesMap;
			pxMap<pxPair<pxString>, pxBool>		m_boolEntriesMap;
			pxMap<pxPair<pxString>, pxInt>		m_intEntriesMap;
			pxMap<pxPair<pxString>, pxFloat>	m_floatEntriesMap;


		////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		//// ---- Methods -----																													////
		////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		private:
		//// ---- Internal methods ---- ////

		public:
		//// ---- Constructor/Destructor ---- ////
			CIniFileReader() { /***/ };
			CIniFileReader(pxString a_iniFilePath);

		//// ---- Operator ---- ////


		//// ---- Getter ---- ////
			pxString	getString	(pxString const& a_key)								const { return m_stringEntriesMap.at(pxPair<pxString>("",a_key)); }
			pxString	getString	(pxString const& a_section, pxString const& a_key)	const { return m_stringEntriesMap.at(pxPair<pxString>(a_section, a_key)); }
			pxBool		getBool		(pxString const& a_key)								const { return m_boolEntriesMap.at(pxPair<pxString>("", a_key)); }
			pxBool		getBool		(pxString const& a_section, pxString const& a_key)	const { return m_boolEntriesMap.at(pxPair<pxString>(a_section, a_key)); }
			pxInt		getInt		(pxString const& a_key)								const { return m_intEntriesMap.at(pxPair<pxString>("", a_key)); }
			pxInt		getInt		(pxString const& a_section, pxString const& a_key)	const { return m_intEntriesMap.at(pxPair<pxString>(a_section, a_key)); }
			pxFloat		getFloat	(pxString const& a_key)								const { return m_floatEntriesMap.at(pxPair<pxString>("", a_key)); }
			pxFloat		getFloat	(pxString const& a_section, pxString const& a_key)	const { return m_floatEntriesMap.at(pxPair<pxString>(a_section, a_key)); }


		//// ---- Setter ---- ////


		//// ---- Core ---- ////
			pxBool isStringValueFound(pxString const& a_key) const { return m_stringEntriesMap.find(pxPair<pxString>("", a_key)) == m_stringEntriesMap.end(); }
			pxBool isStringValueFound(pxString const& a_section, pxString const& a_key) const { return m_stringEntriesMap.find(pxPair<pxString>(a_section, a_key)) == m_stringEntriesMap.end(); }
			pxBool isBoolValueFound(pxString const& a_key) const { return m_boolEntriesMap.find(pxPair<pxString>("", a_key)) == m_boolEntriesMap.end(); }
			pxBool isBoolValueFound(pxString const& a_section, pxString const& a_key) const { return m_boolEntriesMap.find(pxPair<pxString>(a_section, a_key)) == m_boolEntriesMap.end(); }
			pxBool isIntValueFound(pxString const& a_key) const { return m_intEntriesMap.find(pxPair<pxString>("", a_key)) == m_intEntriesMap.end(); }
			pxBool isIntValueFound(pxString const& a_section, pxString const& a_key) const { return m_intEntriesMap.find(pxPair<pxString>(a_section, a_key)) == m_intEntriesMap.end(); }
			pxBool isFloatValueFound(pxString const& a_key) const { return m_floatEntriesMap.find(pxPair<pxString>("", a_key)) == m_floatEntriesMap.end(); }
			pxBool isFloatValueFound(pxString const& a_section, pxString const& a_key) const { return m_floatEntriesMap.find(pxPair<pxString>(a_section, a_key)) == m_floatEntriesMap.end(); }
			pxBool isValueFound(pxString const& a_key);
			pxBool isValueFound(pxString const& a_section, pxString const& a_key);
			void parse(pxString a_iniFilePath);


		//// ---- Static ---- ////

		};
	}
}
