#pragma once

class MessageEvent
{
private:

	MessageEvent() = delete;

	static void EventCallback(SKSE::MessagingInterface::Message* msg)
	{
		using MES = SKSE::MessagingInterface;
		switch (msg->type) {
		case MES::kPostLoad:
			DEBUG("PostLoad Message!");
			break;

		case MES::kPostPostLoad:
			DEBUG("PostPostLoad Message!");
			break;

		case MES::kPreLoadGame:
			DEBUG("PreLoadGame Message!");
			break;

		case MES::kPostLoadGame:
			DEBUG("PostLoadGame Message!");
			break;

		case MES::kSaveGame:
			DEBUG("SaveGane Message!");
			break;

		case MES::kDeleteGame:
			DEBUG("DeleteGane Message!");
			break;

		case MES::kInputLoaded:
			DEBUG("InputLoaded Message!");
			break;

		case MES::kDataLoaded:
			DEBUG("DataLoaded Message!");
			break;
		}
	}

public:
	
	static bool Register()
	{
		auto g_message = SKSE::GetMessagingInterface();
		if (!g_message) {
			ERROR("Messaging Interface Not Found!");
			return false;
		}

		g_message->RegisterListener(EventCallback);
		INFO("Register Message Event!");
		return true;
	}
};