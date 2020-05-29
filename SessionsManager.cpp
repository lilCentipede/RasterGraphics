#include "SessionsManager.h"
SessionsManager::SessionsManager(): current_id(0){}
SessionsManager::SessionsManager(Session& s) {
	current_id = s.getId();
	all_sessions.push_back(s);
}
SessionsManager::SessionsManager(const SessionsManager& other) {
	all_sessions = other.all_sessions;
	current_id = other.current_id;
}
void SessionsManager::switchsession(unsigned int id) {
	assert(id <= all_sessions.size());
	current_id = id;
}
void SessionsManager::createSession(Image* i) {
	current_id++;
	Session s(current_id, i);
	addSession(s);
}
void SessionsManager::addSession(Session s) {
	all_sessions.push_back(s);
}
void SessionsManager::addSessionAndSwitch(Session s) {
	current_id = s.getId();
	all_sessions.push_back(s);
}
void SessionsManager::save() {
	getcurrentSession().save();
}

Session SessionsManager::getSessionById(unsigned int id) const {
	assert(id <= all_sessions.size());
	return all_sessions[id - 1];
}
Session& SessionsManager::operator[](unsigned int i) {
	assert(i <= all_sessions.size());
	return all_sessions[i];
}
Session SessionsManager::operator[](unsigned int i) const {
	assert(i <= all_sessions.size());
	return all_sessions[i];
}
Session& SessionsManager::operator*() {
	return all_sessions[current_id - 1];
}
Session SessionsManager::operator*() const {
	return all_sessions[current_id - 1];
}

Session& SessionsManager::getcurrentSession() {
	return all_sessions[current_id - 1];
}
