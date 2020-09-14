#include "Translate.h"

/**
   @brief Constructor clase Translate
   @param string  spanish_word
   @param string english_word
   @returns void
*/
Translate::Translate(string _spanish_word, string _english_word)
{
	_spanish = _spanish_word;
	_english = _english_word;
}
/**
   @brief Constructor por defecto clase Translate
   @param void
   @returns void
*/
Translate::Translate()
{
	_spanish = "";
	_english = "";
}

/**
   @brief Funcion para setear la palabra en español
   @param string word
   @returns void
*/
void Translate::set_spanish(string _word)
{
	_spanish = _word;
}
/**
   @brief Funcion para setear la palabra en ingles
   @param string word
   @returns void
*/
void Translate::set_english(string _word)
{
	_english = _word;
}
/**
   @brief Funcion para mostrar el objeto Translate
   @param void
   @returns string
*/
string Translate::_to_string_T()
{
	return this->_spanish + "," + this->_english;
}
/**
   @brief Funcion para obtener la palabra en español
   @param void
   @returns string
*/
string Translate::get_spanish()
{
	return _spanish;
}
/**
   @brief Funcion para obtener la palabra en ingles
   @param void
   @returns string
*/
string Translate::get_english()
{
	return _english;
}

/**
   @brief Funcion para lectura de voz 
   @param int _flag
   @returns void
*/
void Translate::hablar(int _flag)
{
	ISpVoice* pVoice = NULL;

	if (FAILED(::CoInitialize(NULL)))
		return;

	HRESULT hr = CoCreateInstance(CLSID_SpVoice, NULL, CLSCTX_ALL, IID_ISpVoice, (void**)&pVoice);
	if (SUCCEEDED(hr))
	{
		if (_flag == 1) {
			wstring wide_string = wstring(_spanish.begin(), _spanish.end());
			const wchar_t* result = wide_string.c_str();
			hr = pVoice->Speak(result, 0, NULL);

			wide_string = wstring(_english.begin(), _english.end());
			result = wide_string.c_str();
			// Change pitch
			hr = pVoice->Speak(result, SPF_IS_XML, NULL);
			pVoice->Release();
			pVoice = NULL;
		}
		else {
			wstring wide_string = wstring(_english.begin(), _english.end());
			const wchar_t* result = wide_string.c_str();
			hr = pVoice->Speak(result, 0, NULL);

			wide_string = wstring(_spanish.begin(), _spanish.end());
			result = wide_string.c_str();
			// Change pitch
			hr = pVoice->Speak(result, SPF_IS_XML, NULL);
			pVoice->Release();
			pVoice = NULL;
		}
		
	}
	::CoUninitialize();
	return;
}
/**
   @brief Sobrecargar operador menor que <
   @param void
   @returns bool
*/
bool Translate::operator < (const Translate& p) const
{
	return strcmp(this->_spanish.c_str(), p._spanish.c_str()) < 0;
}
/**
   @brief Sobrecargar operador diferente de
   @param void
   @returns bool
*/
bool Translate::operator != (const Translate& p) const
{
	if (this->_english._Equal("")) {
		return strcmp(this->_spanish.c_str(), p._spanish.c_str()) != 0;
	}
	else {
		return strcmp(this->_english.c_str(), p._english.c_str()) != 0;
	}
}
/**
   @brief Sobrecargar operador igual igual ==
   @param void
   @returns bool
*/
bool Translate::operator==(const Translate& p) const
{
	return strcmp(this->_spanish.c_str(), p._spanish.c_str()) == 0 && strcmp(this->_english.c_str(), p._english.c_str()) == 0;
}
/**
   @brief Sobrecargar dezplazamiento izquierda <<
   @param void
   @returns bool
*/
ostream& operator<<(ostream& o, const Translate& p)
{
	o << p._spanish << ", " << p._english;
	return o;
}
