#pragma once
#include "Session.h"
class SessionsManager
{
private:
	unsigned int current_id;
	std::vector<Session> all_sessions;
public:
	SessionsManager();
	SessionsManager(Session& s);
	SessionsManager(const SessionsManager& other);
	~SessionsManager() {}
	int getSize()const { return all_sessions.size(); }
	void switchsession(unsigned int id);
	void save();
	void close();
	void createSession(Image*);
	void addSession(Session s);
	void addSessionAndSwitch(Session s);
	Session getSessionById(unsigned int id) const;
	Session& operator[](unsigned int id);
	Session operator[](unsigned int id) const;
	Session& operator*();
	Session operator*() const;
	unsigned int getcurrentId() { return current_id; }
	Session& getcurrentSession();


};

