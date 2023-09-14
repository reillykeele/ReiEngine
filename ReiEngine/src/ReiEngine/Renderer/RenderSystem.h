#pragma once

namespace ReiEngine
{
	class RenderSystem
	{
	public:
		enum class RenderSystemType {
			None = 0,
			OpenGL = 1,
		};

	public:
		virtual ~RenderSystem() = default;

		static RenderSystemType GetRenderSystem() { return s_RenderSystem; }

	private:
		static RenderSystemType s_RenderSystem;
	};
}