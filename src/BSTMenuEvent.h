#pragma once

class MenuOpenCloseEvent : public RE::BSTEventSink<RE::MenuOpenCloseEvent>
{
public:
	virtual RE::BSEventNotifyControl ProcessEvent(RE::MenuOpenCloseEvent const* a_event, RE::BSTEventSource<RE::MenuOpenCloseEvent>* a_eventSource)
	{
		if (!a_event || !a_eventSource) {
			ERROR("Event Source Not Found!");
			return EventResult::kContinue;
		}

		if (a_event->opening && a_event->menuName == RE::InterfaceStrings::GetSingleton()->console)
			DEBUG("Console Open!");
		
		return RE::BSEventNotifyControl::kContinue;
	}

	static bool Register()
	{
		static MenuOpenCloseEvent singleton;

		auto ui = RE::UI::GetSingleton();
		if (!ui)
			return false;

		ui->AddEventSink(&singleton);
		INFO("Register {}", typeid(singleton).name());

		return true;
	}

private:
	MenuOpenCloseEvent() = default;

	~MenuOpenCloseEvent() = default;

	MenuOpenCloseEvent(const MenuOpenCloseEvent&) = delete;

	MenuOpenCloseEvent(MenuOpenCloseEvent&&) = delete;

	MenuOpenCloseEvent& operator=(const MenuOpenCloseEvent&) = delete;

	MenuOpenCloseEvent& operator=(MenuOpenCloseEvent&&) = delete;
};