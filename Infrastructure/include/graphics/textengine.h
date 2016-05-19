
#pragma once

#include <memory>
#include <string>
#include <EASTL/string.h>
#include <EASTL/fixed_vector.h>
#include "math.h"

struct ID3D11Device;

namespace gfx {

	enum class TextAlign : uint8_t {
		Left,
		Center,
		Right,
		Justified
	};

	struct Brush {
		bool gradient = false;
		XMCOLOR primaryColor = { 1,1,1,1 };
		XMCOLOR secondaryColor = { 1,1,1,1 };
	};

	struct TextStyle {
		eastl::string fontFace;
		float pointSize = 12;
		bool bold = false;
		bool italic = false;
		TextAlign align = TextAlign::Left;
		Brush foreground;
		bool uniformLineHeight = false;
		float lineHeight;
		float baseLine;
		bool dropShadow = false;
		Brush dropShadowBrush;
		bool trim = false;
		float tabStopWidth = 0;
	};

	struct TextMetrics {
		uint32_t width = 0;
		uint32_t height = 0;
		uint32_t lineHeight = 0;
		uint32_t lines = 0;
	};

	struct ConstrainedTextStyle {
		TextStyle style;
		uint32_t startChar = 0;
		uint32_t length = 0;

		ConstrainedTextStyle() {}

		ConstrainedTextStyle(const TextStyle &o) : style(o) {}
	};

	struct FormattedText {
		std::wstring text;
		TextStyle defaultStyle;
		eastl::fixed_vector<ConstrainedTextStyle, 4> formats;
	};

	class TextEngine {
	friend class FontLoader;
	public:
		TextEngine(ID3D11Device* device3d, bool debugDevice);
		~TextEngine();

		void RenderText(const TigRect &rect, const FormattedText &formattedStr);

		void RenderText(const TigRect &rect, const TextStyle &style, const std::wstring &text);
			
		void RenderText(const TigRect &rect, const TextStyle &style, const std::string &text);

		void MeasureText(const FormattedText &formattedStr, TextMetrics &metrics);

		void MeasureText(const TextStyle &style, const std::wstring &text, TextMetrics &metrics);
		
		void MeasureText(const TextStyle &style, const std::string &text, TextMetrics &metrics);

		void SetRenderTarget(ID3D11Texture2D *renderTarget);

		void AddFont(const std::string &filename);

	private:
		struct Impl;
		std::unique_ptr<Impl> mImpl;
	};

}

