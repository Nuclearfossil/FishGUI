#pragma once

#include <FishGUI/Widget.hpp>
#include <functional>
// #include <boost/signals2/signal.hpp>
#include <FishGUI/SimpleSignals.h>

class UnityToolBar : public FishGUI::ToolBar
{
public:
	UnityToolBar() : ToolBar() {}

	UnityToolBar(UnityToolBar&) = delete;
	UnityToolBar& operator=(UnityToolBar&) = delete;

	virtual void Draw() override;

	typedef std::function<void(void)> Callback;

	void SetTransformType();

	Simple::Signal<void(void)> OnRun;
	Simple::Signal<void(void)> OnStop;
	Simple::Signal<void(void)> OnPause;
	Simple::Signal<void(void)> OnResume;
	Simple::Signal<void(void)> OnNextFrame;

protected:

	void Run() { OnRun.emit(); }
	void Stop() { OnStop.emit(); }
	void Pause() { OnPause.emit(); }
	void Resume() { OnResume.emit(); }
	void NextFrame() { OnNextFrame.emit(); }
};
