#include "Translate.h"

Translate::Translate(string _spanish_word, string _english_word)
{
	_spanish = _spanish_word;
	_english = _english_word;
}

Translate::Translate()
{
	_spanish = "";
	_english = "";
}

void Translate::set_flag(int _f) {
	_flag = _f;
}

void Translate::set_spanish(string _word)
{
	_spanish = _word;
}

void Translate::set_english(string _word)
{
	_english = _word;
}

string Translate::get_spanish()
{
	return _spanish;
}

string Translate::get_english()
{
	return _english;
}

int Translate::get_flag() {
	return _flag;
}

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

bool Translate::operator < (const Translate& p) const
{
	return strcmp(this->_spanish.c_str(), p._spanish.c_str()) < 0;
}

bool Translate::operator != (const Translate& p) const
{
	if (this->_english._Equal("")) {
		return strcmp(this->_spanish.c_str(), p._spanish.c_str()) != 0;
	}
	else {
		return strcmp(this->_english.c_str(), p._english.c_str()) != 0;
	}
}

bool Translate::operator==(const Translate& p) const
{
	return strcmp(this->_spanish.c_str(), p._spanish.c_str()) == 0 || strcmp(this->_english.c_str(), p._english.c_str()) == 0;
}

ostream& operator<<(ostream& o, const Translate& p)
{
	o << p._spanish << ", " << p._english;
	return o;
}
