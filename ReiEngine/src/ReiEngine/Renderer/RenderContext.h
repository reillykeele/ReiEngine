#pragma once

namespace ReiEngine
{
	class RenderContext
	{
	public:		
		virtual void Clear() = 0;
		virtual void SwapBuffers() = 0;	// TODO: Should this be elsewhere?
	};
}