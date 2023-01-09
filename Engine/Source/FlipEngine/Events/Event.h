#pragma once

namespace Flip
{
	enum class EventTypes
	{
		None = 0,
		// Window
		WindowClose,
		WindowResize,
		WindowFocus,
		WindowLostFocus,
		WindowMoved,
		// Keyboard
		KeyPressed,
		KeyReleased,
		// Mouse
		MouseButtonPressed,
		MouseButtonReleased,
		MouseMoved,
		MouseWheelScrolled,
	};

	class Event
	{
	public:
		
	private:

	};
}