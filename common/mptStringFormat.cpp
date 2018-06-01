/*
 * mptStringFormat.cpp
 * -------------------
 * Purpose: Convert other types to strings.
 * Notes  : Currently none.
 * Authors: OpenMPT Devs
 * The OpenMPT source code is released under the BSD license. Read LICENSE for more details.
 */

#include "stdafx.h"
#include "mptStringFormat.h"

#include <iomanip>
#include <locale>
#include <sstream>
#include <string>


OPENMPT_NAMESPACE_BEGIN



namespace mpt
{


template<typename Tstream, typename T> inline void SaneInsert(Tstream & s, const T & x) { s << x; }
// do the right thing for signed/unsigned char and bool
template<typename Tstream> inline void SaneInsert(Tstream & s, const bool & x) { s << static_cast<int>(x); }
template<typename Tstream> inline void SaneInsert(Tstream & s, const signed char & x) { s << static_cast<signed int>(x); }
template<typename Tstream> inline void SaneInsert(Tstream & s, const unsigned char & x) { s << static_cast<unsigned int>(x); }
 
template<typename T>
inline std::string ToStringHelper(const T & x)
{
	std::ostringstream o;
	o.imbue(std::locale::classic());
	SaneInsert(o, x);
	return o.str();
}

#if MPT_WSTRING_FORMAT
template<typename T>
inline std::wstring ToWStringHelper(const T & x)
{
	std::wostringstream o;
	o.imbue(std::locale::classic());
	SaneInsert(o, x);
	return o.str();
}
#endif

#if MPT_WSTRING_CONVERT
std::string ToString(const std::wstring & x) { return mpt::ToCharset(mpt::CharsetLocaleOrUTF8, x); }
std::string ToString(const wchar_t * const & x) { return mpt::ToCharset(mpt::CharsetLocaleOrUTF8, x); }
std::string ToString(const wchar_t & x) { return mpt::ToCharset(mpt::CharsetLocaleOrUTF8, std::wstring(1, x)); }
#endif
#if MPT_USTRING_MODE_UTF8
std::string ToString(const mpt::ustring & x) { return mpt::ToCharset(mpt::CharsetLocaleOrUTF8, x); }
#endif
#if defined(_MFC_VER)
std::string ToString(const CString & x) { return mpt::ToCharset(mpt::CharsetLocaleOrUTF8, x); }
#endif
std::string ToString(const bool & x) { return ToStringHelper(x); }
std::string ToString(const signed char & x) { return ToStringHelper(x); }
std::string ToString(const unsigned char & x) { return ToStringHelper(x); }
std::string ToString(const signed short & x) { return ToStringHelper(x); }
std::string ToString(const unsigned short & x) { return ToStringHelper(x); }
std::string ToString(const signed int & x) { return ToStringHelper(x); }
std::string ToString(const unsigned int & x) { return ToStringHelper(x); }
std::string ToString(const signed long & x) { return ToStringHelper(x); }
std::string ToString(const unsigned long & x) { return ToStringHelper(x); }
std::string ToString(const signed long long & x) { return ToStringHelper(x); }
std::string ToString(const unsigned long long & x) { return ToStringHelper(x); }
std::string ToString(const float & x) { return ToStringHelper(x); }
std::string ToString(const double & x) { return ToStringHelper(x); }
std::string ToString(const long double & x) { return ToStringHelper(x); }

mpt::ustring ToUString(const std::string & x) { return mpt::ToUnicode(mpt::CharsetLocaleOrUTF8, x); }
mpt::ustring ToUString(const char * const & x) { return mpt::ToUnicode(mpt::CharsetLocaleOrUTF8, x); }
mpt::ustring ToUString(const char & x) { return mpt::ToUnicode(mpt::CharsetLocaleOrUTF8, std::string(1, x)); }
#if MPT_WSTRING_FORMAT
#if MPT_USTRING_MODE_UTF8
mpt::ustring ToUString(const std::wstring & x) { return mpt::ToUnicode(x); }
#endif
mpt::ustring ToUString(const wchar_t * const & x) { return mpt::ToUnicode(x); }
mpt::ustring ToUString(const wchar_t & x) { return mpt::ToUnicode(std::wstring(1, x)); }
#endif
#if defined(_MFC_VER)
mpt::ustring ToUString(const CString & x)  { return mpt::ToUnicode(x); }
#endif
#if MPT_USTRING_MODE_WIDE
mpt::ustring ToUString(const bool & x) { return ToWStringHelper(x); }
mpt::ustring ToUString(const signed char & x) { return ToWStringHelper(x); }
mpt::ustring ToUString(const unsigned char & x) { return ToWStringHelper(x); }
mpt::ustring ToUString(const signed short & x) { return ToWStringHelper(x); }
mpt::ustring ToUString(const unsigned short & x) { return ToWStringHelper(x); }
mpt::ustring ToUString(const signed int & x) { return ToWStringHelper(x); }
mpt::ustring ToUString(const unsigned int & x) { return ToWStringHelper(x); }
mpt::ustring ToUString(const signed long & x) { return ToWStringHelper(x); }
mpt::ustring ToUString(const unsigned long & x) { return ToWStringHelper(x); }
mpt::ustring ToUString(const signed long long & x) { return ToWStringHelper(x); }
mpt::ustring ToUString(const unsigned long long & x) { return ToWStringHelper(x); }
mpt::ustring ToUString(const float & x) { return ToWStringHelper(x); }
mpt::ustring ToUString(const double & x) { return ToWStringHelper(x); }
mpt::ustring ToUString(const long double & x) { return ToWStringHelper(x); }
#endif
#if MPT_USTRING_MODE_UTF8
mpt::ustring ToUString(const bool & x) { return mpt::ToUnicode(mpt::CharsetUTF8, ToStringHelper(x)); }
mpt::ustring ToUString(const signed char & x) { return mpt::ToUnicode(mpt::CharsetUTF8, ToStringHelper(x)); }
mpt::ustring ToUString(const unsigned char & x) { return mpt::ToUnicode(mpt::CharsetUTF8, ToStringHelper(x)); }
mpt::ustring ToUString(const signed short & x) { return mpt::ToUnicode(mpt::CharsetUTF8, ToStringHelper(x)); }
mpt::ustring ToUString(const unsigned short & x) { return mpt::ToUnicode(mpt::CharsetUTF8, ToStringHelper(x)); }
mpt::ustring ToUString(const signed int & x) { return mpt::ToUnicode(mpt::CharsetUTF8, ToStringHelper(x)); }
mpt::ustring ToUString(const unsigned int & x) { return mpt::ToUnicode(mpt::CharsetUTF8, ToStringHelper(x)); }
mpt::ustring ToUString(const signed long & x) { return mpt::ToUnicode(mpt::CharsetUTF8, ToStringHelper(x)); }
mpt::ustring ToUString(const unsigned long & x) { return mpt::ToUnicode(mpt::CharsetUTF8, ToStringHelper(x)); }
mpt::ustring ToUString(const signed long long & x) { return mpt::ToUnicode(mpt::CharsetUTF8, ToStringHelper(x)); }
mpt::ustring ToUString(const unsigned long long & x) { return mpt::ToUnicode(mpt::CharsetUTF8, ToStringHelper(x)); }
mpt::ustring ToUString(const float & x) { return mpt::ToUnicode(mpt::CharsetUTF8, ToStringHelper(x)); }
mpt::ustring ToUString(const double & x) { return mpt::ToUnicode(mpt::CharsetUTF8, ToStringHelper(x)); }
mpt::ustring ToUString(const long double & x) { return mpt::ToUnicode(mpt::CharsetUTF8, ToStringHelper(x)); }
#endif

#if MPT_WSTRING_FORMAT
std::wstring ToWString(const std::string & x) { return mpt::ToWide(mpt::CharsetLocaleOrUTF8, x); }
std::wstring ToWString(const char * const & x) { return mpt::ToWide(mpt::CharsetLocaleOrUTF8, x); }
std::wstring ToWString(const char & x) { return mpt::ToWide(mpt::CharsetLocaleOrUTF8, std::string(1, x)); }
#if MPT_USTRING_MODE_UTF8
std::wstring ToWString(const mpt::ustring & x) { return mpt::ToWide(x); }
#endif
#if defined(_MFC_VER)
std::wstring ToWString(const CString & x) { return mpt::ToWide(x); }
#endif
std::wstring ToWString(const bool & x) { return ToWStringHelper(x); }
std::wstring ToWString(const signed char & x) { return ToWStringHelper(x); }
std::wstring ToWString(const unsigned char & x) { return ToWStringHelper(x); }
std::wstring ToWString(const signed short & x) { return ToWStringHelper(x); }
std::wstring ToWString(const unsigned short & x) { return ToWStringHelper(x); }
std::wstring ToWString(const signed int & x) { return ToWStringHelper(x); }
std::wstring ToWString(const unsigned int & x) { return ToWStringHelper(x); }
std::wstring ToWString(const signed long & x) { return ToWStringHelper(x); }
std::wstring ToWString(const unsigned long & x) { return ToWStringHelper(x); }
std::wstring ToWString(const signed long long & x) { return ToWStringHelper(x); }
std::wstring ToWString(const unsigned long long & x) { return ToWStringHelper(x); }
std::wstring ToWString(const float & x) { return ToWStringHelper(x); }
std::wstring ToWString(const double & x) { return ToWStringHelper(x); }
std::wstring ToWString(const long double & x) { return ToWStringHelper(x); }
#endif


template <typename Tchar>
struct NumPunct : std::numpunct<Tchar>
{
private:
	unsigned int group;
	char sep;
public:
	NumPunct(unsigned int g, char s)
		: group(g)
		, sep(s)
	{}
	std::string do_grouping() const override
	{
		return std::string(1, static_cast<char>(group));
	}
	Tchar do_thousands_sep() const override
	{
		return static_cast<Tchar>(sep);
	}
};

template<typename Tostream, typename T>
static inline void ApplyFormat(Tostream & o, const FormatSpec & format, const T &)
{
	if(format.GetGroup() > 0)
	{
		o.imbue(std::locale(o.getloc(), new NumPunct<typename Tostream::char_type>(format.GetGroup(), format.GetGroupSep())));
	}
	FormatFlags f = format.GetFlags();
	std::size_t width = format.GetWidth();
	int precision = format.GetPrecision();
	if(precision != -1 && width != 0 && !(f & fmt_base::NotaFix) && !(f & fmt_base::NotaSci))
	{
		// fixup:
		// precision behaves differently from .#
		// avoid default format when precision and width are set
		f &= ~fmt_base::NotaNrm;
		f |= fmt_base::NotaFix;
	}
	if(f & fmt_base::BaseDec) { o << std::dec; }
	else if(f & fmt_base::BaseHex) { o << std::hex; }
	if(f & fmt_base::NotaNrm ) { /*nothing*/ }
	else if(f & fmt_base::NotaFix ) { o << std::setiosflags(std::ios::fixed); }
	else if(f & fmt_base::NotaSci ) { o << std::setiosflags(std::ios::scientific); }
	if(f & fmt_base::CaseLow) { o << std::nouppercase; }
	else if(f & fmt_base::CaseUpp) { o << std::uppercase; }
	MPT_MAYBE_CONSTANT_IF(!std::numeric_limits<T>::is_integer)
	{
		if(f & fmt_base::FillOff) { /* nothing */ }
		else if(f & fmt_base::FillNul) { o << std::setw(width) << std::setfill(typename Tostream::char_type('0')); }
	}
	if(precision != -1) { o << std::setprecision(precision); }
}

template<typename Tstring, typename T>
static inline void PostProcessDigits(Tstring &str, const FormatSpec & format, const T &)
{
	FormatFlags f = format.GetFlags();
	std::size_t width = format.GetWidth();
	if(f & fmt_base::FillOff)
	{
		/* nothing */
	} else if(f & fmt_base::FillNul)
	{
		auto pos = str.begin();
		if(str.length() > 0)
		{
			if(str[0] == '+')
			{
				pos++;
				width++;
			} else if(str[0] == '-')
			{
				pos++;
				width++;
			}
		}
		if(str.length() < width)
		{
			str.insert(pos, width - str.length(), '0');
		}
	}
}

template<typename T>
static inline std::string FormatValHelperInt(const T & x, const FormatSpec & f)
{
	std::ostringstream o;
	o.imbue(std::locale::classic());
	ApplyFormat(o, f, x);
	SaneInsert(o, x);
	std::string result = o.str();
	PostProcessDigits(result, f, x);
	return result;
}
template<typename T>
static inline std::string FormatValHelperFloat(const T & x, const FormatSpec & f)
{
	std::ostringstream o;
	o.imbue(std::locale::classic());
	ApplyFormat(o, f, x);
	SaneInsert(o, x);
	return o.str();
}

#if MPT_WSTRING_FORMAT
template<typename T>
static inline std::wstring FormatValWHelperInt(const T & x, const FormatSpec & f)
{
	std::wostringstream o;
	o.imbue(std::locale::classic());
	ApplyFormat(o, f, x);
	SaneInsert(o, x);
	std::wstring result = o.str();
	PostProcessDigits(result, f, x);
	return result;
}
template<typename T>
static inline std::wstring FormatValWHelperFloat(const T & x, const FormatSpec & f)
{
	std::wostringstream o;
	o.imbue(std::locale::classic());
	ApplyFormat(o, f, x);
	SaneInsert(o, x);
	return o.str();
}
#endif


std::string FormatVal(const char & x, const FormatSpec & f) { return FormatValHelperInt(x, f); }
std::string FormatVal(const wchar_t & x, const FormatSpec & f) { return FormatValHelperInt(x, f); }
std::string FormatVal(const bool & x, const FormatSpec & f) { return FormatValHelperInt(x, f); }
std::string FormatVal(const signed char & x, const FormatSpec & f) { return FormatValHelperInt(x, f); }
std::string FormatVal(const unsigned char & x, const FormatSpec & f) { return FormatValHelperInt(x, f); }
std::string FormatVal(const signed short & x, const FormatSpec & f) { return FormatValHelperInt(x, f); }
std::string FormatVal(const unsigned short & x, const FormatSpec & f) { return FormatValHelperInt(x, f); }
std::string FormatVal(const signed int & x, const FormatSpec & f) { return FormatValHelperInt(x, f); }
std::string FormatVal(const unsigned int & x, const FormatSpec & f) { return FormatValHelperInt(x, f); }
std::string FormatVal(const signed long & x, const FormatSpec & f) { return FormatValHelperInt(x, f); }
std::string FormatVal(const unsigned long & x, const FormatSpec & f) { return FormatValHelperInt(x, f); }
std::string FormatVal(const signed long long & x, const FormatSpec & f) { return FormatValHelperInt(x, f); }
std::string FormatVal(const unsigned long long & x, const FormatSpec & f) { return FormatValHelperInt(x, f); }
std::string FormatVal(const float & x, const FormatSpec & f) { return FormatValHelperFloat(x, f); }
std::string FormatVal(const double & x, const FormatSpec & f) { return FormatValHelperFloat(x, f); }
std::string FormatVal(const long double & x, const FormatSpec & f) { return FormatValHelperFloat(x, f); }

#if MPT_USTRING_MODE_WIDE
mpt::ustring FormatValU(const char & x, const FormatSpec & f) { return FormatValWHelperInt(x, f); }
mpt::ustring FormatValU(const wchar_t & x, const FormatSpec & f) { return FormatValWHelperInt(x, f); }
mpt::ustring FormatValU(const bool & x, const FormatSpec & f) { return FormatValWHelperInt(x, f); }
mpt::ustring FormatValU(const signed char & x, const FormatSpec & f) { return FormatValWHelperInt(x, f); }
mpt::ustring FormatValU(const unsigned char & x, const FormatSpec & f) { return FormatValWHelperInt(x, f); }
mpt::ustring FormatValU(const signed short & x, const FormatSpec & f) { return FormatValWHelperInt(x, f); }
mpt::ustring FormatValU(const unsigned short & x, const FormatSpec & f) { return FormatValWHelperInt(x, f); }
mpt::ustring FormatValU(const signed int & x, const FormatSpec & f) { return FormatValWHelperInt(x, f); }
mpt::ustring FormatValU(const unsigned int & x, const FormatSpec & f) { return FormatValWHelperInt(x, f); }
mpt::ustring FormatValU(const signed long & x, const FormatSpec & f) { return FormatValWHelperInt(x, f); }
mpt::ustring FormatValU(const unsigned long & x, const FormatSpec & f) { return FormatValWHelperInt(x, f); }
mpt::ustring FormatValU(const signed long long & x, const FormatSpec & f) { return FormatValWHelperInt(x, f); }
mpt::ustring FormatValU(const unsigned long long & x, const FormatSpec & f) { return FormatValWHelperInt(x, f); }
mpt::ustring FormatValU(const float & x, const FormatSpec & f) { return FormatValWHelperFloat(x, f); }
mpt::ustring FormatValU(const double & x, const FormatSpec & f) { return FormatValWHelperFloat(x, f); }
mpt::ustring FormatValU(const long double & x, const FormatSpec & f) { return FormatValWHelperFloat(x, f); }
#endif
#if MPT_USTRING_MODE_UTF8
mpt::ustring FormatValU(const char & x, const FormatSpec & f) { return mpt::ToUnicode(mpt::CharsetUTF8, FormatValHelperInt(x, f)); }
mpt::ustring FormatValU(const wchar_t & x, const FormatSpec & f) { return mpt::ToUnicode(mpt::CharsetUTF8, FormatValHelperInt(x, f)); }
mpt::ustring FormatValU(const bool & x, const FormatSpec & f) { return mpt::ToUnicode(mpt::CharsetUTF8, FormatValHelperInt(x, f)); }
mpt::ustring FormatValU(const signed char & x, const FormatSpec & f) { return mpt::ToUnicode(mpt::CharsetUTF8, FormatValHelperInt(x, f)); }
mpt::ustring FormatValU(const unsigned char & x, const FormatSpec & f) { return mpt::ToUnicode(mpt::CharsetUTF8, FormatValHelperInt(x, f)); }
mpt::ustring FormatValU(const signed short & x, const FormatSpec & f) { return mpt::ToUnicode(mpt::CharsetUTF8, FormatValHelperInt(x, f)); }
mpt::ustring FormatValU(const unsigned short & x, const FormatSpec & f) { return mpt::ToUnicode(mpt::CharsetUTF8, FormatValHelperInt(x, f)); }
mpt::ustring FormatValU(const signed int & x, const FormatSpec & f) { return mpt::ToUnicode(mpt::CharsetUTF8, FormatValHelperInt(x, f)); }
mpt::ustring FormatValU(const unsigned int & x, const FormatSpec & f) { return mpt::ToUnicode(mpt::CharsetUTF8, FormatValHelperInt(x, f)); }
mpt::ustring FormatValU(const signed long & x, const FormatSpec & f) { return mpt::ToUnicode(mpt::CharsetUTF8, FormatValHelperInt(x, f)); }
mpt::ustring FormatValU(const unsigned long & x, const FormatSpec & f) { return mpt::ToUnicode(mpt::CharsetUTF8, FormatValHelperInt(x, f)); }
mpt::ustring FormatValU(const signed long long & x, const FormatSpec & f) { return mpt::ToUnicode(mpt::CharsetUTF8, FormatValHelperInt(x, f)); }
mpt::ustring FormatValU(const unsigned long long & x, const FormatSpec & f) { return mpt::ToUnicode(mpt::CharsetUTF8, FormatValHelperInt(x, f)); }
mpt::ustring FormatValU(const float & x, const FormatSpec & f) { return mpt::ToUnicode(mpt::CharsetUTF8, FormatValHelperFloat(x, f)); }
mpt::ustring FormatValU(const double & x, const FormatSpec & f) { return mpt::ToUnicode(mpt::CharsetUTF8, FormatValHelperFloat(x, f)); }
mpt::ustring FormatValU(const long double & x, const FormatSpec & f) { return mpt::ToUnicode(mpt::CharsetUTF8, FormatValHelperFloat(x, f)); }
#endif

#if MPT_WSTRING_FORMAT
std::wstring FormatValW(const char & x, const FormatSpec & f) { return FormatValWHelperInt(x, f); }
std::wstring FormatValW(const wchar_t & x, const FormatSpec & f) { return FormatValWHelperInt(x, f); }
std::wstring FormatValW(const bool & x, const FormatSpec & f) { return FormatValWHelperInt(x, f); }
std::wstring FormatValW(const signed char & x, const FormatSpec & f) { return FormatValWHelperInt(x, f); }
std::wstring FormatValW(const unsigned char & x, const FormatSpec & f) { return FormatValWHelperInt(x, f); }
std::wstring FormatValW(const signed short & x, const FormatSpec & f) { return FormatValWHelperInt(x, f); }
std::wstring FormatValW(const unsigned short & x, const FormatSpec & f) { return FormatValWHelperInt(x, f); }
std::wstring FormatValW(const signed int & x, const FormatSpec & f) { return FormatValWHelperInt(x, f); }
std::wstring FormatValW(const unsigned int & x, const FormatSpec & f) { return FormatValWHelperInt(x, f); }
std::wstring FormatValW(const signed long & x, const FormatSpec & f) { return FormatValWHelperInt(x, f); }
std::wstring FormatValW(const unsigned long & x, const FormatSpec & f) { return FormatValWHelperInt(x, f); }
std::wstring FormatValW(const signed long long & x, const FormatSpec & f) { return FormatValWHelperInt(x, f); }
std::wstring FormatValW(const unsigned long long & x, const FormatSpec & f) { return FormatValWHelperInt(x, f); }
std::wstring FormatValW(const float & x, const FormatSpec & f) { return FormatValWHelperFloat(x, f); }
std::wstring FormatValW(const double & x, const FormatSpec & f) { return FormatValWHelperFloat(x, f); }
std::wstring FormatValW(const long double & x, const FormatSpec & f) { return FormatValWHelperFloat(x, f); }
#endif


namespace String
{


namespace detail
{

template<typename Tstring>
Tstring PrintImplTemplate(const Tstring & format
	, const Tstring & x1
	, const Tstring & x2
	, const Tstring & x3
	, const Tstring & x4
	, const Tstring & x5
	, const Tstring & x6
	, const Tstring & x7
	, const Tstring & x8
	)
{
	typedef typename mpt::string_traits<Tstring> traits;
	Tstring result;
	const std::size_t len = traits::length(format);
	traits::reserve(result, len);
	for(std::size_t pos = 0; pos != len; ++pos)
	{
		typename traits::char_type c = format[pos];
		if(pos + 1 != len && c == typename traits::char_type('%'))
		{
			pos++;
			c = format[pos];
			if(typename traits::char_type('1') <= c && c <= typename traits::char_type('9'))
			{
				const std::size_t n = c - typename traits::char_type('0');
				switch(n)
				{
					case 1: traits::append(result, x1); break;
					case 2: traits::append(result, x2); break;
					case 3: traits::append(result, x3); break;
					case 4: traits::append(result, x4); break;
					case 5: traits::append(result, x5); break;
					case 6: traits::append(result, x6); break;
					case 7: traits::append(result, x7); break;
					case 8: traits::append(result, x8); break;
				}
				continue;
			} else if(c != typename traits::char_type('%'))
			{
				traits::append(result, 1, typename traits::char_type('%'));
			}
		}
		traits::append(result, 1, c);
	}
	return result;
}

std::string PrintImpl(const std::string & format
	, const std::string & x1
	, const std::string & x2
	, const std::string & x3
	, const std::string & x4
	, const std::string & x5
	, const std::string & x6
	, const std::string & x7
	, const std::string & x8
	)
{
	return PrintImplTemplate<std::string>(format, x1,x2,x3,x4,x5,x6,x7,x8);
}

#if MPT_WSTRING_FORMAT
std::wstring PrintImpl(const std::wstring & format
	, const std::wstring & x1
	, const std::wstring & x2
	, const std::wstring & x3
	, const std::wstring & x4
	, const std::wstring & x5
	, const std::wstring & x6
	, const std::wstring & x7
	, const std::wstring & x8
	)
{
	return PrintImplTemplate<std::wstring>(format, x1,x2,x3,x4,x5,x6,x7,x8);
}
#endif

#if MPT_USTRING_MODE_UTF8
mpt::ustring PrintImpl(const mpt::ustring & format
	, const mpt::ustring & x1
	, const mpt::ustring & x2
	, const mpt::ustring & x3
	, const mpt::ustring & x4
	, const mpt::ustring & x5
	, const mpt::ustring & x6
	, const mpt::ustring & x7
	, const mpt::ustring & x8
	)
{
	return PrintImplTemplate<mpt::ustring>(format, x1,x2,x3,x4,x5,x6,x7,x8);
}
#endif

#if defined(MPT_ENABLE_CHARSET_LOCALE)
mpt::lstring PrintImpl(const mpt::lstring & format
	, const mpt::lstring & x1
	, const mpt::lstring & x2
	, const mpt::lstring & x3
	, const mpt::lstring & x4
	, const mpt::lstring & x5
	, const mpt::lstring & x6
	, const mpt::lstring & x7
	, const mpt::lstring & x8
	)
{
	return PrintImplTemplate<mpt::lstring>(format, x1,x2,x3,x4,x5,x6,x7,x8);
}
#endif // MPT_ENABLE_CHARSET_LOCALE

#if defined(_MFC_VER)
CString PrintImpl(const CString & format
	, const CString & x1
	, const CString & x2
	, const CString & x3
	, const CString & x4
	, const CString & x5
	, const CString & x6
	, const CString & x7
	, const CString & x8
	)
{
	return PrintImplTemplate<CString>(format, x1,x2,x3,x4,x5,x6,x7,x8);
}
#endif

} // namespace detail


} // namespace String


} // namespace mpt


OPENMPT_NAMESPACE_END
