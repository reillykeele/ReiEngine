#pragma once

namespace ReiEngine
{
	class Window
	{
	public:		
		virtual ~Window() = default;

		static Window* Create();

		virtual void Show() = 0;
		virtual void Hide() = 0;
		
		virtual bool IsVsync() = 0;
		virtual void SetVsync(bool useVsync) = 0;
		
		virtual void Swap() = 0;
	};
}
