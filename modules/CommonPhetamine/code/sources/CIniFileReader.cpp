#include "CIniFileReader.h"

namespace CommonPhetamine {
	namespace IO {

		////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		////  ================================================================================================================================  ////
		////    ---- Constructor/Destructor -----                                                                                               ////
		////  ================================================================================================================================  ////
		////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

		//----------------------------------------------------------------------------------------------------------------------------------------//
		///
		//----------------------------------------------------------------------------------------------------------------------------------------//
		CIniFileReader::CIniFileReader(pxString a_iniFilePath) {
			parse(a_iniFilePath);
		}

		////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		////  ================================================================================================================================  ////
		////    ---- Core -----                                                                                                                 ////
		////  ================================================================================================================================  ////
		////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

		//----------------------------------------------------------------------------------------------------------------------------------------//
		///
		//----------------------------------------------------------------------------------------------------------------------------------------//
		pxBool CIniFileReader::isValueFound(pxString const& a_key) {
			return isStringValueFound(a_key);
		}

		//----------------------------------------------------------------------------------------------------------------------------------------//
		///
		//----------------------------------------------------------------------------------------------------------------------------------------//
		pxBool CIniFileReader::isValueFound(pxString const& a_section, pxString const& a_key) {
			return isStringValueFound(a_section, a_key);
		}

		//----------------------------------------------------------------------------------------------------------------------------------------//
		///
		//----------------------------------------------------------------------------------------------------------------------------------------//
		void CIniFileReader::parse(pxString a_iniFilePath) {
			//STACK_TRACE;
			// Return a string containing the source code of the input file
			std::ifstream iniFile(a_iniFilePath, std::ios::in);

			if (!iniFile.is_open()) {
				//STACK_TRACE;
				//ERROR("File " + std::string(a_iniFilePath) + " not found!");
			}

			pxString currentSection = "";
			pxString line = "";
			pxUInt16 separator = 0;
			pxString key = "";
			pxString value = "";

			while (getline(iniFile, line)) {
				// Reading section
				if (line[0] == '[') {
					currentSection = line.substr(1, line.length() - 2);
				}
				else {
					separator = line.find('=');
					if (separator != std::string::npos) {
						key = line.substr(0, separator);
						value = line.substr(separator + 1, line.length() - 1 - separator);

						if (is_lexically_castable<pxInt>(value)) { // If castable into int
							m_intEntriesMap[pxPair<pxString,pxString>(currentSection, key)] = lexical_cast<pxInt>(value); // Add as int
							if (value == "0") // If in boolean it means something ... eg only 0 or 1!!!
								m_boolEntriesMap[pxPair<pxString,pxString>(currentSection, key)] = false; // Add as False
							else if (value == "1")
								m_boolEntriesMap[pxPair<pxString,pxString>(currentSection, key)] = true; // Add as False
						}
							
						if (is_lexically_castable<pxFloat>(value)) // If castable as float
							m_floatEntriesMap[pxPair<pxString,pxString>(currentSection, key)] = lexical_cast<pxFloat>(value); // Add as float
						
						if (value == "yes")
							m_boolEntriesMap[pxPair<pxString,pxString>(currentSection, key)] = true;
						if (value == "no")
							m_boolEntriesMap[pxPair<pxString,pxString>(currentSection, key)] = false;

						// Whatever, add as string!
						m_stringEntriesMap[pxPair<pxString,pxString>(currentSection, key)] = value;
					}
				}
			}
			iniFile.close();

			//UNSTACK_TRACE;
		}
	}
}